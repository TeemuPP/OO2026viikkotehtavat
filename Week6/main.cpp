#include <iostream>
#include <vector>
#include <algorithm>
#include "student.h"

using namespace std;


int main ()
{
    int selection =0;
    vector<Student>studentList;
    int age;
    string name;

    do
    {
        cout<<endl;
        cout<<"Select"<<endl;
        cout<<"Add students = 0"<<endl;
        cout<<"Print all students = 1"<<endl;
        cout<<"Sort and print students according to Name = 2"<<endl;
        cout<<"Sort and print students according to Age = 3"<<endl;
        cout<<"Find and print student = 4"<<endl;
        cin>>selection;

        switch(selection)
        {
        case 0:
            // Kysy käyttäjältä uuden opiskelijan nimi ja ikä
            // Lisää uusi student StudentList vektoriin.
            cout<<"Syota uuden opiskelijan nimi: "<<endl;
            cin>>name;
            cout<<"Syota uuden opiskelijan ika: "<<endl;
            cin>>age;
            studentList.push_back(Student(name, age));
            break;
        case 1:
            // Tulosta StudentList vektorin kaikkien opiskelijoiden
            // nimet.
            for (auto student : studentList)
            {
                cout<<"Opiskelijan nimi: "<<student.getName()<<endl;
            }
            break;

        case 2:
            // Järjestä StudentList vektorin Student oliot nimen mukaan
            // algoritmikirjaston sort funktion avulla
            // ja tulosta printStudentInfo() funktion avulla järjestetyt
            // opiskelijat
            sort(studentList.begin(), studentList.end(),[](Student& a, Student& b){
                return a.getName() < b.getName();});

            cout<<"Opiskelijat jarjestyksessa nimen mukaan: "<<endl;
            for(auto student : studentList)
                {
                student.printStudentInfo();
                }
            break;

        case 3:
            // Järjestä StudentList vektorin Student oliot iän mukaan
            // algoritmikirjaston sort funktion avulla
            // ja tulosta printStudentInfo() funktion avulla järjestetyt
            // opiskelijat
            sort(studentList.begin(), studentList.end(),[](Student& a, Student& b){
                return a.getAge() > b.getAge();});

            cout<<"Opiskelijat jarjestyksessa ian mukaan: "<<endl;
            for(auto student : studentList)
            {
                student.printStudentInfo();
            }
            break;
        case 4:
        {
            // Kysy käyttäjältä opiskelijan nimi
            // Etsi studentListan opiskelijoista algoritmikirjaston
            // find_if funktion avulla löytyykö käyttäjän antamaa nimeä
            // listalta. Jos löytyy, niin tulosta opiskelijan tiedot.
            cout<<"Syota etsittavan opiskelijan nimi: "<<endl;
            cin>>name;
            auto it = find_if(studentList.begin(),studentList.end(),[name](Student& c){
                return name == c.getName();});

            if(it != studentList.end())
            {
                it->printStudentInfo();
            }
            else
            {
                cout<<"Opiskelijaa ei loytynyt"<<endl;
            }

            break;
        }
    default:
        cout<< "Wrong selection, stopping..."<<endl;
        break;
    }
}while(selection < 5);

return 0;
}
