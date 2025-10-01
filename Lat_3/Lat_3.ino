bool kondisiLampu;

void setup() {
  // put your setup code here, to run once:
  pinMode(22, OUTPUT);  // Lampu Merah
  pinMode(24, OUTPUT);  // Lampu Kuning
  pinMode(26, OUTPUT);  // Lampu Hijau
  pinMode(28, INPUT);  // Tombol

  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:

  if (digitalRead(28) == HIGH) {
    kondisiLampu = true;
  } 
  if (digitalRead(28) == LOW){
    kondisiLampu = false;
  }

  

  if (kondisiLampu == true) {
    if (digitalRead(28) == HIGH) {  // Maka ketika button ditekan, lampu akan mati
      digitalWrite(22, LOW);
      
    }
  }
  if (kondisiLampu == false) {
    if (digitalRead(28) == HIGH) { // Maka ketika button ditekan, lampu akan menyala
      digitalWrite(22, HIGH);
    }
  }

  Serial.println(kondisiLampu);

}
