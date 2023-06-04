// CityManger.h
#ifndef TASK6_DVIR_AVRAHAM_CITYMANGER_H
#define TASK6_DVIR_AVRAHAM_CITYMANGER_H

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <limits>
#include "CityContainer.h"
#include <set>

const std::string FILENAME = "data.txt";
using Cord = std::pair<double, double>;

struct GetValue {
    std::string operator()(const std::pair<const double, std::string>& pair) const {
        return pair.second;
    }
};

class CityManger {
    CityContainer cities;

    double calculateDistance(Cord city1, Cord city2, int norm) const;
    std::vector<std::string> getCitiesInRange(const Cord& idx, double radius) const;
    size_t countCitiesNorthOfCenter(const std::vector<std::string>& citiesInsideSquare, const Cord& idx) const;
    void printCitiesInsideSquare(const std::vector<std::string>& citiesInsideSquare) const;

public:
    explicit CityManger();
    Cord SearchCity(const std::string& keyword);
    void GetNearestCities(const Cord& idx, double radius, int norm) const;
};

#endif // TASK6_DVIR_AVRAHAM_CITYCONTAINER_H
