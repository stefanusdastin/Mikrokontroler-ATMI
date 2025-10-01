void setup() {
  // put your setup code here, to run once:
  pinMode(22, OUTPUT);  // Lampu Merah
  pinMode(24, OUTPUT);  // Lampu Kuning
  pinMode(26, OUTPUT);  // Lampu Hijau
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(22, HIGH);
  delay(100);
  digitalWrite(24, HIGH);
  delay(100);
  digitalWrite(22, LOW);
  delay(100);
  digitalWrite(26, HIGH);
  delay(100);
  digitalWrite(24, LOW);
  delay(100);
  digitalWrite(26, LOW);
  delay(100);
}
