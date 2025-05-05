#ifndef BST_TEST_H
#define BST_TEST_H

#include <iostream>
#include <iomanip>
#include <ctime>
#include "../Classes/Bst/Bst.h"

using std::cout;
using std::setw;
using std::setfill;
using std::boolalpha;


    /*
        Title: Test of the Bst template class

        Purpose: To Test the constructors and the various
                 methods of the class

        Outcome: The constructor and the rest of the methods
                 all pass the test

        Author: Terence Lee
        Date : 29 March 2020
        Version of Bst template class Tested: Version 01
    */
class BstTest
{
    public:
            //Runs all the tests below
        static void RunTest();

    private:

            // a callback function (method) that is used by
            // Bst for integer comparison
            // It is equivalent to the operator <
        static bool IsLessThan(const int& firstNum,
                               const int& secondNum);


            // a callback function (method) that is used by
            // Bst for integer comparison
            // It is equivalent to the operator ==
        static bool IsEqualTo(const int& firstNum,
                              const int& secondNum);


            // a callback function (method) that is used by
            // Bst for integer comparison
            // It is equivalent to the operator >
        static bool IsMoreThan(const int& firstNum,
                               const int& secondNum);


            // a callback function (method) that is used by
            // Bst for printing numbers during traversals
        static void PrintNum(const int& num);


            // Test constructor and  .IsEmpty()
        static void Test1();


            // Test .Insert() and .IsEmpty()
        static void Test2();


            // Test .Insert() for inserting the same number
            // into the binary search tree twice
            // (invalid second insertion)
        static void Test3();


            // Test .Insert() for inserting two different
            // numbers into the binary search tree
            // (valid insertions)
        static void Test4();


            // Test .Delete() for a number that exists
            // in the binary search tree
        static void Test5();


            // Test .Delete() from an empty binary
            // search tree
        static void Test6();


            // Test .Delete() for a number that does not
            // exist in a non-empty binary search
            // tree
        static void Test7();


            // Test .Search() for an existing number
            // within the binary search tree
        static void Test8();


            // Test .Search() for an empty binary search
            // tree
        static void Test9();


            // Test .Search() for a number that does not
            // exist in a non-empty binary search tree
        static void Test10();


            // Test .Clear()
        static void Test11();


            // Test various traversal methods for insertion
            // of numbers in ascending order
        static void Test12();


            // Test various traversal methods for insertion
            // of numbers in descending order
        static void Test13();


            // Test various traversal methods for insertion
            // of numbers in random order
        static void Test14();


            // Test time taken to insert and search from
            // 20,000 integers(numbers)
        static void Test15();


};

#endif // BST_TEST_H
