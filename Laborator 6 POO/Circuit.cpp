#include "Circuit.h"
#include <iostream>
#include <algorithm>

Circuit::Circuit() : length(0), weather(Weather::Sunny) {}

Circuit::~Circuit() {
    for (Car* car : cars) {
        delete car;
    }
}

void Circuit::SetLength(double length) {
    this->length = length;
}

void Circuit::SetWeather(Weather weather) {
    this->weather = weather;
}

void Circuit::AddCar(Car* car) {
    cars.push_back(car);
}

void Circuit::Race() {
    finishedCars.clear();
    dnfCars.clear();

    for (Car* car : cars) {
        double maxDistance = (car->GetFuelCapacity() / car->GetFuelConsumption()) * 100.0;

        if (maxDistance >= length) {
            double time = length / car->GetSpeed(weather);
            finishedCars.push_back({ car, time });
        }
        else {
            dnfCars.push_back(car);
        }
    }

    std::sort(finishedCars.begin(), finishedCars.end(),
        [](const std::pair<Car*, double>& a, const std::pair<Car*, double>& b) {
            return a.second < b.second;
        });
}

void Circuit::ShowFinalRanks() const {
    for (const auto& entry : finishedCars) {
        std::cout << entry.first->GetName() << " - " << entry.second << " h\n";
    }
}

void Circuit::ShowWhoDidNotFinish() const {
    for (Car* car : dnfCars) {
        std::cout << car->GetName() << "\n";
    }
}