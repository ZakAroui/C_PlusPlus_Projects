#include "Person.h"

using namespace std;

Person::Person() :m_life(100),m_mana(100)
{

}
Person::Person(string armName,int armDegat) : m_life(100),m_mana(100),m_arm(armName,armDegat)
{

}
Person::~Person()
{

}
void Person::receiveDegat(int degatNbr)
{
    m_life-= degatNbr;
    if (m_life<0)
    {
        m_life=0;
    }
}
void Person::attack(Person &target)
{
    target.receiveDegat(m_arm.getDegat());
}
void Person::haveLifePortion(int portionQuantity)
{
    m_life+= portionQuantity;
    if (m_life>100)
    {
        m_life=100;
    }
}
void Person::armChange(string newArmName,int newArmDegat)
{
    m_arm.change(newArmName,newArmDegat);
}
bool Person::isAlive() const
{
    if (m_life>0)
    {
        return true;
    }
    else
    {
        return false;
    }
}
void Person::stateDisplay() const
{
    cout<<"life : "<<m_life<<endl;
    cout<<"mana : "<<m_mana<<endl;
    m_arm.display();
}
