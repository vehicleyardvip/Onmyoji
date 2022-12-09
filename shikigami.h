#include <iostream>
#include <string>

class Shikigami
{
    Shikigami(std::string name);
    ~Shikigami();

public:
    std::string Life();
    double Health(int attack);

private:
    void SetProperity(char star);
    void ProperityLimit(double attack, double health, double defend, double speed, double cirtical);

public:
    std::string name_;
    enum rarity
    {
        N,
        R,
        SR,
        SSR,
        SP
    };

private:
    char star_;
    unsigned short int level;
    double attack_;
    double health_;
    double defend_;
    double speed_;
    double critical_;
    enum rank
    {
        D,
        C,
        B,
        A
    };
};