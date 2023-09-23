//HousePrice.cpp
#include "HousePrice.h"

// 初始化构造函数
HousePrice::HousePrice() //构造函数，用于初始化数据成员
    :AllDataStr({'\0'}) //构造只有1个元素’\0‘即AllDataStr = '\0'
{}



// 重载=运算符
HousePrice & HousePrice::operator=(const HousePrice &housePrice) //重载=运算符
{
    if(this == &housePrice) // 如果赋值运算表达式的右值对象与本对象为同一对象（它们的地址相同）
        return *this; // 则直接返回本对象（*this）
    // 这是重载双目运算符函数时应该注意的问题。如果赋值表达式左、右两个对象为同一对象，贸然执行下面的语句将造成严重错误！
    // 因为，尽管右边的对象list还被视为const常量对象，释放了左边对象（即本对象）的所有结点后，右边对象的所有结点也就不存在了
    AllDataStr = housePrice.AllDataStr; //拷贝AllDataStr
    return *this;
}

//数据顺序按索引升序为户型-房间	户型-厅	户型-卫生	建筑面积	朝向	电梯	总楼层 所处层数	小区	地址	建筑时间	价格（万）
void HousePrice::Set(const std::string&  str) //设置数据成员的值，使用一个str
{

    AllDataStr = str;
    Modify();
}

void HousePrice::Show() const
{
    std::cout << AllDataStr;
}
//数据顺序按索引升序为户型-房间	户型-厅	户型-卫生	建筑面积	朝向	电梯	总楼层 所处层数	小区	地址	建筑时间	价格（万）
void HousePrice::Modify()
{
    // O(n)
    for(int i=0; i<AllDataStr.size(); ++i)
    {
        if(AllDataStr.at(i) == '\t')
        {
            AllDataStr.at(i) = ' ';
        }
    }
}

std::ostream & operator<<(std::ostream &out ,const HousePrice &housePrice)
{
    out << housePrice.AllDataStr;
    return out;
}
/*

NumRoom = std::stoi(AllDataStr.at(0) , nullptr , 10); //转换为十进制数
NumLiving = std::stoi(AllDataStr.at(1) , nullptr , 10); //转换为十进制数
NumWC = std::stoi(AllDataStr.at(2) , nullptr , 10); //转换为十进制数
area = std::stod(AllDataStr.at(3) , nullptr); //转换为double
direction = AllDataStr.at(4);
escalator = bool(std::stoi(AllDataStr.at(5) , nullptr , 10)); //强制转换为bool
stories = std::stoi(AllDataStr.at(6) , nullptr , 10); //转换为十进制数
floor = AllDataStr.at(7);
district = AllDataStr.at(8);
adress = AllDataStr.at(9);
MadeTime = std::stoi(AllDataStr.at(10) , nullptr , 10); //转换为十进制数
price = std::stoi(AllDataStr.at(11) , nullptr , 10); //转换为十进制数*/
