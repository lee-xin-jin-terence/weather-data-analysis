#ifndef UNAGGREGATED_WEATHER_TEST_H
#define UNAGGREGATED_WEATHER_TEST_H

#include <iostream>
#include <iomanip>
#include "../Classes/UnaggregatedWeather/UnaggregatedWeather.h"
#include "../Classes/Date/Date.h"
#include "../Classes/Time/Time.h"


using std::cout;
using std::setw;
using std::setfill;
using std::boolalpha;

    /*
        Title: Test of The UnaggregatedWeather Class

        Purpose: To Test the constructors and the various
                 methods of the class

        Outcome: The constructor and the rest of the methods
                 all pass the test

        Author: Terence Lee
        Date : 24 February 2020
        Version of UnaggregatedWeather class Tested: Version 01
    */
class UnaggregatedWeatherTest
{
    public:
            //Runs all the test below
        static void RunTest();


    private:
            //Test the constructor, GetWindSpeed(),
            // GetTemperature() and GetSolarRadiation()
        static void Test1();

            //Test SetTime() and GetTime()
        static void Test2();

            // Test SetDate() and GetDate()
        static void Test3();

            // Test SetWindSpeed() and GetWindSpeed()
        static void Test4();

            // Test SetTemperature() and GetTemperature()
        static void Test5();

            // Test SetSolarRadiation() with valid parameter
            //value and GetSolarRadiation
        static void Test6();

            // Test SetSolarRadiation() with invalid parameter
            // value and GetSolarRadiation
        static void Test7();
};

#endif // UNAGGREGATED_WEATHER_TEST_H
