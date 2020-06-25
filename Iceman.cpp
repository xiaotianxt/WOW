//
// Created by Tian on 2020/6/24.
//

#include "Iceman.h"

void Iceman::AfterMove() {
    walked++;
    if (walked == 3) //第三步完成之后
    {
        elements -= 9;
        force += 20;
        if (elements <= 0)
            elements = 1;
        walked = 0;
    }
}
