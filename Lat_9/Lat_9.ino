#include <Arduino.h>
#include <TM1637Display.h>

// Module connection pins (Digital Pins)
#define CLK 22
#define DIO 24


TM1637Display display(CLK, DIO);

void setup()
{
}

void loop() {

  display.setBrightness(0x0f);

  // count up
  for (int i = 0; i <= 9999; i++) {
    display.showNumberDec(i);
  }
  
  // count down
  for (int k = 9999; k >= 0; k--) {
    display.showNumberDec(k);
  }
}
