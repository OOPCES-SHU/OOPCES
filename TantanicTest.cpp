//TitanicTest.cpp(TantanicTest.cpp)

#include "LinkList.h"
#include "Tantanic.h"
#include <fstream>
#include <bits/stdc++.h>

bool is_number(const std::string& s)
{
    std::string::const_iterator it = s.begin();
    while (it != s.end() && std::isdigit(*it)) ++it;
    return !s.empty() && it == s.end();
}


static bool inputtest(const std::string& str, char split)
{
    if (str == "")		return false;
    int sum=0;
    //在字符串末尾也加入分隔符，方便截取最后一段
    std::string strs = str + split;
    size_t pos = strs.find(split);
    // 若找不到内容则字符串搜索函数返回 npos
    while (pos != strs.npos)
    {
        std::string temp = strs.substr(0, pos);
        strs = strs.substr(pos + 1, strs.size());
        pos = strs.find(split);
        sum++;
    }
    if(sum==11) return true;
    else return false;
}
//增删该查

static void TestAppend(LinkList<Tantanic> &tan)
{
    Tantanic TanObj;
    Tantanic temp;
    std::string buf;
    int CurNode = tan.CurPos();
    std::cout << "请输入要添加的数据，以回车结束:\n";
    std::cout << "输入顺序为PassengerId,Survived,Pclass,Name,Sex,Age,SibSp,Parch,Ticket,Fare,Embarked\n";
    std::cout << "即乘客id,是否存活,乘客等级,乘客姓名,乘客性别,年龄,同代直系亲属数量,不同代直系亲属数量,票的类型,费用,几号港口\n";
    std::cout << "[每个数据之间用逗号隔开]\n[其中1代表存活,0代表死亡,1代表女性,0代表男性,0,1,2分别代表S,C,Q港口]\n";
    std::getline(std::cin, buf);
    if(inputtest(buf,','))
    {
        TanObj.Set(buf+'\n');
        if(is_number(TanObj.GetAllDataVec().at(0)))
        {
            temp.Set(TanObj.GetAllDataVec().at(0)+",0,0,0,0,0,0,0,0,0,1");
            if(tan.Locate(temp, true) == nullptr)
            {
                tan.Append(TanObj);
                std::cout << "添加成功\n";
            }
            else{
                std::cout << "添加失败,已有该id\n";
            }
            tan.Go(CurNode);
        }
    }
    else
    {
        std::cout<<"输入的数据个数有误，请检查后重新输入\n";
    }
}

static void TestDelete(LinkList<Tantanic > &tan)
{
    std::string PassengerId;
    Tantanic TanObj;
    int CurNode = tan.CurPos();
    std::cout << "请输入要删除的数据的PassengerId:";
    std::cin >> PassengerId;
    TanObj.Set(PassengerId+",0,0,0,0,0,0,0,0,0,1");
    if(tan.Locate(TanObj, true)) std::cout << "Id不存在，删除失败\n";
    else std::cout << "删除成功\n";
    tan.Go(CurNode+1);
}

static void Search(const std::string &x ,LinkList<Tantanic >& tan)   //根据姓名模糊搜索
{
    int count = 0; //记录找到的个数
    int CurNode = tan.CurPos(); //记录当前位置
    tan.GoTop(); //移动到头结点
    Tantanic temp; //临时变量
    temp = tan.CurData(); //获取当前结点的数据
    for(int i=0; i< tan.NumNodes(); i++)
    {
        std::string Name = temp.GetName(); //获取姓名
        if(Name.find(x) != std::string::npos)
        {
            std::cout << temp << '\n';
            count++;
        }
        tan.Go(i); //移动到下一个结点
        temp = tan.CurData(); //更新temp
    }
    tan.Go(CurNode); //恢复原来的位置
    if(count==0)
        std::cout << "未找到相关信息\n";
    else
        std::cout << "共找到" << count << "条相关信息\n";
}

static void ShowListDeadOrSur(LinkList<Tantanic >& tan, bool DeadOrSur) //输出所有死者或者幸存者
{
    int CurNode = tan.CurPos(); //记录当前位置
    tan.GoTop(); //移动到头结点
    Tantanic temp = tan.CurData(); //获取当前结点的数据
    for(int i=0; i<tan.NumNodes(); i++)
    {
        if(!DeadOrSur) //输出死者
        {
            if(temp.GetSurvived() == false)
            std::cout << temp << '\n';
        }
        else //输出幸存者
        {
            if(temp.GetSurvived() == true)
            std::cout << temp << '\n';
        }
        tan.Go(i); //移动到下一个结点
        temp = tan.CurData(); //更新temp
    }
    tan.Go(CurNode); //恢复原来的位置
}

static void TestFind(char choice2, LinkList<Tantanic > &TanList)
{
    std::cout << "请选择查找的方式:\n";
    std::cout << "[1] 使用PassengerId查找    ";
    std::cout << "[2] 使用姓名查找    ";
    std::cout << "[3] 输出所有死者    ";//对不起对不起对不起RIP,RIP,RIP
    std::cout << "[4] 输出所有幸存者    ";
    std::cout << "[0] 返回上一级    \n";
    std::cin >> choice2;
    std::string name;
    switch(choice2)
    {
        case '1':
        {
            std::cout << "请输入要查找的PassengerId:";
            std::string PassengerId;
            std::cin >> PassengerId;
            Tantanic temp;
            temp.Set(PassengerId+",0,0,0,0,0,0,0,0,0,1");
            if(TanList.Locate(temp, true) == nullptr) std::cout << "未找到相关信息\n";
            else std::cout << '\n' << TanList.CurData() << '\n';
            std::cout << "等待下一次输入.......按任意键继续\n";
            system("pause");
            break;
        }
        case '2':
            std::cout << "请输入要查找的姓名:";
            std::cin >> name;
            std::cout << "查找结果如下:\n";
            Search(name, TanList);
            std::cout << "等待下一次输入.......按任意键继续\n";
            system("pause");
            break;
        case '3':
            ShowListDeadOrSur(TanList, false);
            std::cout << "等待下一次输入.......按任意键继续\n";
            system("pause");
            break;
        case '4':
            ShowListDeadOrSur(TanList, true);
            std::cout << "等待下一次输入.......按任意键继续\n";
            system("pause");
            break;
        case '0':
            break;
        default:
            std::cout << "输入错误\n";
            std::cout << "等待下一次输入.......按任意键继续\n";
            system("pause");
            std::cin.clear();
            break;
    }
}

static void TestEditor(LinkList<Tantanic > &tan)
{
    Tantanic TanObj;
    std::cout << "请输入要修改的乘客的Id:";
    int CurNode = tan.CurPos(); //记录当前位置
    std::string PassengerId;
    bool flag{false};
    std::cin.clear();
    std::cin >> PassengerId;
    std::cin.sync();
    if(std::cin.good())
    {
        TanObj.Set(PassengerId+",0,0,0,0,0,0,0,0,0,1");
        if(tan.Locate(TanObj, true) == nullptr)
        {
            std::cout << "Id不存在，修改失败\n";
            return;
        }
        while(!flag) {
            system("cls");
            std::cout << "请选择要修改的内容:\n";
            std::cout << "[i]乘客id [s]是否存活 [p]乘客等级 [n]乘客姓名 \n"
                      << "[x]乘客性别 [a]年龄 [b]同代直系亲属数量 "
                      << "[r]不同代直系亲属数量 [t]票的类型 [f]费用 "
                      <<  "[e]几号港口 [q]退出修改\n";
            std::cout << "\n[其中1代表存活,0代表死亡,1代表女性,0代表男性,0,1,2分别代表S,C,Q港口]\n";
            char choice3;
            std::cin >> choice3;
            switch (choice3) {
                case 'i': {
                    std::cout << "请输入新的乘客id:";
                    std::string NewPassengerId;
                    std::cin >> NewPassengerId;
                    if (is_number(NewPassengerId)) {
                        tan.CurData().SetId(NewPassengerId);
                        //tan.Go(CurNode);
                        Tantanic tem;
                        tan.Sort(tem, true);
                        std::cout << "修改成功\n";
                        std::cout << "等待下一次输入.......按任意键继续\n";
                        system("pause");
                        break;
                    } else {
                        std::cout << "请输入整数！\n";
                        std::cin.clear();
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // 清除错误行
                        system("pause");
                        break;
                    }
                }
                case 's': {
                    std::cout << "请输入新的存活状态:\n";
                    std::cout << "[1] 存活    ";
                    std::cout << "[0] 死亡    \n";
                    std::string NewSurvived;
                    std::cin >> NewSurvived;
                    if (is_number(NewSurvived)) {
                        tan.CurData().SetSurvived(NewSurvived);
                        std::cout << "修改成功\n";
                        std::cout << "等待下一次输入.......按任意键继续\n";
                        system("pause");
                        break;
                    } else {
                        std::cout << "请输入整数！\n";
                        std::cin.clear();
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // 清除错误行
                        system("pause");
                        break;
                    }
                }
                case 'p': {
                    std::cout << "请输入新的乘客等级:\n";
                    std::cout << "[1] 低    ";
                    std::cout << "[2] 中    ";
                    std::cout << "[3] 高    \n";
                    std::string NewPclass;
                    std::cin >> NewPclass;
                    if (is_number(NewPclass)) {
                        tan.CurData().SetPclass(NewPclass);
                        std::cout << "修改成功\n";
                        std::cout << "等待下一次输入.......按任意键继续\n";
                        system("pause");
                        break;
                    } else {
                        std::cout << "请输入整数！\n";
                        std::cin.clear();
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // 清除错误行
                        system("pause");
                        break;
                    }
                }
                case 'n': {
                        std::cout << "请输入新的乘客姓名:";
                        std::string NewName;
                        std::cin >> NewName;
                        tan.CurData().SetName(NewName);
                        std::cout << "修改成功\n";
                        std::cout << "等待下一次输入.......按任意键继续\n";
                        system("pause");
                        break;
                }
                case 'x': {
                    std::cout << "请输入新的乘客性别:\n";
                    std::cout << "[1] 女性    ";
                    std::cout << "[0] 男性    \n";
                    std::string NewSex;
                    std::cin >> NewSex;
                    if (is_number(NewSex)) {
                        tan.CurData().SetSex(NewSex);
                        std::cout << "修改成功\n";
                        std::cout << "等待下一次输入.......按任意键继续\n";
                        system("pause");
                        break;
                    } else {
                        std::cout << "请输入整数！\n";
                        std::cin.clear();
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // 清除错误行
                        system("pause");
                        break;
                    }

                }
                case 'a': {
                    std::cout << "请输入新的年龄:";
                    std::string NewAge;
                    std::cin >> NewAge;
                    if (is_number(NewAge)) {
                        tan.CurData().SetAge(NewAge);
                        std::cout << "修改成功\n";
                        std::cout << "等待下一次输入.......按任意键继续\n";
                        system("pause");
                        break;
                    } else {
                        std::cout << "请输入整数！\n";
                        std::cin.clear();
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // 清除错误行
                        system("pause");
                        break;
                    }
                }
                case 'b': {
                    std::cout << "请输入新的同代直系亲属数量:";
                    std::string NewSibSp;
                    std::cin >> NewSibSp;
                    if (is_number(NewSibSp)) {
                        tan.CurData().SetSibSp(NewSibSp);
                        std::cout << "修改成功\n";
                        std::cout << "等待下一次输入.......按任意键继续\n";
                        system("pause");
                        break;
                    } else {
                        std::cout << "请输入整数！\n";
                        std::cin.clear();
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // 清除错误行
                        system("pause");
                        break;
                    }
                }
                case 'r': {
                    std::cout << "请输入新的不同代直系亲属数量:";
                    std::string NewParch;
                    std::cin >> NewParch;
                    if (is_number(NewParch)) {
                        tan.CurData().SetParch(NewParch);
                        std::cout << "修改成功\n";
                        std::cout << "等待下一次输入.......按任意键继续\n";
                        system("pause");
                        break;
                    } else {
                        std::cout << "请输入整数！\n";
                        std::cin.clear();
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // 清除错误行
                        system("pause");
                        break;
                    }
                }
                case 't': {
                    std::cout << "请输入新的票的类型:\n";
                    std::string NewTicket;
                    std::cin >> NewTicket;
                    tan.CurData().SetTicket(NewTicket);
                    std::cout << "修改成功\n";
                    std::cout << "等待下一次输入.......按任意键继续\n";
                    system("pause");
                    break;
                }
                case 'f': {
                    void Stringsplit(const std::string &str,const char split, std::vector<std::string> &res);
                    std::cout << "请输入新的费用:";
                    std::vector<std::string > temp(2, "0");
                    std::string NewFare;
                    std::cin >> NewFare;
                    Stringsplit(NewFare, '.', temp);
                    if (is_number(temp[0]) && is_number(temp[1])) {
                        tan.CurData().SetFare(NewFare);
                        std::cout << "修改成功\n";
                        std::cout << "等待下一次输入.......按任意键继续\n";
                        system("pause");
                        break;
                    } else {
                        std::cout << "请输入数字！\n";
                        std::cin.clear();
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // 清除错误行
                        system("pause");
                        break;
                    }
                }
                case 'e': {
                    std::cout << "请输入新的几号港口:\n";
                    std::cout << "[1] S    ";
                    std::cout << "[2] C    ";
                    std::cout << "[3] Q    \n";
                    std::string NewEmbarked;
                    std::cin >> NewEmbarked;
                    if (is_number(NewEmbarked)) {
                        tan.CurData().SetEmbarked(NewEmbarked);
                        std::cout << "修改成功\n";
                        std::cout << "等待下一次输入.......按任意键继续\n";
                        system("pause");
                        break;
                    } else {
                        std::cout << "请输入整数！\n";
                        std::cin.clear();
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // 清除错误行
                        system("pause");
                        break;
                    }
                }
                case 'q': {
                    flag = true;
                    std::cout << "退出修改\n";
                    break;
                }
                default: {
                    std::cout << "输入错误，请重新输入\n";
                    std::cout << "等待下一次输入.......按任意键继续\n";
                    system("pause");
                    break;
                }
            }
        }
        tan.Go(CurNode);
        std::cout << "等待下一次输入.......按任意键继续\n";
        system("pause");
    }
    else
    {
        std::cout << "请输入整数！\n";
        std::cin.clear();
        std::cin.ignore( std::numeric_limits<std::streamsize>::max(), '\n' ); // 清除错误行
        system("pause");
    }
}

static void TestSort(LinkList<Tantanic > &tan)
{
    //将tan中的数据按照id从小到大排序
//    int CurNode = tan.CurPos(); //记录当前位置
    std::cout << "请选择排序方式(只以Id进行排序):\n"
              << "[1]升序 "
              << "[0]降序\n";
    bool ascending{true};
    std::cin.clear();
    std::cin >> ascending;
    std::cin.sync();
    if(std::cin.good())
    {
        Tantanic x;
        tan.Sort(x, ascending);
        std::cout << "排序成功\n";
    } else
    {
        std::cout << "输入错误\n";
    }
//    tan.Go(CurNode);
}

//PassengerId,Survived,Pclass,Name,Sex,Age,SibSp,Parch,Ticket,Fare,Embarked
void TantanicTest()
{
    LinkList<Tantanic > TanList;
    Tantanic TanObj;
    std::fstream fin("../data_train.csv");
    std::string buf;
    TanList.SetCurrentPage(1); // 初始化当前页码
    TanList.SetPageSize(5); // 每页显示的数据条数
    int CurPage = TanList.GetCurrentPage();
    int PageSize = TanList.GetPageSize();
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
        int totalPages = (TanList.NumNodes() + TanList.GetPageSize() - 1) / TanList.GetPageSize();
        std::cout << "\n============================泰坦尼克号成员名单========================\n";
        std::cout << "                             【尊重死者R.I.P】                         \n";
        //输出前五个数据
        std::cout << "[当前页码：" << TanList.GetCurrentPage() << " / " << totalPages << "]\n";
        TanList.displayDataPage();

        std::cout << "============================对成员名单进行操作========================\n";
        std::cout << "输出所有数据[s]    "; //show //每个选项后面四个空格
        std::cout << "添加新的数据[a]    "; //add
        std::cout << "删除数据[d]    ";//delete
        std::cout << "查找数据[f]\n";//find
        std::cout << "上一页[p]    "; // previous page
        std::cout << "下一页[n]    "; // next page
        std::cout << "跳转到指定页面[e]    "; // designated page
        std::cout << "修改数据[m]    ";//modify
        std::cout << "按id排序[o]\n";//order
        std::cout << "退出系统[q]\n";//quit
        std::cout << "请输入要进行的操作:";
        char choice, choice2;
        std::cin.clear();
        std::cin >> choice;
        std::cin.sync();
        system("cls");
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
                TestDelete(TanList);
                std::cout << "等待下一次输入.......按任意键继续\n";
                system("pause");
                break;
            case 'f':
                TestFind(choice2, TanList);
                break;
            case 'p':
                if (CurPage > 1)
                {
                    CurPage--;
                    TanList.SetCurrentPage(CurPage);
                }
                else
                {
                    std::cout << "[已经是第一页了]\n";
                    std::cout << "等待下一次输入.......按任意键继续\n";
                    system("pause");
                }
                break;
            case 'n':
                if ( CurPage< totalPages)
                {
                    CurPage++;
                    TanList.SetCurrentPage(CurPage);
                }
                else if(CurPage == totalPages)
                {
                    std::cout << "[已经是最后一页了]\n";
                    std::cout << "等待下一次输入.......按任意键继续\n";
                    system("pause");
                }
                break;
            case 'e':
            {
                int designatedPage;
                std::cout << "[请输入要跳转到的页面]:" ;
                std::cin >> designatedPage;
                if(std::cin.good())
                {
                    if (designatedPage > totalPages)
                        designatedPage = totalPages;
                    else if (designatedPage < 1)
                        designatedPage = 1;
                    CurPage = designatedPage;
                    TanList.SetCurrentPage(CurPage);
                    break;
                }
                else {
                    std::cout << "请输入整数！\n";
                    std::cin.clear();
                    std::cin.ignore( std::numeric_limits<std::streamsize>::max(), '\n' ); // 清除错误行
                    system("pause");
                    break;
                }
            }
            case 'm':
                TestEditor(TanList);
                break;
            case 'o':

                TestSort(TanList);
                std::cout << "等待下一次输入.......按任意键继续\n";
                system("pause");
                break;
            case 'q':
                flag = true;
                std::cout << "退出系统\n";
                system("pause");
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