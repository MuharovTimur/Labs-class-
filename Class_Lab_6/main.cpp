#include <iostream>
#include "class.h"
using namespace std;

int main()
{
    Plenty a(5);
    cout << " Пустое множество a" << endl;
    cout << a << endl;
    cout << "Заполните множество a" << endl;
    cin >> a;
    cout << " Заполненное множество a" << endl;
    cout << a << endl;
    a[2]=100;
    cout << " Множество a,элементу с индексом 2 которого присвоили новое значение 100(доступ по индексу)" << endl;
    cout << a << endl;
    Plenty b(10);
    cout << " Пустой множество b" << endl;
    cout << b << endl;
    b=a;
    cout << " Множество b,значения элементов которого присвоили из a" << endl;
    cout << b << endl;
    Plenty c(10);
    c=b+100;
    cout << " Множество c,значения элементов которого присвоили из b+100" << endl;
    cout << c << endl;
    Plenty d(5);
    cout << "Заполните множества d" << endl;
    cin >> d;
    cout << " Заполненный множества d" << endl;
    cout << d << endl;
    Plenty e(10);
    e=a*d;
    cout << " Множество е,пересечение множеств a и d" << endl;
    cout << e << endl;
    cout << "Длина множества a=" << a() << endl;
    cout << "Первый элемент из множества a" << endl;
    cout <<  *(a.first()) << endl;
    Iterator i=a.first();
    ++i;
    cout << "следующий после первого,элемент из множества a(по итератору)" << endl;
    cout << *i << endl;
    i=a.last();
    --i;
    cout << "предыдущий перед последним,элемент из множества a(по итератору)" << endl;
    cout << *i << endl;
    cout << "Все элементы множества а(по итератору)" << endl;
    for(i=a.first();i!=a.last();++i)
    {
        cout << *i << endl;
    }
    return 0;
}
