#ifndef PERSON_H_INCLUDED
#define PERSON_H_INCLUDED

#include <iostream>
#include <string>
#include "Arm.h"

class Person
{
    public:

    Person();
     Person(std::string armName,int armDegat);
    ~Person();
    void receiveDegat(int degatNbr);
    void attack(Person &target);
    void haveLifePortion(int portionQuantity);
    void armChange(std::string newArmName,int newArmDegat);
    bool isAlive() const;
    void stateDisplay() const;

    private:

    int m_life;
    int m_mana;
    Arm m_arm;
};

#endif // PERSON_H_INCLUDED
