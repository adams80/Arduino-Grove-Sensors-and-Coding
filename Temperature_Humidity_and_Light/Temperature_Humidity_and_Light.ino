#include "Arduino_SensorKit.h"

int light_sensor = A3; //light sensor on analog pin A3

void setup() {
  Oled.begin();
  Oled.setFlipMode(true);
  Environment.begin();
}
void loop() {
  Oled.setFont(u8x8_font_chroma48medium8_r); //Set font style
  
  Oled.setCursor(0, 1); //Location on Oled
  Oled.print("Temperature (C):"); //Display temperature label
  Oled.setCursor(0, 2); //Location on Oled
  Oled.print(Environment.readTemperature()); //Print the temperature, read from the temperature sensor

  Oled.setCursor(0, 3); //Location on Oled
  Oled.print("Humidity (%): "); //Display humidity label
  Oled.setCursor(0, 4); //Location on Oled
  Oled.print(Environment.readHumidity()); //Print the humidity, read from the humidity sensor

  int raw_light = analogRead(light_sensor); //Read the raw light sensor value, in the range 0-1023
  int light = map(raw_light, 0, 1023, 0, 100); //Scale the value in the range 0-1023 so it's in the range 0-100
  Oled.setCursor(0, 5); //Location on Oled
  Oled.print("Light (0-100): "); //Display light label
  Oled.setCursor(0, 6); //Location on Oled
  Oled.print(light); //Print the light value
  
  delay(10000); //Wait for 10 seconds
}
