#include "ProcessOutputResult.h"


void ProcessOption1Result(
                const AggregatedWeatherMap& aggWeatherMap,
                const DateBst& aggWeatherQueryTree,
                int targetYear, int targetMonth,
                string& returnedStringResult)
{
    AggregatedWeather currentWeather;
    Date targetDate;

    float averageWindSpeedKMH;
    float averageAmbientTempC;

    bool recordExists;


    stringstream ssBuffer;

    string monthString;
    string windSpeedString;
    string ambientTempString;


        /*
            Step 0: Initialise returnedStringResult
            to an empty string first
        */
    returnedStringResult= "";

        /*
            Step 1: Search using the Binary Search Tree
            to see if the particular record exists
            -----------------------------------------------
            Note: As all the aggregated records have day value
            set to 1, therefore the SetDay() has a parameter
            of 1
        */
    targetDate.SetDay(1);
    targetDate.SetMonth(targetMonth);
    targetDate.SetYear(targetYear);

    recordExists = aggWeatherQueryTree.Search(targetDate);


        /*
            Step 2: First write some of the things to output
            to the string returnedStringResult
        */

    ssBuffer << fixed << setprecision(FLOATING_POINT_PRECISION)
             << showpoint;

    GetMonthString(targetMonth, monthString);

    returnedStringResult += monthString;
    returnedStringResult += ' ';
    returnedStringResult += to_string ( targetYear);
    returnedStringResult += ": ";


        /*
            Step 3: Write the remaining output result to the
            string returnedStringResult
        */
    if (!recordExists )
    {
        returnedStringResult += "No Data";

    }
    else
    {
            /*
                If the record exists, the record is extracted
                from the map
            */
        currentWeather = aggWeatherMap.at(targetDate);

        averageWindSpeedKMH = currentWeather.GetAvgWindSpeed();

        averageAmbientTempC = currentWeather.GetAvgTemperature();


        ssBuffer << averageWindSpeedKMH ;
        ssBuffer >> windSpeedString;

        ssBuffer.clear();
        ssBuffer << averageAmbientTempC;
        ssBuffer >> ambientTempString;


        returnedStringResult += windSpeedString;

        returnedStringResult += " km/h, ";

        returnedStringResult += ambientTempString;

        returnedStringResult += " degrees C";


    }//end of if (!recordExists )

}//end of function ProcessOption1Result


//-----------------------------------------------------------
void ProcessOption2Result(
            const AggregatedWeatherMap& aggWeatherMap,
            const DateBst& aggWeatherQueryTree,
            int targetYear, string& returnedStringResult)
{

    AggregatedWeather currentWeather;
    Date currentDate;

    bool currentMonthQueryOutcome;
    bool anyRecordExists;


    stringstream ssBuffer;

    string monthString;
    string windSpeedString;
    string ambientTempString;


        /*
            Step 0: Initialise returnedStringResult
            to an empty string first
        */
    returnedStringResult= "";

        /*
            Step 1: Create three arrays
            --------------------------------------------
            The first two array stores the data of interest,
            that is wind speed and ambient temperature.

            The third array will state whether a record
            exists for a particular month

            Index 0 refers to January, index 1 refers to
            February ,... and index 11 refers to December
        */
    float averageWindSpeedKMHByMonth[12] = {0,0,0,0,
                                            0,0,0,0,
                                            0,0,0,0};

    float averageAmbientTempCByMonth[12] = {0,0,0,0,
                                            0,0,0,0,
                                            0,0,0,0};

    bool recordExistsByMonth[12] = {false, false, false, false,
                                    false, false, false, false,
                                    false, false, false, false};



        /*
            Step 2: Searching and accessing the records of
            interest
            -------------------------------------------------
            Using a for-loop, we search for records for each
            month using a Binary Search Tree

            If the record for the particular month exists,
            the record is extracted from the map


            Note: As all the aggregated records have the day
            value set to 1, therefore the SetDay() has a
            parameter of 1
        */

    currentDate.SetDay(1);
    currentDate.SetYear(targetYear);
    anyRecordExists = false;


    for (int currentMonth = 1; currentMonth <=12;
                                                currentMonth++)
    {
        currentDate.SetMonth(currentMonth);

        currentMonthQueryOutcome =
                        aggWeatherQueryTree.Search(currentDate);


        if (currentMonthQueryOutcome)
        {

            currentWeather = aggWeatherMap.at(currentDate);

            averageWindSpeedKMHByMonth[currentMonth -1]
                            = currentWeather.GetAvgWindSpeed();

            averageAmbientTempCByMonth[currentMonth -1]
                        = currentWeather.GetAvgTemperature();

            recordExistsByMonth[currentMonth - 1]= true;

            if (!anyRecordExists)
            {
                anyRecordExists = true;
            }

        }//end of if (currentMonthQueryOutcome)

    }//end of for-loop



        /*
            Step 3: Storing output in string
            -------------------------------------
            Storing the requested output in the
            string returnedStringResult
        */

    ssBuffer << fixed << setprecision(FLOATING_POINT_PRECISION)
             << showpoint;

    returnedStringResult += to_string(targetYear);
    returnedStringResult += '\n';

    if (!anyRecordExists)
    {
        returnedStringResult += "No Data";
    }
    else
    {
        for (int tempMonth = 0; tempMonth < 12 ; tempMonth++)
        {

            GetMonthString(tempMonth + 1, monthString);

            if (!recordExistsByMonth[tempMonth])
            {
                returnedStringResult += monthString;
                returnedStringResult += ": No Data";
                returnedStringResult +=  '\n';
            }
            else
            {
                ssBuffer << averageWindSpeedKMHByMonth[tempMonth] ;
                ssBuffer >> windSpeedString;
                ssBuffer.clear();

                ssBuffer << averageAmbientTempCByMonth[tempMonth];
                ssBuffer >> ambientTempString;
                ssBuffer.clear();

                returnedStringResult += monthString;
                returnedStringResult += ": ";

                //appending the average wind speed
                returnedStringResult += windSpeedString;

                returnedStringResult += " km/h, ";

                //appending the average ambient temperature
                returnedStringResult += ambientTempString;

                returnedStringResult += " degrees C";
                returnedStringResult +='\n';

            }//end of if (!recordExistsByMonth[tempMonth])

        }//end of for-loop

    }//end of if (!anyRecordExists)



}//end of function ProcessOption2Result


//--------------------------------------------------------------
void ProcessOption3Result(
            const AggregatedWeatherMap& aggWeatherMap,
            const DateBst& aggWeatherQueryTree,
            int targetYear, string& returnedStringResult)
{

    AggregatedWeather currentWeather;
    Date currentDate;

    bool anyRecordExists;
    bool currentMonthQueryOutcome;

    stringstream ssBuffer;

    string monthString;
    string solarRadString;

        /*
            Step 0: Initialise returnedStringResult
            to an empty string first
        */

    returnedStringResult= "";


        /*
            Step 1: Create two arrays
            --------------------------------------------
            The first  array stores the data of interest,
            that is total solar radiation.

            The second array will state whether a record exists
            for a particular month

            Index 0 refers to January, index 1 refers to
            February ,... and index 11 refers to December
        */
    float totalSolarRadKWM2ByMonth[12] = {0,0,0,0,
                                          0,0,0,0,
                                          0,0,0,0};

    bool recordExistsByMonth[12] =
                                {false, false, false, false,
                                 false, false, false, false,
                                 false, false, false, false};


        /*
            Step 2: Searching and accessing the records of
            interest
            -------------------------------------------------
            Using a for-loop, we search for records for each
            month using a Binary Search Tree

            If the record for the particular month exists,
            the record is extracted from the map


            Note: As all the aggregated records have the day
            value set to 1, therefore the SetDay() has a
            parameter of 1
        */

    anyRecordExists = false;
    currentDate.SetDay(1);
    currentDate.SetYear(targetYear);

    for (int currentMonth = 1; currentMonth <=12;
                                                currentMonth++)
    {
        currentDate.SetMonth(currentMonth);

        currentMonthQueryOutcome =
                        aggWeatherQueryTree.Search(currentDate);


        if (currentMonthQueryOutcome)
        {

            currentWeather = aggWeatherMap.at(currentDate);


            totalSolarRadKWM2ByMonth[currentMonth -1]
                     = currentWeather.GetTotalSolarRadiation();


            recordExistsByMonth[currentMonth - 1]= true;


            if (!anyRecordExists)
            {
                anyRecordExists = true;
            }

        }//end of if (currentMonthQueryOutcome)

    }//end of for-loop



        /*
            Step 3: Storing output in string
            -------------------------------------
            Storing the requested output in the
            string returnedStringResult
        */
    ssBuffer << fixed << setprecision(FLOATING_POINT_PRECISION)
             << showpoint;

    returnedStringResult += to_string(targetYear);
    returnedStringResult += '\n';

    if (!anyRecordExists)
    {
        returnedStringResult += "No Data";
    }
    else
    {
        for (int tempMonth = 0; tempMonth < 12 ; tempMonth++)
        {

            GetMonthString(tempMonth + 1, monthString);

            if (!recordExistsByMonth[tempMonth])
            {
                returnedStringResult +=  monthString;
                returnedStringResult += ": No Data";
                returnedStringResult += '\n';
            }
            else
            {

                ssBuffer << totalSolarRadKWM2ByMonth[tempMonth];
                ssBuffer >> solarRadString;
                ssBuffer.clear();

                returnedStringResult += monthString;
                returnedStringResult += ": ";
                returnedStringResult += solarRadString;

                returnedStringResult += " kWh/m^2";
                returnedStringResult += '\n';

            }//end of if (!recordExistsByMonth[tempMonth])

        }//end of for-loop

    }//end of if (!anyRecordExists)


}//end of function ProcessOption3Result


//--------------------------------------------------------------
void ProcessOption4Result(
            const AggregatedWeatherMap& aggWeatherMap,
            const DateBst& aggWeatherQueryTree,
            int targetYear,
            string& returnedStringResult)
{

    AggregatedWeather currentWeather;
    Date currentDate;

    bool anyRecordExists;
    bool currentMonthQueryOutcome;

    stringstream ssBuffer;

    string monthString;
    string windSpeedString;
    string ambientTempString;
    string solarRadString;

        /*
            Step 0: Initialise returnedStringResult
            to an empty string first
        */

    returnedStringResult = "";

        /*
            Step 1: Create four arrays
            --------------------------------------------
            The first three stores the data of interest,
            that are average windspeed, average ambient
            temperature and  total solar radiation.

            The last array will state whether a record exists
            for a particular month

            Index 0 refers to January, index 1 refers to
            February ,... and index 11 refers to December

        */
    float averageWindSpeedKMHByMonth[12] = {0,0,0,0,
                                            0,0,0,0,
                                            0,0,0,0};

    float averageAmbientTempCByMonth[12] = {0,0,0,0,
                                            0,0,0,0,
                                            0,0,0,0};

    float totalSolarRadKWM2ByMonth[12] = {0,0,0,0,
                                          0,0,0,0,
                                          0,0,0,0};

    bool recordExistsByMonth[12] =
                                {false, false, false, false,
                                 false, false, false, false,
                                 false, false, false, false};


        /*
            Step 2: Searching and accessing the records of
            interest
            -------------------------------------------------
            Using a for-loop, we search for records for each
            month using a Binary Search Tree

            If the record for the particular month exists,
            the record is extracted from the map


            Note: As all the aggregated records have the day
            value set to 1, therefore the SetDay() has a
            parameter of 1
        */

    anyRecordExists = false;
    currentDate.SetDay(1);
    currentDate.SetYear(targetYear);

    for (int currentMonth = 1; currentMonth <=12;
                                                currentMonth++)
    {

        currentDate.SetMonth(currentMonth);


        currentMonthQueryOutcome
                = aggWeatherQueryTree.Search(currentDate);


        if (currentMonthQueryOutcome)
        {

            currentWeather = aggWeatherMap.at(currentDate);

            averageWindSpeedKMHByMonth[currentMonth -1]
                            = currentWeather.GetAvgWindSpeed();

            averageAmbientTempCByMonth[currentMonth -1]
                            = currentWeather.GetAvgTemperature();

            totalSolarRadKWM2ByMonth[currentMonth -1]
                      = currentWeather.GetTotalSolarRadiation();

            recordExistsByMonth[currentMonth - 1]= true;


            if (!anyRecordExists)
            {
                anyRecordExists = true;
            }

        }//end of if (currentMonthQueryOutcome)

    }//end of for-loop




        /*
            Step 3: Storing output in string
            -------------------------------------
            Storing the requested output in the
            string returnedStringResult
        */

    ssBuffer << fixed << setprecision(FLOATING_POINT_PRECISION)
             << showpoint;

    returnedStringResult += to_string(targetYear);
    returnedStringResult += '\n';

    if (!anyRecordExists)
    {
        returnedStringResult += "No Data";
    }
    else
    {
        for (int tempMonth = 0; tempMonth < 12 ; tempMonth++)
        {

            GetMonthString(tempMonth + 1, monthString);

            if (recordExistsByMonth[tempMonth])
            {
                ssBuffer <<
                          averageWindSpeedKMHByMonth[tempMonth];
                ssBuffer>> windSpeedString;
                ssBuffer.clear();

                ssBuffer <<
                          averageAmbientTempCByMonth[tempMonth];
                ssBuffer >> ambientTempString;
                ssBuffer.clear();

                ssBuffer << totalSolarRadKWM2ByMonth[tempMonth];
                ssBuffer >> solarRadString;
                ssBuffer.clear();


                //appending the month
                returnedStringResult += monthString;
                returnedStringResult +=  ',';

                //appending the average wind speed
                returnedStringResult += windSpeedString;

                returnedStringResult += ',';

                //appending the average air ambient temp

                returnedStringResult += ambientTempString;

                returnedStringResult += ',';

                //appending the total solar radiation

                returnedStringResult += solarRadString;
                returnedStringResult += '\n';

            }//end of if (recordExistsByMonth[tempMonth])

        }//end of for-loop

    }//end of if (!anyRecordExists)

}//end of function

