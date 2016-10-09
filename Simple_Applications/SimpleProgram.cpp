#include<iostream>
#include<string>
#include<cmath>
using namespace std;
 int main()
 {
     cout<<"how much did u get in economic engineering???"<< endl ;
     double mark(0);
     cin >>mark ;
     cin.ignore();
     cout<<"hi there what's u r name"<< endl;
     string name("blank");
     getline(cin,name);
     cout <<"so "<<name<<" you get "<<mark<< endl ;
     cout<<"enter a and b"<<endl;
     int a(0),b(0);
     cin>>a; cin>>b;
     int const s(a+b),d(a/b),p(a*b),sb(a-b),m(a%b);
     cout<<"do u know that:"<<endl;
     cout<<a<<"+"<<b<<"="<<s<<endl<<a<<"-"<<b<<"="<<sb<<endl<<a<<"*"<<b<<"="<<p<<endl<<a<<"/"<<b<<"="<<d<<endl<<a<<" mod "<<b<<"="<<m<<endl;
     ++a;
     --b;
     cout<<"now, a is "<<a<<endl;
     cout<<"now, b is "<<b<<endl;
     a +=4;
     cout<<"a is "<<a<<endl;
     double sr(0),cs(0);
     sr=sqrt(a);
     cs=cos(b);
     cout<<"square root of a= "<<sr<<endl;
     cout<<"cosine of b ="<<cs<<endl;
     return 0;
 }
