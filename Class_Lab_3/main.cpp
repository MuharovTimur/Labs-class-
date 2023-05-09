#include <iostream>
#include "class.h"
using namespace std;

int main()
{
    Money A;
    Money B;
    Money C;
    Money D;
    cin>>A;
    cin>>B;
    C=A/B;
    D=A*B;
    cout << "A=" << A << endl;
    cout << "B=" << B << endl;
    cout << "C=" << C << endl;
    cout << "D=" << D << endl;
    return 0;
}
