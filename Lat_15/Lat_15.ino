// Define the analog pin connected to the potentiometer
const int pin1 = A0;
void setup() {
  // Initialize serial communication at 9600 baud rate
  Serial.begin(9600);
}
void loop() {
  int val = analogRead(pin1);

  val = map(val, 0, 1023, 0, 100);

  Serial.print("Value: ");
  Serial.println(val);

}
