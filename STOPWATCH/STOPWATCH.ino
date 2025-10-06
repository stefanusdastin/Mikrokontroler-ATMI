#include <LiquidCrystal.h>

// SETTING DISPLAY I2C DAN PIN BUTTON

const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;     // Pin-nya I2C
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
int pinStart = 22;
int pinPause = 24;
int pinReset = 26;

// AKHIR SETTING DISPLAY DAN PIN BUTTON

// VARIABEL KONDISI

bool ProsesCounting = false;
unsigned long wMulai = 0;           //  Waktu pada saat mulai/resume (nilai millis)
unsigned long wTerlampaui = 0;      //  Waktu
bool StartBtn = 0;
int DelayTime = 100;
int StartTime = 0;


void start() {
  
}

void reset() {

}

void pause() {
  
}

void setup() {
  // put your setup code here, to run once:
  lcd.begin(16, 2);
  pinMode(22, INPUT);
  pinMode(24, INPUT);
  pinMode(26, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  lcd.setCursor(0, 0);
  lcd.print("00.00.00");
  StartBtn = digitalRead(22);
  if (StartBtn == 1) {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("START");
    delay(1000);
    lcd.clear();
  }

}
