int clock_pin = 13;//SHCP
int latch_pin = 10;//STCP
int data_pin = 11;//DS
int buttonLeft = A0;
int buttonRight = A1;
int c = 0 ;
void setup()
{
  pinMode(clock_pin,OUTPUT);
  pinMode(latch_pin,OUTPUT);
  pinMode(data_pin,OUTPUT);
  Serial.begin(9600);
}

void reg(uint8_t updata){
  for(int i=0;i<8;i++){
     digitalWrite(data_pin,(updata>>7-i & 0b00000001));
     digitalWrite(clock_pin,HIGH);
     digitalWrite(clock_pin,LOW);
     Serial.println(updata);
     Serial.println("void reg end");
  }
}
void loop() {
  // put your main code here, to run repeatedly:
  if(Serial.available()>0){
   int inputNum = Serial.read();
    switch(inputNum){
      case '0':
      digitalWrite(latch_pin,LOW);
      reg(0b00111111);
      digitalWrite(latch_pin,HIGH);
      Serial.println(inputNum);
      delay(1000);//0
      break;
      case '1':
      Serial.println(inputNum);
      digitalWrite(latch_pin,LOW);
      reg(0b00000110);
      digitalWrite(latch_pin,HIGH);
      break;
      case '2':
      Serial.println(inputNum);
      digitalWrite(latch_pin,LOW);
      reg(0b01011011);
      digitalWrite(latch_pin,HIGH);
      delay(1000);//2
      break;
      case '3':
      Serial.println(inputNum);
      digitalWrite(latch_pin,LOW);
      reg(0b01001111);
      digitalWrite(latch_pin,HIGH);
      delay(1000);//3
      break;
      case '4':
      Serial.println(inputNum);
      digitalWrite(latch_pin,LOW);
      reg(0b01100110);
      digitalWrite(latch_pin,HIGH);
      delay(1000);//4
      break;
      case '5':
      Serial.println(inputNum);
      digitalWrite(latch_pin,LOW);
      reg(0b01101101);
      digitalWrite(latch_pin,HIGH);
      delay(1000);//5
      break;
      case '6':
      Serial.println(inputNum);
      digitalWrite(latch_pin,LOW);
      reg(0b01111101);
      digitalWrite(latch_pin,HIGH);
      delay(1000);//6
      break;
      case '7':
      Serial.println(inputNum);
      digitalWrite(latch_pin,LOW);
      reg(0b00000111);
      digitalWrite(latch_pin,HIGH);
      delay(1000);//7
      break;
      case '8':
      Serial.println(inputNum);
      digitalWrite(latch_pin,LOW);
      reg(0b01111111);
      digitalWrite(latch_pin,HIGH);
      delay(1000);//8
      break;
      case '9':
      Serial.println(inputNum);
      digitalWrite(latch_pin,LOW);
      reg(0b01101111);
      digitalWrite(latch_pin,HIGH);
      delay(1000);//9
      break;
      default:
      Serial.println("0-9 only");
  }
}
}
