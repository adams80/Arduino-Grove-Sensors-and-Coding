#define BUZZER 5

void setup() {
  pinMode(BUZZER, OUTPUT);
}
 void loop() {
  tone(BUZZER, 85);
  delay(1000);
  noTone(BUZZER);
  delay(1000);
 }
