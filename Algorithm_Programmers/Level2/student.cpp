#include <iostream>
using namespace std;
class Student
{
	int no;
	string name;
	int kor, mat, eng;
	int total;
	double avg;
public:
	void calculate();
	void print();
	Student(int n, string na, int k, int m, int e);
};

Student::Student(int n, string na, int k, int m, int e)
{
	no = n;
	name = na;
	kor = k;
	mat = m;
	eng = e;
	calculate();
}

void Student::calculate()
{
	total = kor + mat + eng;
	avg = total / 3.0;
}

void Student::print()
{
	cout << no << "\t" << "\t" << name << "\t" << kor << "\t" << mat << "\t" << eng << "\t" << total << "\t" << avg << endl;
}

void main()
{
	Student student1(1, "Ȳ����", 99, 80, 95);
	Student student2(2, "�̹ο�", 60, 90, 90);
	Student student3(3, "�����", 85, 70, 90);
	cout << "�л���ȣ   �̸�   ����   ����   ����   ����      ���\n";
	student1.print();
	student2.print();
	student3.print();
}