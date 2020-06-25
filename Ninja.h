//
// Created by Tian on 2020/6/24.
//

#ifndef WOW_NINJA_H
#define WOW_NINJA_H
#include "Warrior.h"

class Ninja : public Warrior{
public:
    Ninja(int id_, PLAYER camp_, WARRIOR type_, int elements_, int force_) : Warrior(id_, camp_, type_, elements_, force_) {}
};


#endif //WOW_NINJA_H
