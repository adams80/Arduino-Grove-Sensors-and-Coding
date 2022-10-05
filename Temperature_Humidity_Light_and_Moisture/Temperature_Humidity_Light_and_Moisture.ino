#include "Arduino_SensorKit.h"

int light_sensor = A3;
int moisture_sensor = A1;

void setup() {
  Oled.begin();
  Oled.setFlipMode(true);
  Environment.begin();
}
void loop() {
  Oled.setFont(u8x8_font_chroma48medium8_r); //Set font style
  
  Oled.setCursor(0, 0); //Location on Oled
  Oled.print("Temperature (C):"); //Display temperature label
  Oled.setCursor(0, 1); //Location on Oled
  Oled.print(Environment.readTemperature()); //Print the temperature
  
  Oled.setCursor(0, 2); //Location on Oled
  Oled.print("Humidity (%):"); //Display humidity label
  Oled.setCursor(0, 3); //Location on Oled
  Oled.print(Environment.readHumidity()); //Print the humidity
  
  int raw_light = analogRead(light_sensor); //Read the raw value in the range 0-1023
  int light = map(raw_light, 0, 1023, 0, 100); //Take the raw light value in the range 0-1023 and scale it so it's in the range 0-100

  Oled.setCursor(0, 4); //Location on Oled
  Oled.print("Light (0-100):"); //Display the light label
  Oled.setCursor(0, 5); //Location on Oled
  Oled.println(light); //Print the scaled light value
  
  int raw_moisture = analogRead(moisture_sensor); //Read the raw moisture value from the moisture sensor pin
  int moisture = map(raw_moisture, 0, 1023, 0, 100); //Take the raw moisture value in the range 0-1023 and scale it so it's in the range 0-100
  Oled.setCursor(0, 6); //Location on Oled
  Oled.print("Moisture (0-100)"); //Print moisture label
  Oled.setCursor(0, 7); //Location on Oled
  Oled.println(moisture); //Print the scaled moisture value
  delay(10000); //Wait for 10 seconds
}
