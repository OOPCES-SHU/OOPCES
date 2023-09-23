
#include "HousePrice.h"
#include "LinkList.h"
#include <fstream>
// 该函数用于调用类的功能对数据进行读写测试
// 应包括增删改查、排序、界面打印功能.
// 界面打印功能也可使用另外一个函数

void TestHousePrice()
{
    LinkList<HousePrice > HosLink; //房子链表
    HousePrice HosObj; //房子对象

    std::fstream fin("D:\\CLionCodeField\\OOP\\OOPCES\\houseprice.txt"); //读入文件对象(文件为houseprice.txt)(utf-8)
    std::string buf{'\0'};//初始化一个缓存字符串

    // 打开失败时使用cerr进行错误警报
    if(!fin) std::cerr << "OPEN ERROR!";
    //打开成功
    else
    {
        while(std::getline(fin,buf)) // 读入buf
        {
            HosObj.Set(buf+'\n');
            HosObj.Show();
        }
    }
}