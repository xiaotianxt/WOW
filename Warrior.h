//
// Created by Tian on 2020/6/23.
//

#ifndef WOW_WARRIOR_H
#define WOW_WARRIOR_H
#include "util_value.h"

class Warrior {
protected:
    unsigned id; // 武士id
    PLAYER camp; // 玩家类别
    WARRIOR type; // 武士类别
    bool isDead = false;
    int elements; // 生命元
    int location;
    int force; // 攻击力
public:
    Warrior() = default;
    Warrior(int id_, PLAYER camp_, WARRIOR type_, int elements_, int force_);
    ~Warrior() = default;

    virtual void Attack( Warrior * target ) {
        target->elements = target->elements - force;
        if (target->elements <= 0)
            target->isDead = !target->isDead;
    }
    virtual void FightBack( Warrior * target ) {
        target->elements = target->elements - force/2;
        if (target->elements <= 0)
            target->isDead = !target->isDead;
    } // 反击

    void AddElem(int add) { elements += add; } // 增加生命值

    PLAYER GetCamp() {return camp;} // 用于获得类别
    int GetElem() const { return elements; }
    int GetForce() const { return force; }
    std::string GetInfo() { return " with " + std::to_string(elements) + " elements and force " + std::to_string(force); }
    WARRIOR GetType() { return type; }
    bool IsDead() const { return isDead; } // 是否死亡

    virtual void AfterMove() {} // 前进之后的动作
    virtual void AfterWin() {} // 战胜之后的动作
    virtual void AfterDead(Warrior * another) {} // 死后干什么

    friend std::ostream& operator<< (std::ostream& os, const Warrior& wr); // 重载输出
};

#endif //WOW_WARRIOR_H
