#ifndef AGGREGATED_WEATHERTEST_H
#define AGGREGATED_WEATHERTEST_H


#include <iostream>
#include <iomanip>
#include "../Classes/AggregatedWeather/AggregatedWeather.h"


using std::cout;
using std::setw;
using std::setfill;
using std::boolalpha;

    /*
        Title: Test of The AggregatedWeather Class

        Purpose: To Test the constructor , and the various
                Set and Get methods of the class

        Outcome: The Constructor and all remaining methods
                set/get passed the test

        Author: Terence Lee
        Date : 24 February 2020
        Version of Date class Tested: Version 01
    */
class AggregatedWeatherTest
{
    public:
            //Runs all the tests below
        static void RunTest();

    protected:

            //Test the constructor, .GetAvgWindSpeed(),
            // .GetAvgTemperature() and .GetTotalSolarRadiation()
        static void Test1();

            //Test .SetDate() and .GetDate()
        static void Test2();

            //Test .SetAvgWindSpeed() and .GetAvgWindSpeed()
        static void Test3();

            //Test .SetAvgTemperature() and .GetAvgTemperature()
        static void Test4();

            //Test .SetTotalSolarRadiation() and
            // .GetTotalSolarRadiation()
        static void Test5();

};

#endif // AGGREGATED_WEATHERTEST_H
