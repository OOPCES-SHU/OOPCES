
#include "LinkList.h"
#include "Tantanic.h"
#include <fstream>
#include <bits/stdc++.h>




//PassengerId,Survived,Pclass,Name,Sex,Age,SibSp,Parch,Ticket,Fare,Embarked
void TantanicTest()
{
    LinkList<Tantanic > TanList;
    Tantanic TanObj;
    std::fstream fin("../data_train.csv");
    std::string buf;
    if(!fin) std::cerr << "File not found!" << std::endl;
    else
    {
        while (std::getline(fin, buf)) {
            TanObj.Set(buf+'\n');
            TanList.Append(TanObj);
        }
        TanList.ShowList();
    }
    system("pause");
}
