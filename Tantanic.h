

#ifndef OOPCES_TANTANIC_H
#define OOPCES_TANTANIC_H
#include <string>
#include <vector>
class Tantanic
{
public:
    Tantanic();
    void Set(const std::string &str);
    friend std::ostream &operator<<(std::ostream &os, const Tantanic &tan);
private:
    unsigned int PassengerId;
    bool Survived;
    unsigned int Pclass;
    std::string Name;
    bool Sex;
    unsigned int Age;
    unsigned int SibSp;
    unsigned int Parch;
    std::string Ticket;
    double Fare;
    unsigned int Embarked;
    std::string AllDataStr;
    std::vector<std::string> AllDataVec;
};


#endif //OOPCES_TANTANIC_H
