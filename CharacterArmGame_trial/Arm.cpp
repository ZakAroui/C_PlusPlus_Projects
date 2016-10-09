#include "Arm.h"

using namespace std;

Arm::Arm() : m_name("mkhada"),m_degat(10)
{

}
Arm::Arm(string name,int degat) : m_name(name),m_degat(degat)
{

}
void Arm::change(string name,int degat)
{
    m_name=name;
    m_degat=degat;
}
void Arm::display() const
{
    cout<<"Arm: "<<m_name<<" (degat: "<<m_degat<<")"<<endl;
}
int Arm::getDegat() const
{
    return m_degat;
}
