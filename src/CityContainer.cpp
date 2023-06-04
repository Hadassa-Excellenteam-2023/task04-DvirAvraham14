//
// Created by Dvir Avraham on 14/05/2023.
//

#include "../include/CityContainer.h"

/*
 * Constructor
 * @param filename - the name of the file to read the cities from
 * @throw runtime_error if the file cannot be opened
 */
CityContainer::CityContainer(const std::string &filename) {
    initCities(filename);
}

/*
 * Initialize the cities container
 * @param filename - the name of the file to read the cities from
 * @throw runtime_error if the file cannot be opened

 */
void CityContainer::initCities(const std::string &filename) {
    // open the file and check if it's open
    std::ifstream file(filename);
    if (file.is_open()) {
        std::string line;
        while (std::getline(file, line)) {
            std::string name = line;
            std::getline(file, line); // Read the second line from the file
            try {
                Coordinates coordinates = parseCoordinates(line);
                cities.insert({name,coordinates});
                x_axis.insert({coordinates.first, name});
                y_axis.insert({coordinates.second, name});
            } catch (const std::exception &e) {
                // Catch and handle any exceptions that occur during parsing
                std::cout << "Error parsing coordinates: " << e.what() << std::endl;
            }
        }
        file.close();
    } else {
        throw std::runtime_error("Error opening file: " + filename);
    }
}

/*
 * Parse the coordinates from a string
 * @param coordinateString - the string to parse the coordinates from
 * @return a pair of the x and y coordinates
 */
CityContainer::Coordinates CityContainer::parseCoordinates(const std::string& coordinateString) {
    std::stringstream ss(coordinateString);
    double xStr, yStr;
    char dash;
    // Extract x and y as strings
    ss >> std::ws >> xStr >> dash >> std::ws >> yStr;
    return std::make_pair(xStr, yStr);
}

std::ostream& operator<<(std::ostream& os, const CityContainer& container) {
    os << std::fixed << std::setprecision(6);
    os << "Total number of cities: " << container.cities.size() << std::endl;
    for (const auto &city : container.cities) {
        os << city.first << std::endl << city.second.first << " " << city.second.second << std::endl;
    }
    return os;
}