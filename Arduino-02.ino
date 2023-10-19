#include <Adafruit_Sensor.h>
#include <DHT.h>
#include <LiquidCrystal_I2C.h> 

float temperature;
float humidity;
DHT dht14(D4, DHT11);

LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  Serial.begin(9600);

  dht14.begin();

  lcd.begin();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("Temp:       C");
  lcd.setCursor(0, 1);
  lcd.print("Hum:       %");
}

void loop()
 {
  humidity = dht14.readHumidity();
  temperature = dht14.readTemperature();

  Serial.print(humidity);
  Serial.println(" %");
  Serial.print("Temperature: ");
  Serial.print(temperature);
  Serial.print(" °C  Humidity: ");
  
  String humidityText = "Hum: " + String(humidity) + " %";
  String tempText = "Temp: " + String(temperature) + " C";

  lcd.clear();

  lcd.setCursor(0, 1);
  lcd.print(humidityText);
  lcd.setCursor(0, 0);
  lcd.print(tempText);

 
  delay(1000);
}