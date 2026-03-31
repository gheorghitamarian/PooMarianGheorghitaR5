#include "Seat.h"

double Seat::GetFuelCapacity() const {
    return 50.0;
}

double Seat::GetFuelConsumption() const {
    return 6.0;
}

double Seat::GetSpeed(Weather weather) const {
    switch (weather) {
    case Weather::Rain: return 85.0;
    case Weather::Sunny: return 120.0;
    case Weather::Snow: return 65.0;
    }
    return 0.0;
}

const char* Seat::GetName() const {
    return "Seat";
}