#pragma once
#include "Car.h"

class RangeRover : public Car {
public:
    double GetFuelCapacity() const override;
    double GetFuelConsumption() const override;
    double GetSpeed(Weather weather) const override;
    const char* GetName() const override;
};