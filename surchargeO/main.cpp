#include <iostream>
#include "interval.h"

using namespace std;

int main()
{
    interval interv1(0,10,28),interv2(0,15,2);
    interval result;

    interv1.display();
    cout<<"+"<<endl;
    interv2.display();

    result = interv1+interv2;

    cout<<"="<<endl;
    result.display();

    return 0;
}
