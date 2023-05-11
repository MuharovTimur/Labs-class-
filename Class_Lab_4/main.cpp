#include <iostream>
#include "class.h"
using namespace std;

void f1(PAIR&p)
{
    p.setfirst(25);
   cout << " Шестая пара:" << p << endl;
}

PAIR f2()
{
    RATIONAL r(1,2,1,2);
    return r;
}

int main()
{
    int A,B;
    PAIR a;
    PAIR b(5,25);
    PAIR c(a);
    
    cin >> a;
    cout << " Первая пара:" << a << endl;
    cout << " Вторая пара:" << b << endl;
    c=b;
    cout << " Третья пара:" << c << endl;
    
    cout << " Проверка на равенство первой пары.";
    a.check_pair();
    cout << "Перемножение второй пары=";
    A=b.multi_pair();
    cout << A << endl;
    cout << "Вычитание второй и первой пар=";
    B=b.sub(a);
    cout << B << endl;
    
    RATIONAL d;
    cin >> d;
    cout << " Первая дробь:" << d << endl;
    RATIONAL e;
    cin >> e;
    cout << " Вторая дробь:" << e << endl;
    RATIONAL f;
    
    cout << "Вычитание Пятой и четвертой пар=";
    B=e.PAIR::sub(d);
    cout << B << endl;
    f=d.sub(e);
    cout << " Результат вычитания дробей:" << f << endl;
    f=d.add(e);
    cout << " Результат сложения дробей:" << f << endl;
    f=d.multi(e);
    cout << " Результат умножения дробей:" << f << endl;
    
    cout << " Принцип подстановки" << endl;
    f1(d);
    a=f2();
    cout << " Седьмая пара:" <<a << endl;
    
    return 0;
}
