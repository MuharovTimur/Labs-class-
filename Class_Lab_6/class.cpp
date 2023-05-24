#include <iostream>
#include "class.h"
using namespace std;

Iterator::Iterator()
{
    elem=0;
}

Iterator::Iterator(const Iterator&it)
{
    elem=it.elem;
}

bool Iterator::operator==(const Iterator&it)
{
    return elem==it.elem;
}

bool Iterator::operator!=(const Iterator&it)
{
    return elem!=it.elem;
}

void Iterator::operator++()
{
    ++elem;
}

void Iterator::operator--()
{
    --elem;
}

int& Iterator::operator*()
const{
    return *elem;
}

Plenty::Plenty(int s)
{
    int k=0;
    size=s;
    data=new int[size];
    for(int i=0;i<size;i++)
    {
        data[i]=k;
    }
    beg.elem=&data[0];
    end.elem=&data[size];
}

Plenty::Plenty(const Plenty&a)
{
    size=a.size;
    data=new int[size];
    for(int i=0;i<size;i++)
    {
        data[i]=a.data[i];
    }
    beg=a.beg;
    end=a.end;
}

Plenty::~Plenty()
{
    delete [] data;
    data=0;
}

Plenty&Plenty::operator=(const Plenty&a)
{
    if(this==&a)
      return *this;
    size=a.size;
    if(data!=0)
      delete [] data;
    data=new int [size];
    for(int i=0;i<size;i++)
    {
        data[i]=a.data[i];
    }
    beg=a.beg;
    end=a.end;
    return *this;
}

int&Plenty::operator[](int index)
{
    if(index<size)
      return data[index];
    else
      cout << "Ошибка! index>size";
}

Plenty Plenty::operator+(const int k)
{
    Plenty temp(size);
    for(int i=0;i<size;i++)
    {
        temp.data[i]+=data[i]+k;
    }
    return temp;
}

int Plenty::operator()()
{
    return size;
}

Plenty Plenty::operator*(const Plenty&a)
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
    Plenty temp(l);
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

istream &operator >>(istream&in, Plenty&p)
{
    for(int i=0;i<p.size;i++)
    {
        in >> p.data[i];
    }
    return in;
}

ostream &operator <<(ostream&out, const Plenty&p)
{
    for(int i=0;i<p.size;i++)
    {
        out << p.data[i] << " ";
    }
    return out;
}

Iterator Plenty::first()
{
    return beg;
}

Iterator Plenty::last()
{
    return end;
}
