//
// Created by Tian on 2020/6/23.
//

#ifndef WOW_ABSTRACTCITY_H
#define WOW_ABSTRACTCITY_H

#include "util_value.h"
#include "Warrior.h"
#include "Dragon.h"
#include "Iceman.h"
#include "Lion.h"
#include "Ninja.h"
#include "Wolf.h"

class AbstractCity {
protected:
    PLAYER flag; // 用于记录归属地
    int elemNum; // 用于记录生命值（城市产生的，或是大本营的
    PLAYER lastWinner; // 用于记录上一个在此地获胜的玩家(1. 普通城市插旗 2. 大本营满两人获胜

public:
    std::map < PLAYER, Warrior* > warriorMap ;
    AbstractCity( PLAYER player_, int elem_num_ );
    ~AbstractCity();

    virtual void Move(PLAYER who, AbstractCity &dest); // 用于移动

    virtual std::string GetName() { return std::string(); } // 返回城市名称
    PLAYER GetFlag() { return flag; }
    PLAYER GetLastWinner() { return lastWinner; }
    int GetElem() const { return elemNum; }

    void SetLastWinner(PLAYER player) {lastWinner = player;}
    void SetFlag() { flag = lastWinner; }
    void AddElem(int add) {elemNum += add;} // 20分 生成新的elem
    void GiveElem() {elemNum = 0; }  // 30分 将elem给予武士并提交给司令部

    virtual Warrior* GetWarrior(PLAYER who); // 获得who方的武士
};


#endif //WOW_ABSTRACTCITY_H
