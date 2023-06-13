#include <iostream>
#include <string>
using namespace std;
class student {
	friend class teacher;// делаем класс студента дружественным к учителю, чтобы учитель мог измен€ть параметры private: // приватные переменные возраст, им€, оценка, чтобы пользователь не мог изменить их
private:
	int age; 
	string name; 
	int grade;
public:
	student(string n, int a, int g) {
		this->age = a;
		this->grade = g;
		this->name = n;
	}
	void setg(int g)//сеттер оценки, сократим
	{
		this->grade = g;
	}
	int getg()//геттер оценки
	{
		return grade;//вернем значение оценки
	}
	void Whatsyourname() {
		cout << "My name: " << name << endl;
	}
	void ages() {
		cout << "My age: " << age << endl;
	}
	void yourgrade() {
		cout << "My grade: " << grade << endl;
	}
	static int count_of_students;//статическа€ переменна€ количества студентов
	student() {
		count_of_students++;
	}
	static void n_b() {
		count_of_students++;
	}
};
 class teacher 
 {
 public:
	 void msg(student& student, int newgrade)//ссылка на студента. нова€ оценка задаетс€ сама
	 {
		 student.setg(newgrade);
	 }
 };
 int student::count_of_students = 0; 
 int main() {
	 student A("Andrey", 19, 5);
	 A.Whatsyourname();
	 A.ages();
	 A.yourgrade();
 }

