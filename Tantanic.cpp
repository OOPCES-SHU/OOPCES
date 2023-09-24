
#include "Tantanic.h"
// 使用字符分割
//字符串分割函数,分割结果放在一个 vector<string >中
void Stringsplit(const std::string& str, const char split, std::vector<std::string>& res)
{
    if (str == "")		return;
    //在字符串末尾也加入分隔符，方便截取最后一段
    std::string strs = str + split;
    size_t pos = strs.find(split);

    // 若找不到内容则字符串搜索函数返回 npos
    while (pos != strs.npos)
    {
        std::string temp = strs.substr(0, pos);
        res.push_back(temp);
        //去掉已分割的字符串,在剩下的字符串中进行分割
        strs = strs.substr(pos + 1, strs.size());
        pos = strs.find(split);
    }
}
//
void Stringsplit(const std::string& str, const std::string& splits, std::vector<std::string>& res)
{
    if (str == "")		return;
    //在字符串末尾也加入分隔符，方便截取最后一段
    std::string strs = str + splits;
    size_t pos = strs.find(splits);
    int step = splits.size();

    // 若找不到内容则字符串搜索函数返回 npos
    while (pos != strs.npos)
    {
        std::string temp = strs.substr(0, pos);
        res.push_back(temp);
        //去掉已分割的字符串,在剩下的字符串中进行分割
        strs = strs.substr(pos + step, strs.size());
        pos = strs.find(splits);
    }
}


Tantanic::Tantanic()
    :PassengerId(0),Survived(true),Pclass(0),Name("unknown"),
    Sex(true),Age(0),SibSp(0),Parch(0),Ticket("unknown"),
    Fare(0),Embarked(0),AllDataStr("unknown"),AllDataVec(0)
{}

void Tantanic::Set(const std::string &str)
{
    AllDataStr = str;
    Stringsplit(AllDataStr, ",", AllDataVec);
    PassengerId = std::stoi(AllDataVec[0]);
    Survived = (AllDataVec[1] == "1");
    Pclass = std::stoi(AllDataVec[2]);
    Name = AllDataVec[3];
    Sex = AllDataVec[4] == "1";
    Age = std::stoi(AllDataVec[5]);
    SibSp = std::stoi(AllDataVec[6]);
    Parch = std::stoi(AllDataVec[7]);
    Ticket = AllDataVec[8];
    Fare = std::stod(AllDataVec[9]);
    Embarked = std::stoi(AllDataVec[10]);
}

std::ostream &operator<<(std::ostream &os, const Tantanic &tan)
{
    os << tan.AllDataStr;
    return os;
}