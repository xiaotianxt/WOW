//
// Created by Tian on 2020/6/24.
//

#ifndef WOW_ICEMAN_H
#define WOW_ICEMAN_H
#include "Warrior.h"

class Iceman : public Warrior{
protected:
    int walked;
public:
    Iceman(int id_, PLAYER camp_, WARRIOR type_, int elements_, int force_) : Warrior(id_, camp_, type_, elements_, force_) {walked = 0;}
    void AfterMove();
};


#endif //WOW_ICEMAN_H
