#include<iostream>
#include<string>
#include<conio.h>
using namespace std;
class student // ������� ����� �������
{
    friend class teacher;//������ ����� �������� ������������� � �������, ���� ������� ��� �������� ���������
private: // ��������� ���������� ���, �������, ������, ���� ������������ �� ��� �������� ��
    string name;
    int age;
    int grade;

public: // ������ ����� ��������� ��� ������ ������
    student(string n, int a, int g) // ������ ���������� ��������� ���, �������, ������
    {
        this->name = n;
        this->age = a;
        this->grade = g; // ��������� ����������
    }

    void setg(int g)//������ ������ � ���������
    {
        this->grade = g;
    }

    int getg()//������ ������
    {
        return grade;//���������� �������� ������
    }

    void whoru()// ������� ���������� � �������
    {
        cout << "My name: " << name << endl;
        cout << "My age: " << age << endl;
        cout << "My usually grade: " << grade << endl;
    }
    void im() {
        cout << "My name is " << name << endl;//������� ��� �������
    }
    void whatuwant() {
        cout << name << ':' << " I want to go home:((((" << endl;//������� ������� �������?
    }
    static int count_of_students;//����������� ���������� ���������� ���������
    student() {
        count_of_students++;
    }
    static void n_b() {
        count_of_students++;
    }
};

class teacher//������� ����� �������
{
public:
    void msg(student& student, int newgrade)//������ �� �������� � �������� ���� ����� ������
    {
        student.setg(newgrade);
    }
};
int student::count_of_students = 0; // ������ ���� ���������� ��� ������, ����� ����� �� ���������(((
int main() {

    student a("ReN", 15, 6);
    int w;
    a.n_b();
    a.whoru();
    a.im();
    a.whatuwant();
    system("cls");//������� ������� �� ���������� ����������, ���������
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