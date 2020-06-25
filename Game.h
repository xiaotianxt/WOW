//
// Created by Tian on 2020/6/24.
//

#ifndef WOW_GAME_H
#define WOW_GAME_H

#include "util_value.h"
#include "Headquarter.h"
#include "City.h"

class Game {
protected:
    int startElem; // M
    int cityNum;  // N
    int timeLimit; // T
    int currentTime;
    std::vector< Headquarter * > headlist;
    std::vector< City* > citylist;
public:
    Game() = default;
    Game(std::string info, std::string element, std::string force); // 给定信息初始化
    ~Game();

    std::string GetTimeInfo(); // 格式化时间输出
    void Play(std::ofstream &fout, int caseNum);
};

#endif //WOW_GAME_H
