//
// Created by Dvir Avraham on 14/05/2023.
//

#ifndef TASK6_DVIR_AVRAHAM_CITYCONTAINER_H
#define TASK6_DVIR_AVRAHAM_CITYCONTAINER_H
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <unordered_map>
#include <algorithm>
#include <iomanip>
#include <iterator>

class CityContainer {
public:
    using Coordinates = std::pair<long double, long double> ; // for readability purposes only
    // Iterator typedefs
    using iterator = std::unordered_map<std::string, Coordinates>::iterator;
    using const_iterator = std::unordered_map<std::string, Coordinates>::const_iterator;

    explicit CityContainer(const std::string& filename);

    // Iterator access functions
    iterator begin() {
        return cities.begin();
    }

    iterator end() {
        return cities.end();
    }

    const_iterator begin() const {
        return cities.begin();
    }

    const_iterator end() const {
        return cities.end();
    }

    //void findCity(const std::string& cityName) const;
private:
    void initCities(const std::string& filename);
    Coordinates parseCoordinates(const std::string& coordinateString);

    std::unordered_map<std::string, Coordinates> cities;
    friend std::ostream& operator<<(std::ostream& os, const CityContainer& container);
};


#endif //TASK6_DVIR_AVRAHAM_CITYCONTAINER_H
