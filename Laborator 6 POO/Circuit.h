#pragma once
#include "Car.h"
#include "Weather.h"
#include <vector>

class Circuit {
private:
    double length;
    Weather weather;
    std::vector<Car*> cars;
    std::vector<std::pair<Car*, double>> finishedCars;
    std::vector<Car*> dnfCars;

public:
    Circuit();
    ~Circuit();
    void SetLength(double length);
    void SetWeather(Weather weather);
    void AddCar(Car* car);
    void Race();
    void ShowFinalRanks() const;
    void ShowWhoDidNotFinish() const;
};