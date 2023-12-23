#ifndef TEMPDISPLAY_BMP280_H
#define TEMPDISPLAY_BMP280_H

#include <Wire.h>
#include "Adafruit_BMP280.h"

class BMP280 {
private:
    Adafruit_BMP280 bmp;
    bool initSuccess;
public:
    explicit BMP280();

    /**
     * Initialize the BMP280.
     * Call this function after initializing the TwoWire I2C interface.
     * @return True if init was successful.
     */
    bool begin();

    /**
     * Check if the sensor was successfully initialized
     * @return True if it is initialized. False if not.
     */
    [[nodiscard]] bool isInitialized() const;

    /**
     * Get the current temperature.
     * @return Temperature in degrees Celsius.
     */
    float getTemperature();

    /**
     * Get the current atmospheric pressure.
     * @return Pressure in Pa.
     */
    float getPressure();
};

#endif //TEMPDISPLAY_BMP280_H
