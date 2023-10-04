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
    bool operator<(const Tantanic &tan) const;
    bool operator>(const Tantanic &tan) const;
    bool operator==(const Tantanic &tan) const;
    bool operator!=(const Tantanic &tan) const;
    bool operator<=(const Tantanic &tan) const;
    bool operator>=(const Tantanic &tan) const;

    int GetId() const;
    void SetId(const std::string &id);
    bool GetSurvived() const;
    void SetSurvived(const std::string &survived);
    void SetPclass(const std::string &pclass);
    std::string GetName() const;
    void SetName(const std::string &name);
    void SetSex(const std::string &sex);
    void SetAge(const std::string &age);
    void SetSibSp(const std::string &sibSp);
    void SetParch(const std::string &parch);
    void SetTicket(const std::string &ticket);
    void SetFare(const std::string &fare);
    void SetEmbarked(const std::string &embarked);
    std::string GetAllDataStr() const;
    std::vector<std::string> GetAllDataVec() const;
private:
    int PassengerId;
    bool Survived;
    int Pclass;
    std::string Name;
    bool Sex;
    int Age;
    int SibSp;
    int Parch;
    std::string Ticket;
    double Fare;
    int Embarked;
    std::string AllDataStr;
    std::vector<std::string> AllDataVec;
};

#endif //OOPCES_TANTANIC_H