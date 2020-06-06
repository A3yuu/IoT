//全灯
int dataOFFAir[] = {
8140, 4087, 577, 1520, 570, 527, 570, 510, 580, 527, 573, 1513, 573, 1520, 570, 1527, 563, 530, 567, 530, 563, 527, 567, 1523, 567, 1530, 570, 523, 563, 533, 553, 540, 553, 540, 557, 537, 553, 540, 560, 540, 550, 540, 550, 540, 557, 1533, 567, 537, 560, 533, 560, 530, 567, 530, 560, 537, 560, 533, 560, 533, 557, 533, 563, 1517, 577, 1537, 557, 1517, 577, 1530, 567, 1523, 570, 18137, 563, 1530, 570, 527, 563, 533, 563, 530, 563, 530, 567, 530, 560, 530, 563, 533, 563, 530, 560, 537, 560, 533, 563, 523, 570, 523, 573, 523, 570, 520, 570, 1517, 577, 523, 570, 520, 570, 527, 573, 523, 570, 520, 573, 523, 573, 520, 563, 540, 557, 530, 573, 530, 560, 530, 560, 533, 563, 533, 560, 527, 563, 1523, 573, 527, 563, 36283, 8137, 4083, 570, 520, 577, 520, 577, 517, 577, 517, 577, 520, 570, 520, 580, 517, 573, 520, 577, 517, 580, 513, 577, 517, 577, 523, 573, 517, 577, 520, 577, 517, 570, 510, 590, 517, 573, 520, 577, 520, 577, 513, 577, 510, 583, 523, 570, 520, 577, 517, 577, 517, 573, 523, 577, 517, 573, 520, 577, 520, 573, 1510, 583, 1507, 587, 1507, 583, 1510, 587, 1507, 583, 1513, 580, 18123, 587, 520, 577, 517, 573, 520, 573, 517, 580, 517, 577, 517, 583, 510, 577, 520, 573, 523, 573, 517, 573, 513, 587, 517, 573, 517, 583, 517, 570, 520, 577, 520, 580, 510, 577, 510, 583, 520, 573, 517, 583, 517, 577, 517, 577, 517, 577, 517, 573, 520, 577, 517, 583, 500, 590, 517, 573, 1517, 580, 1517, 573, 1520, 577, 1520, 573, 0
};
int dataCoolAir[] = {
4453, 2225, 322, 824, 317, 281, 318, 280, 318, 823, 322, 825, 318, 827, 318, 822, 323, 277, 318, 281, 318, 280, 319, 823, 322, 823, 317, 281, 318, 281, 318, 277, 322, 276, 322, 277, 318, 281, 318, 281, 318, 277, 322, 276, 322, 824, 318, 827, 318, 277, 322, 277, 321, 277, 318, 281, 318, 281, 318, 276, 323, 276, 322, 825, 317, 827, 319, 823, 322, 824, 317, 827, 319, 9913, 317, 827, 318, 281, 318, 277, 322, 277, 318, 280, 318, 281, 318, 277, 322, 277, 321, 278, 317, 281, 318, 281, 318, 277, 322, 277, 322, 277, 317, 281, 318, 828, 318, 276, 322, 277, 318, 280, 318, 281, 318, 281, 318, 276, 323, 276, 318, 280, 318, 280, 319, 277, 322, 277, 321, 278, 317, 281, 318, 281, 319, 823, 321, 825, 317, 19834, 4452, 2229, 318, 281, 318, 280, 319, 276, 322, 276, 319, 280, 319, 280, 318, 279, 320, 276, 322, 277, 319, 280, 318, 280, 319, 276, 323, 276, 322, 278, 317, 281, 319, 280, 318, 276, 323, 276, 323, 277, 318, 281, 318, 280, 318, 277, 322, 277, 322, 277, 318, 281, 318, 280, 319, 277, 322, 276, 323, 277, 318, 827, 318, 823, 322, 823, 317, 828, 318, 823, 322, 823, 318, 9915, 319, 277, 321, 277, 318, 280, 318, 281, 319, 277, 322, 277, 321, 277, 318, 281, 318, 281, 318, 277, 322, 277, 322, 277, 318, 281, 317, 281, 319, 276, 322, 277, 322, 277, 317, 281, 318, 281, 319, 277, 322, 276, 322, 277, 318, 280, 319, 280, 319, 276, 323, 276, 322, 277, 318, 280, 318, 824, 321, 823, 318, 827, 318, 828, 317, 0
};
int dataHotAir[] = {
4455, 2234, 317, 281, 319, 280, 320, 825, 322, 824, 318, 281, 319, 281, 318, 825, 322, 277, 319, 828, 318, 277, 323, 825, 322, 277, 318, 280, 319, 280, 320, 277, 323, 277, 318, 281, 318, 282, 319, 280, 319, 276, 323, 277, 319, 829, 318, 824, 322, 277, 323, 277, 318, 282, 318, 280, 320, 276, 323, 277, 322, 279, 317, 830, 317, 825, 321, 826, 317, 831, 316, 826, 321, 9927, 314, 283, 317, 293, 306, 279, 321, 278, 317, 282, 317, 298, 302, 293, 306, 293, 307, 279, 316, 282, 318, 282, 317, 294, 306, 278, 318, 282, 317, 298, 301, 843, 304, 279, 320, 295, 301, 299, 300, 299, 300, 280, 320, 296, 303, 296, 300, 284, 316, 299, 301, 296, 305, 278, 320, 280, 321, 278, 321, 291, 309, 274, 325, 838, 305, 19857, 4458, 2233, 318, 282, 318, 278, 321, 278, 322, 278, 317, 283, 317, 282, 318, 278, 322, 278, 321, 278, 318, 282, 318, 282, 317, 278, 321, 279, 318, 281, 318, 282, 318, 281, 318, 278, 322, 278, 317, 283, 317, 282, 318, 278, 321, 278, 322, 278, 317, 282, 318, 282, 317, 278, 322, 278, 322, 278, 318, 282, 318, 829, 318, 825, 321, 825, 318, 829, 318, 825, 321, 826, 317, 9926, 322, 278, 318, 281, 318, 282, 317, 278, 322, 278, 322, 278, 317, 282, 317, 282, 318, 277, 322, 278, 322, 278, 318, 281, 318, 282, 318, 278, 321, 278, 322, 277, 318, 282, 318, 282, 318, 278, 321, 278, 322, 278, 317, 282, 318, 282, 318, 278, 321, 279, 317, 282, 318, 282, 318, 281, 318, 825, 322, 825, 317, 829, 319, 824, 322, 0
};
int buf[1024];
const int pinSend = 16;
const int pinRecv = 17;
//赤外送信
void sendData(int datas[], int pin) {
  boolean data = HIGH;
  for (int i = 0; datas[i] != 0; i++) {
    if (data) {
      for (int j = 0; j < datas[i]; j += 26) {
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
void setup() {
  Serial.begin(115200);
  pinMode(pinSend, OUTPUT);
  pinMode(pinRecv, INPUT);
  Serial.println("This is IR test");
}
void loop() {
  //再現
  //sendData(dataOFFAir , pinSend);
  //delay(2000);

  //解析
  
    if(digitalRead(pinRecv) == LOW){
    boolean data;
    boolean now = LOW;
    int c=0;
    int p=0;
    for(;c<30000;c++){
      data = digitalRead(pinRecv);
      if(data != now){
        now = data;
        buf[p++]=c;
        c=0;
      }
      delayMicroseconds(10);
    }
    for(int i=0;i<p;i++)Serial.println(buf[i]);
    Serial.println("end");
    }
    delayMicroseconds(10);
  
}