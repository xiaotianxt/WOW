//
// Created by Tian on 2020/6/23.
//

#include "AbstractCity.h"

AbstractCity::AbstractCity(PLAYER player_, int elem_num_)  : flag(player_), elemNum(elem_num_), lastWinner(PLAYER::EMPTY) {
    warriorMap[PLAYER::BLUE] = nullptr;
    warriorMap[PLAYER::RED] = nullptr;
    lastWinner = PLAYER::EMPTY;
}

void AbstractCity::Move(PLAYER who, AbstractCity &dest) {
    dest.warriorMap[who] = warriorMap[who];
    if (dest.warriorMap[who] != nullptr) dest.warriorMap[who]->AfterMove();
    warriorMap[who] = nullptr;
    // 直接将this中属于who的PLAYER移动到who中
}

Warrior* AbstractCity::GetWarrior(PLAYER who) {
    return warriorMap[who];
}

AbstractCity::~AbstractCity() {
    if (warriorMap[PLAYER::BLUE])
        delete warriorMap[PLAYER::BLUE];
    if (warriorMap[PLAYER::RED])
        delete warriorMap[PLAYER::RED];
}