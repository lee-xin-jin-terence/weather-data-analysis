#ifndef I_WEATHER_H
#define I_WEATHER_H

#include "../Date/Date.h"

    /**
    *@class IWeather
    *
    *@brief An interface that is used by other classes to
    * to derive, for storing weather-related data
    *
    *@author Terence Lee
    *@version 01
    *@date 24 February 2020 Terence Lee, Created
    */
class IWeather
{
    public:
            /**
            * @brief This constructor does not do anything,
            * except to allow child classes to be able
            * instantiate
            */
        IWeather(){}


            /**
            *@brief An abstract method that allows the user
            * to set the data instance where the weather
            * data was recorded
            *
            *@param dateObj - an instance of date where the
            * data was recorded
            *
            *@return void
            */
        virtual void SetDate(const Date& dateObj) = 0;


            /**
            *@brief An abstract method which allows the
            * user to obtain the instance of data where
            * the weather data was recorded
            *
            *@param dateObj - the date instance where the
            * weather data was recorded, to be returned
            * by reference via the parameter
            *
            *@return dateObj - the date that the weather
            * data was recorded, to be returned by
            * reference via the parameter
            */
        virtual void GetDate(Date& dateObj) const = 0;

};

#endif // I_WEATHER_H
