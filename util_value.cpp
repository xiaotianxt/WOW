//
// Created by Tian on 2020/6/24.
//
#include "util_value.h"

// 用于记录不同精灵的生命值和攻击力
std::map < WARRIOR, int > ELEMENT = {
        { WARRIOR::DRAGON, 0},
        { WARRIOR::NINJA, 0},
        { WARRIOR::ICEMAN, 0},
        { WARRIOR::LION, 0},
        { WARRIOR::WOLF, 0},
};

std::map < WARRIOR, int > FORCE{
        { WARRIOR::DRAGON, 0},
        { WARRIOR::NINJA, 0},
        { WARRIOR::ICEMAN, 0},
        { WARRIOR::LION, 0},
        { WARRIOR::WOLF, 0},
};

std::map < WARRIOR, std::string > WARRIOR_NAME{
        { WARRIOR::DRAGON, "dragon"},
        { WARRIOR::NINJA, "ninja"},
        { WARRIOR::ICEMAN, "iceman"},
        { WARRIOR::LION, "lion"},
        { WARRIOR::WOLF, "wolf"},
};

std::map < PLAYER, std::string > PLAYER_NAME{
        {PLAYER::RED, "red"},
        {PLAYER::BLUE, "blue"},
};