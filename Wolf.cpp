//
// Created by Tian on 2020/6/24.
//

#include "Wolf.h"

void Wolf::AfterWin() {
    killTimes++;

    if (killTimes % 2 == 0) // 偶数次
    {
        elements *= 2;
        force *= 2;
    }
}
