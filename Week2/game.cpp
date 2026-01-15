#include "game.h"
#include <ctime>
#include <iostream>
#include <cstdlib>

using namespace std;

Game::Game(int max)
{
    maxNumber = max;
    numOfGuesses = 1;

    srand(time(nullptr));
    randomNumber = rand() % maxNumber + 1;
}

Game::~Game()
{
    cout<<"GAME DESTRUCTOR: object cleared from stack memory"<<endl;
}


void Game::play()
{

    cout<<"GAME CONSTRUCTOR: object initialized with "<<maxNumber<<" as maximum value"<<endl;
    cout<<"Arvaa luku: "<<endl;
    cin>>playerGuess;

    while(playerGuess != randomNumber)
    {

        if(playerGuess > randomNumber)
        {
            cout<<"Liian suuri"<<endl;
            cout<<"Uusi arvaus: "<<endl;
            cin>>playerGuess;
            numOfGuesses++;
        }
        else if (playerGuess < randomNumber)
        {
            cout<<"Liian pieni"<<endl;
            cout<<"Uusi arvaus: "<<endl;
            cin>>playerGuess;
            numOfGuesses++;

        }
    } printGameResult();
}
void Game::printGameResult()
{
    cout<<"Arvasit oikein"<<endl;
    cout<<"Arvasit "<<numOfGuesses<<" kertaa"<<endl;
}
