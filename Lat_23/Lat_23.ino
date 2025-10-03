#include <LiquidCrystal.h>

// SETTING DISPLAY I2C

const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;     // Pin-nya I2C
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

// AKHIR SETTING DISPLAY

int TempPin = 22;

void setup() {
  // put your setup code here, to run once:
  lcd.begin(16, 2);
}

void loop() {
  // put your main code here, to run repeatedly:
  int temp = digitalRead(TempPin);
  lcd.setCursor(0, 0);
  lcd.print("Suhu : ");
  lcd.print(temp);
  delay(10000);
}
