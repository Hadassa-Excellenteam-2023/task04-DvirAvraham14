// CityManger.cpp
#include "../include/CityManger.h"

/*
 * Constructor
 * Read the data from the file and insert it to the cities container
 * @param filename - the name of the file to read from
 * @throw runtime_error if the file cannot be opened
 */
CityManger::CityManger() : cities(FILENAME) {
    std::cout << "CityManger constructor" << std::endl << cities << std::endl;
}


/*
 * Search for a city in the cities container
 * @param keyword - the name of the city to search for
 * @return the coordinates of the city
 */
Cord CityManger::SearchCity(const std::string& keyword) {
    auto it = cities.getCities().find(keyword);

    if (it != cities.getCities().end()) {
        return it->second;
    }

    throw std::runtime_error("City not found");
}


/*
 * Get all the cities that are inside the square
 * @param idx - the center of the square
 * @param radius - the radius of the square
 * @return a vector of all the cities that are inside the square
 */
void CityManger::GetNearestCities(const Cord& idx, double radius, int norm) const {
    Cord BoundX = {idx.first - radius, idx.first + radius}; // left, right bounds for x
    Cord BoundY = {idx.second - radius, idx.second + radius}; // bottom, top bounds for y

    std::vector<std::string> citiesInsideSquare = getCitiesInRange(idx, radius);
    citiesInsideSquare.erase(std::remove_if(citiesInsideSquare.begin(), citiesInsideSquare.end(),
                                            [&](const std::string& city) {
                                                return calculateDistance(idx, cities.getCities().find(city)->second,
                                                                         norm) > radius;
                                            }), citiesInsideSquare.end());

    std::cout << citiesInsideSquare.size() << " cities found inside the circle" << std::endl;
    size_t totalNorthCities = countCitiesNorthOfCenter(citiesInsideSquare, idx);
    std::cout << totalNorthCities << " cities are located north to the center" << std::endl;
    printCitiesInsideSquare(citiesInsideSquare);
}

/*
 * calculate the distance between two cities
 * @param c1 - the first city coordinates
 * @param c2 - the second city coordinates
 * @param norm - the norm to calculate the distance by
 * @return the distance between the two cities
 */
double CityManger::calculateDistance(Cord c1, Cord c2, int norm) const {
    if (norm == 0) {
        return sqrt(pow(c1.first - c2.first, 2) + pow(c1.second - c2.second, 2));
    } else if (norm == 1) {
        return std::max(std::abs(c1.first - c2.first), std::abs(c1.second - c2.second));
    } else if (norm == 2) {
        return std::abs(c1.first - c2.first) + std::abs(c1.second - c2.second);
    }
    return 0.0;
}

/*
 * Get all the cities that are inside the range
 * @param idx - the center of the range
 * @param radius - the radius of the range
 * @return a vector of all the cities that are inside the range
 */
std::vector<std::string> CityManger::getCitiesInRange(const Cord& idx, double radius) const {
    Cord BoundX = {idx.first - radius, idx.first + radius};
    Cord BoundY = {idx.second - radius, idx.second + radius};

    auto xLeftBound = cities.getXAxis().lower_bound(BoundX.first);
    auto xRightBound = cities.getXAxis().upper_bound(BoundX.second);
    auto yBottomBound = cities.getYAxis().lower_bound(BoundY.first);
    auto yTopBound = cities.getYAxis().upper_bound(BoundY.second);

    std::vector<std::string> xNearestCities;
    std::vector<std::string> yNearestCities;

    std::transform(xLeftBound, xRightBound, std::back_inserter(xNearestCities),
                   GetValue());

    std::transform(yBottomBound, yTopBound, std::back_inserter(yNearestCities),
                   GetValue());

    std::sort(xNearestCities.begin(), xNearestCities.end());
    std::sort(yNearestCities.begin(), yNearestCities.end());

    std::vector<std::string> citiesInsideSquare;
    std::set_intersection(xNearestCities.begin(), xNearestCities.end(),
                          yNearestCities.begin(), yNearestCities.end(),
                          std::back_inserter(citiesInsideSquare));

    return citiesInsideSquare;
}


/*
 * Count the number of cities that are north to the center
 * @param citiesInsideSquare - a vector of all the cities that are inside the square
 * @param idx - the center of the square
 * @return the number of cities that are north to the center
 */
size_t CityManger::countCitiesNorthOfCenter(const std::vector<std::string>& citiesInsideSquare, const Cord& idx) const {
    return std::count_if(citiesInsideSquare.begin(), citiesInsideSquare.end(),
                         [&](const std::string& city) {
                             return cities.getCities().find(city)->second.first < idx.first;
                         });
}

/*
 * Print all the cities that are inside the square
 * @param citiesInsideSquare - a vector of all the cities that are inside the square
 */
void CityManger::printCitiesInsideSquare(const std::vector<std::string>& citiesInsideSquare) const {
    std::cout << "Cities inside the square: " << std::endl;
    for (const auto& city : citiesInsideSquare) {
        std::cout << city << std::endl;
    }
}
