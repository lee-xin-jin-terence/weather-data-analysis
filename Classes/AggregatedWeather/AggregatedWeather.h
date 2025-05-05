#ifndef AGGREGATED_WEATHER_H
#define AGGREGATED_WEATHER_H


#include "../IWeather/IWeather.h"
#include "../Date/Date.h"

    /**
    *@class AggregatedWeather
    *
    *@brief Used to create an instance that stores
    * aggregated weather data, with weather data
    * aggregated by month
    *
    *@author Terence Lee
    *@version 01
    *@date 24 February 2020 Terence Lee, Created
    *
    */
class AggregatedWeather : public IWeather
{

    public:
            /**
            *@brief Initialises the instance variables
            * m_avgWindSpeed, m_avgTemperature and
            * m_totalSolarRadiation to 0
            */
        AggregatedWeather();


            /**
            *@brief Sets the date instance where the aggregated
            * weather data was recorded
            *
            *@param dateObj - the date instance where the
            * aggregated weather data was recorded
            *
            *@return void
            */
        void SetDate(const Date& dateObj);


            /**
            *@brief Returns the date instance where the aggregated
            * weather data was recorded
            *
            *@param dateObj - the date instance when the weather
            * data was recorded, to be returned by reference
            * from the parameter
            *
            *@return dateObj - the date where the weather
            * data was recorded, to be returned by reference
            * from the parameter
            */
        void GetDate(Date& dateObj) const;


            /**
            *@brief Sets the average wind speed that was
            * recorded
            *
            *@param avgWindSpeed - the average wind speed
            * that was recorded in kilometers per hour
            *
            *@return void
            */
        void SetAvgWindSpeed(float avgWindSpeed);


            /**
            *@brief Returns the average wind speed recorded
            *in kilometers per hour
            *
            *@return float - the average wind speed recorded
            */
        float GetAvgWindSpeed() const;


            /**
            *@brief Sets the average ambient air temperature
            * that was recorded
            *
            *@param avgTemperature - the average ambient air
            * temperature recorded in degree Celsius
            *
            *@return void
            */
        void SetAvgTemperature(float avgTemperature);


            /**
            *@brief Returns the average ambient air temperature
            *recorded in degree celsius
            *
            *@return float -  the average ambient
            *ambient air temperature recorded
            */
        float GetAvgTemperature() const;


            /**
            *@brief Sets the total amount solar radiation
            * energy
            *
            *@param solarRadiation - the amount of solar
            * radiation recorded in kilo Watts hour per square
            * meter
            *
            *@return void
            */
        void SetTotalSolarRadiation(float totalSolarRadiation);


            /**
            *@brief Return the total amount of solar radiation
            * recorded in kilo Watts hour per square meter
            *
            *@return float - the total amount of solar radiation
            * recorded
            */
        float GetTotalSolarRadiation() const;

    private:
            /// Date of the aggregated weather data
        Date m_date;

            /// average wind speed measured in km/h
        float m_avgWindSpeed;

            /// average temperature measured in degree
            /// celsius
        float m_avgTemperature;

            /// total solar radiation recorded in
            /// kilo Watts hour per meter square
        float m_totalSolarRadiation;
};

#endif // AGGREGATED_WEATHER_H
