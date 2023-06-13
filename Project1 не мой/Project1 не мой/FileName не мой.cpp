#include<iostream>
#include<string>
#include<conio.h>
using namespace std;
class student // создаем класс студент
{
    friend class teacher;//делаем класс студента дружественным к учитель, дабы учитель мог изменять параметры
private: // приватные переменные имя, возраст, оценка, дабы пользователь не мог изменить их
    string name;
    int age;
    int grade;

public: // делаем класс публичным вне самого класса
    student(string n, int a, int g) // задаем формальные параметры имя, возраст, оценка
    {
        this->name = n;
        this->age = a;
        this->grade = g; // сокращаем переменные
    }

    void setg(int g)//сеттер оценки и сокращаем
    {
        this->grade = g;
    }

    int getg()//геттер оценки
    {
        return grade;//возвращаем значение оценки
    }

    void whoru()// выводит информацию о ученике
    {
        cout << "My name: " << name << endl;
        cout << "My age: " << age << endl;
        cout << "My usually grade: " << grade << endl;
    }
    void im() {
        cout << "My name is " << name << endl;//выводит имя ученика
    }
    void whatuwant() {
        cout << name << ':' << " I want to go home:((((" << endl;//выводит желание ученика?
    }
    static int count_of_students;//статическая переменная количества студентов
    student() {
        count_of_students++;
    }
    static void n_b() {
        count_of_students++;
    }
};

class teacher//создаем класс учитель
{
public:
    void msg(student& student, int newgrade)//ссылка на студента и задается сама новая оценка
    {
        student.setg(newgrade);
    }
};
int student::count_of_students = 0; // должно быть определено вне класса, чтобы никто не жаловался(((
int main() {

    student a("ReN", 15, 6);
    int w;
    a.n_b();
    a.whoru();
    a.im();
    a.whatuwant();
    system("cls");//очищает консоль от предыдущей информации, загуглено
    cout << "Dialogue with a Student" << endl << "actions:" << endl << "1:" << "whats ur name?" << endl << "2:" << "tell abt you." << endl << "3:" << "what you want?" << endl;
    cin >> w;
    if (w == 1) {
        a.im();
    };
    if (w == 2) {
        a.whoru();
    };
    if (w == 3) {
        a.whatuwant();
    };
    cout << student::count_of_students << " - number of students" << endl;
}//ReN