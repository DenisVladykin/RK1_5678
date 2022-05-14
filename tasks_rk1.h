#ifndef TASKS_RK1_H
#define TASKS_RK1_H
#include <QList>
#include <tuple>
#include <map>
#include <string>
#include <iostream>

using namespace std;

void task4(int H_of_elka);
QList<double> task5(int* mas, int m, int n);
struct Node;
class LinkedList {
    private :
        Node* Head;
        Node* Tail;
        int count = 0;
    public :
        LinkedList();
        ~LinkedList();
        void push_back(int _nameNode);
        void writeToFileFromTail(const char* FileName);
        void writeToFileFromHead(const char* FileName);
        void print();
        void insert(int _nameNode, int posit);
};

class StudentInfo {
        private :
            std::tuple<string /*фамилия*/,string /*имя*/,char* /*№ студ билета*/> info;
            std::map<string/*название предмета*/, std::pair<std::list<int> /*список оценок*/, float /*средняя оценка*/>> subjMark;
        public :
            /*	desription	:	добавления отметки по выбранному предмету
                input		:	subjName - название предмета, mark -- оценка
                output		:	0 - оценка добавлена, 1 - нет такого предмета
                author		:
                date		:
            */
            int addMark(const string& subjName, int mark);
            /*	desription	:	добавления отметки по выбранному предмету
                input		:	subjName - название предмета
                output		:	0 - предмет добавлен, 1 - такой предмет уже есть
                author		:
                date		:

            */
            int addSubj(const string& subjName);
            /*	desription	:	добавления нового предмета
                input		:	subjName - название предмета
                output		:	среднее значение оценки
                author		:
                date		:
            */
            float getAverMark(const string& subjName);
            /*	desription	:	вычисления средней оценки по предметам
                input		:	subjName - название предмета
                output		:	среднее значение оценки
                author		:
                date		:
            */
            void printInfoStudent();
            /*	desription	:	запись данных в файл формат файла
                                    [Фамилия] [имя] : [номер билета]
                                        [предмет 1]	:	[оценка 1], [оценка 2],... [оценка N] -- [среднее значение]
                                        [предмет 2]	:	[оценка 1], [оценка 2],... [оценка N] -- [среднее значение]
                input		:	subjName - название предмета
                output		:	среднее значение оценки
                author		:
                date		:
            */
            void writeAllInfoToFile();

            StudentInfo(const string& lastname, const string& name, char* num);
    };

#endif // TASKS_RK1_H
