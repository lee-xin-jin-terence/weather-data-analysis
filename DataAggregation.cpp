#include "DataAggregation.h"

bool CreateAggWeatherMapAndQueryTree(
            const UnaggregatedWeatherVector& unaggWeatherVec,
            AggregatedWeatherMap& aggWeatherMap,
            DateBst& aggWeatherQueryTree)
{

    bool hasNoError;

        /*------------------------------------------------
            STEP 1:
            Aggregate the unaggregated weather data
            and store the aggregated weather data in
            the map aggWeatherMap
        ------------------------------------------------*/
    hasNoError = CreateAggregatedWeatherMap(unaggWeatherVec,
                                            aggWeatherMap);


    if (hasNoError)
    {
            /*-------------------------------------------
                STEP 2:
                Populate the binary search tree
                aggWeatherQueryTree
            --------------------------------------------*/
        hasNoError = CreateAggWeatherQueryTree(
                                    aggWeatherMap,
                                    aggWeatherQueryTree);
    }

        /*----------------------------------------------
            STEP 3:
            Return the outcome

            true - successful
            false - unsuccessful
        -----------------------------------------------*/
    return hasNoError;
}


//--------------------------------------------------------
bool CreateAggregatedWeatherMap(
        const UnaggregatedWeatherVector& unaggWeatherVec,
        AggregatedWeatherMap& aggWeatherMap)
{

    bool hasNoError;

    int unaggWeatherVecSize =
                    unaggWeatherVec.GetCurrentSize();

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

        /*-----------------------------------------------
            Aggregates Weather data from vector of type
            UnaggregatedWeather to map that stores
            AggregatedWeather. The weather data are
            aggregated by calendar months.

            For example, all January records from year 1994
            will be aggregated into one single record and
            stored in the map as a single element(entry).

            The key of the map will be the Date, while the
            value of the map will be the entire
            AggregatedWeather record itself
        -------------------------------------------------*/
    hasNoError = true;

    for (int index=0;
         (index < unaggWeatherVecSize) && hasNoError;
         index++)
    {
            /*--------------------------------------------
                STEP 1:
                Find out what the current date
                (year and month) is for the current
                unaggregated weather data
                (UnaggregatedWeather) instance
            ---------------------------------------------*/
        unaggWeatherVec.Get(index,currentWeatherUnagg);

        currentWeatherUnagg.GetDate(currentMonthDate);

        currentMonthUnagg = currentMonthDate.GetMonth();
        currentYearUnagg = currentMonthDate.GetYear();


        if (index==0)
        {
                /*-----------------------------------------
                    STEP 2:
                    For the very first iteration of
                    the loop, initialise the sum and
                    values of the various variables
                -----------------------------------------*/

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
                /*------------------------------------------
                    STEP 3:
                    For the remaining records of the
                    current month (of the current year)
                    onwards, the values of various weather
                    records will be added up to the various
                    weather data totals
                ------------------------------------------*/
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
            /*---------------------------------------------
                STEP 4:
                If this is the very last record
                of the current month, calculate the various
                values and insert it into the map
                aggWeatherMap.

                If any is any error in inserting it into
                the map, hasNoError flag will be set to
                false

                date(as key of the map) is always set to
                first day of the month
            ---------------------------------------------*/

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

            try
            {
                aggWeatherMap[previousMonthDate] =
                                        currentWeatherAgg;
            }
            catch(...)
            {
                hasNoError = false;
            }



            /*-------------------------------------------
                STEP 5:
                Reset the total calculated values
                for the next month of the various weather
                data
            ---------------------------------------------*/

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




        /*-------------------------------------------------
            Also STEP 5:
            Insert the very last remaining
            aggregated weather data to the map
        -------------------------------------------------*/

    if (hasNoError)
    {
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

        try
        {
            aggWeatherMap[previousMonthDate] =
                                currentWeatherAgg;
        }
        catch(...)
        {
            hasNoError = false;
        }

    }//end of if (hasNoError)

        /*------------------------------------------------
            STEP 6:
            Return the outcome of aggregating data and
            storing the aggregated weather in a map

            true - successful
            false - unsuccessful
        -------------------------------------------------*/
    return hasNoError;
}


//-----------------------------------------------------------
bool CreateAggWeatherQueryTree(
            const AggregatedWeatherMap& aggWeatherMap,
            DateBst& aggWeatherQueryTree)
{

    AggregatedWeatherMapCItr itr;
    bool hasSufficientMemory = true;

        /*-----------------------------------------------
            STEP 1:
            Stores all the keys of the map aggWeatherMap
            in the binary search tree aggWeatherQueryTree
        -------------------------------------------------*/
    for (itr = aggWeatherMap.begin() ;
         itr != aggWeatherMap.end() && hasSufficientMemory;
         itr++)
    {
            /*
                Note that itr->first is a Date instance,
                which is the key of the current key-value
                pair
            */
        hasSufficientMemory = aggWeatherQueryTree.Insert(
                                            itr->first);
    }


        /*------------------------------------------------
            STEP 2:
            Return the outcome of populating the binary
            search tree

            true - successful
            false - unsuccessful
        -------------------------------------------------*/
    return hasSufficientMemory;
}
