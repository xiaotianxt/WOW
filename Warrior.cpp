//
// Created by Tian on 2020/6/23.
//

#include "Warrior.h"

Warrior::Warrior(int id_, PLAYER camp_, WARRIOR type_, int elements_, int force_) : id(id_), camp(camp_), type(type_), elements(elements_), force(force_){


}

std::ostream &operator<<(std::ostream &os, const Warrior &wr) {
    os << PLAYER_NAME[wr.camp]
        << " "
        << WARRIOR_NAME[wr.type]
        << " "
        << wr.id
        << " ";
    return os;
}

