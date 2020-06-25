//
// Created by Tian on 2020/6/24.
//

#include "Lion.h"

void Lion::AfterDead(Warrior *another) {
    another->AddElem(another->GetForce() + elements);
}
