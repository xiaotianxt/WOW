//
// Created by Tian on 2020/6/24.
//

#ifndef WOW_CITY_H
#define WOW_CITY_H

#include "AbstractCity.h"
#include "Warrior.h"

class City : public AbstractCity{
protected:
    int id;
public:
    City() = default;
    City(int id_) : AbstractCity(PLAYER::EMPTY, 0), id(id_) {}

    std::string GetName() override { return "city " + std::to_string(id) ;} // 获得城市名称
};


#endif //WOW_CITY_H
