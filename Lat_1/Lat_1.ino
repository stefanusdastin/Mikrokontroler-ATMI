void setup() {
  // put your setup code here, to run once:
  pinMode(22, OUTPUT);  // Lampu Merah
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(22, HIGH);
  delay(100);
  digitalWrite(22, LOW);
  delay(100);

}
