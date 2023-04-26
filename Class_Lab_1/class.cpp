#include <iostream>
#include "class.h"
using namespace std;

void Linear::Init(float F,float S)
{
    first=F;
    second=S;
}

void Linear::Read()
{
    cout << "Введите A:";
    cin >> first;
    cout << endl;
    cout << "Введите B:";
    cin >> second;
    cout << endl;
}

void Linear::Show()
{
    cout << "A=" << first << endl;
    cout << "B=" << second << endl;
}

float Linear::function(double x)
{
    return(first*x+second);
}