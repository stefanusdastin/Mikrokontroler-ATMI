// Define the analog pin connected to the potentiometer
int pin1 = A0;    // pin potensio
int pin2 = 2;      // pin lampu
 
void setup() {
}

void loop() {
  long int k = analogRead(pin1);
  k = map(k, 0, 1023, 0, 255);
  analogWrite(pin2, k);
}
