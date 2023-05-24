#pragma once
#include <iostream>
using namespace std;

class Iterator
{
    friend class Plenty;
    
  private:
    int*elem;
  public:
    Iterator();
    Iterator(const Iterator&it);
    
    bool operator==(const Iterator&it);
    bool operator!=(const Iterator&it);
    void operator++();
    void operator--();
    int&operator*()const;
};

class Plenty
{
  private:
    int size;
    int *data;
    Iterator beg;
    Iterator end;
  public:
    Plenty(int s);
    Plenty(const Plenty&a);
    ~Plenty();
    
    Plenty&operator=(const Plenty&a);
    int&operator[](int index);
    Plenty operator+(const int k);
    int operator()();
    Plenty operator*(const Plenty&a);
    
    friend istream &operator >>(istream&in, Plenty&p);
    friend ostream &operator <<(ostream&out, const Plenty&p);
    
    Iterator first();
    Iterator last();
};
