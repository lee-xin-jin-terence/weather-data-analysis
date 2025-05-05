#include "AggregatedWeatherTest.h"

void AggregatedWeatherTest::RunTest()
{
        //Test the constructor, .GetAvgWindSpeed(),
        // .GetAvgTemperature() and .GetTotalSolarRadiation()
    Test1();

        //Test .SetDate() and .GetDate()
    Test2();

        //Test .SetAvgWindSpeed() and .GetAvgWindSpeed()
    Test3();

        //Test .SetAvgTemperature() and .GetAvgTemperature()
    Test4();

        //Test .SetTotalSolarRadiation() and
        // .GetTotalSolarRadiation()
    Test5();
}


//--------------------------------------------------------------
//Test the constructor, .GetAvgWindSpeed(),
// .GetAvgTemperature() and .GetTotalSolarRadiation
void AggregatedWeatherTest::Test1()
{
    AggregatedWeather weatherObj;
    float returnedAvgWindSpeed;
    float returnedAvgTemperature;
    float returnedTotalSolarRadiation;


    //get the windspeed, temperature and solar radiation
    // values from weatherObj
    returnedAvgWindSpeed = weatherObj.GetAvgWindSpeed();
    returnedAvgTemperature = weatherObj.GetAvgTemperature();
    returnedTotalSolarRadiation
                          = weatherObj.GetTotalSolarRadiation();


    cout << "AggregatedWeather Class Test 1 : Test Constructor "
         << ", .GetAvgWindSpeed() ,"  << '\n'
         << " .GetAvgTemperature() , & .GetTotalSolarRadiation()"
         << '\n';

    cout << setfill('#') << setw(60) << "" << '\n';

    cout << "After creating a Weather instance " << '\n';

    cout << setfill('-') << setw(35) << "" << '\n';

    cout << "the return value of .GetAvgWindSpeed() is : "
         << returnedAvgWindSpeed << '\n';

    cout << "the return value of .GetAvgTemperature() is : "
         << returnedAvgTemperature << '\n';

    cout << "the return value of .GetTotalSolarRadiation() is : "
         << returnedTotalSolarRadiation << "\n\n\n\n\n";

}


//-------------------------------------------------------------
//Test .SetDate() and .GetDate()
void AggregatedWeatherTest::Test2()
{
    AggregatedWeather weatherObj;
    Date setDateObj;
    Date returnedDateObj;


    //get the date from weatherObj
    weatherObj.GetDate(returnedDateObj);


    cout << "AggregatedWeather Class Test 2 : Test .SetDate() "
         << "and .GetDate() " << '\n';

    cout << setfill('#') << setw(60) << "" << '\n';

    cout << "After creating a UnaggregatedWeather instance " << '\n';

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


//------------------------------------------------------------
//Test .SetAvgWindSpeed() and .GetAvgWindSpeed()
void AggregatedWeatherTest::Test3()
{
    AggregatedWeather weatherObj;
    float returnedAvgWindSpeed;

    //get the windspeed value from weatherObj
    returnedAvgWindSpeed = weatherObj.GetAvgWindSpeed();


    cout << "AggregatedWeather Class Test 3 : Test "
         << ".SetAvgWindSpeed() and .GetAvgWindSpeed() "
         << '\n';

    cout << setfill('#') << setw(60) << "" << '\n';

    cout << "After creating a AggregatedWeather instance "
         << '\n';

    cout << setfill('-') << setw(35) << "" << '\n';

    cout << "the return value of .GetAvgWindSpeed() is : "
         << returnedAvgWindSpeed << "\n\n\n";

         //--------------------------------------

    weatherObj.SetAvgWindSpeed(100.25);
    returnedAvgWindSpeed = weatherObj.GetAvgWindSpeed();

    cout << "After setting the AggregatedWeather average "
         << "windspeed as \'100.25\' "<< '\n' << "using the "
         << "method .SetAvgWindSpeed()" << '\n';

    cout << setfill('-') << setw(35) << "" << '\n';

    cout << "the return value of .GetAvgWindSpeed() is : "
         << returnedAvgWindSpeed << "\n\n\n\n\n";

}


//-------------------------------------------------------------
//Test .SetAvgTemperature() and .GetAvgTemperature()
void AggregatedWeatherTest::Test4()
{
    AggregatedWeather weatherObj;
    float returnedAvgTemperature;

    //get the temperature value from weatherObj
    returnedAvgTemperature = weatherObj.GetAvgTemperature();


    cout << "AggregatedWeather Class Test 4 : Test "
         << ".SetAvgTemperature() and .GetAvgTemperature() "
         << '\n';

    cout << setfill('#') << setw(60) << "" << '\n';

    cout << "After creating a AggregatedWeather instance "
         << '\n';

    cout << setfill('-') << setw(35) << "" << '\n';

    cout << "the return value of .GetAvgTemperature() is : "
         << returnedAvgTemperature << "\n\n\n";

         //--------------------------------------

    weatherObj.SetAvgTemperature(100.29);
    returnedAvgTemperature = weatherObj.GetAvgTemperature();

    cout << "After setting the AggregatedWeather average "
         << "temperature as \'100.29\' "<< '\n' << "using the "
         << "method .SetAvgTemperature()" << '\n';

    cout << setfill('-') << setw(35) << "" << '\n';

    cout << "the return value of .GetAvgTemperature() is : "
         << returnedAvgTemperature << "\n\n\n\n\n";
}


//------------------------------------------------------------
//Test .SetTotalSolarRadiation() and .GetTotalSolarRadiation()
void AggregatedWeatherTest::Test5()
{
    AggregatedWeather weatherObj;
    float returnedTotalSolarRadiation;

    //get the solar radiation value from weatherObj
    returnedTotalSolarRadiation
                    = weatherObj.GetTotalSolarRadiation();


    cout << "AggregatedWeather Class Test 5 : Test "
         << ".SetTotalSolarRadiation() " << '\n'
         << "and .GetTotalSolarRadiation() " << '\n';

    cout << setfill('#') << setw(60) << "" << '\n';

    cout << "After creating a AggregatedWeather instance "
         << '\n';

    cout << setfill('-') << setw(35) << "" << '\n';

    cout << "the return value of .GetSolarTotalRadiation() is : "
         << returnedTotalSolarRadiation << "\n\n\n";

         //------------------------------------------

    weatherObj.SetTotalSolarRadiation(250.55);
    returnedTotalSolarRadiation
                        = weatherObj.GetTotalSolarRadiation();

    cout << "After setting the AggregatedWeather total solar "
         << "radiation as "
         << "\'250.55\' "<< '\n' << "using the "
         << "method .SetTotalSolarRadiation()" << '\n';

    cout << setfill('-') << setw(35) << "" << '\n';

    cout << "the return value of .GetTotalSolarRadiation() is : "
         << returnedTotalSolarRadiation << "\n\n\n\n\n";
}
