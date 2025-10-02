// Define the analog pin connected to the potentiometer
const int Pin1 = A0;
const int Pin2 = A1;
const int Pin3 = A2;



void setup() {
  // Initialize serial communication at 9600 baud rate
  Serial.begin(9600);
}
void loop() {
  int potValue1 = analogRead(Pin1);
  int potValue2 = analogRead(Pin2);
  int potValue3 = analogRead(Pin3);

  float voltage1 = potValue1 * (5.0 / 1023.0);                // Convert the analog value to voltage (assuming 5V system)
  float voltage2 = potValue2 * (5.0 / 1023.0);                // Convert the analog value to voltage (assuming 5V system)
  float voltage3 = potValue3 * (5.0 / 1023.0);                // Convert the analog value to voltage (assuming 5V system)

  Serial.print("Voltage Potensio 1: ");
  Serial.print(voltage1);
  Serial.print("    ");

  Serial.print("Voltage Potensio 2: ");
  Serial.print(voltage2);
  Serial.print("    ");

  Serial.print("Voltage Potensio 3: ");
  Serial.println(voltage3);
  Serial.print("    ");

}
