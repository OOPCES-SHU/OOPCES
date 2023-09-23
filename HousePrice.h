//HousePrice.h
#ifndef OOPCES_HOUSEPRICE_H
#define OOPCES_HOUSEPRICE_H
#include <bits/stdc++.h>
class HousePrice
{

public:
    //添加默认构造函数
    HousePrice(); //构造函数，用于初始化数据成员
    HousePrice & operator=(const HousePrice &housePrice); //重载=运算符
    void Set(const std::string&  str); //设置数据成员的值，使用一个str
    // 重载<< 输出
    void Show(int n=-1) const;
    friend std::ostream & operator<<(std::ostream &out ,const HousePrice &housePrice);
private:
    void Modify(); // 将AllDataStr与其他具体数据成员对应

private:

    bool escalator{false} ; //电梯（有无）(0为无)
    std::string  direction{"空"}; // 朝向（南北）
    double area{0}; //占地面积
    int NumRoom{0} , NumLiving{0} , NumWC{0} ; //户型房间数、户型厅数、互相厕所数
    int stories{0} ; //总楼层数
    std::string floor{"空"} ; //所处层数(中高低层)
    std::string district{"空"} ; //小区
    std::string adress{"空"} ; //地址
    int MadeTime{0} ; //建筑时间
    int price{0} ; //价格(万)
    std::string AllDataStr; //数据顺序按索引升序为户型-房间	户型-厅	户型-卫生	建筑面积	朝向	电梯	总楼层	所处层数	小区	地址	建筑时间	价格（万）
    std::vector<std::string > AllDataVec;
};


#endif //OOPCES_HOUSEPRICE_H
