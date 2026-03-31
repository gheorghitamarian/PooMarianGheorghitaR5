#include "RangeRover.h"

double RangeRover::GetFuelCapacity() const {
    return 90.0;
}

double RangeRover::GetFuelConsumption() const {
    return 15.0;
}

double RangeRover::GetSpeed(Weather weather) const {
    switch (weather) {
    case Weather::Rain: return 120.0;
    case Weather::Sunny: return 140.0;
    case Weather::Snow: return 100.0;
    }
    return 0.0;
}

const char* RangeRover::GetName() const {
    return "RangeRover";
}