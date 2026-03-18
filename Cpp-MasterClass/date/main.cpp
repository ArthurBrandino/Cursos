#include "date.h"
#include <cstdlib>

int main()
{
    Date d1;

    d1.change(31, 1, 2001);  d1.print(); // result: 31/01/2001
    d1.change(29, 2, 2001);  d1.print(); // result: Invalid Date | Is not Leap Year
    d1.change(29, 2, 1997);  d1.print(); // result: Invalid Date | Is not Leap Year
    d1.change(29, 2, 1800);  d1.print(); // result: Invalid Date | Is not Leap Year (e fora do range 1900+)
    d1.change(29, 2, 1996);  d1.print(); // result: 29/02/1996
    d1.change(29, 2, 2000);  d1.print(); // result: 29/02/2000
    d1.change(31, 6, 2001);  d1.print(); // result: Invalid Date | June has only 30 days
    d1.change(31, 7, 2001);  d1.print(); // result: 31/07/2001
    d1.change(31, 8, 2001);  d1.print(); // result: 31/08/2001
    d1.change(31, 9, 2001);  d1.print(); // result: Invalid Date | September has only 30 days
    d1.change(31, 12, 2001); d1.print(); // result: 31/12/2001

    system("pause");
    return 0;
}
