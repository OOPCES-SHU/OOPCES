//Titanic.cpp(Tantanic.cpp)

#include "Tantanic.h"
// 使用字符分割
// 字符串分割函数,分割结果放在一个 vector<string >中
void Stringsplit(const std::string& str, const char split, std::vector<std::string>& res)
{
    res.clear();
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
    res.clear();
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

/*PassengerId(0),Survived(true),Pclass(0),Name("unknown"),
Sex(true),Age(0),SibSp(0),Parch(0),Ticket("unknown"),
Fare(0),Embarked(0),*/
Tantanic::Tantanic()
    :AllDataStr("unknown"),AllDataVec(0)
{
    AllDataVec.reserve(23);
}

void Tantanic::Set(const std::string &str)
{
    AllDataStr = str;
    Stringsplit(AllDataStr, ",", AllDataVec);
//    PassengerId = std::stoi(AllDataVec[0]);
//    Survived = (AllDataVec[1] == "1");
//    Pclass = std::stoi(AllDataVec[2]);
//    Name = AllDataVec[3];
//    Sex = AllDataVec[4] == "1"; //0代表男
//    Age = std::stoi(AllDataVec[5]);
//    SibSp = std::stoi(AllDataVec[6]);
//    Parch = std::stoi(AllDataVec[7]);
//    Ticket = AllDataVec[8];
//    Fare = std::stod(AllDataVec[9]);
//    Embarked = std::stoi(AllDataVec[10]);
    AllDataVec.push_back({"id."}); //11

    if(AllDataVec.at(1) == "1") //12
        AllDataVec.push_back({"\t是否存活:存活"});
    else
        AllDataVec.push_back({"\t是否存活:死亡"});

    if(AllDataVec.at(2) == "1") //13
        AllDataVec.push_back({"\n| 乘客等级:低"});
    else if(AllDataVec.at(2) == "2")
        AllDataVec.push_back({"\n| 乘客等级:中"});
    else
        AllDataVec.push_back({"\n| 乘客等级:高"});

    AllDataVec.push_back({"\t姓名:"}); //姓名 14

    if(AllDataVec.at(4) == "0") // 15
        AllDataVec.push_back({"\t性别:男"});
    else
        AllDataVec.push_back({"\t性别:女"});

    AllDataVec.push_back({"\t年龄:"});//16
    AllDataVec.push_back({"\t同代直系亲属数量:"}); //17
    AllDataVec.push_back({"\t不同代直系亲属数量:"}); //18
    AllDataVec.push_back({"\n| 票的类型:"}); //19
    AllDataVec.push_back({"\t费用:"}); //20

    if(AllDataVec.at(10) == "1") //21
        AllDataVec.push_back({"\t几号港口:S"});
    else if(AllDataVec.at(10) == "2")
        AllDataVec.push_back({"\t几号港口:C"});
    else
        AllDataVec.push_back({"\t几号港口:Q"});

    AllDataVec.push_back({"\n"}); //22
}

std::ostream &operator<<(std::ostream &os, const Tantanic &tan)
{
    /*
 =============ddddddddd===============
 id.1 姓名:dwd 性别:女 年龄:24 是否存活:存活
 | 乘客等级:中 同代直系亲属数量:123 不同代直系亲属数量:12
 | 票的类型:  费用:100 几号港口:Q
 */
    os << tan.AllDataVec.at(11) << tan.AllDataVec.at(0); //输出乘客id
    os << tan.AllDataVec.at(14) << tan.AllDataVec.at(3); //输出乘客姓名
    os << tan.AllDataVec.at(15);  //输出乘客性别
    os << tan.AllDataVec.at(16) << tan.AllDataVec.at(5); //输出乘客年龄
    os << tan.AllDataVec.at(12); //输出是否存活
    os << tan.AllDataVec.at(13); //输出乘客等级
    os << tan.AllDataVec.at(17) << tan.AllDataVec.at(6); //输出同代直系亲属数量
    os << tan.AllDataVec.at(18) << tan.AllDataVec.at(7); //输出不同代直系亲属数量
    os << tan.AllDataVec.at(19) << tan.AllDataVec.at(8); //输出票的类型
    os << tan.AllDataVec.at(20) << tan.AllDataVec.at(9); //输出费用
    os << tan.AllDataVec.at(21); //输出几号港口
    os << tan.AllDataVec.at(22); //换行
    return os;
}