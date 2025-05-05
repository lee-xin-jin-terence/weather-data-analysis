#ifndef TIME_TEST_H
#define TIME_TEST_H

#include <iostream>
#include <iomanip>
#include "../Classes/Time/Time.h"

using std::cout;
using std::setw;
using std::setfill;
using std::boolalpha;

    /*
        Title: Test of The Time Class

        Purpose: To Test the constructors , and the various
                Set and Get methods of the class

        Outcome: The Constructors and all remaining methods
                set/get passed the test

        Author: Terence Lee
        Date : 21 February 2020
        Version of Time class Tested: Version 01


    */

class TimeTest
{
    public:
            //Runs all the tests below
        static void RunTest();

    private:
            //Test constructor and Get methods
        static void Test1();

            //Test SetHour() with valid parameter and GetHour()
        static void Test2();

            //Test SetHour() with invalid negative parameter
            // and GetHour()
        static void Test3();

            //Test SetHour() with invalid positive parameter
            // and GetHour()
        static void Test4();

            //Test SetMinute() with valid parameter and
            // GetMinute()
        static void Test5();

            //Test SetMinute() with invalid negative parameter
            // and GetMinute()
        static void Test6();

            //Test SetMinute() with invalid positive parameter
            // and GetMinute()
        static void Test7();

            //Test SetSecond() with valid parameter and
            // GetSecond()
        static void Test8();

            //Test SetSecond() with invalid negative parameter
            // and GetSecond()
        static void Test9();

            //Test SetSecond() with invalid positive parameter
            // and GetSecond()
        static void Test10();
};


#endif // TIMETEST_H
