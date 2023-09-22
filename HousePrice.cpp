
#include "HousePrice.h"
#include <vector>

// 初始化构造函数
HousePrice::HousePrice()
    :escalator(false),direction("空"),area(0),
    NumRoom(0),NumLiving(0),NumWC(0),stories(0),
    floor("空"),district("空"),adress("空"),
    MadeTime(0),price(0),AllDataStr(12,{'\0'}) //构造只有1个元素’\0‘即AllDataStr[0] = '\0'
{}

//数据顺序按索引升序为户型-房间	户型-厅	户型-卫生	建筑面积	朝向	电梯	总楼层 所处层数	小区	地址	建筑时间	价格（万）
void HousePrice::Set(const std::vector<std::string >  str) //设置数据成员的值，使用一个str
{

    for(int i=0; i<str.size(); i++)
    {
        AllDataStr.at(i) = str.at(i); //使用at 防止越界
    }
    Modify();
}
//数据顺序按索引升序为户型-房间	户型-厅	户型-卫生	建筑面积	朝向	电梯	总楼层 所处层数	小区	地址	建筑时间	价格（万）
void HousePrice::Modify()
{
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
    price = std::stoi(AllDataStr.at(11) , nullptr , 10); //转换为十进制数
}