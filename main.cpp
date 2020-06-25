#include "Game.h"

int main() {
    std::ifstream fin("input.txt");
    std::ofstream fout("output.txt");
    std::string gameTurns, info, element, force;
    std::getline(fin, gameTurns); // 开始循环启动游戏
    
    for (int i = 0; i < std::atoi(gameTurns.c_str()); i++){
        std::getline(fin, info);
        std::getline(fin, element);
        std::getline(fin, force);
        Game NewGame(info, element, force);
        NewGame.Play(fout, i);
    }

    return 0;
}