#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#include <ThreeWire.h>
#include <RtcDS1302.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET -1

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);
ThreeWire myWire(3, 6, 2);
RtcDS1302<ThreeWire> Rtc(myWire);
void printDateTime(const RtcDateTime& dt)
{
  display.clearDisplay();
  display.setTextSize(2);
  display.setTextColor(WHITE);
  display.setCursor(0,0);
  display.print(dt.Year());
  display.print('/');
  display.print(dt.Month());
  display.print('/');
  display.print(dt.Day());
  display.print(' ');
  display.print(dt.Hour());
  display.print(':');
  display.print(dt.Minute());
  display.print(':');
  display.print(dt.Second());
  display.display();
}

void setup() {
  Serial.begin(57600);
  Rtc.Begin();
  display.print("");
  display.begin(SSD1306_SWITCHCAPVCC, 0x3c);
  display.clearDisplay();
  RtcDateTime setting_time(2020,2,27,14,20,10);
  Rtc.SetDateTime(setting_time);
}

void loop() {
  RtcDateTime now = Rtc.GetDateTime();
  Serial.println(now.Year());
  printDateTime(now);
  delay(100);
}
