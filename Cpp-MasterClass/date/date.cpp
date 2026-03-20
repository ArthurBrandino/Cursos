#include "date.h"
#include <iostream>

void Date::change(short day, short month, short year)
{
    m_day = day;
    m_month = month;
    m_year = year;

    validate();
}



void Date::print()const
{
    if (m_valid) {
        std::cout.fill('0');
        std::cout.width(2);
        std::cout << m_day << '/';
        std::cout.width(2);
        std::cout << m_month << '/' << m_year << std::endl;
    } 
    else 
        std::cout << "Invalid date!\n";
}

short Date::lastDayOfMonth()const
{
    if(m_month > JULY)          return (m_month % 2 == 0) ? 31 : 30;
    if(m_month != FEBRUARY)     return (m_month % 2 == 0) ? 30 : 31;
    
    return (isLeapYear()) ? 29 : 28;
}

bool Date::isLeapYear()const
{
    return (!(m_year % 4) && (m_year % 100)) || !(m_year % 400 );  
}

