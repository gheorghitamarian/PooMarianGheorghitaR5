#include "Volvo.h"

double Volvo::GetFuelCapacity() const {
    return 60.0;
}

double Volvo::GetFuelConsumption() const {
    return 7.5;
}

double Volvo::GetSpeed(Weather weather) const {
    switch (weather) {
    case Weather::Rain: return 95.0;
    case Weather::Sunny: return 130.0;
    case Weather::Snow: return 75.0;
    }
    return 0.0;
}

const char* Volvo::GetName() const {
    return "Volvo";
}