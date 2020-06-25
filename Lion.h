//
// Created by Tian on 2020/6/24.
//

#ifndef WOW_LION_H
#define WOW_LION_H
#include "Warrior.h"

class Lion : public Warrior{
public:
    void AfterDead(Warrior *another) override ;
    Lion(int id_, PLAYER camp_, WARRIOR type_, int elements_, int force_) : Warrior(id_, camp_, type_, elements_, force_) {}
};


#endif //WOW_LION_H
