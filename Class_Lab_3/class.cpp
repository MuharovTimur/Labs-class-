#include <iostream>
#include "class.h"
using namespace std;

Money::Money()
{
    rubles=0;
    kopecks=0;
}

Money::Money(long newr, int newk)
{
    rubles=newr;
    kopecks=newk;
}

Money::Money(const Money &money)
{
    rubles=money.rubles;
    kopecks=money.kopecks;
}

Money::~Money()
{
    
}

void Money::setrub(long Rub)
{
    rubles=Rub;
}

void Money::setkop(int Kop)
{
    kopecks=Kop;
}

long Money::getrub()
{
    return rubles;
}

int Money::getkop()
{
    return kopecks;
}

Money&Money::operator=(const Money&m)
{
    if(&m==this)
    return *this;
    rubles=m.rubles;
    kopecks=m.kopecks;
    return *this;
}

Money Money::operator/(const Money&m)
{
    int temp1=rubles*100+kopecks;
    int temp2=m.rubles*100+m.kopecks;
    Money p;
    p.rubles=temp1/temp2;
    p.kopecks=temp1%temp2;
    return p;
}

Money Money::operator*(const Money&m)
{
    int temp1=rubles*100+kopecks;
    int temp2=m.rubles*100+m.kopecks;
    Money p;
    p.rubles=(temp1*temp2)/10000;
    p.kopecks=(temp1*temp2)%10000;
    return p;
}

istream&operator>>(istream&in, Money&m)
{
    cout << "Рубли:"; 
    in>>m.rubles;
    cout << "Копейки:"; 
    in>>m.kopecks;
    return in;
}

ostream&operator<<(ostream&out, const Money&m)
{
    return (out << m.rubles << "," << m.kopecks);
}