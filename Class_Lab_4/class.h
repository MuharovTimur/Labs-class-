#pragma once
#include <iostream>
using namespace std;

class PAIR
{
 protected:
    int first;
    int second;
 public:
    PAIR();
    PAIR(int, int);
    PAIR(const PAIR&);
    virtual ~PAIR();
    
    void setfirst(int);
    void setsecond(int);
    int getfirst();
    int getsecond();
    
    PAIR &operator =(const PAIR&);
    friend istream &operator >>(istream&in, PAIR&p);
    friend ostream &operator <<(ostream&out, const PAIR&p);
    
    void check_pair();
    int multi_pair();
    int sub_pair(int,int);
    virtual int sub(PAIR&);
};

class RATIONAL:public PAIR
{
 protected:
    int numerator;
    int denominator;
 public:
    RATIONAL();
    RATIONAL(int, int, int, int);
    RATIONAL(const RATIONAL&);
    ~RATIONAL();
    
    void setnum(int);
    void setden(int);
    int getnum();
    int getden();
    
    RATIONAL &operator =(const RATIONAL&);
    friend istream &operator >>(istream&in, RATIONAL&r);
    friend ostream &operator <<(ostream&out, const RATIONAL&r);
    
    bool check_den(int,int);
    RATIONAL sub(RATIONAL&);
    RATIONAL add(RATIONAL&);
    RATIONAL multi(RATIONAL&);
};
