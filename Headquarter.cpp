//
// Created by Tian on 2020/6/24.
//

#include "Headquarter.h"

std::string Headquarter::Born() {
    WARRIOR newone = ORDER[(warriorId - 1) % 5].second;
    if (elemNum >= ELEMENT[newone]) {
        elemNum -= ELEMENT[newone];
        Warrior *p;
        switch(newone){
            case (WARRIOR::WOLF) :
                p = new Wolf(warriorId, flag, newone, ELEMENT[newone], FORCE[newone]);
                break;
            case (WARRIOR::ICEMAN) :
                p = new Iceman(warriorId, flag, newone, ELEMENT[newone], FORCE[newone]);
                break;
            case (WARRIOR::NINJA) :
                p = new Ninja(warriorId, flag, newone, ELEMENT[newone], FORCE[newone]);
                break;
            case (WARRIOR::DRAGON) :
                p = new Dragon(warriorId, flag, newone, ELEMENT[newone], FORCE[newone]);
                break;
            case (WARRIOR::LION) :
                p = new Lion(warriorId, flag, newone, ELEMENT[newone], FORCE[newone]);
                break;

        }
        warriorId++; // 下一个id增加
        warriorMap[flag] = p; // 出生
        return PLAYER_NAME[flag] + " " + WARRIOR_NAME[newone] + " " + std::to_string(warriorId - 1) + " born";
    }
    return "";
}

Headquarter::Headquarter(PLAYER player_, int elem_num_): AbstractCity(player_, elem_num_), warriorId(1), isOccupied(false)
{
    if (flag == PLAYER::RED)
        ORDER = std::vector<std::pair<std::string, WARRIOR> >{
                std::pair<std::string, WARRIOR>("iceman", WARRIOR::ICEMAN),
                std::pair<std::string, WARRIOR>("lion", WARRIOR::LION),
                std::pair<std::string, WARRIOR>("wolf", WARRIOR::WOLF),
                std::pair<std::string, WARRIOR>("ninja", WARRIOR::NINJA),
                std::pair<std::string, WARRIOR>("dragon", WARRIOR::DRAGON),
        };
    else if ( flag == PLAYER::BLUE )
        ORDER = std::vector< std::pair< std::string, WARRIOR > >{
                std::pair< std::string, WARRIOR > ("lion", WARRIOR::LION),
                std::pair< std::string, WARRIOR > ("dragon", WARRIOR::DRAGON),
                std::pair< std::string, WARRIOR > ("ninja", WARRIOR::NINJA),
                std::pair< std::string, WARRIOR > ("iceman", WARRIOR::ICEMAN),
                std::pair< std::string, WARRIOR > ("wolf", WARRIOR::WOLF),
        };
}
