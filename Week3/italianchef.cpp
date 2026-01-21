#include "italianchef.h"
#include <iostream>
#include "chef.h"
#include <string>
using namespace std;

ItalianChef::ItalianChef(string chefName) : Chef(chefName)
{
   cout<<"ItalianChef "<<chefName<<" konstruktori"<<endl;
}

ItalianChef::~ItalianChef()
{
    cout<<"ItalianChef "<<chefName<< " destruktori"<<endl;
}

bool ItalianChef::askSecret(string salasana, int jauho, int vesi)
{

    if ((password.compare(salasana)) == 0)
    {
        cout << "PASSWORD OK!" << endl;
        makepizza(jauho,vesi);
        return true;
    }
    else
        cout << "WRONG PASSWORD!" << endl;
        return false;

}

int ItalianChef::makepizza(int a, int b)
{
    int pizzaMin = min(a,b) / 5;
    cout<<"Chef Mario with "<<a<<" flour and "<<b<<" water can make "<<pizzaMin<<" pizzas"<<endl;
    return pizzaMin;

}
