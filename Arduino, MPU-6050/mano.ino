#include<Wire.h>
const int MPU2=0x69, MPU1=0x68;
// Valores RAW (sin procesar) del acelerometro y giroscopio en los ejes x,y,z
int16_t AcX1, AcY1, AcZ1,Tmp1,GyX1,GyY1,GyZ1;
int16_t AcX2, AcY2, AcZ2,Tmp2,GyX2,GyY2,GyZ2;
int datas;

void setup() {
  // put your setup code here, to run once:
  Wire.begin();
  Wire.beginTransmission(MPU1);
  Wire.write(0x6B);
  Wire.write(0);
  Wire.endTransmission(true);
  Wire.begin();
  Wire.beginTransmission(MPU2);
  Wire.write(0x6B);
  Wire.write(0);
  Wire.endTransmission(true);
  Serial.begin(9600);
  

}

void loop() {
  // put your main code here, to run repeatedly:
  GetMpuValue1(MPU1);
  sentunity();
}

void GetMpuValue1(const int MPU){
  Wire.beginTransmission(MPU);
    Wire.write(0x3B);
    Wire.endTransmission(false);
    Wire.requestFrom(MPU,14,true);
    AcX1=Wire.read()<<8| Wire.read();
    AcY1=Wire.read()<<8| Wire.read();
    AcZ1=Wire.read()<<8| Wire.read();
    Tmp1=Wire.read()<<8| Wire.read();
    GyX1=Wire.read()<<8| Wire.read();
    GyY1=Wire.read()<<8| Wire.read();
    GyZ1=Wire.read()<<8| Wire.read();
    AcX2=Wire.read()<<8| Wire.read();
    AcY2=Wire.read()<<8| Wire.read();
    AcZ2=Wire.read()<<8| Wire.read();
    Tmp2=Wire.read()<<8| Wire.read();
    GyX2=Wire.read()<<8| Wire.read();
    GyY2=Wire.read()<<8| Wire.read();
    GyZ2=Wire.read()<<8| Wire.read();
}


void sentunity(){
  if(Serial.available()){
    datas=Serial.read();
    if(datas=='a'){
      Serial.println(AcX1);
    }
    if(datas=='b'){
      Serial.println(AcY1);
    }
    if(datas=='c'){
      Serial.println(AcZ1);
    }
    if(datas=='d'){
      Serial.println(GyX1);
    }
    if(datas=='e'){
      Serial.println(GyY1);
    }
    if(datas=='f'){
      Serial.println(GyZ1);
    }
    if(datas=='g'){
      Serial.println(AcX2);
    }
    if(datas=='h'){
      Serial.println(AcY2);
    }
    if(datas=='i'){
      Serial.println(AcZ2);
    }
    if(datas=='j'){
      Serial.println(GyX2);
    }
    if(datas=='k'){
      Serial.println(GyY2);
    }
    if(datas=='l'){
      Serial.println(GyZ2);
    }
  }
}
