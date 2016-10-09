#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
    ifstream stream2;
    stream2.open("data.txt");
    stream2.seekg(10,ios::beg);
    int position= stream2.tellg();
    cout<<"position is "<<position<<endl;
    stream2.seekg(0,ios::end);
    int ps=stream2.tellg();
    cout<<"file has a quantity of "<<ps<<"characters."<<endl;
    if (stream2)
    {
       char a;
       stream2.get(a);
       cout<<a<<endl;

       string line;
       while(getline(stream2,line))
       {
           cout<<line<<endl;
       }

       double nbr;
       stream2>>nbr;

       string word1;
       stream2>>word1;
    }
    else
    {
        cout<<"error: can't open the file"<<endl;
    }
    stream2.close();
    return 0;
}
