#include <Arduino.h>
#include <TM1637Display.h>

// Module connection pins (Digital Pins)
#define CLK 22
#define DIO 24

// The amount of time (in milliseconds) between tests
#define TEST_DELAY   2000

const uint8_t SEG_DONE[] = {
  SEG_B | SEG_C | SEG_D | SEG_E | SEG_G,           // d
  SEG_A | SEG_B | SEG_C | SEG_D | SEG_E | SEG_F,   // O
  SEG_C | SEG_E | SEG_G,                           // n
  SEG_A | SEG_D | SEG_E | SEG_F | SEG_G            // E
};

TM1637Display display(CLK, DIO);


void setup()
{
}

void loop() {

  int a = 6;
  int b = 7;
  int c = 8;
  int d = 9;
  

  int k;
  uint8_t data[] = { 0xff, 0xff, 0xff, 0xff };
  uint8_t blank[] = { 0x00, 0x00, 0x00, 0x00 };
  display.setBrightness(0x0f);

  // Selectively set different digits
  
  data[0] = display.encodeDigit(a);
  data[1] = display.encodeDigit(b);
  data[2] = display.encodeDigit(c);
  data[3] = display.encodeDigit(d);
  display.setSegments(data);
  delay(TEST_DELAY);

    for(k = 3; k >= 0; k--) {
  display.setSegments(data, 1, k);
  delay(TEST_DELAY);
  }

  while (1);
}
