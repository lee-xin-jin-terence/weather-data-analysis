#include "DATE.h"

Date::Date()
{
    m_day = 0;
    m_month = 0;
    m_year = 0;
}


//----------------------------------------------------------
bool Date::SetDay(int day)
{
    if (day>= 1 && day <=31)
    {
        m_day = day;
        return true;
    }

    return false;
}


//------------------------------------------------------------
int Date::GetDay() const
{
    return m_day;
}


//-------------------------------------------------------------
bool Date::SetMonth(int month)
{
    if (month >= 1 && month <= 12)
    {
        m_month = month;
        return true;
    }

    return false;

}


//--------------------------------------------------------------
int Date::GetMonth() const
{
    return m_month;
}


//--------------------------------------------------------------
bool Date::SetYear(int year)
{
    if (year > 0)
    {
        m_year = year;
        return true;
    }

    return false;
}


//--------------------------------------------------------------
int Date::GetYear() const
{
    return m_year;
}


