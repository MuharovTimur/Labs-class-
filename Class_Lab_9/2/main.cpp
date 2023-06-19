#include <iostream>
#include "class.h"
using namespace std;

int main()
{
	try
	{
		Plenty x(2);
		Plenty y(0);
		cout << "Множество x:";
		cout << x << endl;
		cout << "Введите индекс i:" << endl;
		int i;
		cin >> i;
		cout << "Доступ по индексу:";
		cout << x[i] << endl;
		y = x + 3;
		cout << "Множество y:";
		cout << y << endl;
		Plenty z1(0);
		Plenty z2(0);
		Plenty z3(0);
		z1=z1+1;
		z1=z1+2;
		z1=z1+3;
		z2=z2+1;
		z2=z2+3;
		z2=z2+5;
		z3=z1*z2;
		cout << "Множество z1:";
		cout << z1 << endl;
		cout << "Множество z2:";
		cout << z2 << endl;
		cout << "Множество z3(пересечение z1 и z2):";
		cout << z3 << endl;
		--x;
		cout << "Множество x:";
		cout << x << endl;
		--x;
		cout << "Множество x:";
		cout << x << endl;
		--x;
	}
	catch (error e)
	{
		e.what();
	}

	return 0;
}
