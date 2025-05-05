#include "DataComparisonDefinitions.h"

bool DateIsLessThan(const Date& firstDate,
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
bool DateIsEqualTo(const Date& firstDate,
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
bool DateIsMoreThan(const Date& firstDate,
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
bool TimeIsLessThan(const Time& firstTime,
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


//------------------------------------------------------
bool StringIsLessThan(const string& firstString,
                      const string& secondString)
{
        /*
            Returns true if firstString comes before secondString
            lexically, and false if otherwise
        */
    return (firstString < secondString);
}


//------------------------------------------------------
bool StringIsEqualTo(const string& firstString,
                     const string& secondString)
{
        /*
            Returns true if firstString is equal to secondString
            lexically, and false if otherwise
        */
    return (firstString == secondString);
}


//-----------------------------------------------------
bool StringIsMoreThan(const string& firstString,
                     const string& secondString)
{
        /*
            Returns true if firstString comes after secondString
            lexically, and false if otherwise
        */
    return (firstString > secondString);
}


//------------------------------------------------------
bool UnaggregatedWeatherIsLessThan(
            const UnaggregatedWeather& firstWeather,
            const UnaggregatedWeather& secondWeather)
{
    Date firstDate;
    Time firstTime;

    Date secondDate;
    Time secondTime;

        /*
            STEP 1:
            Extract the Date and Time from both
            UnaggregatedWeather instances
        */
    firstWeather.GetDate(firstDate);
    firstWeather.GetTime(firstTime);


    secondWeather.GetDate(secondDate);
    secondWeather.GetTime(secondTime);


        /*
            STEP 2:
            Return a boolean value on whether firstWeather
            is less than secondWeather
        */
    return (DateIsLessThan(firstDate,secondDate)
                         ||
            (DateIsEqualTo(firstDate,secondDate) &&
             TimeIsLessThan(firstTime, secondTime))  );
}


//------------------------------------------------------
bool DateIsLessThanFuncObj::operator()
                           (const Date& firstDate,
                            const Date& secondDate) const
{
        /*
            Returns a boolean value on whether firstDate
            is less than secondDate
        */
    return DateIsLessThan(firstDate, secondDate);
}
