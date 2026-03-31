#pragma once
#include "Weather.h"

class Car {
public:
    virtual ~Car() = default;
    virtual double GetFuelCapacity() const = 0;
    virtual double GetFuelConsumption() const = 0;
    virtual double GetSpeed(Weather weather) const = 0;
    virtual const char* GetName() const = 0;
};