//
// Created by Tian on 2020/6/24.
//

#include "Game.h"

void Game::Play(std::ofstream &fout, int caseNum) {
    fout << "Case:" << caseNum +1 << std::endl;
    std::cout  << "Case:" << caseNum +1 << std::endl;

    for (currentTime = 0; currentTime < timeLimit; currentTime += 10) {
        if (currentTime % 60 == 0) // 初始化英雄
        {
            std::string lineinfo = headlist[0]->Born();
            if (!lineinfo.empty())
            {std::cout << GetTimeInfo() << lineinfo << std::endl;
            fout << GetTimeInfo() << lineinfo << std::endl;}

            lineinfo = headlist[1]->Born();
            if (!lineinfo.empty())
            {std::cout << GetTimeInfo() << lineinfo << std::endl;
            fout << GetTimeInfo() << lineinfo << std::endl;}
        }

        else if (currentTime % 60 == 10) // 行军
        {

            if (!citylist.empty()) {
                // 首先完成红方的移动
                citylist.back()->Move(PLAYER::RED, *headlist[1]);

                for (int i = citylist.size() - 2; i >= 0; i--){
                    citylist[i]->Move(PLAYER::RED, *citylist[i + 1]);
                }

                headlist[0]->Move(PLAYER::RED, *citylist[0]);

                // 随后是蓝方
                citylist[0]->Move(PLAYER::BLUE, *headlist[0]);

                for (int i = 1; i < citylist.size(); i++){
                    citylist[i]->Move(PLAYER::BLUE, *citylist[i - 1]);
                }

                headlist[1]->Move(PLAYER::BLUE, *citylist.back());

                // 开始说明进军情况
                if (headlist[0]->GetWarrior(PLAYER::BLUE) != nullptr) // 红方大本营是否有人
                {
                    Warrior *winner = headlist[0]->GetWarrior(PLAYER::BLUE); // 有人则标明进军

                    std::cout << GetTimeInfo() << *winner << "reached red headquarter" << winner->GetInfo()
                              << std::endl;
                    fout << GetTimeInfo() << *winner << "reached red headquarter" << winner->GetInfo()
                         << std::endl;

                    if (headlist[0]->GetLastWinner() == PLAYER::BLUE) // 如果之前就已经有了人了说明胜利
                    {
                        std::cout << GetTimeInfo() << "red headquarter was taken" << std::endl;
                        fout << GetTimeInfo() << "red headquarter was taken" << std::endl;
                        headlist[0]->Occupied();
                    } else { // 第一个到达了大本营
                        headlist[0]->SetLastWinner(PLAYER::BLUE);
                    }
                }

                // 按照城市顺序描述所有进军情况
                for (int i = 0; i < citylist.size(); i++){
                    if (citylist[i]->GetWarrior(PLAYER::RED) != nullptr)
                    {
                        std::cout << GetTimeInfo() << *citylist[i]->GetWarrior(PLAYER::RED)
                                  << "marched to city " + std::to_string(i+1)
                                  << citylist[i]->GetWarrior(PLAYER::RED)->GetInfo() << std::endl;
                        fout << GetTimeInfo() << *citylist[i]->GetWarrior(PLAYER::RED)
                             << "marched to city " + std::to_string(i+1)
                             << citylist[i]->GetWarrior(PLAYER::RED)->GetInfo() << std::endl;
                    }

                    if (citylist[i]->GetWarrior(PLAYER::BLUE) != nullptr)
                    {
                        std::cout
                                << GetTimeInfo()
                                << *citylist[i]->GetWarrior(PLAYER::BLUE)
                                << "marched to city " + std::to_string(i+1);
                        std::cout << citylist[i]->GetWarrior(PLAYER::BLUE)->GetInfo() << std::endl;

                        fout
                                << GetTimeInfo()
                                << *citylist[i]->GetWarrior(PLAYER::BLUE)
                                << "marched to city " + std::to_string(i+1);
                        fout << citylist[i]->GetWarrior(PLAYER::BLUE)->GetInfo() << std::endl;
                    }
                }

                if (headlist[1]->GetWarrior(PLAYER::RED) != nullptr) // 蓝方大本营是否有人
                {
                    Warrior *winner = headlist[1]->GetWarrior(PLAYER::RED); // 有人则标明进军

                    std::cout << GetTimeInfo() << *winner << "reached blue headquarter" << winner->GetInfo()
                              << std::endl;
                    fout << GetTimeInfo() << *winner << "reached blue headquarter" << winner->GetInfo()
                         << std::endl;

                    if (headlist[1]->GetLastWinner() == PLAYER::RED) // 如果之前就已经有了人了说明胜利
                    {
                        std::cout << GetTimeInfo() << "blue headquarter was taken" << std::endl;
                        fout << GetTimeInfo() << "blue headquarter was taken" << std::endl;
                        headlist[1]->Occupied();
                    }
                    else { // 第一个到达了大本营
                        headlist[1]->SetLastWinner(PLAYER::RED);
                    }
                }


                if (headlist[0]->IsOccupied() || headlist[1]->IsOccupied()) // 如果有一个被占领了，就退出
                    return;

            }


        }

        else if (currentTime % 60 == 20) // 城市增加10生命元
        {
            for (int i = 0; i < citylist.size(); i++){
                citylist[i]->AddElem(10);
            }
        }

        else if (currentTime % 60 == 30) // 取走生命元
        {
            Warrior* blue, *red;
            for (int i = 0; i < citylist.size(); i++){
                blue = citylist[i]->GetWarrior(PLAYER::BLUE);
                red = citylist[i]->GetWarrior(PLAYER::RED);
                if (blue != nullptr && red == nullptr) // 如果只有蓝方没有红方
                {
                    // 蓝方取走
                    headlist[1]->AddElem(citylist[i]->GetElem());
                    std::cout << GetTimeInfo() << *blue << "earned " << citylist[i]->GetElem() << " elements for his headquarter" << std::endl;
                    fout << GetTimeInfo() << *blue << "earned " << citylist[i]->GetElem() << " elements for his headquarter" << std::endl;
                    citylist[i]->GiveElem();
                    continue;
                }
                if (red != nullptr && blue == nullptr) // 如果只有红方没有蓝方
                {
                    // 红方取走
                    headlist[0]->AddElem(citylist[i]->GetElem());
                    std::cout << GetTimeInfo() << *red << "earned " << citylist[i]->GetElem() << " elements for his headquarter" << std::endl;
                    fout << GetTimeInfo() << *red << "earned " << citylist[i]->GetElem() << " elements for his headquarter" << std::endl;
                    citylist[i]->GiveElem();
                    continue;
                }
            }
        }

        else if (currentTime % 60 == 40) // 战斗
        {
            Warrior * attacker, *defender;
            std::vector< std::pair< int, char > > red;  //红色阵营胜利信息
            std::vector< std::pair< int, char > > blue; //蓝方胜利信息
            for (int i = 0; i < citylist.size(); i++) // 第一次循环查找需要奖励的城市
            {
                if (citylist[i]->GetWarrior(PLAYER::BLUE) != nullptr && citylist[i]->GetWarrior(PLAYER::RED) != nullptr) // 两方都有人
                {
                    if (citylist[i]->GetFlag() != PLAYER::EMPTY){ // 已经被插旗
                        attacker = citylist[i]->GetWarrior(citylist[i]->GetFlag()); // 记录攻击者
                        defender = citylist[i]->GetWarrior(PLAYER(-1 * (int) citylist[i]->GetFlag())); // 记录防御者
                    }
                    else{
                        if ((i + 1) % 2) // 奇数
                        {
                            attacker = citylist[i]->GetWarrior(PLAYER::BLUE);
                            defender = citylist[i]->GetWarrior(PLAYER::RED);
                        } else {
                            attacker = citylist[i]->GetWarrior(PLAYER::RED);
                            defender = citylist[i]->GetWarrior(PLAYER::BLUE);
                        }
                    }

                    if (attacker->GetForce() >= defender->GetElem()) // attacker胜利
                    {
                        if (attacker->GetCamp() == PLAYER::RED){
                            red.emplace_back(i, 'A');
                        } else{
                            blue.emplace_back(i, 'A');
                        }
                    }
                    else{
                        if (defender->GetType() == WARRIOR::NINJA) continue; // 如果是ninja就直接跳过
                        if (defender->GetForce() / 2 >= attacker->GetElem()) // 如果反击致死
                        {
                            if (attacker->GetCamp() == PLAYER::RED)
                                blue.emplace_back(i, 'B');
                            else
                                red.emplace_back(i, 'B');
                        }
                        else {
                            NULL; // 双方都没死人，仅仅发生战斗
                        }

                    }
                }
            }

            // 查看奖励是否可以给所有人
            if (red.size() * 8 > headlist[0]->GetElem())
                red = std::vector< std::pair< int, char > > (red.end() - headlist[0]->GetElem() / 8, red.end());
            if (blue.size() * 8 > headlist[1]->GetElem())
                blue = std::vector< std::pair< int, char > > (blue.begin(), blue.begin() + headlist[1]->GetElem() / 8);

            for (int i = 0; i < citylist.size(); i++) // 第二次循环查看输出结果
            {
                PLAYER turnwinner = PLAYER::EMPTY; // 假设本轮没有赢家
                // 至少得有俩人
                if(citylist[i]->GetWarrior(PLAYER::BLUE) != nullptr && citylist[i]->GetWarrior(PLAYER::RED) != nullptr) {
                    if (citylist[i]->GetFlag() != PLAYER::EMPTY) // 如果城市已经被插旗
                    {
                        attacker = citylist[i]->GetWarrior(citylist[i]->GetFlag()); // 记录攻击者
                        defender = citylist[i]->GetWarrior(PLAYER(-1 * (int) citylist[i]->GetFlag())); // 记录防御者
                    } else {
                        if ((i + 1) % 2) // 奇数
                        {
                            attacker = citylist[i]->GetWarrior(PLAYER::BLUE);
                            defender = citylist[i]->GetWarrior(PLAYER::RED);
                        } else {
                            attacker = citylist[i]->GetWarrior(PLAYER::RED);
                            defender = citylist[i]->GetWarrior(PLAYER::BLUE);
                        }
                    }

                    attacker->Attack(defender);
                    std::cout << GetTimeInfo() << *attacker << "attacked " << *defender << "in city " << i+1 << attacker->GetInfo() << std::endl;
                    fout << GetTimeInfo() << *attacker << "attacked " << *defender << "in city " << i+1 << attacker->GetInfo() << std::endl;

                    if (defender->IsDead()){ // A类型
                        turnwinner = attacker->GetCamp(); // 本回合攻者是赢家
                        std::cout << GetTimeInfo() << *defender << "was killed in city " << i+1 << std::endl;
                        fout << GetTimeInfo() << *defender << "was killed in city " << i+1 << std::endl;

                        defender->AfterDead(attacker); // lion死了之后需要将生命值转移给对方
                        (citylist[i])->warriorMap[defender->GetCamp()] = nullptr;
                        delete defender;

                        if (attacker->GetCamp() == PLAYER::RED){
                            int index = 0;
                            for (index = 0; index < red.size(); index++){
                                if (red[index].first == i && red[index].second == 'A')
                                {
                                    headlist[0]->AddElem(-8);
                                    attacker->AddElem(8);
                                }
                            }
                        }
                        else if (attacker->GetCamp() == PLAYER::BLUE){
                            int index = 0;
                            for (index = 0; index < blue.size(); index++){
                                if (blue[index].first == i && blue[index].second == 'A'){
                                    headlist[1]->AddElem(-8);
                                    attacker->AddElem(8);
                                }
                            }
                        }
                        if (attacker->GetType() == WARRIOR::DRAGON)
                        {std::cout << GetTimeInfo() << *attacker << "yelled in city " << i+1 << std::endl;
                        fout << GetTimeInfo() << *attacker << "yelled in city " << i+1 << std::endl;}

                        std::cout << GetTimeInfo() << *attacker << "earned " << citylist[i]->GetElem() << " elements for his headquarter" << std::endl;
                        fout << GetTimeInfo() << *attacker << "earned " << citylist[i]->GetElem() << " elements for his headquarter" << std::endl;
                        headlist[(attacker->GetCamp() == PLAYER::RED) ? 0 : 1]->AddElem(citylist[i]->GetElem()); // 将city i的宝石全部送回指挥部
                        citylist[i]->GiveElem(); // city i 清除宝石

                    }
                    else{
                        if (defender->GetType() == WARRIOR::NINJA) goto a;
                        defender->FightBack(attacker);
                        std::cout << GetTimeInfo() << *defender << "fought back against " << *attacker << "in city " << i +1 << std::endl;
                        fout << GetTimeInfo() << *defender << "fought back against " << *attacker << "in city " << i +1 << std::endl;
                        if(attacker->IsDead()){ // 如果attacker死了就要说明和奖励
                            turnwinner = defender->GetCamp(); // 本回合defender是赢家
                            std::cout << GetTimeInfo() << *attacker << "was killed in city " << i+1 << std::endl;
                            fout << GetTimeInfo() << *attacker << "was killed in city " << i+1 << std::endl;
                            citylist[i]->warriorMap[attacker->GetCamp()] = nullptr;
                            delete attacker;
                            if (defender->GetCamp() == PLAYER::RED){
                                int index =  0;
                                for (index = 0; index < red.size(); index++){
                                    if (red[index].first == i && red[index].second == 'B'){
                                        headlist[0]->AddElem(-8);
                                        defender->AddElem(8);
                                    }
                                }
                            }
                            else if (defender->GetCamp() == PLAYER::BLUE){
                                int index = 0;
                                for (index = 0; index < blue.size(); index++){
                                    if (blue[index].first == i && blue[index].second == 'B'){
                                        headlist[1]->AddElem(-8);
                                        defender->AddElem(8);
                                    }
                                }
                            }

                            std::cout << GetTimeInfo() << *defender << "earned " << citylist[i]->GetElem() << " elements for his headquarter" << std::endl;
                            fout << GetTimeInfo() << *defender << "earned " << citylist[i]->GetElem() << " elements for his headquarter" << std::endl;
                            headlist[(defender->GetCamp() == PLAYER::RED) ? 0 : 1]->AddElem(citylist[i]->GetElem()); // 将city i的宝石全部送回指挥部
                            citylist[i]->GiveElem(); // city i 清除宝石
                        }
                        a:

                        if (!attacker->IsDead() && attacker->GetType() == WARRIOR::DRAGON)
                        {std::cout << GetTimeInfo() << *attacker << "yelled in city " << i+1 << std::endl;
                        fout << GetTimeInfo() << *attacker << "yelled in city " << i+1 << std::endl;}
                        NULL;
                    }
                    if (turnwinner == citylist[i]->GetLastWinner() && turnwinner != PLAYER::EMPTY) // 如果本轮有赢家，且和之前的赢家不一样
                    {
                        if (citylist[i]->GetFlag() != turnwinner)
                        {
                            citylist[i]->SetFlag(); // 插旗
                            std::cout << GetTimeInfo() << PLAYER_NAME[turnwinner] << " flag raised in city " << i+1 << std::endl;
                            fout << GetTimeInfo() << PLAYER_NAME[turnwinner] << " flag raised in city " << i+1 << std::endl;
                        }
                    }
                    //citylist[i]->SetLastWinner(turnwinner);
                }
            }
        }

        else if (currentTime % 60 == 50) // 报告生命值
        {
            std::cout << GetTimeInfo() << headlist[0]->GetElem() << " elements in red headquarter" << std::endl;
            fout << GetTimeInfo() << headlist[0]->GetElem() << " elements in red headquarter" << std::endl;
            std::cout << GetTimeInfo() << headlist[1]->GetElem() << " elements in blue headquarter" << std::endl;
            fout << GetTimeInfo() << headlist[1]->GetElem() << " elements in blue headquarter" << std::endl;
        }
    }
}

Game::Game(std::string info, std::string element, std::string force) {
    /*******************   读取数据   ***********************/
    std::regex infoPattern(R"((\d+) (\d+) (\d+))");
    std::smatch results;
    if (std::regex_match(info, results, infoPattern)) {
        startElem = std::atoi(results[1].str().c_str());
        cityNum = std::atoi(results[2].str().c_str());
        timeLimit = std::atoi(results[3].str().c_str());
    }
    std::regex elementPattern("(\\d+) (\\d+) (\\d+) (\\d+) (\\d+)");
    if (std::regex_match(element, results, elementPattern)) {
        ELEMENT[WARRIOR::DRAGON] = std::atoi(results[1].str().c_str());
        ELEMENT[WARRIOR::NINJA] = std::atoi(results[2].str().c_str());
        ELEMENT[WARRIOR::ICEMAN] = std::atoi(results[3].str().c_str());
        ELEMENT[WARRIOR::LION] = std::atoi(results[4].str().c_str());
        ELEMENT[WARRIOR::WOLF] = std::atoi(results[5].str().c_str());
    }

    if (std::regex_match(force, results, elementPattern)) {
        FORCE[WARRIOR::DRAGON] = std::atoi(results[1].str().c_str());
        FORCE[WARRIOR::NINJA] = std::atoi(results[2].str().c_str());
        FORCE[WARRIOR::ICEMAN] = std::atoi(results[3].str().c_str());
        FORCE[WARRIOR::LION] = std::atoi(results[4].str().c_str());
        FORCE[WARRIOR::WOLF] = std::atoi(results[5].str().c_str());
    }

    /*******************   初始化城市、大本营   ***********************/
    headlist.push_back(new Headquarter(PLAYER::RED, startElem));
    headlist.push_back(new Headquarter(PLAYER::BLUE, startElem));

    for (int i = 0; i < cityNum; i++) {
        citylist.push_back(new City(i + 1));
    }
}

std::string Game::GetTimeInfo() {
    std::ostringstream ss;
    ss << std::setw(3) << std::setfill('0') << currentTime / 60;
    ss << ":";
    ss << std::setw(2) << std::setfill('0') << currentTime % 60 << " ";
    return ss.str();
}

Game::~Game() {
    for (int i = 0; i < headlist.size(); i++){
        if (headlist[i]) delete headlist[i];
    }
    for (int i  =0; i < citylist.size(); i++){
        if (citylist[i]) delete citylist[i];
    }
}