#ifndef __SOIL_MOISTURE_SENSOR_H__
#define __SOIL_MOISTURE_SENSOR_H__

#include "Sensor.h"
#include <Arduino.h>

#define SOIL_MOISTURE_KEY 3

class SoilMoistureSensor final : public Sensor
{
private:
    uint8_t pin;

public:
    SoilMoistureSensor(uint8_t pin) : pin{pin} {};
    void startMeasurement() { pinMode(pin, INPUT); };
    SensorValue getMeasurement()
    {
        return SensorValue(getTypeTag(), getInstanceTag(), static_cast<float>(analogRead(pin)));
    };
    uint8_t getTypeTag() const { return SOIL_MOISTURE_KEY; };
};

#endif
