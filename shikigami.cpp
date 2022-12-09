#include "shikigami.h"

Shikigami::Shikigami(std::string name) // 给定式神名，构造一个式神
{
    name_ = name;
};

std::string Shikigami::Life()
{
    if (health_ <= 0)
    {
        return "dead";
    }
    else
    {
        return "alive";
    }
};

void Shikigami::SetProperity(char star){

};

void Shikigami::ProperityLimit(double attack, double health, double defend, double speed, double cirtical)
{
    if (attack >= 70)
    {
    }
};