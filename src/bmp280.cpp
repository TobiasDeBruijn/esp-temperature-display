#include "bmp280.h"
#include <Adafruit_BMP280.h>

BMP280::BMP280() {
  bmp = Adafruit_BMP280();
  initSuccess = false;
}

bool BMP280::isInitialized() const {
  return initSuccess;

}

float BMP280::getTemperature() {

  if (!isInitialized()) {
    return 0;
  }

  return bmp.readTemperature();
}

float BMP280::getPressure() {
  if (!isInitialized()) {
    return 0;
  }

  return bmp.readPressure();
}

bool BMP280::begin() {
  initSuccess = bmp.begin(BMP280_ADDRESS_ALT, BMP280_CHIPID);

  if (!initSuccess) {
    return false;
  }

  bmp.setSampling(
          Adafruit_BMP280::MODE_NORMAL,
          Adafruit_BMP280::SAMPLING_X2,
          Adafruit_BMP280::SAMPLING_X16,
          Adafruit_BMP280::FILTER_X16,
          Adafruit_BMP280::STANDBY_MS_500
  );

  return true;
}

