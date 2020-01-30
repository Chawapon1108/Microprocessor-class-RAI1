#define DATA_PIN 5
#define LATCH_PIN 4
#define CLOCK_PIN 6

void setup()
{
  pinMode(DATA_PIN,OUTPUT);
  pinMode(CLOCK_PIN,OUTPUT);
  pinMode(LATCH_PIN,OUTPUT);
}
void loop()
{
  
  for (int i=0; i<8; i++) {
    shiftOut(DATA_PIN, CLOCK_PIN, MSBFIRST, B00000001 << i);
    digitalWrite(LATCH_PIN, HIGH);
    delay(125); 
    digitalWrite(LATCH_PIN, LOW);
  }
  
  for (int i=0; i<8; i++) {
    shiftOut(DATA_PIN, CLOCK_PIN, MSBFIRST, B10000000 >> i);
    digitalWrite(LATCH_PIN, HIGH);
    delay(125);  
    digitalWrite(LATCH_PIN, LOW);
  }
}