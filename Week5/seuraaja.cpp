#include "seuraaja.h"

Seuraaja::Seuraaja(string n)
{
    nimi = n;
    cout<<"Luodaan seuraaja "<<n<<endl;
}

string Seuraaja::getNimi()
{
    return nimi;
}

void Seuraaja::paivitys(string viesti)
{
    cout<<"Seuraaja "<<nimi<<" sai viestin "<<viesti<<endl;
}
