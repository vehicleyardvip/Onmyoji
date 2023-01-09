#include <iostream>
#include "shikigami.h"

Shikigami::Shikigami(const std::string name, unsigned short int rare = 0) // 给定式神名，构造一个式神
{
    name_ = name;
    // card default property (unified use N card's)
    attack_ = 100;
    health_ = 900;
    defend_ = 70;
    speed_ = 100;
    critical_ = 0;
    Shikigami::ConvRarity(rare);
};

void Shikigami::SetCardGrade(unsigned short int level)
{
    (level < 1 || level > 40) ?: (level_ = level); // 三目运算符只能缺省中间操作数
    // 等级每到达20/25/30/35可提升1星级
    level_ - 21 < 0 ? star_ = 2 : star_ = (level_ - 21) / 5 + 3; // 当等级超过可升星阈值后，才能提升星级

    // 升级，并且随着等级的提升升级星级
    /* 只适用于初始星级为2、一步步升级的情况
    for (int diff = level_ - 21, i = diff / 5; diff >= 0 && i >= 0; i--) // "diff>=0"用来防止"-5<diff<0"导致"i=0"的情况
    {
        star_++;
    }
    */
};

void Shikigami::SetProperity(double attack, double health, double defend, double speed, double cirtical)
{
    if (attack >= 70)
    {
    }
};

void Shikigami::PrintInfo()
{
    std::cout << "shikigami name: " << name_ << std::endl;
    Shikigami::ShowRarity(); // 这里不加类作用域也可以，因为两个函数在同一文件中
    Shikigami::ShowStar();
    std::cout << "level: " << level_ << std::endl;
}

std::string Shikigami::Life()
{
    std::string life;
    (health_ <= 0) ? life = "dead" : life = "alive";
    return life;
};

Shikigami &Shikigami::operator++()
{
    level_++; // 前置++i自增，先自增++再返回i
    return *this;
}

Shikigami Shikigami::operator++(int)
{
    Shikigami temp = *this; // 后置i++自增，先返回i再++
    level_++;
    return temp;
}

void Shikigami::ShowStar()
{
    std::cout << "star: ";
    for (int i = 0; i < star_; i++)
    {
        std::cout << "*";
    }
    std::cout << std::endl;
}

void Shikigami::ConvRarity(unsigned short int rare)
{
    switch (rare)
    {
    case 0:
        rare_ = rarity(0); // 只能将定义的枚举量赋给枚举变量，但有效的int值可以强制类型转换为枚举量
        break;
    case 1:
        rare_ = rarity(1);
        break;
    case 2:
        rare_ = rarity(2);
        break;
    case 3:
        rare_ = rarity(3);
        break;
    case 4:
        rare_ = rarity(4);
        break;
    default:
        rare_ = N;
        break;
    }
}

void Shikigami::ShowRarity()
{
    std::cout << "rarity: ";
    switch (rare_)
    {
    case N:
        std::cout << "N" << std::endl;
        break;
    case R:
        std::cout << "R" << std::endl;
        break;
    case SR:
        std::cout << "SR" << std::endl;
        break;
    case SSR:
        std::cout << "SSR" << std::endl;
        break;
    case SP:
        std::cout << "SP" << std::endl;
        break;
    default:
        break;
    }
}