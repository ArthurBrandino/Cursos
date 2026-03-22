#include "date.cppm"
#include <cstdlib>
#include <iostream>
using namespace std;

int main()
{
    Date d1(1, 1, 2000), d2(1, 1, 1999);

    d1.print();
    d2.print();

    system("pause");
    return 0;
}
