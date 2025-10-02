#include <Arduino.h>
#include <TM1637Display.h>
#include <Key.h>
#include <Keypad.h>

// Module connection pins (Digital Pins)
#define CLK 22
#define DIO 24

// The amount of time (in milliseconds) between tests
#define TEST_DELAY   25

TM1637Display display(CLK, DIO);

// Define the keypad layout
const byte ROWS = 4; // Four rows
const byte COLS = 4; // Four columns
char keys[ROWS][COLS] = {
  {'3', '6', '9', '*'},
  {'5', '8', '1', '#'},
  {'4', '7', '0', '0'},
  {'A', 'B', 'C', 'D'}
};

// Define row and column pins
byte rowPins[ROWS] = {2, 3, 4, 5}; // Connect to the row pins of the keypad
byte colPins[COLS] = {6, 7, 8, 9}; // Connect to the column pins of the keypad

// Create the Keypad object
Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);

void setup() {
  Serial.begin(9600); // Initialize serial communication
}

void loop() {
  display.setBrightness(0x0f);
  char key = keypad.getKey(); // Read the pressed key

  if (key) {
    Serial.print(key); // Print the key to the Serial Monitor
    display.showNumberDec(key, false, 1, 3);
  }

}
