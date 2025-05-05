#ifndef TWO_DIMENSIONAL_BST_TEST_H
#define TWO_DIMENSIONAL_BST_TEST_H

#include <iostream>
#include <iomanip>
#include <ctime>
#include "../Classes/Date/Date.h"
#include "../Classes/Time/Time.h"
#include "../Classes/TwoDimensionalBst/TwoDimensionalBst.h"
#include "DateIsLessThanStruct.h"

using std::cout;
using std::setw;
using std::setfill;
using std::boolalpha;
using TwoDimensionalBstTestSubcomponent::
                    DateIsLessThanStruct;

    /*
        Title: Test of The TwoDimensionalBst Class

        Purpose: To Test the constructors and the various
                 methods of the class

        Outcome: The constructor and the rest of the methods
                 all pass the test

        Author: Terence Lee
        Date : 23 March 2020
        Version of TwoDimensionalBst Tested: Version 01


    */
class TwoDimensionalBstTest
{
    public:
            // Runs all the tests below
        static void RunTest();


    private:

            // typedef of TwoDimensionalBst, where the
            // Date and Time each form part of the
            // composite key
        typedef TwoDimensionalBst <Date, Time,
                    DateIsLessThanStruct> DateTime2DBst;

            // callback function that behaves like '<' (less-than)
            // for Date instances
        static bool DateIsLessThan(
                            const Date& firstDate,
                            const Date& secondDate);


            // Callback function that behaves like '==' (equal to)
            // for Date instances
        static bool DateIsEqualTo(
                           const Date& firstDate,
                           const Date& secondDate);


            // Callback function that behaves like '>' (more than)
            // for Date instances
        static bool DateIsMoreThan(
                            const Date& firstDate,
                            const Date& secondDate);


            // callback function that behaves like '<' (less-than)
            // for Time instances
        static bool TimeIsLessThan(
                            const Time& firstTime,
                            const Time& secondTime);

            // Callback function that behaves like '==' (equal to)
            // for Time instances
        static bool TimeIsEqualTo(
                           const Time& firstTime,
                           const Time& secondTime);


            // Callback function that behaves like '>' (more than)
            // for Time instances
        static bool TimeIsMoreThan(
                            const Time& firstTime,
                            const Time& secondTime);


            //Test constructor and .IsEmpty()
        static void Test1();

            //Test .Insert() for an empty tree
            //and .IsEmpty()
        static void Test2();

            //Test .Insert() for a date-time composite key
            //that already exists
        static void Test3();

            //Test .Insert() for a date-time composite key
            //where the date key exists but not the
            //time key
        static void Test4();

            //Test .Insert() for a date-time composite key
            //where the date-key doesn't exists but the
            //time key does
        static void Test5();

            //Test .Delete() for an existing date-time
            //composite key
        static void Test6();

            //Test .Delete() for an empty tree
        static void Test7();


            //Test .Delete() for a non-existent date-time
            //composite key from a non-empty tree where the
            //date key exists but not the time key
        static void Test8();

            //Test .Delete() for a non-existent date-time
            //composite key from a non-empty tree where the
            //date key does not exists but the time key
            //exists
        static void Test9();

            //Test .Search() for an existing date-time
            //keys pair
        static void Test10();

            //Test .Search() for an empty tree
        static void Test11();

            //Test .Search() for a non-existent date-time
            //composite key where the date key exists
            //but not the time key
        static void Test12();

            //Test .Search() for a non-existent date-time
            //composite key where the date key does not
            //exist but the time key exists
        static void Test13();

            //Testing .Clear()
        static void Test14();

            //Test time taken to insert and search one
            //year worth of date-time composite keys
        static void Test15();


};

#endif // TWO_DIMENSIONAL_BST_H
