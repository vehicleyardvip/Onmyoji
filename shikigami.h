#include <string>

class Shikigami
{
private:
    // 式神私有属性，阴阳师和达摩没有稀有度
    enum rarity // 自定义的数据结构需要在使用前先进行定义
    {
        N,
        R,
        SR,
        SSR,
        SP
    } rare_;

protected:
    // physical property rank
    enum rank
    {
        A = 65,
        B,
        C,
        D
    } rank_;

public:
    Shikigami(const std::string name, unsigned short int rare);
    //~Shikigami();

    void SetCardGrade(unsigned short int level);
    void SetProperity(double attack, double health, double defend, double speed, double cirtical);
    void GetStar();
    void PrintInfo();
    std::string Life();
    double Fight();

    Shikigami &operator++();   // ++i
    Shikigami operator++(int); // i++

protected:
    void ShowStar();

private:
    void ConvRarity(unsigned short int rare);
    void ShowRarity();

public:
    std::string nickname_ = ""; // 仅C++11之后的版本支持类的成员变量在声明时初始化

protected: // 保护属性，参数不允许类外随意修改，只允许通过调用类内相关成员函数修改
    std::string name_;
    unsigned short int star_ = 2;
    unsigned short int level_ = 1;
    // physical properties
    double attack_;
    double health_;
    double defend_;
    double speed_;
    double critical_;
};