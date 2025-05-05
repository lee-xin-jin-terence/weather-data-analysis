#include "AggregatedWeather.h"

AggregatedWeather::AggregatedWeather()
{
    m_avgWindSpeed = 0;
    m_avgTemperature = 0;
    m_totalSolarRadiation = 0;
}


//------------------------------------------------------------
void AggregatedWeather::SetDate(const Date& dateObj)
{
    m_date = dateObj;
}


//---------------------------------------------------------
void AggregatedWeather::GetDate(Date& dateObj) const
{
    dateObj = m_date;
}


//---------------------------------------------------------
void AggregatedWeather::SetAvgWindSpeed(float avgWindSpeed)
{
    m_avgWindSpeed = avgWindSpeed;
}



//---------------------------------------------------------
float AggregatedWeather::GetAvgWindSpeed() const
{
    return m_avgWindSpeed;
}


//----------------------------------------------------------
void AggregatedWeather::SetAvgTemperature(float avgTemperature)
{
    m_avgTemperature = avgTemperature;
}


//-----------------------------------------------------------
float AggregatedWeather::GetAvgTemperature() const
{
    return m_avgTemperature;
}



//-----------------------------------------------------------
void AggregatedWeather::SetTotalSolarRadiation(
                                        float totalSolarRadiation)
{
    m_totalSolarRadiation = totalSolarRadiation;
}


//------------------------------------------------------------
float AggregatedWeather::GetTotalSolarRadiation() const
{
    return m_totalSolarRadiation;
}
