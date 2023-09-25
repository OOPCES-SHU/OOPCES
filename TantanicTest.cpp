//TitanicTest.cpp(TantanicTest.cpp)

#include "LinkList.h"
#include "Tantanic.h"
#include <fstream>
#include <bits/stdc++.h>

//增删该查

void TestAppend(LinkList<Tantanic > &tan)
{
    Tantanic TanObj;
    std::string buf;
    std::cout << "请输入要添加的数据，以回车结束:\n";
    std::cout << "输入顺序为PassengerId,Survived,Pclass,Name,Sex,Age,SibSp,Parch,Ticket,Fare,Embarked\n";
    std::cout << "输入顺序为乘客id,是否存活,乘客等级,乘客姓名,乘客性别,年龄,同代直系亲属数量,不同代直系亲属数量,票的类型,费用,几号港口\n";
    std::cout << "[每个数据之间用逗号隔开]\n[其中1代表存活,0代表死亡,1代表女性,0代表男性,0,1,2分别代表S,C,Q港口]\n";
    std::getline(std::cin, buf);
    TanObj.Set(buf+'\n');
    tan.Append(TanObj);
    std::cout << "添加成功\n";
}

void TestDelet(LinkList<Tantanic > &tan)
{
    int PassemgerId;
    std::cout << "请输入要删除的数据的PassengerId:";
    std::cin >> PassemgerId;
    tan.Go(PassemgerId);
    tan.DeleteCurNode();
    std::cout << "删除成功\n" << std::endl;
}

//PassengerId,Survived,Pclass,Name,Sex,Age,SibSp,Parch,Ticket,Fare,Embarked
void TantanicTest()
{
    LinkList<Tantanic > TanList;
    Tantanic TanObj;
    std::fstream fin("../data_train.csv");
    std::string buf;
    TanList.currentPage = 1; // 初始化当前页码
    TanList.pageSize = 5; // 每页显示的数据条数
    if(!fin) std::cerr << "File not found!" << std::endl;
    else
    {
        while (std::getline(fin, buf))
        {
            TanObj.Set(buf+'\n');
            TanList.Append(TanObj);
        }
    }
    bool flag{false}; //标记是否退出
    while(!flag)
    {
        std::cout << "============================泰坦尼克号成员名单========================\n";
        std::cout << "                             【尊重死者R.I.P】                         \n";
        //输出前五个数据
        TanList.displayDataPage();

        std::cout << "============================对成员名单进行操作========================\n";
        std::cout << "请输入要进行的操作:\n";
        std::cout << "输出所有数据[s]    "; //show //每个选项后面四个空格
        std::cout << "添加新的数据[a]    "; //add
        std::cout << "删除数据[d]    ";//delete
        std::cout << "查找数据[f]    ";//find
        std::cout << "上一页[p]    "; // previous page
        std::cout << "下一页[n]    "; // next page
        std::cout << "退出系统[q]\n";//quit
        char choice,choice2;
        std::cin >> choice;
        int totalPages = (TanList.NumNodes() + TanList.pageSize - 1) / TanList.pageSize;
        switch(choice)
        {
            case 's':
                TanList.ShowList();
                std::cout << "等待下一次输入.......按任意键继续\n";
                system("pause");
                break;
            case 'a':
                TestAppend(TanList);
                std::cout << "等待下一次输入.......按任意键继续\n";
                system("pause");
                break;
            case 'd':
                TestDelet(TanList);
                std::cout << "等待下一次输入.......按任意键继续\n";
                system("pause");
                break;
            case 'f':
                std::cout << "请选择查找的方式:\n";
                std::cout << "[1] 使用PassengerId查找    ";
                std::cout << "[2] 使用姓名查找    ";
                std::cout << "[3] 输出所有幸存者    ";
                std::cout << "[4] 输出所有死者    ";
                std::cout << "[0] 返回上一级    \n";
                std::cin >> choice2;
                switch(choice2)
                {
                    case '1':
                        std::cout << "请输入要查找的PassengerId:";
                        int PassengerId;
                        std::cin >> PassengerId;
                        TanList.Go(PassengerId-1);
                        std::cout << '\n' << TanList.CurData() << '\n';
                    case '2':
                        std::cout << "请输入要查找的姓名:";
                    case '3':
                    case '4':
                    case '0':
                        break;
                    default:
                        std::cout << "输入错误\n";
                        break;
                }
                std::cout << "等待下一次输入.......按任意键继续\n";
                system("pause");
                break;
            case 'p':
                if (TanList.currentPage > 1) {
                    TanList.currentPage--;
                }
                break;
            case 'n':
                if (TanList.currentPage < totalPages) {
                    TanList.currentPage++;
                }
                break;
            case 'q':
                flag = true;
                break;
            default:
                std::cout << "输入错误，请重新输入\n";
                std::cout << "等待下一次输入.......按任意键继续\n";
                system("pause");
                break;
        }
    }
    fin.close();
}