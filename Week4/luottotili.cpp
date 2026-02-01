#include "luottotili.h"
#include <iostream>
using namespace std;

Luottotili::Luottotili(string name, double raja) : Pankkitili(name), luottoRaja(raja)
{
    saldo = raja;
    cout<<"Luottotili luotu "<<name<<":lle, "<<"luottoraja "<<luottoRaja<<endl;
}

bool Luottotili::deposit(double summa)
{
    if (summa <= 0) return false;

    saldo += summa;


    if (saldo > 0)
        saldo = 0;

    return true;
}

bool Luottotili::withdraw(double summa)
{
    if (summa <= 0) return false;


    if (saldo - summa < -luottoRaja)
        return false;

    saldo -= summa;
    return true;
}
