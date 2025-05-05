#include "Time.h"

Time::Time()
{
    m_hour = 0;
    m_minute = 0;
    m_second = 0;
}


//---------------------------------------------------------
bool Time::SetHour(int hour)
{
    if (hour >= 0 && hour <= 23)
    {
        m_hour = hour;
        return true;
    }

    return false;
}


//---------------------------------------------------------
int Time::GetHour() const
{
    return m_hour;
}


//----------------------------------------------------------
bool Time::SetMinute(int minute)
{
    if (minute >= 0 && minute <=59)
    {
        m_minute = minute;
        return true;
    }

    return false;
}


//----------------------------------------------------------
int Time::GetMinute() const
{
    return m_minute;
}


//----------------------------------------------------------
bool Time::SetSecond(int second)
{
    if (second >= 0 && second <=59)
    {
        m_second = second;
        return true;
    }

    return false;
}


//------------------------------------------------------------
int Time::GetSecond() const
{
    return m_second;
}
