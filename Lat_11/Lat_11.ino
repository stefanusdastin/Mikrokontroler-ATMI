#include <Key.h>
#include <Keypad.h>


// Define the keypad layout
const byte ROWS = 4; // Four rows
const byte COLS = 4; // Four columns
char keys[ROWS][COLS] = {
  {'1', '4', '7', '*'},
  {'3', '6', '9', '#'},
  {'2', '5', '8', '0'},
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
  char key = keypad.getKey(); // Read the pressed key
  if (key) {
    Serial.print(key); // Print the key to the Serial Monitor
    
  }






  
}
