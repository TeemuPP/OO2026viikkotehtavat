#include <iostream>
#include "luottotili.h"
#include "pankkitili.h"
#include "asiakas.h"


using namespace std;

int main()
{

    Asiakas a("Aapeli",1000);
    a.talletus(250);
    cout<<"Pankkitili: talletus 250 tehty"<<endl;

    a.luotonNosto(150);
    cout << "Luottotili: nosto 150 tehty, luottoa jaljella "<< 850 << "\n";
    a.showSaldo();
    cout<<"\n";
    Asiakas b("Bertta",1000);
    b.showSaldo();
    cout<<"\n";
    cout<<"Aapeli"<<endl;
    a.showSaldo();
    cout<<"Pankkitili: Aapeli siirtaa 50 Bertta:lle"<<endl;

    a.tiliSiirto(50,b);
    cout<<"Aapeli Pankkitili: nosto 50 tehty"<<endl;
    cout<<"Bertta Pankkitili: talletus 50 tehty"<<endl;

    cout<<"\n";
    cout<<"Bertta"<<endl;
    b.showSaldo();



}
