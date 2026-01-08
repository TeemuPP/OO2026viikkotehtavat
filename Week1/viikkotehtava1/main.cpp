#include <cstdlib>
#include <ctime>
#include <iostream>

using namespace std;


int game(int maxnum)
{
    int arvottuLuku;
    int arvaus;
    int arvaustenMaara = 1;


    std::srand(std::time(nullptr));
    int satunnainen = std::rand() % maxnum + 1;

    arvottuLuku = satunnainen;

    cout<<"Arvaa luku: "<<endl;
    cin>>arvaus;

    while(arvaus != arvottuLuku)
    {
        if(arvaus > arvottuLuku)
        {
            cout<<"Liian suuri"<<endl;
            cout<<"Uusi arvaus: "<<endl;
            cin>>arvaus;
            arvaustenMaara++;
        }
        else if (arvaus < arvottuLuku)
        {
            cout<<"Liian pieni"<<endl;
            cout<<"Uusi arvaus: "<<endl;
            cin>>arvaus;
            arvaustenMaara++;
        }

    }  cout<<"Arvasit oikein"<<endl;

    return arvaustenMaara;
}

int main()
{
    while(1)
    {
    int arvaukset = game(40);
    cout<<"Arvasit "<<arvaukset<<" kertaa"<<endl;

    }
}
