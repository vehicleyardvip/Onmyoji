#include "shikigami.h"

int main()
{
    std::string name;
    unsigned short int rare, level;

    // 提示玩家输入式神名和卡片稀有度
    std::cout << "Please enter shikigami name: ";
    std::cin >> name;
    std::cout << "Please enter card rarity 0/1/2/3/4 (N/R/SR/SSR/SP): ";
    std::cin >> rare;

    Shikigami s(name, rare);
    s.PrintInfo();
    std::cout << "Upgrade the level? Input a number if yes (1~40): ";
    std::cin >> level;
    s.SetCardGrade(level);
    s++;
    s.PrintInfo();
    ++s;
    s.PrintInfo();
    std::cout << s.Life() << std::endl;

    system("pause");
    return 0;
}