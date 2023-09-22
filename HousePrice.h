//HousePrice.h
#ifndef OOPCES_HOUSEPRICE_H
#define OOPCES_HOUSEPRICE_H
#include <bits/stdc++.h>
class HousePrice
{

public:
    HousePrice(); //构造函数，用于初始化数据成员
    void Set(const std::vector<std::string >  str); //设置数据成员的值，使用一个str
    // 重载<< 输出
    friend std::ostream & operator<<(std::ostream &out ,const HousePrice &housePrice);
private:
    void Modify(); // 将AllDataStr与其他具体数据成员对应

private:
    bool escalator ; //电梯（有无）(0为无)
    std::string  direction; // 朝向（南北）
    double area; //占地面积
    int NumRoom , NumLiving , NumWC ; //户型房间数、户型厅数、互相厕所数
    int stories ; //总楼层数
    std::string floor ; //所处层数(中高低层)
    std::string district ; //小区
    std::string adress ; //地址
    int MadeTime ; //建筑时间
    int price ; //价格(万)
    std::vector<std::string > AllDataStr; //数据顺序按索引升序为户型-房间	户型-厅	户型-卫生	建筑面积	朝向	电梯	总楼层	所处层数	小区	地址	建筑时间	价格（万）

};


#endif //OOPCES_HOUSEPRICE_H
