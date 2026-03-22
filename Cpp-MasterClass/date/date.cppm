#ifndef DATE_H
#define DATE_H
#include <cstdint>
#include <compare>
#include <print>

class Date
{
    public:
        enum{ YEAR_MIN = 1900, YEAR_MAX = 2100};
        enum{ FEBRUARY = 2, JULY = 7};

        Date() = default;
        Date(uint8_t day, uint8_t month, uint16_t year)
        {
            change(day, month, year);
        }


        void validate()
        {
            m_valid = ((m_day >= 1 && m_day <= lastDayOfMonth()) && 
                        (m_month >= 1 && m_month <= 12) && 
                        (m_year >= YEAR_MIN && m_year <= YEAR_MAX));
        }

        void change(uint8_t day, uint8_t month, uint16_t year)
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

        uint8_t lastDayOfMonth()const
        {
            if(m_month > JULY)          return (m_month % 2 == 0) ? 31 : 30;
            if(m_month != FEBRUARY)     return (m_month % 2 == 0) ? 30 : 31;
            
            return (isLeapYear()) ? 29 : 28;
        }

        bool isLeapYear()const
        {
            return (!(m_year % 4) && (m_year % 100)) || !(m_year % 400 );  
        }


        uint8_t day()const
        {
            return m_day;
        }

        uint8_t month()const
        {
            return m_month;
        }

        uint16_t year()const
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
        bool m_valid : 1 {false};
        uint8_t m_day;
        uint8_t m_month;
        uint16_t m_year;
};

#endif