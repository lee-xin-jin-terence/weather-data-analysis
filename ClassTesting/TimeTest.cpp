#include "TimeTest.h"

void TimeTest::RunTest()
{
            //Test constructor and Get methods
        Test1();

            //Test SetHour() with valid parameter and GetHour()
        Test2();

            //Test SetHour() with invalid negative parameter
            // and GetHour()
        Test3();

            //Test SetHour() with invalid positive parameter
            // and GetHour()
        Test4();

            //Test SetMinute() with valid parameter and
            // GetMinute()
        Test5();

            //Test SetMinute() with invalid negative parameter
            // and GetMinute()
        Test6();

            //Test SetMinute() with invalid positive parameter
            // and GetMinute()
        Test7();

            //Test SetSecond() with valid parameter and
            // GetSecond()
        Test8();

            //Test SetSecond() with invalid negative parameter
            // and GetSecond()
        Test9();

            //Test SetSecond() with invalid positive parameter
            // and GetSecond()
        Test10();
}


//--------------------------------------------------------------
//Test constructor and Get methods
void TimeTest::Test1()
{

    Time timeObj;
    int returnedHour;
    int returnedMinute;
    int returnedSecond;


    //get the hour, minute and second values from timeObj
    returnedHour = timeObj.GetHour();
    returnedMinute = timeObj.GetMinute();
    returnedSecond = timeObj.GetSecond();


    cout << "Time Class Test 1 : Test Constructor "
         << ", .GetHour() , .GetMinute() , & .GetSecond() "
         << '\n';

    cout << setfill('#') << setw(60) << "" << '\n';

    cout << "After creating a Time instance " << '\n';

    cout << setfill('-') << setw(35) << "" << '\n';

    cout << "the return value of .GetHour() is : "
         << returnedHour << '\n';

    cout << "the return value of .GetMinute() is : "
         << returnedMinute << '\n';

    cout << "the return value of .GetSecond() is : "
         << returnedSecond << "\n\n\n\n\n";
}


//---------------------------------------------------------------
//Test SetHour() with valid parameter and GetHour()
void TimeTest::Test2()
{

    Time timeObj;
    int returnedHour;
    bool setHourOutcome;

    //get the hour value from timeObj
    returnedHour = timeObj.GetHour();


    cout << "Time Class Test 2 : Test .SetHour() "
         << "and .GetHour() with valid parameter "
         << "for .SetHour() " << '\n';

    cout << setfill('#') << setw(60) << "" << '\n';

    cout << "After creating a Time instance " << '\n';

    cout << setfill('-') << setw(35) << "" << '\n';

    cout << "the return value of .GetHour() is : "
         << returnedHour << "\n\n\n";

         //---------------------------------------------

    setHourOutcome = timeObj.SetHour(12);
    returnedHour = timeObj.GetHour();

    cout << "After setting the Time hour as "
         << "\'12\' "<< '\n' << "using the "
         << "method .SetHour()" << '\n';

    cout << setfill('-') << setw(35) << "" << '\n';

    cout << "the boolean return value of .SetHour() is : "
         << boolalpha << setHourOutcome << '\n';

    cout << "the return value of .GetHour() is : "
         << returnedHour<< "\n\n\n\n\n";
}


//---------------------------------------------------------------
//Test SetHour() with invalid negative parameter
// and GetHour()
void TimeTest::Test3()
{

    Time timeObj;
    int returnedHour;
    bool setHourOutcome;

    //get the hour value from timeObj
    returnedHour = timeObj.GetHour();


    cout << "Time Class Test 3 : Test .SetHour() "
         << "and .GetHour() with invalid negative parameter "
         << '\n' << "for .SetHour() " << '\n';

    cout << setfill('#') << setw(60) << "" << '\n';

    cout << "After creating a Time instance " << '\n';

    cout << setfill('-') << setw(35) << "" << '\n';

    cout << "the return value of .GetHour() is : "
         << returnedHour << "\n\n\n";

         //------------------------------------------

    setHourOutcome = timeObj.SetHour(-4);
    returnedHour = timeObj.GetHour();

    cout << "After setting the Time hour as "
         << "\'-4\' "<< '\n' << "using the "
         << "method .SetHour()" << '\n';

    cout << setfill('-') << setw(35) << "" << '\n';

    cout << "the boolean return value of .SetHour() is : "
         << boolalpha << setHourOutcome << '\n';

    cout << "the return value of .GetHour() is : "
         << returnedHour<< "\n\n\n\n\n";
}


//---------------------------------------------------------------
//Test SetHour() with invalid positive parameter
// and GetHour()
void TimeTest::Test4()
{

    Time timeObj;
    int returnedHour;
    bool setHourOutcome;

    //get the day value from dateObj
    returnedHour = timeObj.GetHour();


    cout << "Time Class Test 4 : Test .SetHour() "
         << "and .GetHour() with invalid positive parameter "
         << '\n' << "for .SetHour() " << '\n';

    cout << setfill('#') << setw(60) << "" << '\n';

    cout << "After creating a Time instance " << '\n';

    cout << setfill('-') << setw(35) << "" << '\n';

    cout << "the return value of .GetTime() is : "
         << returnedHour << "\n\n\n";

         //--------------------------------------

    setHourOutcome = timeObj.SetHour(100);
    returnedHour = timeObj.GetHour();

    cout << "After setting the Time hour as "
         << "\'100\' "<< '\n' << "using the "
         << "method .SetHour()" << '\n';

    cout << setfill('-') << setw(35) << "" << '\n';

    cout << "the boolean return value of .SetHour() is : "
         << boolalpha << setHourOutcome << '\n';

    cout << "the return value of .GetHour() is : "
         << returnedHour<< "\n\n\n\n\n";
}


//--------------------------------------------------------------
//Test SetMinute() with valid parameter and
// GetMinute()
void TimeTest::Test5()
{
    Time timeObj;
    int returnedMinute;
    bool setMinuteOutcome;

    //get the minute value from timeObj
    returnedMinute= timeObj.GetMinute();



    cout << "Time Class Test 5 : Test .SetMinute() "
         << "and .GetMinute() with valid  parameter "
         << '\n' << "for .SetMinute() " << '\n';

    cout << setfill('#') << setw(60) << "" << '\n';

    cout << "After creating a Time instance " << '\n';

    cout << setfill('-') << setw(35) << "" << '\n';

    cout << "the return value of .GetMinute() is : "
         << returnedMinute << "\n\n\n";

         //-------------------------------------------

    setMinuteOutcome = timeObj.SetMinute(6);
    returnedMinute = timeObj.GetMinute();

    cout << "After setting the Time minute as "
         << "\'6\' "<< '\n' << "using the "
         << "method .SetMinute()" << '\n';

    cout << setfill('-') << setw(35) << "" << '\n';

    cout << "the boolean return value of .SetMinute() is : "
         << boolalpha << setMinuteOutcome << '\n';

    cout << "the return value of .GetMinute() is : "
         << returnedMinute << "\n\n\n\n\n";
}


//--------------------------------------------------------------
//Test SetMinute() with invalid negative parameter
// and GetMinute()
void TimeTest::Test6()
{

    Time timeObj;
    int returnedMinute;
    bool setMinuteOutcome;


    //get the minute value from timeObj
    returnedMinute= timeObj.GetMinute();


    cout << "Time Class Test 6 : Test .SetMinute() "
         << "and .GetMinute() with invalid negative parameter "
         << '\n' << "for .SetMinute() " << '\n';

    cout << setfill('#') << setw(60) << "" << '\n';

    cout << "After creating a Time instance " << '\n';

    cout << setfill('-') << setw(35) << "" << '\n';

    cout << "the return value of .GetMinute() is : "
         << returnedMinute << "\n\n\n";


         //--------------------------------------------

    setMinuteOutcome = timeObj.SetMinute(-10);
    returnedMinute = timeObj.GetMinute();

    cout << "After setting the Time minute as "
         << "\'-10\' "<< '\n' << "using the "
         << "method .SetMinute()" << '\n';

    cout << setfill('-') << setw(35) << "" << '\n';

    cout << "the boolean return value of .SetMinute() is : "
         << boolalpha << setMinuteOutcome << '\n';

    cout << "the return value of .GetMinute() is : "
         << returnedMinute << "\n\n\n\n\n";

}


//--------------------------------------------------------------
//Test SetMinute() with invalid positive parameter
// and GetMinute()
void TimeTest::Test7()
{

    Time timeObj;
    int returnedMinute;
    bool setMinuteOutcome;


    //get the minute value from timeObj
    returnedMinute = timeObj.GetMinute();


    cout << "Time Class Test 7 : Test .SetMinute() "
         << "and .GetMinute() with invalid positive parameter "
         << '\n' << "for .SetMinute() " << '\n';

    cout << setfill('#') << setw(60) << "" << '\n';

    cout << "After creating a Time instance " << '\n';

    cout << setfill('-') << setw(35) << "" << '\n';

    cout << "the return value of .GetMinute() is : "
         << returnedMinute << "\n\n\n";

         //------------------------------------------------

    setMinuteOutcome = timeObj.SetMinute(100);
    returnedMinute = timeObj.GetMinute();

    cout << "After setting the Time minute as "
         << "\'100\' "<< '\n' << "using the "
         << "method .SetMinute()" << '\n';

    cout << setfill('-') << setw(35) << "" << '\n';

    cout << "the boolean return value of .SetMinute() is : "
         << boolalpha << setMinuteOutcome << '\n';

    cout << "the return value of .GetMinute() is : "
         << returnedMinute<< "\n\n\n\n\n";
}


//--------------------------------------------------------------
//Test SetSecond() with valid parameter and
// GetSecond()
void TimeTest::Test8()
{

    Time timeObj;
    int returnedSecond;
    bool setSecondOutcome;


    //get the second value from timeObj
    returnedSecond = timeObj.GetSecond();


    cout << "Time Class Test 8 : Test .SetSecond() "
         << "and .GetSecond() with valid parameter "
         << '\n' << "for .SetSecond() " << '\n';

    cout << setfill('#') << setw(60) << "" << '\n';

    cout << "After creating a Time instance " << '\n';

    cout << setfill('-') << setw(35) << "" << '\n';

    cout << "the return value of .GetSecond() is : "
         << returnedSecond << "\n\n\n";

         //-------------------------------------------

    setSecondOutcome = timeObj.SetSecond(10);
    returnedSecond = timeObj.GetSecond();

    cout << "After setting the Time second as "
         << "\'10\' "<< '\n' << "using the "
         << "method .SetSecond()" << '\n';

    cout << setfill('-') << setw(35) << "" << '\n';

    cout << "the boolean return value of .SetSecond() is : "
         << boolalpha << setSecondOutcome << '\n';

    cout << "the return value of .GetSecond() is : "
         << returnedSecond << "\n\n\n\n\n";
}


//--------------------------------------------------------------
//Test SetSecond() with invalid negative parameter
// and GetSecond()
void TimeTest::Test9()
{

    Time timeObj;
    int returnedSecond;
    bool setSecondOutcome;


    //get the second value from timeObj
    returnedSecond= timeObj.GetSecond();



    cout << "Time Class Test 9 : Test .SetSecond() "
         << "and .GetSecond() with invalid negative "
         << '\n' << "parameter for .SetSecond() " << '\n';

    cout << setfill('#') << setw(60) << "" << '\n';

    cout << "After creating a Time instance " << '\n';

    cout << setfill('-') << setw(35) << "" << '\n';

    cout << "the return value of .GetSecond() is : "
         << returnedSecond << "\n\n\n";

         //-------------------------------------

    setSecondOutcome = timeObj.SetSecond(-4);
    returnedSecond = timeObj.GetSecond();

    cout << "After setting the Time second as "
         << "\'-4\' "<< '\n' << "using the "
         << "method .SetSecond()" << '\n';

    cout << setfill('-') << setw(35) << "" << '\n';

    cout << "the boolean return value of .SetSecond() is : "
         << boolalpha << setSecondOutcome << '\n';

    cout << "the return value of .GetSecond() is : "
         << returnedSecond << "\n\n\n\n\n";
}


//--------------------------------------------------------------
//Test SetSecond() with invalid positive parameter
// and GetSecond()
void TimeTest::Test10()
{
    Time timeObj;
    int returnedSecond;
    bool setSecondOutcome;


    //get the second value from timeObj
    returnedSecond= timeObj.GetSecond();



    cout << "Time Class Test 10 : Test .SetSecond() "
         << "and .GetSecond() with invalid positive "
         << '\n' << "parameter for .SetSecond() " << '\n';

    cout << setfill('#') << setw(60) << "" << '\n';

    cout << "After creating a Time instance " << '\n';

    cout << setfill('-') << setw(35) << "" << '\n';

    cout << "the return value of .GetSecond() is : "
         << returnedSecond << "\n\n\n";

         //-------------------------------------

    setSecondOutcome = timeObj.SetSecond(100);
    returnedSecond = timeObj.GetSecond();

    cout << "After setting the Time second as "
         << "\'100\' "<< '\n' << "using the "
         << "method .SetSecond()" << '\n';

    cout << setfill('-') << setw(35) << "" << '\n';

    cout << "the boolean return value of .SetSecond() is : "
         << boolalpha << setSecondOutcome << '\n';

    cout << "the return value of .GetSecond() is : "
         << returnedSecond << "\n\n\n\n\n";
}
