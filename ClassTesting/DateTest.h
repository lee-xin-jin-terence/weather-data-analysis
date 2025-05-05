#ifndef DATE_TEST_H
#define DATE_TEST_H

#include <iostream>
#include <iomanip>
#include "../Classes/Date/Date.h"

using std::cout;
using std::setw;
using std::setfill;
using std::boolalpha;

    /*
        Title: Test of The Date Class

        Purpose: To Test the constructors , and the various
                Set and Get methods of the class

        Outcome: The Constructors and all remaining methods
                passed the test

        Author: Terence Lee
        Date : 12 February 2020
        Version of Date class Tested: Version 01
    */

class DateTest
{
public:
        //Run all the 9 tests below
    static void RunTest();


private:
        //Test constructor and Get methods
    static void Test1();

        //Test SetDay() with valid parameter and GetDay()
    static void Test2();

        //Test SetDay() with invalid negative parameter
        // and GetDay()
    static void Test3();

        //Test SetDay() with invalid positive parameter
    static void Test4();

        //Test SetMonth() with valid parameter and GetMonth()
    static void Test5();

        //Test SetMonth() with invalid negative parameter
        // and GetMonth()
    static void Test6();

        //Test SetMonth() with invalid positive parameter
        // and GetMonth()
    static void Test7();

        //Test SetYear() with valid positive parameter
        // and GetYear()
    static void Test8();

        //Test SetYear() with invalid non-positive parameter
        // and GetYear()
    static void Test9();
};

#endif
