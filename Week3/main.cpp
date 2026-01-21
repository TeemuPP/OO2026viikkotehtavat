#include <iostream>
#include "chef.h"
#include "italianchef.h"
#include <string>

using namespace std;

int main()
{
    Chef Chef("Gordon");
    Chef.makeSalad(11);
    Chef.makeSoup(14);
    ItalianChef ItalianChef("Mario");
    ItalianChef.makeSalad(11);
    ItalianChef.askSecret("pizza",10,10);

    return 0;
}
