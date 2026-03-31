#include "BMW.h"

double BMW::GetFuelCapacity() const {
    return 70.0;
}

double BMW::GetFuelConsumption() const {
    return 10.0;
}

double BMW::GetSpeed(Weather weather) const {
    switch (weather) {
    case Weather::Rain: return 110.0;
    case Weather::Sunny: return 160.0;
    case Weather::Snow: return 85.0;
    }
    return 0.0;
}

const char* BMW::GetName() const {
    return "BMW";
}