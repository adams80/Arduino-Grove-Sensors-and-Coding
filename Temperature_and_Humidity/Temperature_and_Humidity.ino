#include "Arduino_SensorKit.h"

void setup() {
  Oled.begin();
  Oled.setFlipMode(true);
  Environment.begin();
}
void loop() {
  Oled.setFont(u8x8_font_chroma48medium8_r); //Set font style
  
  Oled.setCursor(0, 1); //Location on OLED
  Oled.print("Temperature (C):"); //Print temperature label
  Oled.setCursor(0, 2); //Location on OLED
  Oled.print(Environment.readTemperature()); //Print the temperature

  Oled.setCursor(0, 4); //Location on Oled
  Oled.print("Humidity (%):"); //Print humidity label
  Oled.setCursor(0, 5); //Location on OLED
  Oled.print(Environment.readHumidity()); //Print the humidity
  
  delay(10000); //Wait for 10 seconds
}
