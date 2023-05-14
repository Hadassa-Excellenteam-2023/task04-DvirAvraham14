//
// Created by Dvir Avraham on 14/05/2023.
//

#include "../include/CityManger.h"


CityManger::CityManger() : citis(FILENAME)
{
    std::cout << "CityManger constructor" << std::endl << citis << std::endl;
}

void CityManger::SearchCity(const std::string& keyword) {
    for(auto& city : citis)
    {
        if(city.first.find(keyword) != std::string::npos)
        {
            std::cout << "Found city: " << city.first << std::endl;
            return;
        }
    }
    throw std::runtime_error("City not found");
}
