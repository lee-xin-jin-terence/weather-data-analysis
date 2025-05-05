#include "TwoDimensionalBstTest.h"

void TwoDimensionalBstTest::RunTest()
{
        //Test constructor and .IsEmpty()
    Test1();

        //Test .Insert() for an empty tree
        //and .IsEmpty()
    Test2();

        //Test .Insert() for a date-time keys pair
        //that already exists
    Test3();

        //Test .Insert() for a date-time composite key
        //where the date key exists but not the
        //time key
    Test4();

        //Test .Insert() for a date-time composite key
        //where the date-key doesn't exists but the
        //time key does
    Test5();

        //Test .Delete() for an existing date-time
        //composite key
    Test6();

        //Test .Delete() for an empty tree
    Test7();

        //Test .Delete() for a non-existent date-time
        //composite key from a non-empty tree where the
        //date key exists but not the time key
    Test8();

        //Test .Delete() for a non-existent date-time
        //composite key from a non-empty tree where the
        //date key does not exists but the time key
        //exists
    Test9();

        //Test .Search() for an existing date-time
        //keys pair
    Test10();

        //Test .Search() for an empty tree
    Test11();

        //Test .Search() for a non-existent date-time
        //composite key where the date key exists
        //but not the time key
    Test12();

        //Test .Search() for a non-existent date-time
        //composite key where the date key does not
        //exist but the time key exists
    Test13();

        //Test .Clear()
    Test14();

        //Test time taken to insert and search from one
        //year worth of date-time composite keys
    Test15();
}


//-------------------------------------------------------
bool TwoDimensionalBstTest::DateIsLessThan(
                    const Date& firstDate,
                    const Date& secondDate)
{
        /*
            STEP 1:
            Extract the day, month and year values from
            both Date instances
        */
    int firstDateDay = firstDate.GetDay();
    int firstDateMonth = firstDate.GetMonth();
    int firstDateYear = firstDate.GetYear();

    int secondDateDay = secondDate.GetDay();
    int secondDateMonth = secondDate.GetMonth();
    int secondDateYear = secondDate.GetYear();


        /*
            Step 2:
            Return a boolean value on whether firstDate
            is less than secondDate
        */
    return ((firstDateYear < secondDateYear)
                          ||
            (firstDateYear == secondDateYear &&
             firstDateMonth < secondDateMonth)
                          ||
            (firstDateYear == secondDateYear &&
             firstDateMonth == secondDateMonth &&
             firstDateDay < secondDateDay));
}


//------------------------------------------------------------
bool TwoDimensionalBstTest::DateIsEqualTo(
                    const Date& firstDate,
                    const Date& secondDate)
{
        /*
            STEP 1:
            Extract the day, month and year values from
            both Date instances
        */
    int firstDateDay = firstDate.GetDay();
    int firstDateMonth = firstDate.GetMonth();
    int firstDateYear = firstDate.GetYear();

    int secondDateDay = secondDate.GetDay();
    int secondDateMonth = secondDate.GetMonth();
    int secondDateYear = secondDate.GetYear();


        /*
            STEP 2:
            Return a boolean value on whether firstDate
            is equal to secondDate
        */
    return (firstDateYear == secondDateYear &&
             firstDateMonth == secondDateMonth &&
             firstDateDay == secondDateDay);
}


//---------------------------------------------------------
bool TwoDimensionalBstTest::DateIsMoreThan(
                    const Date& firstDate,
                    const Date& secondDate)
{
        /*
            STEP 1:
            Extract the day, month and year values from
            both Date instances
        */
    int firstDateDay = firstDate.GetDay();
    int firstDateMonth = firstDate.GetMonth();
    int firstDateYear = firstDate.GetYear();

    int secondDateDay = secondDate.GetDay();
    int secondDateMonth = secondDate.GetMonth();
    int secondDateYear = secondDate.GetYear();


        /*
            STEP 2:
            Return a boolean value on whether firstDate
            is more than secondDate
        */
    return ((firstDateYear > secondDateYear)
                          ||
            (firstDateYear == secondDateYear &&
             firstDateMonth > secondDateMonth)
                          ||
            (firstDateYear == secondDateYear &&
             firstDateMonth == secondDateMonth &&
             firstDateDay > secondDateDay));
}


//------------------------------------------------------
bool TwoDimensionalBstTest::TimeIsLessThan(
                    const Time& firstTime,
                    const Time& secondTime)
{

        /*
            STEP 1:
            Extract the hour, minute and second values
            from both Time instances
        */
    int firstTimeHour = firstTime.GetHour();
    int firstTimeMinute = firstTime.GetMinute();
    int firstTimeSecond = firstTime.GetSecond();

    int secondTimeHour = secondTime.GetHour();
    int secondTimeMinute = secondTime.GetMinute();
    int secondTimeSecond = secondTime.GetSecond();


        /*
            STEP 2:
            Return a boolean value on whether firstTime
            is less than secondTime

        */
    return ( (firstTimeHour < secondTimeHour)
                            ||
             (firstTimeHour == secondTimeHour &&
              firstTimeMinute < secondTimeMinute)
                            ||
             (firstTimeHour == secondTimeHour &&
              firstTimeMinute == secondTimeMinute &&
              firstTimeSecond < secondTimeSecond));

}


//----------------------------------------------------
bool TwoDimensionalBstTest::TimeIsEqualTo(
                   const Time& firstTime,
                   const Time& secondTime)
{

        /*
            STEP 1:
            Extract the hour, minute and second values
            from both Time instances
        */
    int firstTimeHour = firstTime.GetHour();
    int firstTimeMinute = firstTime.GetMinute();
    int firstTimeSecond = firstTime.GetSecond();

    int secondTimeHour = secondTime.GetHour();
    int secondTimeMinute = secondTime.GetMinute();
    int secondTimeSecond = secondTime.GetSecond();


        /*
            STEP 2:
            Return a boolean value on whether firstTime
            is equal to secondTime

        */
    return (  firstTimeHour == secondTimeHour &&
              firstTimeMinute == secondTimeMinute &&
              firstTimeSecond == secondTimeSecond);
}


//------------------------------------------------------
bool TwoDimensionalBstTest::
    TimeIsMoreThan( const Time& firstTime,
                    const Time& secondTime)
{

        /*
            STEP 1:
            Extract the hour, minute and second values
            from both Time instances
        */
    int firstTimeHour = firstTime.GetHour();
    int firstTimeMinute = firstTime.GetMinute();
    int firstTimeSecond = firstTime.GetSecond();

    int secondTimeHour = secondTime.GetHour();
    int secondTimeMinute = secondTime.GetMinute();
    int secondTimeSecond = secondTime.GetSecond();

        /*
            STEP 2:
            Return a boolean value on whether firstTime
            is more than secondTime

        */
    return ( (firstTimeHour > secondTimeHour)
                            ||
             (firstTimeHour == secondTimeHour &&
              firstTimeMinute > secondTimeMinute)
                            ||
             (firstTimeHour == secondTimeHour &&
              firstTimeMinute == secondTimeMinute &&
              firstTimeSecond > secondTimeSecond));
}


//---------------------------------------------------
//Test constructor and .IsEmpty()
void TwoDimensionalBstTest::Test1()
{
        //note that this is a typedef
        //refer to the test class declaration
    DateTime2DBst tree(DateIsLessThan,
                       DateIsEqualTo,
                       DateIsMoreThan,
                       TimeIsLessThan,
                       TimeIsEqualTo,
                       TimeIsMoreThan);

    cout << "TwoDimensionalBst Test 1 : Test Constructor "
         << "and .IsEmpty() "
         << '\n';

    cout << setfill('#') << setw(60) << "" << '\n';

    cout << "After creating a TwoDimensionalBst instance "
         << '\n';

    cout << setfill('-') << setw(35) << "" << '\n';

    cout << boolalpha;

    cout << "the return value of .IsEmpty() is : "
         << tree.IsEmpty() << '\n';

    cout << "\n\n\n\n\n";


}


//--------------------------------------------------------
//Test .Insert() for an empty tree
//and .IsEmpty()
void TwoDimensionalBstTest::Test2()
{

        //note that this is a typedef
        //refer to the test class declaration
    DateTime2DBst tree(DateIsLessThan,
                       DateIsEqualTo,
                       DateIsMoreThan,
                       TimeIsLessThan,
                       TimeIsEqualTo,
                       TimeIsMoreThan);

    bool insertOutcome;


    Date tempDate;
    Time tempTime;

    tempDate.SetDay(2);
    tempDate.SetMonth(3);
    tempDate.SetYear(2004);

    tempTime.SetHour(23);
    tempTime.SetMinute(2);
    tempTime.SetSecond(45);



    cout << "TwoDimensionalBst Test 2 : Test .Insert() "
         << "for an empty tree "
         << '\n' << "and .IsEmpty() "
         << '\n';

    cout << setfill('#') << setw(60) << "" << '\n';

    cout << "After creating a TwoDimensionalBst instance "
         << '\n';

    cout << setfill('-') << setw(35) << "" << '\n';

    cout << boolalpha;

    cout << "the return value of .IsEmpty() is : "
         << tree.IsEmpty() << '\n';

    cout << "\n\n\n" ;

         //-------------------------------------------

    insertOutcome = tree.Insert(tempDate, tempTime);


    cout << "After setting the date(first key) as "
         << " \'2/3/2004\' and time(second key) as \'23:02:45\' "
         << '\n' << " and inserting them into the tree : "
         << '\n';

    cout << setfill('-') << setw(35) << "" << '\n';

    cout << "the return value of .IsEmpty() is : "
         << tree.IsEmpty() << '\n';

    cout << "the return value of .Insert() is : "
         << insertOutcome;

    cout << "\n\n\n\n\n";

}


//----------------------------------------------------------
//Test .Insert() for a date-time composite key
//that already exists
void TwoDimensionalBstTest::Test3()
{

         //note that this is a typedef
        //refer to the test class declaration
    DateTime2DBst tree(DateIsLessThan,
                       DateIsEqualTo,
                       DateIsMoreThan,
                       TimeIsLessThan,
                       TimeIsEqualTo,
                       TimeIsMoreThan);

    bool insertOutcome;


    Date tempDate;

    Time tempTime;


    tempDate.SetDay(2);
    tempDate.SetMonth(3);
    tempDate.SetYear(2004);

    tempTime.SetHour(23);
    tempTime.SetMinute(2);
    tempTime.SetSecond(45);

        //-------------------------------------------------

    cout << "TwoDimensionalBst Test 3 : Test .Insert() "
         << "for a  " << '\n'
         << "composite key that already exists"
         << '\n';


    cout << setfill('#') << setw(60) << "" << '\n';

    cout << "After creating a TwoDimensionalBst instance "
         << '\n';

    cout << setfill('-') << setw(35) << "" << '\n';

    cout << boolalpha;

    cout << "the return value of .IsEmpty() is : "
         << tree.IsEmpty() << '\n';

    cout << "\n\n\n" ;

        //----------------------------------------------


    insertOutcome = tree.Insert(tempDate, tempTime);


    cout << "After setting the date(first key) as "
         << " \'2/3/2004\' and time(second key) as \'23:02:45\' "
         << '\n' << " and inserting them into the tree : "
         << '\n';

    cout << setfill('-') << setw(35) << "" << '\n';


    cout << "the return value of .IsEmpty() is : "
         << tree.IsEmpty() << '\n';

    cout << "the return value of .Insert() is : "
         << insertOutcome;

    cout << "\n\n\n";


        //------------------------------------------------


    insertOutcome = tree.Insert(tempDate, tempTime);


    cout << "Now inserting the same composite key where "
         << "date(first key) as \'2/3/2004\' " << '\n'
         << "and time(second key) as \'23:02:45\' "
         << "and inserting them into the tree : "
         << '\n';

    cout << setfill('-') << setw(35) << "" << '\n';


    cout << "the return value of .IsEmpty() is : "
         << tree.IsEmpty() << '\n';

    cout << "the return value of .Insert() is : "
         << insertOutcome;

    cout << "\n\n\n\n\n";


}


//----------------------------------------------------------

void TwoDimensionalBstTest::Test4()
{


         //note that this is a typedef
        //refer to the test class declaration
    DateTime2DBst tree(DateIsLessThan,
                       DateIsEqualTo,
                       DateIsMoreThan,
                       TimeIsLessThan,
                       TimeIsEqualTo,
                       TimeIsMoreThan);

    bool insertOutcome;


    Date tempDate;

    Time tempTime1;
    Time tempTime2;


    tempDate.SetDay(2);
    tempDate.SetMonth(3);
    tempDate.SetYear(2004);

    tempTime1.SetHour(23);
    tempTime1.SetMinute(2);
    tempTime1.SetSecond(45);


    tempTime2.SetHour(12);
    tempTime2.SetMinute(3);
    tempTime2.SetSecond(35);

        //-------------------------------------------------

    cout << "TwoDimensionalBst Test 4 : Test .Insert() "
         << "for a composite " << '\n'
         << "key where the first key exists but the "
         << "second key doesn't exist" << '\n';


    cout << setfill('#') << setw(60) << "" << '\n';

    cout << "After creating a TwoDimensionalBst instance "
         << '\n';

    cout << setfill('-') << setw(35) << "" << '\n';

    cout << boolalpha;

    cout << "the return value of .IsEmpty() is : "
         << tree.IsEmpty() << '\n';

    cout << "\n\n\n" ;

        //----------------------------------------------


    insertOutcome = tree.Insert(tempDate, tempTime1);


    cout << "After setting the date(first key) as "
         << " \'2/3/2004\' and time(second key) as \'23:02:45\' "
         << '\n' << " and inserting them into the tree : "
         << '\n';

    cout << setfill('-') << setw(35) << "" << '\n';


    cout << "the return value of .IsEmpty() is : "
         << tree.IsEmpty() << '\n';

    cout << "the return value of .Insert() is : "
         << insertOutcome;

    cout << "\n\n\n";

        //------------------------------------------------

    insertOutcome = tree.Insert(tempDate, tempTime2);


    cout << "After setting the date(first key) as "
         << " \'2/3/2004\' and time(second key) as \'12:03:35\' "
         << '\n' << " and inserting them into the tree : "
         << '\n';

    cout << setfill('-') << setw(35) << "" << '\n';


    cout << "the return value of .IsEmpty() is : "
         << tree.IsEmpty() << '\n';

    cout << "the return value of .Insert() is : "
         << insertOutcome;

    cout << "\n\n\n\n\n";

}


//----------------------------------------------------------
void TwoDimensionalBstTest::Test5()
{


         //note that this is a typedef
        //refer to the test class declaration
    DateTime2DBst tree(DateIsLessThan,
                       DateIsEqualTo,
                       DateIsMoreThan,
                       TimeIsLessThan,
                       TimeIsEqualTo,
                       TimeIsMoreThan);

    bool insertOutcome;


    Date tempDate1;
    Date tempDate2;

    Time tempTime;


    tempDate1.SetDay(2);
    tempDate1.SetMonth(3);
    tempDate1.SetYear(2004);

    tempDate2.SetDay(13);
    tempDate2.SetMonth(3);
    tempDate2.SetYear(2020);


    tempTime.SetHour(23);
    tempTime.SetMinute(2);
    tempTime.SetSecond(45);


        //-------------------------------------------------

    cout << "TwoDimensionalBst Test 5 : Test .Insert() "
         << "for a composite " << '\n'
         << "key where the first key doesn't exist but the "
         << "second key exists" << '\n';


    cout << setfill('#') << setw(60) << "" << '\n';

    cout << "After creating a TwoDimensionalBst instance "
         << '\n';

    cout << setfill('-') << setw(35) << "" << '\n';

    cout << boolalpha;

    cout << "the return value of .IsEmpty() is : "
         << tree.IsEmpty() << '\n';

    cout << "\n\n\n" ;

        //-------------------------------------------------


    insertOutcome = tree.Insert(tempDate1, tempTime);


    cout << "After setting the date(first key) as "
         << " \'2/3/2004\' and time(second key) as \'23:02:45\' "
         << '\n' << " and inserting them into the tree : "
         << '\n';

    cout << setfill('-') << setw(35) << "" << '\n';


    cout << "the return value of .IsEmpty() is : "
         << tree.IsEmpty() << '\n';

    cout << "the return value of .Insert() is : "
         << insertOutcome;

    cout << "\n\n\n";


        //----------------------------------------------

    insertOutcome = tree.Insert(tempDate2, tempTime);


    cout << "After setting the date(first key) as "
         << " \'13/3/2020\' and time(second key) as \'23:02:45\'"
         << '\n' << " and inserting them into the tree : "
         << '\n';

    cout << setfill('-') << setw(35) << "" << '\n';


    cout << "the return value of .IsEmpty() is : "
         << tree.IsEmpty() << '\n';

    cout << "the return value of .Insert() is : "
         << insertOutcome;

    cout << "\n\n\n\n\n";

}


//----------------------------------------------------------
void TwoDimensionalBstTest::Test6()
{

         //note that this is a typedef
        //refer to the test class declaration
    DateTime2DBst tree(DateIsLessThan,
                       DateIsEqualTo,
                       DateIsMoreThan,
                       TimeIsLessThan,
                       TimeIsEqualTo,
                       TimeIsMoreThan);

    bool insertOutcome;

    bool deleteOutcome;


    Date tempDate;
    Time tempTime;

    tempDate.SetDay(2);
    tempDate.SetMonth(3);
    tempDate.SetYear(2004);

    tempTime.SetHour(12);
    tempTime.SetMinute(2);
    tempTime.SetSecond(45);



    cout << "TwoDimensionalBst Test 6 : Test .Delete() "
         << "for an existing composite key "
         << '\n';

    cout << setfill('#') << setw(60) << "" << '\n';

    cout << "After creating a TwoDimensionalBst instance "
         << '\n';

    cout << setfill('-') << setw(35) << "" << '\n';

    cout << boolalpha;

    cout << "the return value of .IsEmpty() is : "
         << tree.IsEmpty() << '\n';

    cout << "\n\n\n" ;

         //-------------------------------------------

    insertOutcome = tree.Insert(tempDate, tempTime);


    cout << "After setting the date(first key) as "
         << " \'2/3/2004\' and time(second key) as \'23:02:45\' "
         << '\n' << " and inserting them into the tree : "
         << '\n';

    cout << setfill('-') << setw(35) << "" << '\n';


    cout << "the return value of .IsEmpty() is : "
         << tree.IsEmpty() << '\n';

    cout << "the return value of .Insert() is : "
         << insertOutcome;

    cout << "\n\n\n";

        //-------------------------------------------


    deleteOutcome = tree.Delete(tempDate, tempTime);

    cout << "After deleting the existing date(first key) as "
         << " \'2/3/2004\' " << '\n'
         << "and time(second key) as \'23:02:45\' "
         << '\n' << " composite key from the tree : "
         << '\n';

    cout << setfill('-') << setw(35) << "" << '\n';

    cout << "the return value of .IsEmpty() is : "
         << tree.IsEmpty() << '\n';

    cout << "the return value of .Delete() is : "
         << deleteOutcome;

    cout << "\n\n\n\n\n";

}


//----------------------------------------------------------
void TwoDimensionalBstTest::Test7()
{

         //note that this is a typedef
        //refer to the test class declaration
    DateTime2DBst tree(DateIsLessThan,
                       DateIsEqualTo,
                       DateIsMoreThan,
                       TimeIsLessThan,
                       TimeIsEqualTo,
                       TimeIsMoreThan);

    bool deleteOutcome;

    Date tempDate;
    Time tempTime;


    tempDate.SetDay(2);
    tempDate.SetMonth(3);
    tempDate.SetYear(2004);

    tempTime.SetHour(12);
    tempTime.SetMinute(2);
    tempTime.SetSecond(45);


    cout << "TwoDimensionalBst Test 7 : Test .Delete() "
         << "from an empty tree "
         << '\n';

    cout << setfill('#') << setw(60) << "" << '\n';

    cout << "After creating a TwoDimensionalBst instance "
         << '\n';

    cout << setfill('-') << setw(35) << "" << '\n';

    cout << boolalpha;

    cout << "the return value of .IsEmpty() is : "
         << tree.IsEmpty() << '\n';

    cout << "\n\n\n" ;

        //--------------------------------------------


    deleteOutcome = tree.Delete(tempDate, tempTime);

    cout << "After deleting the non-existent date(first key) as "
         << " \'2/3/2004\' " << '\n'
         << "and time(second key) as \'23:02:45\' "
         << " composite key from the empty tree : "
         << '\n';

    cout << setfill('-') << setw(35) << "" << '\n';

    cout << "the return value of .IsEmpty() is : "
         << tree.IsEmpty() << '\n';

    cout << "the return value of .Delete() is : "
         << deleteOutcome;

    cout << "\n\n\n\n\n";

}


//---------------------------------------------------------
void TwoDimensionalBstTest::Test8()
{

         //note that this is a typedef
        //refer to the test class declaration
    DateTime2DBst tree(DateIsLessThan,
                       DateIsEqualTo,
                       DateIsMoreThan,
                       TimeIsLessThan,
                       TimeIsEqualTo,
                       TimeIsMoreThan);

    bool insertOutcome;
    bool deleteOutcome;

    Date tempDate;


    Time tempTime1;
    Time tempTime2;


    tempDate.SetDay(2);
    tempDate.SetMonth(3);
    tempDate.SetYear(2004);

    tempTime1.SetHour(23);
    tempTime1.SetMinute(2);
    tempTime1.SetSecond(45);


    tempTime2.SetHour(12);
    tempTime2.SetMinute(3);
    tempTime2.SetSecond(35);

        //---------------------------------------------

    cout << "TwoDimensionalBst Test 8 : Test .Delete() "
         << "from non-existent composite key "
         << '\n' << "from a tree where the "
         << "first key exists but second key doesn't exists "
         << '\n';

    cout << setfill('#') << setw(60) << "" << '\n';

    cout << "After creating a TwoDimensionalBst instance "
         << '\n';

    cout << setfill('-') << setw(35) << "" << '\n';

    cout << boolalpha;

    cout << "the return value of .IsEmpty() is : "
         << tree.IsEmpty() << '\n';

    cout << "\n\n\n" ;

        //--------------------------------------------

    insertOutcome = tree.Insert(tempDate, tempTime1);


    cout << "After setting the date(first key) as "
         << " \'2/3/2004\' " << '\n'
         << "and time(second key) as \'23:02:45\' "
         << '\n' << " and inserting them into the tree : "
         << '\n';

    cout << setfill('-') << setw(35) << "" << '\n';


    cout << "the return value of .IsEmpty() is : "
         << tree.IsEmpty() << '\n';

    cout << "the return value of .Insert() is : "
         << insertOutcome;

    cout << "\n\n\n";

        //---------------------------------------------

    deleteOutcome = tree.Delete(tempDate, tempTime2);


    cout << "After deleting the non-existent date(first key) as "
         << '\n' << " \'2/3/2004\' and time(second key) "
         << "as \'12:03:35\' composite key from the tree : "
         << '\n';

    cout << setfill('-') << setw(35) << "" << '\n';

    cout << "the return value of .IsEmpty() is : "
         << tree.IsEmpty() << '\n';

    cout << "the return value of .Delete() is : "
         << deleteOutcome;

    cout << "\n\n\n\n\n";

}


//---------------------------------------------------------
void TwoDimensionalBstTest::Test9()
{

         //note that this is a typedef
        //refer to the test class declaration
    DateTime2DBst tree(DateIsLessThan,
                       DateIsEqualTo,
                       DateIsMoreThan,
                       TimeIsLessThan,
                       TimeIsEqualTo,
                       TimeIsMoreThan);

    bool insertOutcome;
    bool deleteOutcome;

    Date tempDate1;
    Date tempDate2;

    Time tempTime;


    tempDate1.SetDay(2);
    tempDate1.SetMonth(3);
    tempDate1.SetYear(2004);

    tempDate2.SetDay(13);
    tempDate2.SetMonth(3);
    tempDate2.SetYear(2020);

    tempTime.SetHour(23);
    tempTime.SetMinute(2);
    tempTime.SetSecond(45);

        //--------------------------------------------


    cout << "TwoDimensionalBst Test 9 : Test .Delete() "
         << "from non-existent composite key "
         << '\n' << "from a non-empty tree where the "
         << "first key doesn't exists but second key exists "
         << '\n';


    cout << setfill('#') << setw(60) << "" << '\n';

    cout << "After creating a TwoDimensionalBst instance "
         << '\n';

    cout << setfill('-') << setw(35) << "" << '\n';

    cout << boolalpha;

    cout << "the return value of .IsEmpty() is : "
         << tree.IsEmpty() << '\n';

    cout << "\n\n\n" ;

        //----------------------------------------------

    insertOutcome = tree.Insert(tempDate1, tempTime);


    cout << "After setting the date(first key) as "
         << " \'2/3/2004\' and time(second key) as \'23:02:45\' "
         << '\n' << " and inserting them into the tree : "
         << '\n';

    cout << setfill('-') << setw(35) << "" << '\n';


    cout << "the return value of .IsEmpty() is : "
         << tree.IsEmpty() << '\n';

    cout << "the return value of .Insert() is : "
         << insertOutcome;

    cout << "\n\n\n";

        //---------------------------------------------

    deleteOutcome = tree.Delete(tempDate2, tempTime);


    cout << "After deleting the non-existent date(first key) as "
         << " \'13/3/2020\' " << '\n'
         << "and time(second key) as \'23:02:45\' "
         <<  "composite key from the tree : "
         << '\n';

    cout << setfill('-') << setw(35) << "" << '\n';

    cout << "the return value of .IsEmpty() is : "
         << tree.IsEmpty() << '\n';

    cout << "the return value of .Delete() is : "
         << deleteOutcome;

    cout << "\n\n\n\n\n";

}


//-------------------------------------------------------------
void TwoDimensionalBstTest::Test10()
{

         //note that this is a typedef
        //refer to the test class declaration
    DateTime2DBst tree(DateIsLessThan,
                       DateIsEqualTo,
                       DateIsMoreThan,
                       TimeIsLessThan,
                       TimeIsEqualTo,
                       TimeIsMoreThan);

    bool insertOutcome;
    bool searchOutcome;

    Date tempDate;

    Time tempTime;


    tempDate.SetDay(2);
    tempDate.SetMonth(3);
    tempDate.SetYear(2004);


    tempTime.SetHour(23);
    tempTime.SetMinute(2);
    tempTime.SetSecond(45);


        //------------------------------------------------

    cout << "TwoDimensionalBst Test 10 :Test .Search() "
         << "for an existing composite key "
         << '\n';


    cout << setfill('#') << setw(60) << "" << '\n';

    cout << "After creating a TwoDimensionalBst instance "
         << '\n';

    cout << setfill('-') << setw(35) << "" << '\n';

    cout << boolalpha;

    cout << "the return value of .IsEmpty() is : "
         << tree.IsEmpty() << '\n';

    cout << "\n\n\n" ;

        //------------------------------------------------

    insertOutcome = tree.Insert(tempDate, tempTime);


    cout << "After setting the date(first key) as "
         << " \'2/3/2004\' and time(second key) as \'23:02:45\' "
         << '\n' << " and inserting them into the tree : "
         << '\n';

    cout << setfill('-') << setw(35) << "" << '\n';


    cout << "the return value of .IsEmpty() is : "
         << tree.IsEmpty() << '\n';

    cout << "the return value of .Insert() is : "
         << insertOutcome;

    cout << "\n\n\n";

        //--------------------------------------------

    searchOutcome = tree.Search(tempDate, tempTime);


    cout << "After searching for the composite key "
         << "where date(first key) is " << '\n'
         << " \'2/3/2004\' and time(second key) is \'23:02:45\' "
         << '\n';

    cout << setfill('-') << setw(35) << "" << '\n';


    cout << "the return value of .IsEmpty() is : "
         << tree.IsEmpty() << '\n';

    cout << "the return value of .Search() is : "
         << searchOutcome;

    cout << "\n\n\n\n\n";

}


//--------------------------------------------------------------
void TwoDimensionalBstTest::Test11()
{

         //note that this is a typedef
        //refer to the test class declaration
    DateTime2DBst tree(DateIsLessThan,
                       DateIsEqualTo,
                       DateIsMoreThan,
                       TimeIsLessThan,
                       TimeIsEqualTo,
                       TimeIsMoreThan);

    bool searchOutcome;

    Date tempDate;

    Time tempTime;


    tempDate.SetDay(2);
    tempDate.SetMonth(3);
    tempDate.SetYear(2004);


    tempTime.SetHour(23);
    tempTime.SetMinute(2);
    tempTime.SetSecond(45);

        //------------------------------------------------

    cout << "TwoDimensionalBst Test 11 :Test .Search() "
         << "from an empty tree "
         << '\n';


    cout << setfill('#') << setw(60) << "" << '\n';

    cout << "After creating a TwoDimensionalBst instance "
         << '\n';

    cout << setfill('-') << setw(35) << "" << '\n';

    cout << boolalpha;

    cout << "the return value of .IsEmpty() is : "
         << tree.IsEmpty() << '\n';

    cout << "\n\n\n" ;

        //-----------------------------------------------


    searchOutcome = tree.Search(tempDate, tempTime);


    cout << "After searching for the composite key "
         << "where date(first key) is " << '\n'
         << " \'2/3/2004\' and time(second key) is \'23:02:45\' "
         << '\n';

    cout << setfill('-') << setw(35) << "" << '\n';


    cout << "the return value of .IsEmpty() is : "
         << tree.IsEmpty() << '\n';

    cout << "the return value of .Search() is : "
         << searchOutcome
         << "\n\n\n\n\n";

}


//-------------------------------------------------------------
void TwoDimensionalBstTest::Test12()
{

         //note that this is a typedef
        //refer to the test class declaration
    DateTime2DBst tree(DateIsLessThan,
                       DateIsEqualTo,
                       DateIsMoreThan,
                       TimeIsLessThan,
                       TimeIsEqualTo,
                       TimeIsMoreThan);

    bool insertOutcome;
    bool searchOutcome;

    Date tempDate;

    Time tempTime1;
    Time tempTime2;


    tempDate.SetDay(2);
    tempDate.SetMonth(3);
    tempDate.SetYear(2004);


    tempTime1.SetHour(23);
    tempTime1.SetMinute(2);
    tempTime1.SetSecond(45);


    tempTime2.SetHour(12);
    tempTime2.SetMinute(3);
    tempTime2.SetSecond(35);


    cout << "TwoDimensionalBst Test 12 :Test .Search() "
         << "for non-existent composite key "
         << '\n'
         << "where the first key exists but the second key "
         << "does not exists"
         << '\n';

    cout << setfill('#') << setw(60) << "" << '\n';

    cout << "After creating a TwoDimensionalBst instance "
         << '\n';

    cout << setfill('-') << setw(35) << "" << '\n';

    cout << boolalpha;

    cout << "the return value of .IsEmpty() is : "
         << tree.IsEmpty() << '\n';

    cout << "\n\n\n" ;

        //---------------------------------------------------

    insertOutcome = tree.Insert(tempDate, tempTime1);


    cout << "After setting the date(first key) as "
         << " \'2/3/2004\' and time(second key)as \'23:02:45\' "
         << '\n' << " and inserting them into the tree : "
         << '\n';

    cout << setfill('-') << setw(35) << "" << '\n';


    cout << "the return value of .IsEmpty() is : "
         << tree.IsEmpty() << '\n';

    cout << "the return value of .Insert() is : "
         << insertOutcome;

    cout << "\n\n\n";

        //---------------------------------------------------

    searchOutcome = tree.Search(tempDate, tempTime2);


    cout << "After searching for the composite key "
         << "where date(first key) is " << '\n'
         << " \'2/3/2004\' and time(second key) is \'12:03:35\' "
         << '\n';

    cout << setfill('-') << setw(35) << "" << '\n';


    cout << "the return value of .IsEmpty() is : "
         << tree.IsEmpty() << '\n';

    cout << "the return value of .Search() is : "
         << searchOutcome
         << "\n\n\n\n\n";

}


//-------------------------------------------------------------
void TwoDimensionalBstTest::Test13()
{

         //note that this is a typedef
        //refer to the test class declaration
    DateTime2DBst tree(DateIsLessThan,
                       DateIsEqualTo,
                       DateIsMoreThan,
                       TimeIsLessThan,
                       TimeIsEqualTo,
                       TimeIsMoreThan);

    bool insertOutcome;
    bool searchOutcome;

    Date tempDate1;
    Date tempDate2;

    Time tempTime;

    tempDate1.SetDay(2);
    tempDate1.SetMonth(3);
    tempDate1.SetYear(2004);

    tempDate2.SetDay(13);
    tempDate2.SetMonth(3);
    tempDate2.SetYear(2020);


    tempTime.SetHour(23);
    tempTime.SetMinute(2);
    tempTime.SetSecond(45);

        //-------------------------------------------------

    cout << "TwoDimensionalBst Test 13 :Test .Search() "
         << "for non-existent composite key "
         << '\n'
         << "where the first key doesn't exists but second key "
         << "exists"
         << '\n';

    cout << setfill('#') << setw(60) << "" << '\n';

    cout << "After creating a TwoDimensionalBst instance "
         << '\n';

    cout << setfill('-') << setw(35) << "" << '\n';

    cout << boolalpha;

    cout << "the return value of .IsEmpty() is : "
         << tree.IsEmpty() << '\n';

    cout << "\n\n\n" ;

        //-----------------------------------------------

    insertOutcome = tree.Insert(tempDate1, tempTime);


    cout << "After setting the date(first key) as "
         << " \'2/3/2004\' and time(second key) as \'23:02:45\' "
         << '\n' << " and inserting them into the tree : "
         << '\n';

    cout << setfill('-') << setw(35) << "" << '\n';


    cout << "the return value of .IsEmpty() is : "
         << tree.IsEmpty() << '\n';

    cout << "the return value of .Insert() is : "
         << insertOutcome;

    cout << "\n\n\n";

        //------------------------------------------------

    searchOutcome = tree.Search(tempDate2, tempTime);


    cout << "After searching for the composite key "
         << "where date(first key) is " << '\n'
         << " \'13/3/2020\' and time(second key) is \'23:02:45\' "
         << '\n';

    cout << setfill('-') << setw(35) << "" << '\n';


    cout << "the return value of .IsEmpty() is : "
         << tree.IsEmpty() << '\n';

    cout << "the return value of .Search() is : "
         << searchOutcome
         << "\n\n\n\n\n";

}


//----------------------------------------------------------
void TwoDimensionalBstTest::Test14()
{

         //note that this is a typedef
        //refer to the test class declaration
    DateTime2DBst tree(DateIsLessThan,
                       DateIsEqualTo,
                       DateIsMoreThan,
                       TimeIsLessThan,
                       TimeIsEqualTo,
                       TimeIsMoreThan);

    bool insertOutcome;

    Date tempDate;

    Time tempTime;


    cout << "TwoDimensionalBst Test 14 :Testing .Clear()"
         << '\n';

    cout << setfill('#') << setw(60) << "" << '\n';

    cout << "After creating a TwoDimensionalBst instance "
         << '\n';

    cout << setfill('-') << setw(35) << "" << '\n';

    cout << boolalpha;

    cout << "the return value of .IsEmpty() is : "
         << tree.IsEmpty() << '\n';

    cout << "\n\n\n" ;

        //---------------------------------------------------

    tempDate.SetYear(2020);
    tempDate.SetMonth(1);

    tempTime.SetHour(5);

    for (int day = 1; day <=5; day++)
    {

        tempDate.SetDay(day);


        for (int minute= 0; minute <=10 ;
            minute = minute+5)
        {

            tempTime.SetMinute(minute);

            tree.Insert(tempDate,tempTime);
        }
    }


    cout << "After inserting 15 composite keys "
         << '\n' << "into the binary search tree : "
         << '\n';

    cout << setfill('-') << setw(35) << "" << '\n';


    cout << "the return value of .IsEmpty() is : "
         << tree.IsEmpty() << '\n';

    cout << "\n\n\n";

        //------------------------------------------------

    tree.Clear();

    cout << "After calling .Clear() "
         << '\n';

    cout << setfill('-') << setw(35) << "" << '\n';


    cout << "the return value of .IsEmpty() is : "
         << tree.IsEmpty() << '\n';

    cout << "\n\n\n\n\n";

}


//---------------------------------------------------------
void TwoDimensionalBstTest::Test15()
{

         //note that this is a typedef
        //refer to the test class declaration
    DateTime2DBst tree(DateIsLessThan,
                       DateIsEqualTo,
                       DateIsMoreThan,
                       TimeIsLessThan,
                       TimeIsEqualTo,
                       TimeIsMoreThan);


    Date tempDate;

    Time tempTime;

    time_t startTime;
    time_t endTime;
    time_t timeTaken;

    cout << "TwoDimensionalBst Test 15 :Test time taken "
         << "for insertion of and searching from large  "
         << '\n' << " number of composite keys "
         << '\n';


    cout << setfill('#') << setw(60) << "" << '\n';

    cout << "Please be patient while the insertion of "
         << "967680 keys takes place "
         << "\n\n";

        //-----------------------------------------------

    startTime = time(nullptr);




    for (int year = 2010; year <=2020 ; year++)
    {
        tempDate.SetYear(year);

        for (int month = 1; month <=12 ; month++)
        {
            tempDate.SetMonth(month);

            for (int day = 1; day <=28; day++)
            {
                tempDate.SetDay(day);

                for (int hour = 0; hour <=23 ; hour++)
                {

                    tempTime.SetHour(hour);

                    for (int minute= 0; minute <=55 ;
                        minute = minute+5)
                    {

                        tempTime.SetMinute(minute);

                        tree.Insert(tempDate,tempTime);
                    }
                }

            }
        }
    }

    endTime = time(nullptr);

    timeTaken = endTime - startTime;


    cout << "Time taken to insert 967680 composite "
         << "keys is " << timeTaken << " seconds "
         << '\n';

        //----------------------------------------------------

    cout << "Time taken to search for the last composite key"
         << " inserted is ";

    startTime = time(nullptr);

    tree.Search(tempDate, tempTime);

    endTime = time(nullptr);

    timeTaken =  endTime - startTime;

    cout <<  timeTaken << " seconds";

    cout << "\n\n\n\n\n";

    tree.Clear();
}


//-------------------------------------------------------------

