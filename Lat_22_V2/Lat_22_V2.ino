#include <LiquidCrystal.h>

// SETTING DISPLAY I2C

const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;     // Pin-nya I2C
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

// AKHIR SETTING DISPLAY


const int pinCLK = 26;
const int pinDT  = 24;
const int pinSW  = 22;

int lastCLK;
int menuIndex = 0;
const int totalMenu = 3;

void setup() {
  pinMode(pinCLK, INPUT_PULLUP);
  pinMode(pinDT, INPUT_PULLUP);
  pinMode(pinSW, INPUT_PULLUP);

  lcd.begin(16, 2);
  lcd.setCursor(0, 0);
  lcd.print("Rotary Menu");
  delay(1000);

  lastCLK = digitalRead(pinCLK);
  showMenu();
}

void loop() {
  int currentCLK = digitalRead(pinCLK);

  // Deteksi putaran encoder
  if (currentCLK != lastCLK) {
    if (digitalRead(pinDT) != currentCLK) {
      menuIndex++;
    } else {
      menuIndex--;
    }

    if (menuIndex < 0) menuIndex = totalMenu - 1;
    if (menuIndex >= totalMenu) menuIndex = 0;

    showMenu();
  }
  lastCLK = currentCLK;

  // Deteksi tombol tekan
  if (digitalRead(pinSW) == LOW) {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Pilih:");
    lcd.setCursor(0, 1);
    lcd.print("Menu ");
    lcd.print(menuIndex + 1);
    if () {
      
    }
    delay(1000);
    showMenu();
  }
}

void showMenu() {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Pilih Menu:");
  lcd.setCursor(0, 1);
  lcd.print("Menu ");
  lcd.print(menuIndex + 1);
}


// README : Next buat selector lampu w/rotary encoder
