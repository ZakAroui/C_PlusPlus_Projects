#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>

using namespace std;

void random(string name)
{
   int a;
   a=name.size();
   for (int i(0);i<a;i++)
    {

        int pos;
        pos=rand()% name.size();
        cout<<name[pos];
        name.erase(pos,1);
    }
}

int main()
{
    srand(time(0));

    string name1;
    cout<<"enter a name:"<<endl;
    cin>>name1;

    cout<<"what is this name: ";
    random(name1);
    cout<<endl;
    string trying;

    do
    {
        cin>>trying;
        if (trying == name1)
        {
            cout<<"bravo!!"<<endl;
            break;
        }
        else
        {
            cout<<"it's not the write name!!"<<endl;

        }
    }while(trying.size()!=0);

    return 0;
}
