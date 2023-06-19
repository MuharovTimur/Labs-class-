#pragma once
#include <iostream>
using namespace std;

template <class T>
class Plenty 
{
  private:
    int size;
    T *data;
  public:
    Plenty(int s,T k);
    Plenty(const Plenty<T>&a);
    ~Plenty();
    
    Plenty&operator=(const Plenty<T>&a);
    T&operator[](int index);
    Plenty operator+(const T k);
    int operator()();
    Plenty operator*(const Plenty<T>&a);
    
    template <class U> friend istream& operator>> (istream&in, Plenty<U>&p);
    template <class U> friend ostream& operator<< (ostream&out, const Plenty<U>&p);
};

template <class T>
Plenty<T>::Plenty(int s, T k)
{
    size=s;
    data=new T[size];
    for(int i=0;i<size;i++)
    {
        data[i]=k;
    }
}

template <class T>
Plenty<T>::Plenty(const Plenty<T>&a)
{
    size=a.size;
    data=new T[size];
    for(int i=0;i<size;i++)
    {
        data[i]=a.data[i];
    }
}

template <class T>
Plenty<T>::~Plenty()
{
    delete [] data;
    data=0;
}

template <class T>
Plenty<T>&Plenty<T>::operator=(const Plenty<T>&a)
{
    if(this==&a)
      return *this;
    size=a.size;
    if(data!=0)
      delete [] data;
    data=new T [size];
    for(int i=0;i<size;i++)
    {
        data[i]=a.data[i];
    }
    return *this;
}

template <class T>
T&Plenty<T>::operator[](int index)
{
    if(index<size)
      return data[index];
    else
      cout << "Ошибка! index>size";
}

template <class T>
Plenty<T> Plenty<T>::operator+(const T k)
{
    Plenty<T> temp(size,k);
    for(int i=0;i<size;i++)
    {
        temp.data[i]=data[i]+k;
    }
    return temp;
}

template <class T>
int Plenty<T>::operator()()
{
    return size;
}

template <class T>
Plenty<T> Plenty<T>::operator*(const Plenty<T>&a)
{
    int l=0;
    for(int i=0;i<size;i++)
    {
        for(int j=0;j<size;j++)
        {
            if(data[i]==a.data[j])
            {
                l++;
            }
        }
    }
    Plenty <T>temp(l,0);
    l=0;
    for(int i=0;i<size;i++)
    {
        for(int j=0;j<size;j++)
        {
            if(data[i]==a.data[j])
            {
                temp.data[l]=data[i];
                l++;
            }
        }
    }
    return temp;
}

template <class T>
istream &operator >>(istream&in, Plenty<T>&p)
{
    for(int i=0;i<p.size;i++)
    {
        in >> p.data[i];
    }
    return in;
}

template <class T>
ostream &operator <<(ostream&out, const Plenty<T>&p)
{
    for(int i=0;i<p.size;i++)
    {
        out << p.data[i] << " ";
    }
    return out;
}

class Money
{
 private:
    long rubles;
    int kopecks;
 public:
    Money();
    Money(long, int);
    Money(const Money&);
     virtual ~Money();
    
    void setrub(long);
    void setkop(int);
    long getrub();
    int getkop();
    
    Money &operator =(const Money&);
    Money operator/(const Money&);
    Money operator*(const Money&);
    Money operator+(Money k);
    friend istream &operator >>(istream&in, Money&m);
    friend ostream &operator <<(ostream&out, const Money&m); 
};
