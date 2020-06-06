#include <Arduino.h>
#include <WiFi.h>
#include <HTTPClient.h>

//#define DEBUG_OUT

//固有名
const char* ssid     = "SSID";
const char* password = "PASS";
const char* host = "https://script.google.com/macros/s/*****/exec?device=***";
const int pin = 16;

//定数
//カレンダー保存最大
const uint16_t eventMax = 16;
//赤外us配列長
const uint16_t dataMax = 1024;
const uint32_t httpTime = 600000;
//const uint32_t httpTime = 30000;

//カレンダーデータ
class Event {
  public:
    int32_t second;
    String id;
    uint16_t irSeconds[dataMax];
    Event(int32_t _second, String _id, uint16_t _irSeconds[]): second(_second), id( _id) {
      memcpy(irSeconds, _irSeconds, sizeof(irSeconds));
    };
    Event(): second(-1) {};
    String toString() {
      String str = "";
      for(int i=0;i<dataMax;i++){
        str += String(irSeconds[i]) + " ";
        if(irSeconds[i] == 0)break;
      }
      return "second:" + String(second) + ",id:" + id + ",command:" + str;
    }
};

//変数
//HTTPアクセス
HTTPClient http;
//カレンダー
Event events[eventMax];
//前回時間
uint32_t timeOld;
uint32_t timeOldHttp;
//関数
//カレンダー取得
String getData(String uri) {
  #ifdef DEBUG_OUT
  Serial.println(uri);
  #endif
  String ret;
  // wait for WiFi connection
  if (WiFi.status() == WL_CONNECTED) {
    http.begin(uri);
    int httpCode = http.GET();
    if (httpCode > 0) {
      #ifdef DEBUG_OUT
      Serial.printf("[HTTP] GET... code: %d\n", httpCode);
      #endif
      // file found at server
      if (httpCode == HTTP_CODE_OK) {
        ret = http.getString();
        http.end();
      }
      if (httpCode == 302) {
        String tmp = http.getString();
        http.end();
        delay(1000);
        int startp = tmp.indexOf("<A HREF=") + 9;
        int endp = tmp.indexOf(">here</A>") - 1;
        String ruri;
        ruri = tmp.substring(startp, endp);
        ruri.replace("amp;", "");
        #ifdef DEBUG_OUT
        Serial.println(tmp);
        Serial.print("Redirect to:");
        #endif
        ret = getData(ruri);
      }
    } else {
      #ifdef DEBUG_OUT
      Serial.printf("[HTTP] GET... failed, error: %s\n", http.errorToString(httpCode).c_str());
      #endif
    }
    return ret;
  }
  else {
    #ifdef DEBUG_OUT
    Serial.print("Wifi error:");
    Serial.println(WiFi.status());
    #endif
    WiFi.reconnect();
  }
  return "error";
}
//文字列カレンダー変換
//カレンダー保存リストの空いているところに新しくとってきたものを埋める。
void string2Event(String string, Event events[]) {
  int p = 0;
  //改行ごとに
  while (p >= 0) {
    p = string.indexOf("\n");
    String eventString;
    if (p == -1) {
      eventString = string;
    }
    else {
      eventString = string.substring(0, p);
      string = string.substring(p + 1);
    }
    //パース
    int32_t second;
    uint16_t irSeconds[dataMax];
    String id;
    int point;
    //
    point = eventString.indexOf(" ");
    second = eventString.substring(0, point).toInt();
    eventString = eventString.substring(point+1);
    //
    point = eventString.indexOf(" ");
    id = eventString.substring(0, point);
    eventString = eventString.substring(point+1);
    //
    for(int i=0;i<dataMax;i++){
      point = eventString.indexOf(" ");
      if(point<0){
        irSeconds[i] = 0;
        break;
      }
      irSeconds[i] = eventString.substring(0, point).toInt();
      eventString = eventString.substring(point+1);
    }
    //エラー処理
    if (second == 0)continue;
    if (id.equals(""))continue;
    //登録済み確認
    int pos = -1;
    for (int i = 0; i < eventMax; i++) {
      if (id.equals(events[i].id))pos = i;
    }
    //空き探し
    if (pos == -1) {
        for (int i = 0; i < eventMax; i++) {
          if (events[i].second < 0) {
            pos = i;
            break;
          }
        }
    }
    //短いもの探し
    if (pos == -1) {
        for (int i = 0; i < eventMax; i++) {
          if (events[i].second > second) {
            pos = i;
            break;
          }
        }
    }
    //登録
    if (pos >= 0)events[pos] = Event(second, id, irSeconds);
  }
}
//赤外送信
void sendData(uint16_t datas[],int pin) {
  boolean data = HIGH;
  for (int i = 0; datas[i] != 0; i++) {
    if (data) {
      for (uint16_t j = 0; j < datas[i]; j += 26) {
        digitalWrite(pin, HIGH);
        delayMicroseconds(13);
        digitalWrite(pin, LOW);
        delayMicroseconds(13);
      }
    }
    else {
      digitalWrite(pin, LOW);
      delayMicroseconds(datas[i]);
    }
    data = !data;
  }
  digitalWrite(pin, LOW);
}
//main
void setup() {
  //
  pinMode(pin, OUTPUT);
  #ifdef DEBUG_OUT
  Serial.begin(115200);
  while (!Serial);
  Serial.println("Start");
  #endif
  //
  WiFi.begin(ssid, password);
  #ifdef DEBUG_OUT
  Serial.println("WiFi connecting");
  #endif
  //
  http.setReuse(true);
  http.setTimeout(10000);
  //time
  timeOld=millis();
  timeOldHttp=millis();
}
void loop() {
  #ifdef DEBUG_OUT
  Serial.println("Loop");
  #endif
  if (timeOldHttp + httpTime < millis()|| timeOldHttp > millis()) {
    String data = getData(host);
    #ifdef DEBUG_OUT
    Serial.println(data);
    #endif
    string2Event(data, events);
    timeOldHttp=millis();
  }
  unsigned long time  = millis();
  int past;
  if (time > timeOld) {
    past = time - timeOld;
  }
  else past = 0;
  timeOld = time;
  #ifdef DEBUG_OUT
  Serial.print("Past:");
  Serial.println(past);
  #endif
  //時間経過適応＆コマンド実行
  for (int i = 0; i < eventMax; i++) {
    if (events[i].second >= 0) {
      #ifdef DEBUG_OUT
      Serial.print("Event:");
      Serial.println(events[i].toString());
      #endif
      events[i].second -= past;
      if (events[i].second < 0) {
          #ifdef DEBUG_OUT
          Serial.println("DO");
          #endif
          for(int j=0;j<3;j++)sendData(events[i].irSeconds, pin);
      }
    }
  }
  delay(3000);
}
