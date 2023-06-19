#include <iostream>
#include <string>
#include "class.h"
using namespace std;

int main()
{
    Person *a=new Person;
    cout << "Введите человека a" << endl;
    a->Input();
    cout << "Человек:" << endl;
    a->Show();
    
    Emloyee *b=new Emloyee;
    cout << "Введите сотрудника b" << endl;
    b->Input();
    cout << "Сотрудник:" << endl;
    b->Show();
    
    cout << "Тестирование Dialog" << endl;
    Dialog D;
    D.Execute();
    
    return 0;
}
