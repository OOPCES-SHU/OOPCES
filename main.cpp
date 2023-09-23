//main.cpp
#include <bits/stdc++.h>
#include "LinkList.h"
#include "Node.h"
using namespace std;

int main()
{
    void TestHousePrice(); //声明函数
    int choice;
    while(true)
    {
        cout << "\n========== MENU ==========" << endl;
        cout << "  1 ---- 输出房价列表" << endl;
        cout << "  2 ---- 添加新的房价" << endl;
        cout << "  3 ---- 查 询 房 价" << endl;
        cout << "  4 ---- 数据写入文件" << endl;
        cout << "  5 ---- 读取数据文件" << endl;
        cout << "  0 ---- 退       出" << endl;
        cout << "==========================" << endl;
        cin >> choice;
        if(choice == 0) break;
        switch(choice)
        {
            case 1: test1(); break;
            case 2: test2(); break;
            case 3: test3(); break;
            case 4: test4(); break;
            case 5: test5(); break;
        }
    }
    return 0;
}
