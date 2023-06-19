#pragma once
#include <iostream>
using namespace std;

const int MAX_SIZE = 10;

class Plenty
{
  private:
    int size;
    int *beg;
  public:
    Plenty(int s);
    Plenty(int s, int* mas);
    Plenty(const Plenty&a);
    ~Plenty();
    
    Plenty&operator=(const Plenty&a);
    int&operator[](int i);
    int operator()();
    Plenty operator*(const Plenty&a);
    Plenty operator+(int a);
	Plenty operator--();
    
    friend istream &operator >>(istream&in, Plenty&p);
    friend ostream &operator <<(ostream&out, const Plenty&p);
};
