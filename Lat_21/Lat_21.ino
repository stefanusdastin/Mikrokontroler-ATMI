#include <Bonezegei_DHT11.h>
#include <LiquidCrystal.h>

Bonezegei_DHT11 dht(22);

// SETTING DISPLAY I2C

const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;     // Pin-nya I2C
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

// AKHIR SETTING DISPLAY

void setup() {
  lcd.begin(16, 2);
  Serial.begin(9600);
  dht.begin();
}

void loop() {
  if (dht.getData()) {                         // get All data from DHT11
    float tempDeg = dht.getTemperature();      // return temperature in celsius
    float tempFar = dht.getTemperature(true);  // return temperature in fahrenheit if true celsius of false
    int hum = dht.getHumidity();               // return humidity

    lcd.setCursor(0, 0);
    lcd.print("Temp : ");
    lcd.print(tempDeg);

    lcd.setCursor(0, 1);
    lcd.print("Humi : ");
    lcd.print(hum);

    /*String str  = "Temperature: ";
           str += tempDeg;
           str += "°C  ";
           str += tempFar;
           str += "°F  Humidity:";
           str += hum;
      Serial.println(str.c_str());
      //Serial.printf("Temperature: %0.1lf°C  %0.1lf°F Humidity:%d \n", tempDeg, tempFar, hum);*/

  }
  delay(2000);  //delay atleast 2 seconds for DHT11 to read tha data
  lcd.clear();
}
