#include "asiakas.h"
#include <iostream>

using namespace std;

Asiakas::Asiakas(string nimi, double luottoRaja) : kayttotili(nimi), luottotili(nimi, luottoRaja)
{

    cout<<"Asiakkuus luotu "<<nimi<<":lle"<<endl;
}

string Asiakas::getNimi()
{
    Pankkitili omistaja = nimi;
    return nimi;
}

void Asiakas::showSaldo()
{

    cout<<"Pankkitilin saldo: "<<kayttotili.getBalance()<<endl;
    cout<<"Luottotilin saldo: "<<luottotili.getBalance()<<endl;
}

bool Asiakas::talletus(double s)
{
    return kayttotili.deposit(s);
}

bool Asiakas::nosto(double s)
{
    return kayttotili.withdraw(s);
}

bool Asiakas::luotonMaksu(double s)
{
    return luottotili.deposit(s);
}

bool Asiakas::luotonNosto(double s)
{
    return luottotili.withdraw(s);
}

bool Asiakas::tiliSiirto(double summa, Asiakas &c)
{
    if (!kayttotili.withdraw(summa))
        return false;

    return c.kayttotili.deposit(summa);
}


