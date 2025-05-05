
#include "DateTest.h"


void DateTest:: RunTest()
{
    //Test constructor and Get methods
    Test1();

    //Test SetDay() with valid parameter and GetDay()
    Test2();

    //Test SetDay() with invalid negative parameter
    // and GetDay()
    Test3();

    //Test SetDay() with invalid positive parameter
    Test4();

    //Test SetMonth() with valid parameter and GetMonth()
    Test5();

    //Test SetMonth() with invalid negative parameter
    // and GetMonth()
    Test6();

    //Test SetMonth() with invalid positive parameter
    // and GetMonth()
    Test7();

    //Test SetYear() with valid positive parameter
    // and GetYear()
    Test8();

    //Test SetYear() with invalid non-positive parameter
    // and GetYear()
    Test9();
}


//-------------------------------------------------------------
//Test constructor and Get methods
void DateTest::Test1()
{

    Date dateObj;
    int returnedDay;
    int returnedMonth;
    int returnedYear;


    //get the day, month and year values from dateObj
    returnedDay = dateObj.GetDay();
    returnedMonth = dateObj.GetMonth();
    returnedYear = dateObj.GetYear();


    cout << "Date Class Test 1 : Test Constructor "
         << ", .GetDay() , .GetMonth() , & .GetYear() "
         << '\n';

    cout << setfill('#') << setw(60) << "" << '\n';

    cout << "After creating a Date instance " << '\n';

    cout << setfill('-') << setw(35) << "" << '\n';

    cout << "the return value of .GetDay() is : "
         << returnedDay << '\n';

    cout << "the return value of .GetMonth() is : "
         << returnedMonth << '\n';

    cout << "the return value of .GetYear() is : "
         << returnedYear << "\n\n\n\n\n";

}


//--------------------------------------------------------------
//Test SetDay() with valid parameter and GetDay()
void DateTest::Test2()
{
    Date dateObj;
    int returnedDay;
    bool setDayOutcome;

    //get the day value from dateObj
    returnedDay = dateObj.GetDay();


    cout << "Date Class Test 2 : Test .SetDay() "
         << "and .GetDay() with valid parameter "
         << "for .SetDay() " << '\n';

    cout << setfill('#') << setw(60) << "" << '\n';

    cout << "After creating a Date instance " << '\n';

    cout << setfill('-') << setw(35) << "" << '\n';

    cout << "the return value of .GetDay() is : "
         << returnedDay << "\n\n\n";

         //---------------------------------------------

    setDayOutcome = dateObj.SetDay(12);
    returnedDay = dateObj.GetDay();

    cout << "After setting the Date day as "
         << "\'12\' "<< '\n' << "using the "
         << "method .SetDay()" << '\n';

    cout << setfill('-') << setw(35) << "" << '\n';

    cout << "the boolean return value of .SetDay() is : "
         << boolalpha << setDayOutcome << '\n';

    cout << "the return value of .GetDay() is : "
         << returnedDay<< "\n\n\n\n\n";
}


//-------------------------------------------------------------
//Test SetDay() with invalid negative parameter
// and GetDay()
void DateTest::Test3()
{
    Date dateObj;
    int returnedDay;
    bool setDayOutcome;

    //get the day value from dateObj
    returnedDay = dateObj.GetDay();


    cout << "Date Class Test 3 : Test .SetDay() "
         << "and .GetDay() with invalid negative parameter "
         << '\n' << "for .SetDay() " << '\n';

    cout << setfill('#') << setw(60) << "" << '\n';

    cout << "After creating a Date instance " << '\n';

    cout << setfill('-') << setw(35) << "" << '\n';

    cout << "the return value of .GetDay() is : "
         << returnedDay << "\n\n\n";

         //------------------------------------------

    setDayOutcome = dateObj.SetDay(-4);
    returnedDay = dateObj.GetDay();

    cout << "After setting the Date day as "
         << "\'-4\' "<< '\n' << "using the "
         << "method .SetDay()" << '\n';

    cout << setfill('-') << setw(35) << "" << '\n';

    cout << "the boolean return value of .SetDay() is : "
         << boolalpha << setDayOutcome << '\n';

    cout << "the return value of .GetDay() is : "
         << returnedDay<< "\n\n\n\n\n";
}


//-------------------------------------------------------------
//Test SetDay() with invalid positive parameter
void DateTest::Test4()
{
    Date dateObj;
    int returnedDay;
    bool setDayOutcome;

    //get the day value from dateObj
    returnedDay = dateObj.GetDay();


    cout << "Date Class Test 4 : Test .SetDay() "
         << "and .GetDay() with invalid positive parameter "
         << '\n' << "for .SetDay() " << '\n';

    cout << setfill('#') << setw(60) << "" << '\n';

    cout << "After creating a Date instance " << '\n';

    cout << setfill('-') << setw(35) << "" << '\n';

    cout << "the return value of .GetDay() is : "
         << returnedDay << "\n\n\n";

         //--------------------------------------

    setDayOutcome = dateObj.SetDay(100);
    returnedDay = dateObj.GetDay();

    cout << "After setting the Date day as "
         << "\'100\' "<< '\n' << "using the "
         << "method .SetDay()" << '\n';

    cout << setfill('-') << setw(35) << "" << '\n';

    cout << "the boolean return value of .SetDay() is : "
         << boolalpha << setDayOutcome << '\n';

    cout << "the return value of .GetDay() is : "
         << returnedDay<< "\n\n\n\n\n";
}


//-------------------------------------------------------------
//Test SetMonth() with valid parameter and GetMonth()
void DateTest::Test5()
{
    Date dateObj;
    int returnedMonth;
    bool setMonthOutcome;

    //get the month value from dateObj
    returnedMonth= dateObj.GetMonth();



    cout << "Date Class Test 5 : Test .SetMonth() "
         << "and .GetMonth() with valid  parameter "
         << '\n' << "for .SetMonth() " << '\n';

    cout << setfill('#') << setw(60) << "" << '\n';

    cout << "After creating a Date instance " << '\n';

    cout << setfill('-') << setw(35) << "" << '\n';

    cout << "the return value of .GetMonth() is : "
         << returnedMonth << "\n\n\n";

         //-------------------------------------------

    setMonthOutcome = dateObj.SetMonth(6);
    returnedMonth = dateObj.GetMonth();

    cout << "After setting the Date month as "
         << "\'6\' "<< '\n' << "using the "
         << "method .SetMonth()" << '\n';

    cout << setfill('-') << setw(35) << "" << '\n';

    cout << "the boolean return value of .SetMonth() is : "
         << boolalpha << setMonthOutcome << '\n';

    cout << "the return value of .GetMonth() is : "
         << returnedMonth << "\n\n\n\n\n";

}


//-------------------------------------------------------------
//Test SetMonth() with invalid negative parameter
// and GetMonth()
void DateTest::Test6()
{
    Date dateObj;
    int returnedMonth;
    bool setMonthOutcome;


    //get the month value from dateObj
    returnedMonth= dateObj.GetMonth();


    cout << "Date Class Test 6 : Test .SetMonth() "
         << "and .GetMonth() with invalid negative parameter "
         << '\n' << "for .SetMonth() " << '\n';

    cout << setfill('#') << setw(60) << "" << '\n';

    cout << "After creating a Date instance " << '\n';

    cout << setfill('-') << setw(35) << "" << '\n';

    cout << "the return value of .GetMonth() is : "
         << returnedMonth << "\n\n\n";


         //--------------------------------------------

    setMonthOutcome = dateObj.SetMonth(-10);
    returnedMonth = dateObj.GetMonth();

    cout << "After setting the Date month as "
         << "\'-10\' "<< '\n' << "using the "
         << "method .SetMonth()" << '\n';

    cout << setfill('-') << setw(35) << "" << '\n';

    cout << "the boolean return value of .SetMonth() is : "
         << boolalpha << setMonthOutcome << '\n';

    cout << "the return value of .GetMonth() is : "
         << returnedMonth << "\n\n\n\n\n";

}


//-------------------------------------------------------------
//Test SetMonth() with invalid positive parameter
// and GetMonth()
void DateTest::Test7()
{
    Date dateObj;
    int returnedMonth;
    bool setMonthOutcome;


    //get the month value from dateObj
    returnedMonth= dateObj.GetMonth();


    cout << "Date Class Test 7 : Test .SetMonth() "
         << "and .GetMonth() with invalid positive parameter "
         << '\n' << "for .SetMonth() " << '\n';

    cout << setfill('#') << setw(60) << "" << '\n';

    cout << "After creating a Date instance " << '\n';

    cout << setfill('-') << setw(35) << "" << '\n';

    cout << "the return value of .GetMonth() is : "
         << returnedMonth << "\n\n\n";

         //------------------------------------------------

    setMonthOutcome = dateObj.SetMonth(100);
    returnedMonth = dateObj.GetMonth();

    cout << "After setting the Date month as "
         << "\'100\' "<< '\n' << "using the "
         << "method .SetMonth()" << '\n';

    cout << setfill('-') << setw(35) << "" << '\n';

    cout << "the boolean return value of .SetMonth() is : "
         << boolalpha << setMonthOutcome << '\n';

    cout << "the return value of .GetMonth() is : "
         << returnedMonth << "\n\n\n\n\n";
}


//-------------------------------------------------------------
//Test SetYear() with valid positive parameter
// and GetYear()
void DateTest::Test8()
{
    Date dateObj;
    int returnedYear;
    bool setYearOutcome;


    //get the year value from dateObj
    returnedYear= dateObj.GetYear();


    cout << "Date Class Test 8 : Test .SetYear() "
         << "and .GetYear() with valid positive parameter "
         << '\n' << "for .SetYear() " << '\n';

    cout << setfill('#') << setw(60) << "" << '\n';

    cout << "After creating a Date instance " << '\n';

    cout << setfill('-') << setw(35) << "" << '\n';

    cout << "the return value of .GetYear() is : "
         << returnedYear << "\n\n\n";

         //-------------------------------------------

    setYearOutcome = dateObj.SetYear(1000);
    returnedYear = dateObj.GetYear();

    cout << "After setting the Date year as "
         << "\'1000\' "<< '\n' << "using the "
         << "method .SetYear()" << '\n';

    cout << setfill('-') << setw(35) << "" << '\n';

    cout << "the boolean return value of .SetYear() is : "
         << boolalpha << setYearOutcome << '\n';

    cout << "the return value of .GetYear() is : "
         << returnedYear << "\n\n\n\n\n";

}


//-------------------------------------------------------------
//Test SetYear() with invalid negative parameter
// and GetYear()
void DateTest::Test9()
{

    Date dateObj;
    int returnedYear;
    bool setYearOutcome;


    //get the year value from dateObj
    returnedYear= dateObj.GetYear();



    cout << "Date Class Test 9 : Test .SetYear() "
         << "and .GetYear() with invalid non-positive "
         << '\n' << "parameter for .SetYear() " << '\n';

    cout << setfill('#') << setw(60) << "" << '\n';

    cout << "After creating a Date instance " << '\n';

    cout << setfill('-') << setw(35) << "" << '\n';

    cout << "the return value of .GetYear() is : "
         << returnedYear << "\n\n\n";

         //-------------------------------------

    setYearOutcome = dateObj.SetYear(-4);
    returnedYear = dateObj.GetYear();

    cout << "After setting the Date year as "
         << "\'-4\' "<< '\n' << "using the "
         << "method .SetYear()" << '\n';

    cout << setfill('-') << setw(35) << "" << '\n';

    cout << "the boolean return value of .SetYear() is : "
         << boolalpha << setYearOutcome << '\n';

    cout << "the return value of .GetYear() is : "
         << returnedYear << "\n\n\n\n\n";
}


