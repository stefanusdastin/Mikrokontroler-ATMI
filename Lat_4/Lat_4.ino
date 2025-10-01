
void setup() {
  // put your setup code here, to run once:
  pinMode(22, OUTPUT);  // Lampu Merah
  pinMode(24, OUTPUT);  // Lampu Kuning
  pinMode(26, OUTPUT);  // Lampu Hijau
  pinMode(28, INPUT); // Tombol
}

void loop() {
  // put your main code here, to run repeatedly:
  
  bool a = LOW;
  if (a == LOW) { // Jika lampu mati
    if (digitalRead(28) == HIGH) { // Maka ketika button ditekan, lampu akan menyala
      digitalWrite(22, HIGH);
      a = HIGH;
    }
  }
  if (a == HIGH) { // Jika lampu hidup
    if (digitalRead(28) == HIGH) {  // Maka ketika button ditekan, lampu akan mati
      digitalWrite(22, LOW);
      a = LOW;
    }
  }

}
