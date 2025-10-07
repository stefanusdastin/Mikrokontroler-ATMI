#include <LiquidCrystal.h>


// SETTING DISPLAY I2C DAN PIN BUTTON

const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;  // Pin-nya I2C
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
int pinStart = 22;
int pinPause = 24;
int pinReset = 26;

// AKHIR SETTING DISPLAY DAN PIN BUTTON

// VARIABEL & KONS

bool StartBtn = 0;
bool PauseBtn = 0;
bool ResetBtn = 0;

#define delayMs = 1;       //  Untuk menghitung Milisekon
#define delayS = 1000;     //  Untuk menghitung Detik
#define delayMnt = 60000;  //  Untuk menhitung Menit

int MSekon;
int Sekon;
int Menit;

int SWStatus = 0;  // 0 = Zero Point; 1 = Count; 2 = Paused;


void start() {

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("STOPWATCH ON");
  lcd.setCursor(0, 1);
  lcd.print("TIME : ");

  for (Menit = 0; Menit < 9999; Menit++) {  // Bagian Menit : siapa jg yg nyalain smp 9999menit
    if (Menit < 10) {
      lcd.setCursor(7, 1);
      lcd.print("0");
      lcd.setCursor(8, 1);
      lcd.print(Menit);
      lcd.setCursor(9, 1);
      lcd.print(":");
    } else {
      lcd.setCursor(7, 1);
      lcd.print(Menit);
      lcd.setCursor(9, 1);
      lcd.print(":");
    }
    for (Sekon = 0; Sekon < 60; Sekon++) {  // Bagian Detik
      if (Sekon < 10) {
        lcd.setCursor(10, 1);
        lcd.print("0");
        lcd.setCursor(11, 1);
        lcd.print(Sekon);
        lcd.setCursor(12, 1);
        lcd.print(":");
      } else {
        lcd.setCursor(10, 1);
        lcd.print(Sekon);
        lcd.setCursor(12, 1);
        lcd.print(":");
      }
      for (MSekon = 0; MSekon < 100; MSekon++) {
        lcd.setCursor(13, 1);
        lcd.print(MSekon);
        delay(10);  // yg pas 10
      }
    }
  }
}

void pause() {

  if (SWStatus = 2) {
    lcd.setCursor(0, 0);
    lcd.print("SW PAUSED");
    lcd.setCursor(0, 1);
    lcd.print("TIME : ");

    if (Menit < 10) {
      lcd.setCursor(7, 1);
      lcd.print("0");
      lcd.setCursor(8, 1);
      lcd.print(Menit);
      lcd.setCursor(9, 1);
      lcd.print(":");
    } else {
      lcd.setCursor(7, 1);
      lcd.print(Menit);
      lcd.setCursor(9, 1);
      lcd.print(":");
    }

    if (Sekon < 10) {
      lcd.setCursor(10, 1);
      lcd.print("0");
      lcd.setCursor(11, 1);
      lcd.print(Sekon);
      lcd.setCursor(12, 1);
      lcd.print(":");
    } else {
      lcd.setCursor(10, 1);
      lcd.print(Sekon);
      lcd.setCursor(12, 1);
      lcd.print(":");
    }

    lcd.setCursor(13, 1);
    lcd.print(MSekon);
  }
}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(6900);
  lcd.begin(16, 2);
  pinMode(22, INPUT);
  pinMode(24, INPUT);
  pinMode(26, INPUT);
  lcd.setCursor(0, 0);
  lcd.print("STOP, WATCH!");
  lcd.setCursor(0, 1);
  lcd.print("TIME : 00:00:00");
}

void loop() {
  // put your main code here, to run repeatedly:

  StartBtn = digitalRead(22);
  PauseBtn = digitalRead(24);
  ResetBtn = digitalRead(26);

  if (StartBtn == 1) {
    lcd.clear();
    start();
  }

  if (PauseBtn == 1) {
    SWStatus = 2;
    lcd.clear();
    pause();
  }
}
