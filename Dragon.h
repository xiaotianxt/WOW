//
// Created by Tian on 2020/6/24.
//

#ifndef WOW_DRAGON_H
#define WOW_DRAGON_H
#include "Warrior.h"

class Dragon : public Warrior{
public:
    Dragon(int id_, PLAYER camp_, WARRIOR type_, int elements_, int force_) : Warrior(id_, camp_, type_, elements_, force_) {}
};


#endif //WOW_DRAGON_H
