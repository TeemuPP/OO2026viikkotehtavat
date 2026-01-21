#include "chef.h"
#include <string>
#include <iostream>
#include "italianchef.h"
using namespace std;

Chef::Chef(string s)
{
    chefName = s;
    cout<<"Konstruktori. Kokin nimi on "<<chefName<<endl;
}

Chef::~Chef()
{
    cout<<chefName<<" tuhoaja"<<endl;
}


int Chef::makeSalad(int aines1)
{
    int portion1 = aines1 / 5;

    cout<<"Chef "<<chefName<< " with "<<aines1<<" items can make "<<portion1<<" salad"<<endl;
    return aines1;
}

int Chef::makeSoup(int aines2)
{
    int portion2 = aines2 / 3;

    cout<<"Chef "<<chefName<<" with "<<aines2<<" items can make "<<portion2<<" soup"<<endl;
    return aines2;
}
