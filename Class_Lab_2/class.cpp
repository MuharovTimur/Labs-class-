#include <iostream>
#include <string>
#include "class.h"
using namespace std;

Computer::Computer()
{
    processor="intel core i7";
    OPvolume=2;
    HDvolume=20;
    
    cout << "Сработал конструктор без параметров" << endl;
}

Computer::Computer(string Name,int Vop,int Vhd)
{
    processor=Name;
    OPvolume=Vop;
    HDvolume=Vhd;
    
    cout << "Сработал конструктор с параметрами" << endl;
}

Computer::Computer(const Computer &comp)
{
    processor=comp.processor;
    OPvolume=comp.OPvolume;
    HDvolume=comp.HDvolume;
    
    cout << "Сработал конструктор копирования" << endl;
}

Computer::~Computer()
{
    cout << "Сработал деструктор" << endl;
}

string Computer:: getprocessor()
{
    return processor;
}

void Computer::setprocessor(string Name)
{
    processor=Name;
}

int Computer::getOPvolume()
{
    return OPvolume;
}

void Computer::setOPvolume(int Vop)
{
    OPvolume=Vop;
}

int Computer::getHDvolume()
{
    return HDvolume;
}

void Computer::setHDvolume(int Vhd)
{
    HDvolume=Vhd;
}

void Computer::show()
{
    cout << "Процессор:" << processor << endl;
    cout << "Объем ОП:" << OPvolume << endl;
    cout << "Объем ЖД:" << HDvolume << endl;
}