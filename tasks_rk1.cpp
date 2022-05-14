#include <iostream>
#include <QVector>
#include <QString>
#include <QTextStream>
#include <QtGlobal>
#include <stdio.h>
#include <QList>
#include <QFile>
#include <map>
#include <tuple>
#include <string>
#include <fstream>
#include "tasks_rk1.h"

using namespace std;

//for task 4
void task4(int H_of_elka)
{
    if(H_of_elka<=0)
    {
        cout << "takih elok ne bivaet." << endl;
        return;
    }
    int max_yarus = 1;
    int kolvoprob = 0;
    for(int i = 0; i < H_of_elka; i++)
    {
        kolvoprob++;
    }


    for(int i = 0; i < H_of_elka;i++)
    {
        for(int i = 0; i<kolvoprob;i++)
        {
            cout << " ";
        }
        for(int i = 0; i < max_yarus; i++)
        {
            cout << "*";
        }
        kolvoprob--;
        max_yarus += 2;
        cout << endl;
    }
}

//for task 5
double sred(int*mas, int m)
{
    double rez = 0;
    for(int i = 0; i < m; i++)
    {
        double temp = mas[i];
        rez = rez + temp/m;
    }
    return rez;
}
QList<double> task5(int* mas, int m, int n)
{
    QList<double> rez;
    rez.clear();
    for(int i = 0; i < n; i++)
    {
        double promrez;
        promrez = sred(&mas[m*i], m);
        rez.append(promrez);
    }
    return(rez);
}

//for tasks 6 and 7
struct Node
{
    Node* next;
    Node* prev;
    int  nameNode;
};

LinkedList::LinkedList()
{
    Head = nullptr;
    Tail = nullptr;
    count = 0;
}
LinkedList::~LinkedList()
{
    while(Head != nullptr)
    {
        Node* temp = Head;
        Head = Head->next;
        delete temp;
    }
}
void LinkedList:: push_back(int _nameNode)
{
    Node* tempNode = new Node;
    if(Head==nullptr)
    {
        tempNode->next = nullptr;
        tempNode->prev = nullptr;
        tempNode->nameNode = _nameNode;
        Head = tempNode;
        Tail = tempNode;
        count++;
        return;
    }
    else
    {
        tempNode->next = nullptr;
        tempNode->prev = Tail;
        tempNode->nameNode = _nameNode;
        Tail->next = tempNode;
        Tail = tempNode;
        count++;
        return;
    }

}
void LinkedList:: print()
 {
     Node* tempNode_;
              tempNode_ = Head;
     for(int i = 0; i < count; i++)
     {
         cout << tempNode_->nameNode << endl;
         tempNode_ = tempNode_->next;
     }
     delete tempNode_;
 }
void LinkedList:: writeToFileFromHead(const char* FileName)
{
    QFile f(FileName);
    f.open(QIODevice::WriteOnly);

    Node* temp = new Node;
    temp = Head;
    QTextStream writeStream(&f);
    while(temp!=nullptr)
    {
        int b;
        b = temp->nameNode;
        writeStream << b << "\n";
        temp = temp->next;
    }
    delete temp;
    f.close();
}
void LinkedList:: writeToFileFromTail(const char *FileName)
{
    QFile f(FileName);
    f.open(QIODevice::WriteOnly);

    Node* temp = new Node;
    temp = Tail;
    QTextStream writeStream(&f);
    while(temp!=nullptr)
    {
        int b;
        b = temp->nameNode;
        writeStream << b << "\n";
        temp = temp->prev;
    }
    delete temp;
    f.close();
}
void LinkedList:: insert(int _nameNode, int posit)
{
    int sred = count/2;
    if(posit < 0 || posit > count)
    {
        return;
    }
    Node* temp = new Node;
    temp->nameNode = _nameNode;
    if(posit==0)
    {
       temp->prev = nullptr;
       temp->next = Head;
       Head->prev = temp;
       Head = temp;
       count++;
       return;
    }
    if(posit==count)
    {
        temp->next = nullptr;
        temp->prev = Tail->prev;
        Tail->next = temp;
        Tail = temp;
        count++;
        return;
    }

    if(posit > sred) //Значит быстрее пройти по списку с конца
    {
        Node* ttemp = new Node;
        ttemp = Tail;
        for(int i = sred; i < count - posit; i++)
        {
            ttemp = ttemp->prev;
        }
        temp->prev = ttemp->prev;
        temp->next = ttemp;
        ttemp->prev->next = temp;
        ttemp->prev = temp;
        count++;
        return;
    }
    else //Значит быстрее с начала
    {
        Node* ttemp = new Node;
        ttemp = Head;
        for(int i = 0; i < posit; i++)
        {
            ttemp = ttemp->next;
        }
        ttemp->prev->next = temp;
        temp->prev = ttemp->prev;
        temp->next = ttemp;
        ttemp->prev = temp;
        count++;
        return;
    }
}

//for task 8
StudentInfo::StudentInfo(const string& lastname, const string& name, char* num)
{
   //auto info1 = make_tuple<const string&, const string&, const char*>(lastname, name, (char*)num);
    get<0>(info)=lastname;
    get<1>(info)=name;
    get<2>(info)=num;
}
int StudentInfo:: addMark(const string &subjName, int mark)
{
    if(subjMark.count(subjName) > 0)
    {
        map <string, std::pair<std::list<int>, float>> :: iterator it;
        it = subjMark.find(subjName);
        float temp = it->second.second;
        int klv = it->second.first.size();
        it->second.first.push_back(mark);
        temp = (temp*klv + mark)/(klv+1);
        it->second.second = temp;
        return 0;

    }
    else
    {
        return 1;
    }
}

int StudentInfo::addSubj(const string &subjName)
{
    if(subjMark.count(subjName) < 1)
    {
        subjMark[subjName];
        return 0;
    }
    else
    {
        return 1;
    }
}

float StudentInfo::getAverMark(const string& subjName)
{
    map <string, std::pair<std::list<int>, float>> :: iterator it;
    it = subjMark.find(subjName);
    return it->second.second;
}

void StudentInfo::printInfoStudent()
{
    string sur = get<0>(info);
    string nam = get<1>(info);
    string nom = get<2>(info);

    cout << sur << " " << nam << " : " << nom << endl;
    auto iter = subjMark.begin();
    while(iter != subjMark.end())
    {
        cout << iter->first << " :  ";
        auto it = iter->second.first.begin();
        for(;it != iter->second.first.end(); it++)
        {
            cout << *it << " ";
        }
        cout << " -- " << iter->second.second << endl;
        iter++;
    }
}

void StudentInfo::writeAllInfoToFile()
{
    ofstream fout;
    fout.open("Student.txt");
    string sur = get<0>(info);
    string nam = get<1>(info);
    string nom = get<2>(info);

    fout << sur << " " << nam << " : " << nom << endl;
    auto iter = subjMark.begin();
    while(iter != subjMark.end())
    {
        fout << iter->first << " :  ";
        auto it = iter->second.first.begin();
        for(;it != iter->second.first.end(); it++)
        {
            fout << *it << " ";
        }
        fout << " -- " << iter->second.second << endl;
        iter++;
    }

    fout.close();
}
