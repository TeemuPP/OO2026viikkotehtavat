#include "pankkitili.h"
#include <iostream>
using namespace std;


Pankkitili::Pankkitili(string name)
{
    omistaja = name;
    cout<<"Pankkitili luotu "<<omistaja<<":lle"<<endl;
}

double Pankkitili::getBalance()
{
    return saldo;
}

bool Pankkitili::deposit(double summa)
{

    if (summa <= 0)
    {
        return false;
    } else

    saldo = saldo+summa;
    return true;
}

bool Pankkitili::withdraw(double summa)
{

    if (summa < 0)
    {
        return false;
    } else

    saldo = saldo-summa;
    return true;
}
