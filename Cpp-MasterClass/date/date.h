#ifndef DATE_H
#define DATE_H

#include <stdio.h>

class Date
{
    public:
        enum{ YEAR_MIN = 1900, YEAR_MAX = 2100};
        enum{ FEBRUARY = 2, JULY = 7};

        Date() = default;
        Date(short day, short month, short year)
        {
            change(day, month, year);
        }

        void change(short day, short month, short year);

        void validate()
        {
            m_valid = ((m_day >= 1 && m_day <= lastDayOfMonth()) && 
                        (m_month >= 1 && m_month <= 12) && 
                        (m_year >= YEAR_MIN && m_year <= YEAR_MAX));
        }

        void print()const;
        short lastDayOfMonth() const;
        bool isLeapYear() const;

        short day()const
        {
            return m_day;
        }

        short month()const
        {
            return m_month;
        }

        short year()const
        {
            return m_year;
        }

    private:
        short m_day;
        short m_month;
        short m_year;
        bool m_valid {false};
};

#endif