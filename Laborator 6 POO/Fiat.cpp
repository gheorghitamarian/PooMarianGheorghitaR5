#include "Fiat.h"

double Fiat::GetFuelCapacity() const {
    return 40.0;
}

double Fiat::GetFuelConsumption() const {
    return 5.5;
}

double Fiat::GetSpeed(Weather weather) const {
    switch (weather) {
    case Weather::Rain: return 80.0;
    case Weather::Sunny: return 110.0;
    case Weather::Snow: return 60.0;
    }
    return 0.0;
}

const char* Fiat::GetName() const {
    return "Fiat";
}