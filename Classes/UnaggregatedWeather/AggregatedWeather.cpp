
#include "UnaggregatedWeather.h"

UnaggregatedWeather::UnaggregatedWeather()
{
    m_windSpeed = 0;
    m_temperature = 0;
    m_solarRadiation = 0;
}

//--------------------------------------------------------

void UnaggregatedWeather::SetTime(const Time& timeObj)
{
    m_time = timeObj;
}

//---------------------------------------------------------

void UnaggregatedWeather::GetTime(Time& timeObj) const
{
    timeObj = m_time;
}

//----------------------------------------------------------

void UnaggregatedWeather::SetDate(const Date& dateObj)
{
    m_date = dateObj;
}

//----------------------------------------------------------

void UnaggregatedWeather::GetDate(Date& dateObj) const
{
    dateObj = m_date;
}

//----------------------------------------------------------

void UnaggregatedWeather::SetWindSpeed(float windSpeed)
{
    m_windSpeed = windSpeed;
}

//------------------------------------------------------------

float UnaggregatedWeather::GetWindSpeed() const
{
    return m_windSpeed;
}

//------------------------------------------------------------

void UnaggregatedWeather::SetTemperature(float temperature)
{
    m_temperature = temperature;
}


//------------------------------------------------------------

float UnaggregatedWeather::GetTemperature() const
{
    return m_temperature;
}

//-----------------------------------------------------------

bool UnaggregatedWeather::SetSolarRadiation(float solarRadiation)
{
    if (solarRadiation >= 100)
    {
        m_solarRadiation = solarRadiation;
        return true;
    }

    return false;
}

//------------------------------------------------------------

float UnaggregatedWeather::GetSolarRadiation() const
{
    return m_solarRadiation;
}



