#include <iostream>
#include "class.h"
using namespace std;

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
    
    Object *p=&a;
    cout << "Метод show(указатель)" <<endl;
    p->show();
    
    /*cout << " Проверка на равенство первой пары.";
    a.check_pair();
    cout << "Перемножение второй пары=";
    A=b.multi_pair();
    cout << A << endl;
    cout << "Вычитание второй и первой пар=";
    B=b.sub(a);
    cout << B << endl;*/
    
    RATIONAL d;
    cin >> d;
    cout << " Первая дробь:" << d << endl;
    RATIONAL e;
    cin >> e;
    cout << " Вторая дробь:" << e << endl;
    //RATIONAL f;
    
    p=&d;
    cout << "Метод show(указатель)" <<endl;
    p->show();
    
    /*cout << "Вычитание Пятой и четвертой пар=";
    B=e.PAIR::sub(d);
    cout << B << endl;
    f=d.sub(e);
    cout << " Результат вычитания дробей:" << f << endl;
    f=d.add(e);
    cout << " Результат сложения дробей:" << f << endl;
    f=d.multi(e);
    cout << " Результат умножения дробей:" << f << endl;*/
    
    Vector v(5);
    p=&a;
    v.Add(p);
    p=&b;
    v.Add(p);
    p=&d;
    v.Add(p);
    p=&e;
    v.Add(p);
    cout << " Вывод вектора:" << v << endl;
    
    return 0;
}

