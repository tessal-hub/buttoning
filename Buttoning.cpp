#include <Arduino.h>

void Buttoning(int btnPin, unsigned long duration) {
  static unsigned long pressStartTime = 0;
  static bool pressed = false;
  static bool long_press = false;

  int current_state = digitalRead(btnPin);

  if (current_state == LOW) {  // Button is pressed
    if (!pressed) {
      pressStartTime = millis();
      pressed = true;
      long_press = false;
    } else if (!long_press && (millis() - pressStartTime >= duration)) {
      Serial.println("Long press");
      long_press = true;
    }
  } else {  // Button released
    if (pressed && !long_press) {
      Serial.println("Tap");
    }
    pressed = false;
  }
}
