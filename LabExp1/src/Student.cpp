#include "Student.h"
#include <iostream>
using namespace std;
void Developer2::Student::setStudent(string _name, int _id) // Student sınıfını Developer2 isim alanından kullandık
{
	name=_name;
	id=_id;
}



int Developer2::Student::calculateGrade(){
	return midTermExam + finalExam / 2;
}

void Developer2::Student::print()
{

	cout<<"Name : "<<name<<endl;
	cout<<"ID   : "<<id<<endl;
	cout<<"ID   : "<<calculateGrade()<<endl;

}
