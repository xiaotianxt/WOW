程设作业10 - 魔兽世界
===========

结构说明
-----------
1. `AbstractCity.cpp, AbstractCity.h` 城市抽象类
   1. `City.cpp, City.h` 普通城市
   2. `Headquarter.cpp Headquarter.h` 司令部
2. `Warrior.cpp Warrior.h` 精灵类
   1. `Dragon.cpp Dragon.h`
   2. `Iceman.cpp Iceman.h`
   3. `Lion.cpp Lion.h`
   4. `Ninja.cpp Ninja.h`
   5. `Wolf.cpp Wolf.h`
3. `Game.cpp Game.h` 游戏实现
4. `util_value.cpp util_value.h` 全局变量，头文件等
5. `main.cpp`

程序优点
------------
1. 通过虚函数和指针调用，简化了精灵类的实现
2. 使用stringstream实现数据读入和解读
3. 几乎所有数据使用指针传递，既方便了虚函数实现，又降低了运算成本