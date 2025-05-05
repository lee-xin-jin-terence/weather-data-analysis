#include "UnaggregatedWeatherTest.h"


void UnaggregatedWeatherTest::RunTest()
{
        //Test the constructor, GetWindSpeed(),
        // GetTemperature() and GetSolarRadiation()
    Test1();

        //Test SetTime() and GetTime()
    Test2();

        // Test SetDate() and GetDate()
    Test3();

        // Test SetWindSpeed() and GetWindSpeed()
    Test4();

        // Test SetTemperature() and GetTemperature()
    Test5();

        // Test SetSolarRadiation() with valid parameter
        //value and GetSolarRadiation
    Test6();

        // Test SetSolarRadiation() with invalid parameter
        // value and GetSolarRadiation
    Test7();
}


//-----------------------------------------------------------
//Test the constructor, GetWindSpeed(),
// GetTemperature() and GetSolarRadiation()
void UnaggregatedWeatherTest::Test1()
{
    UnaggregatedWeather weatherObj;
    float returnedWindSpeed;
    float returnedTemperature;
    float returnedSolarRadiation;


    //get the windspeed, temperature and solar radiation
    // values from weatherObj
    returnedWindSpeed = weatherObj.GetWindSpeed();
    returnedTemperature = weatherObj.GetTemperature();
    returnedSolarRadiation = weatherObj.GetSolarRadiation();


    cout << "UnaggregatedWeather Class Test 1 : Test Constructor "
         << ", .GetWindSpeed() , .GetTemperature() , "
         << '\n' << "& .GetSolarRadiation() "
         << '\n';

    cout << setfill('#') << setw(60) << "" << '\n';

    cout << "After creating a Weather instance " << '\n';

    cout << setfill('-') << setw(35) << "" << '\n';

    cout << "the return value of .GetWindSpeed() is : "
         << returnedWindSpeed << '\n';

    cout << "the return value of .GetTemperature() is : "
         << returnedTemperature << '\n';

    cout << "the return value of .GetSolarRadiation() is : "
         << returnedSolarRadiation << "\n\n\n\n\n";
}


//----------------------------------------------------------
//Test SetTime() and GetTime()
void UnaggregatedWeatherTest::Test2()
{
    UnaggregatedWeather weatherObj;
    Time setTimeObj;
    Time returnedTimeObj;


    //get the time from weatherObj
    weatherObj.GetTime(returnedTimeObj);


    cout << "UnaggregatedWeather Class Test 2 : Test .SetTime() "
         << "and .GetTime() " << '\n';

    cout << setfill('#') << setw(60) << "" << '\n';

    cout << "After creating a UnaggregatedWeather instance " << '\n';

    cout << setfill('-') << setw(35) << "" << '\n';

    cout << "the time returned from .GetTime() is "
         << returnedTimeObj.GetHour()
         << ':' << returnedTimeObj.GetMinute()
         << ':' << returnedTimeObj.GetSecond()
         << "\n\n\n";

         //---------------------------------------------

    setTimeObj.SetHour(12);
    setTimeObj.SetMinute(45);
    setTimeObj.SetSecond(55);
    weatherObj.SetTime(setTimeObj);

    weatherObj.GetTime(returnedTimeObj);

    cout << "After setting the Time as "
         << "\'12:45:55\' "<< '\n' << "using the "
         << "method .SetTime()" << '\n';

    cout << setfill('-') << setw(35) << "" << '\n';

    cout << "the time returned from .GetTime() is "
         << returnedTimeObj.GetHour()
         << ':' << returnedTimeObj.GetMinute()
         << ':' << returnedTimeObj.GetSecond()
         << "\n\n\n\n\n";

}


//------------------------------------------------------------
// Test SetDate() and GetDate()
void UnaggregatedWeatherTest::Test3()
{

    UnaggregatedWeather weatherObj;
    Date setDateObj;
    Date returnedDateObj;


    //get the date from weatherObj
    weatherObj.GetDate(returnedDateObj);


    cout << "UnaggregatedWeather Class Test 3 : Test .SetDate() "
         << "and .GetDate() " << '\n';

    cout << setfill('#') << setw(60) << "" << '\n';

    cout << "After creating a UnaggregatedWeather instance "
         << '\n';

    cout << setfill('-') << setw(35) << "" << '\n';

    cout << "the date returned from .GetDate() is "
         << returnedDateObj.GetDay()
         << '/' << returnedDateObj.GetMonth()
         << '/' << returnedDateObj.GetYear()
         << "\n\n\n";

         //---------------------------------------------

    setDateObj.SetDay(25);
    setDateObj.SetMonth(12);
    setDateObj.SetYear(2019);
    weatherObj.SetDate(setDateObj);

    weatherObj.GetDate(returnedDateObj);

    cout << "After setting the Date as "
         << "\'25/12/2019\' "<< '\n' << "using the "
         << "method .SetDate()" << '\n';

    cout << setfill('-') << setw(35) << "" << '\n';

    cout << "the date returned from .GetDate() is "
         << returnedDateObj.GetDay()
         << '/' << returnedDateObj.GetMonth()
         << '/' << returnedDateObj.GetYear()
         << "\n\n\n\n\n";
}


//-------------------------------------------------------------
// Test SetWindSpeed() and GetWindSpeed()
void UnaggregatedWeatherTest::Test4()
{

    UnaggregatedWeather weatherObj;
    float returnedWindSpeed;

    //get the windspeed value from weatherObj
    returnedWindSpeed = weatherObj.GetWindSpeed();


    cout << "UnaggregatedWeather Class Test 4 : Test "
         << ".SetWindSpeed() and .GetWindSpeed() "
         << '\n';

    cout << setfill('#') << setw(60) << "" << '\n';

    cout << "After creating a Weather instance " << '\n';

    cout << setfill('-') << setw(35) << "" << '\n';

    cout << "the return value of .GetWindSpeed() is : "
         << returnedWindSpeed << "\n\n\n";

         //--------------------------------------

    weatherObj.SetWindSpeed(100.25);
    returnedWindSpeed = weatherObj.GetWindSpeed();

    cout << "After setting the UnaggregatedWeather windspeed as "
         << "\'100.25\' "<< '\n' << "using the "
         << "method .SetWindSpeed()" << '\n';

    cout << setfill('-') << setw(35) << "" << '\n';

    cout << "the return value of .GetWindSpeed() is : "
         << returnedWindSpeed << "\n\n\n\n\n";
}


//-------------------------------------------------------------
// Test SetTemperature() and GetTemperature()
void UnaggregatedWeatherTest::Test5()
{

    UnaggregatedWeather weatherObj;
    float returnedTemperature;

    //get the temperature value from weatherObj
    returnedTemperature = weatherObj.GetTemperature();


    cout << "UnaggregatedWeather Class Test 5 : Test "
         << ".SetTemperature() and .GetTemperature() "
         << '\n';

    cout << setfill('#') << setw(60) << "" << '\n';

    cout << "After creating a UnaggregatedWeather instance "
         << '\n';

    cout << setfill('-') << setw(35) << "" << '\n';

    cout << "the return value of .GetTemperature() is : "
         << returnedTemperature << "\n\n\n";

         //--------------------------------------

    weatherObj.SetTemperature(100.29);
    returnedTemperature = weatherObj.GetTemperature();

    cout << "After setting the UnaggregatedWeather temperature"
         << "as \'100.29\' "<< '\n' << "using the "
         << "method .SetTemperature()" << '\n';

    cout << setfill('-') << setw(35) << "" << '\n';

    cout << "the return value of .GetTemperature() is : "
         << returnedTemperature << "\n\n\n\n\n";
}


//-------------------------------------------------------------
// Test SetSolarRadiation() with valid parameter
//value and GetSolarRadiation
void UnaggregatedWeatherTest::Test6()
{
    UnaggregatedWeather weatherObj;
    float returnedSolarRadiation;
    bool setRadiationOutcome;

    //get the solar radiation value from weatherObj
    returnedSolarRadiation = weatherObj.GetSolarRadiation();


    cout << "UnaggregatedWeather Class Test 6 : Test "
         << ".SetSolarRadiation() " << '\n'
         << "and .GetSolarRadiation() with valid " << '\n'
         << "parameter for .SetSolarRadiation() "
         << '\n';

    cout << setfill('#') << setw(60) << "" << '\n';

    cout << "After creating a UnaggregatedWeather instance "
         << '\n';

    cout << setfill('-') << setw(35) << "" << '\n';

    cout << "the return value of .GetSolarRadiation() is : "
         << returnedSolarRadiation << "\n\n\n";

         //------------------------------------------

    setRadiationOutcome = weatherObj.SetSolarRadiation(250.55);
    returnedSolarRadiation = weatherObj.GetSolarRadiation();

    cout << "After setting the UnaggregatedWeather solar "
         << "radiation as "
         << "\'250.55\' "<< '\n' << "using the "
         << "method .SetSolarRadiation()" << '\n';

    cout << setfill('-') << setw(35) << "" << '\n';

    cout << "the boolean return value of .SetSolarRadiation() is"
         << " : " << boolalpha << setRadiationOutcome << '\n';

    cout << "the return value of .GetRadiation() is : "
         << returnedSolarRadiation << "\n\n\n\n\n";
}


//-------------------------------------------------------------
// Test SetSolarRadiation() with invalid parameter
// value and GetSolarRadiation
void UnaggregatedWeatherTest::Test7()
{
    UnaggregatedWeather weatherObj;
    float returnedSolarRadiation;
    bool setRadiationOutcome;

    //get the solar radiation value from weatherObj
    returnedSolarRadiation = weatherObj.GetSolarRadiation();


    cout << "UnaggregatedWeather Class Test 7 : Test "
         << ".SetSolarRadiation() " << '\n'
         << "and .GetSolarRadiation() with invalid " << '\n'
         << "parameter for .SetSolarRadiation() "
         << '\n';

    cout << setfill('#') << setw(60) << "" << '\n';

    cout << "After creating a UnaggregatedWeather instance "
         << '\n';

    cout << setfill('-') << setw(35) << "" << '\n';

    cout << "the return value of .GetSolarRadiation() is : "
         << returnedSolarRadiation << "\n\n\n";

         //------------------------------------------

    setRadiationOutcome = weatherObj.SetSolarRadiation(5);
    returnedSolarRadiation = weatherObj.GetSolarRadiation();

    cout << "After setting the Weather solar radiation as "
         << "\'5\' "<< '\n' << "using the "
         << "method .SetSolarRadiation()" << '\n';

    cout << setfill('-') << setw(35) << "" << '\n';

    cout << "the boolean return value of .SetSolarRadiation() is"
         << " : " << boolalpha << setRadiationOutcome << '\n';

    cout << "the return value of .GetRadiation() is : "
         << returnedSolarRadiation << "\n\n\n\n\n";
}


