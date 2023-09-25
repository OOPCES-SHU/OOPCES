//Titanic.h(Tantanic.h)
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
    std::vector<std::string> AllDataVec;
private:
    /*int PassengerId;
    bool Survived;
    int Pclass;
    std::string Name;
    bool Sex;
    int Age;
    int SibSp;
    int Parch;
    std::string Ticket;
    double Fare;
    int Embarked;*/
    std::string AllDataStr;
};

#endif //OOPCES_TANTANIC_H