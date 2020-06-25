//
// Created by Tian on 2020/6/24.
//

#ifndef WOW_HEADQUARTER_H
#define WOW_HEADQUARTER_H
#include "AbstractCity.h"

class Headquarter : public AbstractCity{
protected:
    int warriorId;
    bool isOccupied;

    std::vector< std::pair< std::string, WARRIOR > > ORDER; // 生成顺序

public:
    Headquarter(PLAYER player_, int elem_num_ ); // 初始化，明确精灵生成顺序

    std::string Born();   // 生成新的

    std::string GetName() override { return PLAYER_NAME[flag] + " headquarter";} // 返回名称

    void Occupied() { isOccupied = true;} // 被占领
    bool IsOccupied() const { return isOccupied; } // 判断是否被占领
};

#endif //WOW_HEADQUARTER_H
