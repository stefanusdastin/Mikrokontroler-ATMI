#include <Arduino.h>
#include <TM1637Display.h>

// Module connection pins (Digital Pins)
#define CLK 22
#define DIO 24

// The amount of time (in milliseconds) between tests
#define TEST_DELAY   25

TM1637Display display(CLK, DIO);


void setup()
{
}

void loop() {

  display.setBrightness(0x0f);

  for (int a = 0; a <= 2; a++) {
    display.showNumberDec(a, false, 1, 0);
    delay(TEST_DELAY);
    if (a == 2) {
      for (int b = 0; b < 4; b++) {
        display.showNumberDec(b, false, 1, 1);
        delay(TEST_DELAY);

        for (int c = 0; c < 6; c++) {
          display.showNumberDec(c, false, 1, 2);
          delay(TEST_DELAY);

          for (int d = 0; d <= 9; d++) {
            display.showNumberDec(d, false, 1, 3);
            delay(TEST_DELAY);
          }
        }
      }
    } else {
      for (int b = 0; b <= 9; b++) {
        display.showNumberDec(b, false, 1, 1);
        delay(TEST_DELAY);

        for (int c = 0; c < 6; c++) {
          display.showNumberDec(c, false, 1, 2);
          delay(TEST_DELAY);

          for (int d = 0; d <= 9; d++) {
            display.showNumberDec(d, false, 1, 3);
            delay(TEST_DELAY);
          }
        }
      }
    }
  }







}
