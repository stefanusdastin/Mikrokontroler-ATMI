// Define the analog pin connected to the potentiometer
const int potPin = A0;
void setup() {
  // Initialize serial communication at 9600 baud rate
  Serial.begin(9600);
}
void loop() {
  int potValue = analogRead(potPin);
  float voltage = potValue * (5.0 / 1023.0);                // Convert the analog value to voltage (assuming 5V system)
  Serial.print("Voltage: ");
  Serial.println(voltage);

}
