#pragma once
#include <iostream>
using namespace std;

class Money
{
 private:
    long rubles;
    int kopecks;
 public:
    Money();
    Money(long, int);
    Money(const Money&);
    ~Money();
    
    void setrub(long);
    void setkop(int);
    long getrub();
    int getkop();
    
    Money &operator =(const Money&);
    Money operator/(const Money&);
    Money operator*(const Money&);
    friend istream &operator >>(istream&in, Money&m);
    friend ostream &operator <<(ostream&out, const Money&m); 
};