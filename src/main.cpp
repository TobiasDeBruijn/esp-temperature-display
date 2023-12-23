#include <Arduino.h>
#include "bmp280.h"
#include "oled.h"

void setup() {
  initialize_oled();
}

void loop() {
  display_values();
  delay(500);
}