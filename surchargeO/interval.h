#ifndef INTERVAL_H_INCLUDED
#define INTERVAL_H_INCLUDED

class interval
{
    public:

    interval(int h=0,int m=0,int s=0);
    interval operator+(interval const& a,interval const& b);
    interval& operator+=(interval const& interval);
    void display() const;

    private:

    int m_h;
    int m_m;
    int m_s;
};

#endif // INTERVAL_H_INCLUDED
