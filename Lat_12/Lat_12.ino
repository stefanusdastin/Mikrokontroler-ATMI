#include <Keypad.h>
#include <TM1637Display.h>

// Define the keypad layout
const byte ROWS = 4;
const byte COLS = 4;

// Define the keypad layout
char keys[ROWS][COLS] = {
  {'1', '4', '7', '*'},
  {'3', '6', '9', '0'},
  {'2', '5', '8', '#'},
  {'A', 'B', 'C', 'D'}
};

// Define row and column pins
byte rowPins[ROWS] = {2, 3, 4, 5}; 
byte colPins[COLS] = {6, 7, 8, 9};

// Create the Keypad object
Keypad customKeypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS);


// Module connection pins (Digital Pins)
// Sesuaikan pin ini dengan kabel yang Anda gunakan!
#define CLK 22  // Contoh: Pin Digital 2
#define DIO 24  // Contoh: Pin Digital 3

TM1637Display display(CLK, DIO);

long displayValue = 0; // Menggunakan long untuk menampung beberapa digit
int digitCount = 0;    // Menghitung berapa digit yang sudah dimasukkan


void setup() {
  Serial.begin(9600);

  // Inisialisasi display
  display.setBrightness(0x0a);
  
  // Tampilkan angka 0 awal
  display.showNumberDec(0, false); 
}


void loop() {
  // 1. Baca tombol yang ditekan (Keypad)
  char key = customKeypad.getKey();

  // 2. Jika ada tombol yang ditekan (key != 0), proses input
  if (key != NO_KEY) {
    Serial.print("Tombol Ditekan: ");
    Serial.println(key);

    // Cek apakah tombol yang ditekan adalah digit (0-9)
    if (key >= '0' && key <= '9') {
      int digit = key - '0'; // Konversi karakter '1' menjadi integer 1

      // Batasi input maksimal 4 digit (sesuai TM1637 4-digit)
      if (digitCount < 4) {
        // Logika untuk menambahkan digit baru:
        // Geser nilai lama ke kiri (dikalikan 10), lalu tambahkan digit baru
        displayValue = (displayValue * 10) + digit;
        digitCount++;
      } else {
        // Jika sudah 4 digit, nilai yang masuk menggantikan digit paling kanan (opsional, bisa juga diabaikan)
        displayValue = (displayValue * 10) + digit;
        displayValue %= 10000; // Hanya ambil 4 digit terakhir
      }

      // Tampilkan nilai terbaru ke 7-segment
      // 'false' di akhir berarti tidak menampilkan titik nol di depan (leading zero)
      display.showNumberDec(displayValue, false);
    }
    
    // Cek tombol fungsi khusus
    else if (key == '*') {
      // Tombol '*' untuk RESET (opsional)
      displayValue = 0;
      digitCount = 0;
      display.showNumberDec(0, false);
      Serial.println("Display di-RESET");
    }
    
    // Tombol selain digit (A, B, C, D, #) akan diabaikan (atau bisa ditambahkan fungsi lain)
  }
}
