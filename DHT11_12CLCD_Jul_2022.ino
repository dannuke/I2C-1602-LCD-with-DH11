/*
 * Created by ArduinoGetStarted.com
 *
 * This example code is in the public domain
 *
 * Tutorial page: https://arduinogetstarted.com/tutorials/arduino-temperature-humidity-sensor-lcd
 * I2C board connections:
 * LCD GND to Arduino GND
 * LCD VCC to Arduino 5v
 * LCD VCC to Arduino A4
 * LCD SCL to Arduino A%
 * 
 */

#include <LiquidCrystal_I2C.h>
#include "DHT.h"
#define DHTPIN 2
#define DHTTYPE DHT11

LiquidCrystal_I2C lcd(0x27, 16, 2);  // I2C address 0x27, 16 column and 2 rows. changed  from 3F. REMOVED F.  Used I2C scanner sketch
DHT dht(DHTPIN, DHTTYPE);

void setup()
{
  dht.begin();     // initialize the sensor
 lcd.init();      // initialize the lcd
 
  lcd.backlight(); // open the backlight 
}

void loop()
{
  delay(2000); // wait a few seconds between measurements

  float humi  = dht.readHumidity();    // read humidity
  float tempC = dht.readTemperature(); // read temperature

  lcd.clear();
  // check if any reads failed
  if (isnan(humi) || isnan(tempC)) {
    lcd.setCursor(0, 0);
    lcd.print("Failed");
  } else {
    lcd.setCursor(0, 0);  // start to print at the first row
    lcd.print("Temp: ");
    lcd.print(tempC);     // print the temperature
    //lcd.print(int)round(1.8*t+32));
    lcd .print(" *C");
    lcd.setCursor(0, 1);  // start to print at the second row
    lcd.print("Humi: ");
    lcd.print(humi);      // print the humidity
    lcd.print("%");
  }
}
