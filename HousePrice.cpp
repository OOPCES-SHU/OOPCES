//HousePrice.cpp
#include "HousePrice.h"

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


// 初始化构造函数
HousePrice::HousePrice() //构造函数，用于初始化数据成员
    :AllDataStr({'\0'}),AllDataVec(1,{'\0'}) //构造只有1个元素’\0‘即AllDataStr = '\0'
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

void HousePrice::Show(int n) const
{
    if( n == -1)
        std::cout << AllDataStr;
    else std::cout << AllDataStr.at(n);
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
    Stringsplit(AllDataStr , ' ' , AllDataVec);
    NumRoom = std::stoi(AllDataVec.at(2) , nullptr , 10); //转换为十进制数
    NumLiving = std::stoi(AllDataVec.at(3) , nullptr , 10); //转换为十进制数
    NumWC = std::stoi(AllDataVec.at(4) , nullptr , 10); //转换为十进制数
    area = std::stod(AllDataVec.at(5) , nullptr); //转换为double
    direction = AllDataVec.at(6);
    escalator = (AllDataVec.at(7) == "有") ? true : false;
    stories = std::stoi(AllDataVec.at(8) , nullptr , 10); //转换为十进制数
    floor = AllDataVec.at(9);
    district = AllDataVec.at(10);
    adress = AllDataVec.at(11);
    MadeTime = std::stoi(AllDataVec.at(12) , nullptr , 10); //转换为十进制数
    price = std::stoi(AllDataVec.at(13) , nullptr , 10); //转换为十进制数
}

std::ostream & operator<<(std::ostream &out ,const HousePrice &housePrice)
{
    out << housePrice.AllDataStr;
    return out;
}
/*

*/
