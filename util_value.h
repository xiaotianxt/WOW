//
// Created by Tian on 2020/6/23.
//

#ifndef WOW_UTIL_VALUE_H
#define WOW_UTIL_VALUE_H

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <fstream>
#include <regex>
#include <sstream>

// 用于标记精灵、城市归属
enum class PLAYER{
    BLUE = 1,
    RED = -1,
    EMPTY = 0
};

// 用于标记武士类型
enum class WARRIOR{
    ICEMAN,
    LION,
    WOLF,
    NINJA,
    DRAGON
};

// 用于标记城市类型（大本营or城市
enum class CITYTYPE{
    HEADQUATER,
    CITY
};

extern std::map < WARRIOR, int > ELEMENT;
extern std::map < WARRIOR, int > FORCE;
extern std::map < WARRIOR, std::string > WARRIOR_NAME;
extern std::map < PLAYER, std::string > PLAYER_NAME;

#endif //WOW_UTIL_VALUE_H
