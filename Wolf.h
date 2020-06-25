//
// Created by Tian on 2020/6/24.
//

#ifndef WOW_WOLF_H
#define WOW_WOLF_H
#include "Warrior.h"

class Wolf : public Warrior{
protected:
    int killTimes;
public:
    Wolf(int id_, PLAYER camp_, WARRIOR type_, int elements_, int force_) : Warrior(id_, camp_, type_, elements_, force_), killTimes(0) {}

    void AfterWin();

};


#endif //WOW_WOLF_H
