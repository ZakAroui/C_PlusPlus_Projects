#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
    string const flname("score.txt",ios::app);
    ofstream stream1(flname.c_str());
    cout<<"what's your age??"<<endl;
    int b(0);
    cin>>b;
    if (stream1)
    {
        stream1 <<"salam, i'm the new editor"<<endl;
        int a(12);
        stream1 <<a<<" is a number"<<endl;
        stream1 <<"1st age is: "<<b<<endl;
    }
    else
    {
        cout<<"error: can't open the file"<<endl;
    }
    return 0;
}
