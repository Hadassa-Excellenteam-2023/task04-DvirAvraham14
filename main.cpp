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
        std::cout << "Enter city name: ";
        std::getline(std::cin, cityName);
        try{
            cityManger.SearchCity(cityName);
        } catch (const std::exception& e) {
            std::cout << e.what() << std::endl;
        }
    }
    return 0;
}
