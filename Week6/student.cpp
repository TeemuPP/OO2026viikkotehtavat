#include "student.h"
using namespace std;

Student::Student(string n, int a)
{
    name = n;
    age = a;

}

void Student::setAge(int a)
{
    age = a;
}

void Student::setName(string n)
{
    name = n;
}

string Student::getName()
{
    return name;
}

int Student::getAge()
{
    return age;
}

void Student::printStudentInfo()
{
    cout<<"Opiskelijan nimi ja ika: "<<getName()<<" "<<getAge()<<endl;
}
