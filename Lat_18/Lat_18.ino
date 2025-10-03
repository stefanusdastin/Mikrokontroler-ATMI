#include <LiquidCrystal.h>

const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;     // pin-nya I2C
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

int button;
int kondisi = 0;

void setup() {
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  pinMode(22, INPUT);
}

void loop() {
  // looping program
  while (kondisi == 0) {
    lcd.setCursor(0, 0);
    lcd.print("tekan dong");
    for (int loop = 0; loop < 500; loop++) {
      button = digitalRead(22);
      if (button == HIGH) {
        kondisi = 1;
      }
    }
    lcd.clear();
  }

  while (kondisi == 1) {
    for (int a = 0; a <= 10; a++) {
      delay(250);
      lcd.setCursor(a - 2, 0);
      lcd.print("satu");
    }

    lcd.clear();
    lcd.setCursor(7, 1);
    lcd.print("dua");

    for (int a = 9; a >= -1; a--) {
      delay(250);
      lcd.setCursor(a - 2, 1);
      lcd.print("tiga");
    }

    lcd.clear();
    lcd.setCursor(7, 1);
    lcd.print("empat");


  }

}
