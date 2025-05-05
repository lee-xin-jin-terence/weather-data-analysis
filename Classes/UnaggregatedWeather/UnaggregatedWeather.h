#ifndef UNAGGREGATED_WEATHER_H
#define UNAGGREGATED_WEATHER_H

#include "../IWeather/IWeather.h"
#include "../Time/Time.h"
#include "../Date/Date.h"

    /**
    *@class UnaggregatedWeather
    *
    *@brief Used to create an instance that stores
    * unaggregated weather data
    *
    *@author Terence Lee
    *@version 01
    *@date 24 February 2020 Terence Lee, Created
    */
class UnaggregatedWeather: public IWeather
{
    public:

            /**
            * @brief Initialises the instance variables
            * m_windSpeed, m_temperature and m_solarRadiation
            * to 0
            */
        UnaggregatedWeather();


            /**
            * @brief Sets the time where the weather data
            * was recorded
            *
            * @param timeObj - a Time instance where the weather
            * data was recorded
            *
            * @return void
            */
        void SetTime(const Time& timeObj);


            /**
            * @brief Returns the time instance where the
            * weather data was recorded
            *
            * @param timeObj - the time instance
            * where the weather data was recorded (output)
            *
            * @return timeObj - time instance where
            * the weather data was recorded, to be returned
            * by reference
            */
        void GetTime(Time& timeObj) const;


            /**
            * @brief Sets the data value where the weather
            * data was recorded
            *
            * @param dateObj - the date instance where the weather
            * data was recorded
            *
            * @return void
            */
        void SetDate(const Date& dateObj);


            /**
            * @brief Return the date instance when the weather
            * data was recorded
            *
            * @param dateObj - the date instance when the weather
            * data was recorded, to be returned by reference
            *
            * @return dateObj - the date instance when the weather
            * data was recorded, to be returned by reference
            */
        void GetDate(Date& dateObj) const;


            /**
            * @brief Sets the wind speed that was recorded
            *
            * @param windSpeed - the wind speed that was
            * recorded, to be used to set the value of the
            * instance variable m_windSpeed
            *
            * @return void
            */
        void SetWindSpeed(float windSpeed);


            /**
            * @brief returns the wind speed that was recorded
            *
            * @return float - wind speed that was recorded
            */
        float GetWindSpeed() const;


            /**
            * @brief Sets the temperature recorded
            *
            * @param temperature - the value used to set the
            * instance variable m_temperature
            *
            * @return void
            */
        void SetTemperature(float temperature);


            /**
            * @brief Returns the temperature that was recorded
            * in degrees
            *
            * @return float - the temperature that
            * was recorded
            */
        float GetTemperature() const;


            /**
            * @brief Sets the solar radiation recorded
            * with the units as Watts per square meter, only
            * if the parameter value of solarRadiation is
            * at least 100
            *
            * @param solarRadiation - the solar radiation
            *  that was recorded, to be used to set the
            *  value of instance variable m_solarRadiation
            *
            * @return bool - true if the value of solar
            * radiation was successfully set, and false
            * if it failed to do so if the value of
            * solarRadiation is less than 100
            */
        bool SetSolarRadiation(float solarRadiation);


            /**
            * @brief Returns the solar radiation that was
            * recorded in Watts per square meter
            *
            * @return float - the value of solar radiation
            * recorded in Watts per square meter
            */
        float GetSolarRadiation() const;


    private:

            /// time where the weather data was recorded
        Time m_time;

            /// date when the weather data was recorded
        Date m_date;

            /// windspeed when the weather data was recorded
            /// in meter per second
        float m_windSpeed;

            /// ambient temperature when the weather data
            /// was recorded in degrees celcius
        float m_temperature;

            /// solar radiation when the weather data was
            /// recorded, in Watts per square meter
        float m_solarRadiation;
};

#endif // UNAGGREGATED_WEATHER_H
