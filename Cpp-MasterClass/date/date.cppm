#ifndef DATE_H
#define DATE_H

#include <compare>
#include <print>

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


        void validate()
        {
            m_valid = ((m_day >= 1 && m_day <= lastDayOfMonth()) && 
                        (m_month >= 1 && m_month <= 12) && 
                        (m_year >= YEAR_MIN && m_year <= YEAR_MAX));
        }

        void change(short day, short month, short year)
        {
            m_day = day;
            m_month = month;
            m_year = year;

            validate();
        }



        void print()const
        {
            if (m_valid) 
                std::println("{:02}/{:02}/{}", m_day, m_month, m_year);
            else 
                std::println("Invalid date!");
        }

        short lastDayOfMonth()const
        {
            if(m_month > JULY)          return (m_month % 2 == 0) ? 31 : 30;
            if(m_month != FEBRUARY)     return (m_month % 2 == 0) ? 30 : 31;
            
            return (isLeapYear()) ? 29 : 28;
        }

        bool isLeapYear()const
        {
            return (!(m_year % 4) && (m_year % 100)) || !(m_year % 400 );  
        }


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

        bool operator==(const Date &other) const = default;

        auto operator<=>(const Date &other) const {
            if(const auto cmp = m_year <=> other.m_year; cmp != 0) return cmp;
            if(const auto cmp = m_month <=> other.m_month; cmp != 0) return cmp;
            return m_day <=> other.m_day;
        }


    private:
        short m_day;
        short m_month;
        short m_year;
        bool m_valid {false};
};

#endif