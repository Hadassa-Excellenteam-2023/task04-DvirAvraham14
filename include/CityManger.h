//
// Created by Dvir Avraham on 14/05/2023.
//

#ifndef TASK6_DVIR_AVRAHAM_CITYMANGER_H
#define TASK6_DVIR_AVRAHAM_CITYMANGER_H
#include <iostream>
#include <string>
#include <algorithm>
#include "CityContainer.h"

const std::string FILENAME = "data.txt";

class CityManger {
    CityContainer citis;

public:
    explicit CityManger();
    void SearchCity(const std::string& keyword);
};


#endif //TASK6_DVIR_AVRAHAM_CITYCONTAINER_H
