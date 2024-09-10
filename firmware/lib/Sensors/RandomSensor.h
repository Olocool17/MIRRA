#ifndef __RANDOM_SENSOR_H__
#define __RANDOM_SENSOR_H__

#include "Sensor.h"

#define RANDOM_KEY 100;
class RandomSensor final : public Sensor
{
private:
    uint8_t measurement;

public:
    RandomSensor(uint32_t seed) { srand(seed); }
    SensorValue getMeasurement()
    {
        return SensorValue(getTypeTag(), getInstanceTag(), static_cast<float>(rand() % 101));
    };
    uint8_t getTypeTag() const { return RANDOM_KEY; }
};
#endif