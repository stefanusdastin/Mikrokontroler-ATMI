void setup() {
  // put your setup code here, to run once:
  pinMode(22, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:

  int i;
  for (i = 0; i < 2; i++) {
    digitalWrite(22, HIGH);
    delay(100);
    digitalWrite(22, LOW);
    delay(100);
  }
  while(1);
}
