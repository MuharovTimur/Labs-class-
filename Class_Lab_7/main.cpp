#include <iostream>
#include "class.h"
using namespace std;

int main()
{
    cout << "Тестирование параметризированного класса Plenty для стандартного типа данных:int" << endl;
    Plenty<int>A(5,0);
    cout << "Вводим значений элементов множества A" << endl;
    cin >> A;
    cout << "Множество A" << endl;
    cout << A << endl;
    Plenty<int>B(10,1);
    cout << "Множество B" << endl;
    cout << B << endl;
    B=A;
    cout << "Множество B(значениям элементам множества B присвоили значения элементов множества A)" << endl;
    cout << B << endl;
    cout << "Выводим элемент,находящийся по индексу 2 из множества A" << endl;
    cout << A[2] << endl;
    cout << "Размер множества A=" << A() << endl;
    B=A+10;
    cout << "Множество B(значениям элементам множества B присвоили значения элементов множества A+10)" << endl;
    cout << B << endl;
    Plenty<int>C(5,0);
    Plenty<int>D(5,0);
    Plenty<int>E(10,0);
    cout << "Вводим значений элементов множества C" << endl;
    cin >> C;
    cout << "Множество C" << endl;
    cout << C << endl;
    cout << "Вводим значений элементов множества D" << endl;
    cin >> D;
    cout << "Множество D" << endl;
    cout << D << endl;
    E=C*D;
    cout << " Множество E,пересечение множеств C и D" << endl;
    cout << E << endl;
    
    cout << "Тестирование параметризированного класса Plenty для пользовательского типа данных:Money" << endl;
    Money m;
    cout << "Money m=";
    cin >> m;
    Money t;
    cout << "Money t=";
    cin >> t;
    Plenty<Money>F(5,m);
    cout << "Вводим значений элементов множества F" << endl;
    cin >> F;
    cout << "Множество F" << endl;
    cout << F << endl;
    Plenty<Money>G(10,m);
    cout << "Множество G" << endl;
    cout << G << endl;
    G=F;
    cout << "Множество G(значениям элементам множества G присвоили значения элементов множества F)" << endl;
    cout << G << endl;
    cout << "Выводим элемент,находящийся по индексу 2 из множества F" << endl;
    cout << F[2] << endl;
    cout << "Размер множества F=" << F() << endl;
    G=F+t;
    cout << "Множество G(значениям элементам множества G присвоили значения элементов множества F+t)" << endl;
    cout << G << endl;
    return 0;
}
