#include "DataAggregation.h"

bool CreateAggWeatherMapAndQueryTree(
            const UnaggregatedWeatherVector& unaggWeatherVec,
            AggregatedWeatherMap& aggWeatherMap,
            DateBst& aggWeatherQueryTree)
{

    bool hasSufficientMemory;


    CreateAggregatedWeatherMap(unaggWeatherVec, aggWeatherMap);


    hasSufficientMemory =
                CreateAggWeatherQueryTree(aggWeatherMap,
                                          aggWeatherQueryTree);


    return hasSufficientMemory;
}


//--------------------------------------------------------
void CreateAggregatedWeatherMap(
            const UnaggregatedWeatherVector& unaggWeatherVec,
            AggregatedWeatherMap& aggWeatherMap)
{


    int unaggWeatherVecSize = unaggWeatherVec.GetCurrentSize();

    UnaggregatedWeather currentWeatherUnagg;
    AggregatedWeather currentWeatherAgg;

    Date currentMonthDate;
    Date previousMonthDate;

    int currentMonthUnagg;
    int currentYearUnagg;

    int currentMonthAgg;
    int currentYearAgg;

    float sumOfCurrentMonthTemp = 0;
    float sumOfCurrentMonthWindSpeed = 0;
    float sumOfCurrentMonthSolarRad = 0;


    int numOfRecordsForCurrentMonth;

        /*
            Aggregates Weather data from vector of type
            UnaggregatedWeather to vector of type
            AggregatedWeather. The weather data are aggregated
            by calendar months.

            For example, all January records from year 1994
            will be aggregated into one single record and
            stored in the vector of type AggregatedWeather as
            a single element(entry)
        */

    for (int index=0;
         index < unaggWeatherVecSize;
         index++)
    {
            /*
                Step 1: Find out what the current date
                (year and month) is for the current
                unaggregated weather data
                (UnaggregatedWeather) instance
            */
        unaggWeatherVec.Get(index,currentWeatherUnagg);

        currentWeatherUnagg.GetDate(currentMonthDate);

        currentMonthUnagg = currentMonthDate.GetMonth();
        currentYearUnagg = currentMonthDate.GetYear();


        if (index==0)
        {
                /*
                    Step 2: For the very first iteration of the
                    loop, initialise the sum and
                    values of the various variables
                */

            currentMonthAgg = currentMonthUnagg;
            currentYearAgg = currentYearUnagg;
            sumOfCurrentMonthTemp =
                        currentWeatherUnagg.GetTemperature();

            sumOfCurrentMonthWindSpeed =
                          currentWeatherUnagg.GetWindSpeed();

            sumOfCurrentMonthSolarRad =
                        currentWeatherUnagg.GetSolarRadiation();

            currentWeatherUnagg.GetDate(previousMonthDate);

            numOfRecordsForCurrentMonth = 1;


        }
        else if ( currentMonthUnagg == currentMonthAgg
                    && currentYearUnagg == currentYearAgg)
        {
                /*
                    Step 3: For the remaining records of the
                    current month (of the current year) onwards,
                    the values of various weather records will be
                    added up to the various weather data
                    totals
                */
            sumOfCurrentMonthTemp +=
                        currentWeatherUnagg.GetTemperature();

            sumOfCurrentMonthWindSpeed +=
                          currentWeatherUnagg.GetWindSpeed();

            sumOfCurrentMonthSolarRad +=
                        currentWeatherUnagg.GetSolarRadiation();

            numOfRecordsForCurrentMonth++;

        }
        else
        {
            /*
                Step 4: If this is the very last record
                of the current month, calculate the various
                values and append it to the vector of type
                AggregatedWeather
            */
            //date is always set to first day of the month

            previousMonthDate.SetDay(1);

            currentWeatherAgg.SetDate(previousMonthDate);


            currentWeatherAgg.SetAvgTemperature(
                             sumOfCurrentMonthTemp/
                               numOfRecordsForCurrentMonth);

            currentWeatherAgg.SetAvgWindSpeed(
                             ConvertWindSpeedMSToKMH(
                                sumOfCurrentMonthWindSpeed/
                                numOfRecordsForCurrentMonth));

            currentWeatherAgg.SetTotalSolarRadiation(
                             Convert10MinRadEnergyToKWHM2(
                                    sumOfCurrentMonthSolarRad));


            aggWeatherMap[previousMonthDate] =
                                currentWeatherAgg;




            /*
                Step 5: Reset the total calculated values
                for the next month of the various weather
                data
            */

            currentWeatherUnagg.GetDate(previousMonthDate);

            currentMonthAgg = currentMonthUnagg;
            currentYearAgg = currentYearUnagg;
            sumOfCurrentMonthTemp =
                         currentWeatherUnagg.GetTemperature();

            sumOfCurrentMonthWindSpeed =
                        currentWeatherUnagg.GetWindSpeed();

            sumOfCurrentMonthSolarRad =
                       currentWeatherUnagg.GetSolarRadiation();



            numOfRecordsForCurrentMonth = 1;

        }//end of if-else statements

    }//end of for-loop




        /*
            Also Step 5: Append the very last remaining
            aggregated weather data to the vector
        */


    previousMonthDate.SetDay(1);

    currentWeatherAgg.SetDate(previousMonthDate);

    currentWeatherAgg.SetAvgTemperature(
                         sumOfCurrentMonthTemp/
                           numOfRecordsForCurrentMonth);

    currentWeatherAgg.SetAvgWindSpeed(
                 ConvertWindSpeedMSToKMH(
                            sumOfCurrentMonthWindSpeed/
                            numOfRecordsForCurrentMonth));

    currentWeatherAgg.SetTotalSolarRadiation(
                   Convert10MinRadEnergyToKWHM2(
                          sumOfCurrentMonthSolarRad));

    aggWeatherMap[previousMonthDate] =
                            currentWeatherAgg;



}


//-----------------------------------------------------------
bool CreateAggWeatherQueryTree(
            const AggregatedWeatherMap& aggWeatherMap,
                        DateBst& aggWeatherQueryTree)
{

    bool hasSufficientMemory = true;


    AggregatedWeatherMapCItr itr;

    Date currentDate;


    for (itr = aggWeatherMap.begin() ;
         itr != aggWeatherMap.end() && hasSufficientMemory;
         itr++)
    {

        currentDate = itr->first;


        hasSufficientMemory = aggWeatherQueryTree.Insert(
                                            currentDate);

    }


    return hasSufficientMemory;
}
