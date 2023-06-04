//
// Created by Dvir Avraham on 14/05/2023.
//

#ifndef TASK6_DVIR_AVRAHAM_CITYCONTAINER_H
#define TASK6_DVIR_AVRAHAM_CITYCONTAINER_H
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <map>
#include <functional> // for std::greater
#include <algorithm>
#include <iomanip>
#include <iterator>

class CityContainer {
public:
    using Coordinates = std::pair<long double, long double>; // for readability purposes only
    //using CityMap = std::map<Coordinates, std::string, std::greater<Coordinates>>; // sort by coordinates
    using CityMap = std::map<std::string, Coordinates>; // sort by coordinates
    using CityAndAxis = std::map<double, std::string, std::less_equal<double>>;

    // Iterator typedefs
    using iterator = CityMap::iterator;
    using const_iterator = CityMap::const_iterator;

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

    CityMap getCities() const {
        return cities;
    }

    const CityAndAxis& getXAxis() const {
        return x_axis;
    }

    const CityAndAxis& getYAxis() const {
        return y_axis;
    }

    //void findCity(const std::string& cityName) const;
private:
    void initCities(const std::string& filename);
    Coordinates parseCoordinates(const std::string& coordinateString);

    CityMap cities;
    CityAndAxis x_axis;
    CityAndAxis y_axis;
    friend std::ostream& operator<<(std::ostream& os, const CityContainer& container);
};


#endif //TASK6_DVIR_AVRAHAM_CITYCONTAINER_H
