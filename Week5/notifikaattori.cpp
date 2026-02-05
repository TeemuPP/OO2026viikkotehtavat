#include "notifikaattori.h"

Notifikaattori::Notifikaattori()
{
    cout<<"Luodaan notifikaattori"<<endl;
}

void Notifikaattori::lisaa(Seuraaja *nimi)
{
    cout<<"Notifikaattori lisaa seuraajan "<<nimi->getNimi()<<endl;
    nimi->next = seuraajat;
    seuraajat = nimi;
}

void Notifikaattori::poista(Seuraaja *pois)
{
    if(seuraajat == pois)
    {
        seuraajat = seuraajat->next;
        cout<<"Notifikaattori poistaa seuraajan "<<pois->getNimi()<<endl;
        return;
    }

    Seuraaja *now = seuraajat;
        while(now->next)
        {
        if(now->next==pois)
            {
                now->next = pois->next;
                cout<<"Notifikaattori poistaa seuraajan "<<pois->getNimi()<<endl;
                return;
            }
        now = now->next;
        }
}

void Notifikaattori::tulosta()
{
    cout<<"Notifikaattorin seuraajat: "<<endl;
    Seuraaja *now = seuraajat;
    while(now != nullptr)
    {
        cout<<"Seuraaja "<<now->getNimi()<<endl;
        now = now->next;
    }
}

void Notifikaattori::postita(string viesti)
{
    cout<<"Notifikaattori postaa viestin "<<viesti<<endl;
    Seuraaja *now = seuraajat;
    while(now != nullptr)
    {
        now->paivitys(viesti);
        now=now->next;
    }
}



