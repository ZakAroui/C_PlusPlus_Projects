#include "interval.h"

using namespace std;

interval::interval(int h,int m,int s) : m_h(h),m_m(m),m_s(s)
{

}
interval operator+(interval const& a,interval const& b)
{
    interval copie(a);
    copie+=b;
    return copie;
}
interval& interval::operator+=(const& interval &interv2)
{
    m_s+=interv2.m_s;
    m_m+=interv2.m_s/60;
    m_s%=60;
    m_m+=interv2.m_m;
    m_h+=interv2.m_m/60;
    m_m%=60;
    m_h+=interv2.m_h;
    return *this;
}
void interval::display() const
{
    cout<<m_h<<":"<<m_m<<":"<<m_s<<endl;
}
