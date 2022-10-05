#include "Arduino_SensorKit.h"

void setup() {
  Oled.begin();
  Oled.setFlipMode(true);
}

void loop() {
  int random_value_1 = random(0, 1023);   // create a random value
  Oled.setFont(u8x8_font_chroma48medium8_r);
  Oled.setCursor(0, 0);
  Oled.print("Value 1: ");
  Oled.print(random_value_1);

  int random_value_2 = random(0, 1023);   //create another random value
  Oled.setCursor(0, 3);
  Oled.print("Value 2: ");
  Oled.print(random_value_2);
  delay(1000);
}
