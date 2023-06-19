#include <iostream>
#include "class.h"
using namespace std;

Plenty::Plenty(int s)
{
    if (s > MAX_SIZE) 
		throw 1;

	size = s;
	beg = new int[s];

	for (int i = 0; i < size; i++)
		beg[i] = 0;
}

Plenty::Plenty(int s, int* mas)
{
	if (s > MAX_SIZE) 
		throw 1;
	size = s;
	beg = new int[size];

	for (int i = 0; i < size; i++)
		beg[i] = mas[i];
}

Plenty::Plenty(const Plenty&a)
{
    size = a.size;
	beg = new int[size];

	for (int i = 0; i < size; i++)
		beg[i] = a.beg[i];
}

Plenty::~Plenty()
{
    if (beg != 0) 
		delete[] beg;
}

Plenty&Plenty::operator=(const Plenty&a)
{
    if (this == &a)
		return *this;
	if (beg != 0) 
		delete[] beg;

	size = a.size;
	beg = new int[size];

	for (int i = 0; i < size; i++)
		beg[i] = a.beg[i];

	return *this;
}

int&Plenty::operator[](int i)
{
    if (i < 0)
		throw 2;
	if (i >= size)
		throw 3;

	return beg[i];
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
            if(beg[i]==a.beg[j])
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
            if(beg[i]==a.beg[j])
            {
                temp.beg[l]=beg[i];
                l++;
            }
        }
    }
    return temp;
}

Plenty Plenty::operator +(int a)
{
	if (size + 1 == MAX_SIZE) 
		throw 4;

	Plenty temp(size + 1, beg);
	temp.beg[size] = a;

	return temp;
}

Plenty Plenty::operator --()
{
	if (size == 0) 
		throw 5;

	if (size == 1)
	{
		size = 0;
		delete[]beg;
		beg = 0;
		return *this;
	};

	Plenty temp(size, beg);
	delete[]beg;
	size--;
	beg = new int[size];

	for (int i = 0; i < size; i++)
		beg[i] = temp.beg[i];

	return*this;
}

istream &operator >>(istream&in, Plenty&p)
{
    for (int i = 0; i < p.size; i++)
	{
		cout << ">";
		in >> p.beg[i];
	}
	return in;
}

ostream &operator <<(ostream&out, const Plenty&p)
{
    if (p.size == 0) 
		out << "Empty" << endl;
	else
	{
		for (int i = 0; i < p.size; i++)
			out << p.beg[i] << " ";
		out << endl;
	}
	return out;
}

