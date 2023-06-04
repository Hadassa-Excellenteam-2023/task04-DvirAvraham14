//#include <iostream>
//#include <fstream>
//#include <sstream>
//#include <string>
//#include <vector>
//#include <cmath>
//#include <algorithm>

#include <iostream>
#include "include/CityManger.h"

int main() {
    CityManger cityManger;
    while (true) {
        std::string cityName;
        int norm;
        double radius;
        std::cout << "Enter city name: ";
        std::getline(std::cin, cityName);
        try {
            auto idx = cityManger.SearchCity(cityName);
            std::cout << "Please enter the wanted radius: ";
            std::cin >> radius;
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout
                    << "Please enter the wanted norm (0 – L2, \E"
                       "uclidean distance, 1 – Linf, Chebyshev distance,\ "
                       "2 – L1, Manhattan distance):";
            std::cin >> norm;
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            cityManger.GetNearestCities(idx, radius, norm);
        } catch (const std::exception &e) {
            std::cout << e.what() << std::endl;
        }
    }
    return 0;
}
