#include "oled.h"
#include "Adafruit_SSD1306.h"
#include "Adafruit_GFX.h"
#include <Wire.h>
#include "bmp280.h"

#define OledReset (-1)
#define OledAddress 0x3C

Adafruit_SSD1306 display(128, 64, &Wire, OledReset);
BMP280 bmp;

void initialize_oled() {
  if(!display.begin(SSD1306_SWITCHCAPVCC, OledAddress)) {
    Serial.println(F("SSD1306 Allocation failed"));
    for(;;);
  }

  display.display();
  delay(200);

  display.setTextSize(2);
  display.setTextColor(SSD1306_WHITE);

  bmp.begin();
}

void display_values() {
  display.clearDisplay();

  display.setCursor(0, 0);
  float tmp = bmp.getTemperature();
  display.printf("%.1f", tmp);

  display.setCursor(128 - (12 * 2), 0);
  display.print((char) 247); // Degrees symbol
  display.print(F("C"));

  display.setCursor(0, 16);
  float pa = bmp.getPressure();
  float hpa = pa / 100.0;

  display.printf("%.1f", hpa);
  display.setCursor(128 - (3 * 12), 16);
  display.print(F("hPa"));

  String v;
  if(tmp < 10) {
    v = "Vrieskist";
  } else if (tmp < 20) {
    v = "Frisjes";
  } else if (tmp < 30) {
    v = "Comfor";
  } else {
    v = "Oven";
  }

  display.setCursor(0, 16 * 3);
  display.print(v);

  display.display();
}