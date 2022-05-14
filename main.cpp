#include <QCoreApplication>
#include <iostream>
#include <QDebug>
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

void test4();
void test5();
void test6();
void test7();
void test8();


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    int c;
    cout << "Kakyu task vi hotite protestirovat' ?" << endl;
    cin >> c;
    while(c != 0)
    {
        switch(c)
        {
        case 4 :
            test4();
            c = -1;
            break;
        case 5 :
            test5();
            c = -1;
            break;
        case 6 :
            test6();
            c = -1;
            break;
        case 7 :
            test7();
            c = -1;
            break;
        case 8 :
            test8();
            c = -1;
            break;
        case -1 :
            cout << "Kakyu task vi hotite protestirovat' ?" << endl;
            cin >> c;
            break;
        }
    }
    return a.exec();
}


void test4()
{
    cout << "Test of task 4: " << endl;
    cout << "Kakoi visoti elky mne sdelat?" << endl;
    int n;
    cin >> n;
    task4(n);
    cout << endl << endl << endl;
}

void test5()
{
    cout << "Test of task 5: " << endl;
    int A[4][3] = {
        {8, 2, 3},
        {21, 24, 30},
        {0, 0, 1},
        {1, 2, 3}
      };
    QList<double> T = task5(*A, 3, 4);
    for(int i = 0; i < T.length(); i++)
    {
        cout << "Average " << i+1 << ": " << T.at(i) << endl;
    }

    cout << endl << endl << endl;
}

void test6()
{
    LinkedList test;
    int myData = 1;
    test.push_back(myData);

    myData = 2;
    test.push_back(myData);

    myData = 3;
    test.push_back(myData);

    cout << "Spisok: " << endl;
    test.print();
    int m;
    cout << "S kakoy storony oboiti spisok dlya zapisi?" << endl;
    cout << "write \"1\" - from begin, \"2\" - from end, \"0\" - to stop" << endl;
    cin >> m;
    while(m!= 0)
    {
        switch(m)
        {
           case 1 :
            test.writeToFileFromHead("ResultFromHead.txt");
            cout << "Dara write: OK. Check file \"ResultFromHead.txt\"" << endl;
            m = -1;
            break;

        case 2 :
            test.writeToFileFromTail("ResultFromTail.txt");
            cout << "Dara write: OK. Check file \"ResultFromTail.txt\"" << endl;
            m = -1;
            break;
        case -1 :
            cout << "S kakoy storony oboiti spisok dlya zapisi?" << endl;
            cout << "write \"1\" - from begin, \"2\" - from end, \"0\" - to stop" << endl;
            cin >> m;
            break;
        }
    }


}

void test7()
{
    LinkedList test;
    int myData;
    myData = 1;
    test.push_back(myData);

    myData = 2;
    test.push_back(myData);

    myData = 3;
    test.push_back(myData);

    myData = 11;
    test.insert(myData, 2);

    test.print();
}

void test8()
{
    StudentInfo test("Ivanov", "Ivan", "1453");
    int i = test.addSubj("Maths");
    test.addMark("Maths", 5);
    test.addMark("Maths", 4);
    int i1 = test.addSubj("C++");
    test.addMark("C++", 5);
    test.addMark("C++", 3);
    test.addMark("C++", 3);
    test.printInfoStudent();
    test.writeAllInfoToFile();
}
