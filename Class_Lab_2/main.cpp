#include <iostream>
#include <string>
#include "class.h"
using namespace std;

int main()
{
    Computer M5K;
    cout << "Первый компьютер." << endl;
    M5K.show();
    Computer M6I("intel core i7",4,30);
    cout << "Второй компьютер." << endl;
    M6I.show();
    Computer N3P=M5K;
    cout << "Третий компьютер." << endl;
    N3P.show();
    N3P.setprocessor("intel core i8");
    N3P.setOPvolume(3);
    N3P.setHDvolume(26);
    cout << "Третий компьютер(после модификаторов)." << endl;
    N3P.show();
    return 0;
}