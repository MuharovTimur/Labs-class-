#include <iostream>
#include "class.h"
using namespace std;

Object::Object()
{
    
}

Object::~Object()
{
    
}

Vector::Vector()
{
    beg=0;
    size=0;
    cur=0;
}

Vector::Vector(int n)
{
    beg=new Object*[n];
    cur=0;
    size=n;
}

Vector::~Vector()
{
    if(beg!=0)
      delete[] beg;
    beg=0;
}

void Vector::Add(Object *p)
{
    if(cur<size)
    {
        beg[cur]=p;
        cur++;
    }
}

ostream& operator<<(ostream&out, const Vector&v)
{
    if(v.size==0)
      out << "Пусто" << endl;
    Object **p=v.beg;
    for(int i=0;i<v.cur;i++)
    {
        (*p)->show();
        p++;
    }
    return out;
}

PAIR::PAIR()
{
    first=0;
    second=0;
    
    //cout << "Сработал конструктор без параметров(PAIR)" << endl;
}

PAIR::PAIR(int newf, int news)
{
    first=newf;
    second=news;
    
    //cout << "Сработал конструктор с параметрами(PAIR)" << endl;
}

PAIR::PAIR(const PAIR &pair)
{
    first=pair.first;
    second=pair.second;
    
   //cout << "Сработал копирования(PAIR)" << endl;
}

PAIR::~PAIR()
{
    //cout << "Сработал деструктор(PAIR)" << endl;
}

void PAIR::setfirst(int one)
{
    first=one;
}

void PAIR::setsecond(int two)
{
    second=two;
}

int PAIR::getfirst()
{
    return first;
}

int PAIR::getsecond()
{
    return second;
}

PAIR&PAIR::operator=(const PAIR&p)
{
    if(&p==this)
        return *this;
    first=p.first;
    second=p.second;
    
    //cout << "Сработала перегрузка оператора присваивания(PAIR)" << endl;
    return *this;
}

istream&operator>>(istream&in, PAIR&p)
{
    cout << "Первое число:"; 
    in>>p.first;
    cout << "Второе число:"; 
    in>>p.second;
    
    //cout << "Сработала перегрузка оператора ввода(PAIR)" << endl;
    return in;
}

ostream&operator<<(ostream&out, const PAIR&p)
{
    out << "Первое число:" << p.first << endl;
    out << "Второе число:" << p.second << endl;
    
   //cout << "Сработала перегрузка оператора вывода(PAIR)" << endl;
    return out;
}

void PAIR::check_pair()
{
    if (first==second)
       cout << "Числа равны" << endl;
    else  cout << "Числа не равны" << endl; 
}

int PAIR::multi_pair()
{
    int rez;
    rez=first*second;
    return rez;
}

int PAIR::sub_pair(int f,int s)
{
    int rez;
    rez=f-s;
    return rez;
}

int PAIR::sub(PAIR &p)
{
    int a,b,rez;
    a=sub_pair(first,second);
    b=sub_pair(p.first,p.second);
    rez=a-b;
    return rez;
}

void PAIR::show()
{
    cout << "Первое число:" << first << endl;
    cout << "Второе число:" << second << endl;
}

RATIONAL::RATIONAL():PAIR()
{
    numerator=0;
    denominator=0;
    
    //cout << "Сработал конструктор без параметров(RATIONAL)" << endl;
}

RATIONAL::RATIONAL(int newf, int news,int newnum, int newden):PAIR(newf,news)
{
    numerator=newnum;
    denominator=newden;
    
    //cout << "Сработал конструктор с параметрами(RATIONAL)" << endl;
}

RATIONAL::RATIONAL(const RATIONAL &rat)
{
    first=rat.first;
    second=rat.second;
    numerator=rat.numerator;
    denominator=rat.denominator;
    
    //cout << "Сработал копирования(RATIONAL)" << endl;
}

RATIONAL::~RATIONAL()
{
    //cout << "Сработал деструктор(RATIONAL)" << endl;
}

void RATIONAL::setnum(int num)
{
    numerator=num;
}

void RATIONAL::setden(int den)
{
    denominator=den;
}

int RATIONAL::getnum()
{
    return numerator;
}

int RATIONAL::getden()
{
    return denominator;
}

RATIONAL&RATIONAL::operator=(const RATIONAL&r)
{
    if(&r==this)
        return *this;
    first=r.first;
    second=r.second;
    numerator=r.numerator;
    denominator=r.denominator;
    
    //cout << "Сработала перегрузка оператора присваивания(RATIONAL)" << endl;
    return *this;
}

istream&operator>>(istream&in, RATIONAL&r)
{
    cout << "Первое число:"; 
    in>>r.first;
    cout << "Второе число:"; 
    in>>r.second;
    cout << "Числитель:"; 
    in>>r.numerator;
    cout << "Знаменатель:"; 
    in>>r.denominator;
    
    //cout << "Сработала перегрузка оператора ввода(RATIONAL)" << endl;
    return in;
}

ostream&operator<<(ostream&out, const RATIONAL&r)
{
    out << "Первое число:" << r.first << endl;
    out << "Второе число:" << r.second << endl;
    out << "Числитель:" << r.numerator << endl;
    out << "Знаменатель:" << r.denominator << endl;
    
    //cout << "Сработала перегрузка оператора вывода(RATIONAL)" << endl;
    return out;
}

bool RATIONAL:: check_den(int den1,int den2)
{
    if(den1==den2)
       return true;
    else return false;
}

RATIONAL RATIONAL:: sub(RATIONAL&r)
{
    RATIONAL temp;
    if(check_den(denominator,r.denominator)==true)
    {
        temp.numerator=numerator-r.numerator;
        temp.denominator=denominator;
    }
    else
    {
        temp.numerator=numerator*r.denominator-r.numerator*denominator;
        temp.denominator=denominator*r.denominator;
    }
    temp.first=temp.numerator;
    temp.second=temp.denominator;
    return temp;
}

RATIONAL RATIONAL:: add(RATIONAL&r)
{
    RATIONAL temp;
    if(check_den(denominator,r.denominator)==true)
    {
        temp.numerator=numerator+r.numerator;
        temp.denominator=denominator;
    }
    else
    {
        temp.numerator=numerator*r.denominator+r.numerator*denominator;
        temp.denominator=denominator*r.denominator;
    }
    temp.first=temp.numerator;
    temp.second=temp.denominator;
    return temp;
}

RATIONAL RATIONAL:: multi(RATIONAL&r)
{
    RATIONAL temp;
    temp.numerator=numerator*r.numerator;
    temp.denominator=denominator*r.denominator;
    temp.first=temp.numerator;
    temp.second=temp.denominator;
    return temp;
}

void RATIONAL::show()
{
    cout << "Первое число:" << first << endl;
    cout << "Второе число:" << second << endl; 
    cout << "Числитель:" << numerator << endl; 
    cout << "Знаменатель:" << denominator << endl; 
}
