#include <LiquidCrystal.h>

// Definisikan pin tombol dan LCD
// Asumsi tombol terhubung ke VCC (HIGH saat ditekan)
#define Pb1 22 // Start/Resume
#define Pb2 24 // Pause
#define Pb3 26 // Reset

const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5,
                  d6, d7);

// Variabel status dan waktu
bool isRunning = false;++
unsigned long startTime = 0;   // Waktu saat stopwatch mulai/resume (nilai millis())
unsigned long elapsedTime = 0; // Waktu kumulatif yang berlalu saat di-pause/stopped
unsigned long displayedTime = 0; // Waktu yang ditampilkan

// Variabel untuk debouncing (deteksi tekan tombol)
bool prevStartButton = LOW;
bool prevPauseButton = LOW;
bool prevResetButton = LOW;

//  FUNGSI UNTUK START

void start_resume() {
  if (!isRunning) {
    // Ketika START dari kondisi berhenti total (elapsedTime = 0) ATAU RESUME dari kondisi PAUSED
    // startTime dihitung dengan mengurangi waktu yang sudah berlalu (elapsedTime)
    // dari waktu millis() saat ini. Ini memastikan stopwatch melanjutkan dari elapsedTime.
    startTime = millis() - elapsedTime;
    isRunning = true;
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Stopwatch Running");
  }
}

// FUNGSI UNTUK PAUSE

void pause_stop() {
  if (isRunning) {
    // Hanya bisa di-Pause jika sedang Running
    // Simpan waktu kumulatif yang telah berlalu (elapsedTime)
    elapsedTime = millis() - startTime;
    isRunning = false;
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Stopwatch Paused");
  }
}

// FUNGSI UNTUK RESET

void reset_stop() {
  // Hanya bisa di-Reset saat di-PAUSED atau STOPPED (isRunning = false)
  if (!isRunning) {
    elapsedTime = 0;
    startTime = 0;
    displayedTime = 0;
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Stopwatch Ready");
  }
}

// --- SETUP ---

void setup() {
  Serial.begin(9600);
  // Asumsi tombol terhubung ke VCC, jadi INPUT (bukan INPUT_PULLUP)
  pinMode(Pb1, INPUT);
  pinMode(Pb2, INPUT);
  pinMode(Pb3, INPUT);
  lcd.begin(16, 2); // 16 kolom, 2 baris
  
  lcd.setCursor(0, 0);          //  Tampilan Awal
  lcd.print("STOPWATCH MS");    //  Tampilan Awal
  lcd.setCursor(0, 1);          //  Tampilan Awal
  lcd.print("Ready");           //  Tampilan Awal
}

// --- LOOP UTAMA ---

void loop() {
  // Baca status tombol
  bool startBtn = digitalRead(Pb1);
  bool pausedBtn = digitalRead(Pb2);
  bool resetBtn = digitalRead(Pb3);

  // Deteksi Tepi Naik (Rising Edge Detection) untuk Debouncing
  // Ini mencegah fungsi dipanggil berkali-kali saat tombol ditahan
  if (startBtn == HIGH && prevStartButton == LOW) {
    start_resume();
    delay(50); // Debounce
  }
  if (pausedBtn == HIGH && prevPauseButton == LOW) {
    pause_stop();
    delay(50); // Debounce
  }
  if (resetBtn == HIGH && prevResetButton == LOW) {
    reset_stop();
    delay(50); // Debounce
  }

  // Simpan status tombol saat ini untuk perulangan berikutnya
  prevStartButton = startBtn;
  prevPauseButton = pausedBtn;
  prevResetButton = resetBtn;

  // --- PEMBARUAN WAKTU ---
  if (isRunning) {
    // Jika Running, waktu yang ditampilkan adalah waktu saat ini - waktu mulai
    displayedTime = millis() - startTime;
  } else {
    // Jika Paused/Stopped, waktu yang ditampilkan adalah waktu kumulatif yang disimpan
    displayedTime = elapsedTime;
  }

  // Konversi Waktu (Milidetik ke Menit:Detik:Milidetik)
  int minutes = displayedTime / 60000;
  int second = (displayedTime % 60000) / 1000;
  // Ambil dua digit pertama milidetik, dibagi 100 untuk menampilkan puluhan milidetik
  int milliseconds = (displayedTime % 1000) / 10;

  // Tampilkan Waktu di LCD
  lcd.setCursor(0, 1);
  lcd.print("Time: ");
  lcd.print(minutes);
  lcd.print(":");
  if (second < 10) lcd.print("0");
  lcd.print(second);
  lcd.print(":");
  if (milliseconds < 10) lcd.print("0");
  lcd.print(milliseconds);
  lcd.print(" "); // Hapus karakter sisa
}
