#ifndef VECTOR_TEST_H
#define VECTOR_TEST_H

#include <iostream>
#include <iomanip>
#include "../Classes/Vector/Vector.h"

using std::cout;
using std::setw;
using std::setfill;
using std::boolalpha;


    /*
      Test of The Vector Template Class

      Purpose: To Test the various methods and constructors
                of the Vector template class

      Outcome: All the various methods and constructors
              passed the tests

      Author: Terence Lee
      Date : 12 February 2020
      Version of Vector template class tested: 1.0
    */
class VectorTest
{
public:
    static void RunTest();

private:
        //Testing Constructor , .GetCurrentSize()
        //and .GetCapacitySize()
    static void Test1();

        //Testing .EnsureCapacity() with valid number as parameter
    static void Test2();

        //Testing .EnsureCapacity() with invalid number (negative
        // number) as parameter
    static void Test3();

        //Testing .Append() for vector instance
        //with zero capacity
    static void Test4();

        //Testing .Append() for full capacity vector instance
    static void Test5();

        //Testing .Append() & .Get()
    static void Test6();

        //Testing .Get() with invalid non-negative index
        //parameter value
    static void Test7();

        //Testing .Get() with negative parameter value
    static void Test8();

        //Testing .Insert() for value insertion
    static void Test9();

        //Testing .Insert(),
        //attempting to use it to append (Invalid usage)
    static void Test10();

        //Testing .Insert()
        //with negative parameter value (invalid usage)
    static void Test11();

        //Testing .Set() with valid parameter index value
    static void Test12();

        //Testing .Set(), attempting to use it to append
        // (invalid usage)
    static void Test13();

        //Testing .Set() with negative
        //index parameter value (invalid usage)
    static void Test14();

        //Testing .TrimToCurrentSize() for valid parameter
        // value on unfilled vector with some capacity
    static void Test15();

        //Testing .TrimToCurrentSize() for
        //partially filled vector
    static void Test16();

        //Testing .TrimToCurrentSize()
        //for a vector instance with 0 capacity
    static void Test17();

        //Testing .Remove() to remove elements from the
        //  front of a vector instance
    static void Test18();

        //Testing .Remove() to remove elements
        //from the back of a vector instance
    static void Test19();

        //Testing .Remove() where index is a negative
        // number (invalid usage)
    static void Test20();

        //Testing .Remove() where the index is greater than or
        // equal to the current size of the vector instance
    static void Test21();

        //Testing the Clear() method to clear the entire vector
    static void Test22();


};


#endif
