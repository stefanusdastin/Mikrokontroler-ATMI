#include <Key.h>
#include <Keypad.h>
#include <LiquidCrystal.h>

// SETTING KEYPAD

// Deklarasi layout keypad
const byte ROWS = 4;
const byte COLS = 4;

// Deklarasi layout keypad
char keys[ROWS][COLS] = {
  {'1', '4', '7', '*'},
  {'2', '5', '8', '0'},
  {'3', '6', '9', '#'},
  {'A', 'B', 'C', 'D'}
};

// Pin-nya Keypad
byte rowPins[ROWS] = {22, 24, 26, 28};
byte colPins[COLS] = {30, 32, 34, 36};

// Deklarasi objek Keypad
Keypad customKeypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS);


// AKHIR SETTING KEYPAD

// SETTING DISPLAY I2C

const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;     // Pin-nya I2C
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

// AKHIR SETTING DISPLAY

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:

  lcd.setCursor(0, 0);
  lcd.print("Contrast Test");
}
