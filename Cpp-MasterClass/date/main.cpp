#include "date.cppm"
#include <cstdlib>
#include <iostream>
using namespace std;

int main()
{
    Date d1(1, 1, 2000), d2(1, 1, 1999);

    if (d1 > d2) cout << "d1 > d2\n";
    if (d1 >= d2) cout << "d1 >= d2\n";
    if (d1 != d2) cout << "d1 != d2\n";

    d2.change(1, 1, 2000);

    if (d1 == d2) cout << "d1 == d2\n";

    d2.change(31, 1, 2000);

    if (d1 < d2) cout << "d1 < d2\n";
    if (d1 <= d2) cout << "d1 <= d2\n";

    system("pause");
    return 0;
}
