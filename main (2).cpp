#include <iostream>
#include "class.h"
using namespace std;

int main()
{
    double x;
    Linear Equation1;
    Linear Equation2;
    Equation1.Init(4.2,5.5);
    cout << "Линейное уравнение y=Ax+B.Значения A и B в первом уравнении:";
    Equation1.Show();
    cout << "Введите A и B для второго уравнения.";
    Equation2.Read();
    cout << "Введите x:";
    cin >> x;
    cout << "Решение.y1=" << Equation1.function(x) << ".y2=" << Equation2.function(x) << "." << endl;
    cout << endl;
    return 0;
}