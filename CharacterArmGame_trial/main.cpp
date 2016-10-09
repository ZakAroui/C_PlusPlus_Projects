#include <iostream>
#include "Person.h"
#include "Arm.h"
#include <string>

using namespace std;

int main()
{
    Person ilyess,med("mkhada",20);

    med.attack(ilyess);
    ilyess.haveLifePortion(15);
    med.attack(ilyess);
    ilyess.attack(med);

    med.armChange("changla",40);
    med.attack(ilyess);

    cout<<"ilyess"<<endl;
    ilyess.stateDisplay();
    cout<<"med : "<<endl;
    med.stateDisplay();

    return 0;
}
