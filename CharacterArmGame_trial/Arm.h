#ifndef ARM_H_INCLUDED
#define ARM_H_INCLUDED

#include <iostream>
#include <string>

class Arm
{
    public:
    Arm();
    Arm(std::string name,int degat);
    void change(std::string name,int degat);
    void display() const;
    int getDegat() const;

    private:
    std::string m_name;
    int m_degat;
};

#endif // ARM_H_INCLUDED
