#include "RawDataProcessing.h"


bool StoreAllUnaggregatedRecordsInVector(
                UnaggregatedWeatherVector& unaggWeatherVec,
                string& errorMessage)
{
    StringVector fileNamesVec;
    StringVector rawStringDataVec;

    bool hasNoErrors;


    errorMessage = "No errors found";


    hasNoErrors = StoreFileNamesInVector(fileNamesVec,
                                         errorMessage);


    if (hasNoErrors)
    {
        hasNoErrors =
                StoreRawStringDataInVector(fileNamesVec,
                                           rawStringDataVec,
                                           errorMessage);


        if (hasNoErrors)
        {
            hasNoErrors =
                ExtractAndStoreAllFileRecordsInVector(
                                        rawStringDataVec,
                                        unaggWeatherVec,
                                        errorMessage);

        }

    }

    fileNamesVec.Clear();
    rawStringDataVec.Clear();


    return hasNoErrors;

}


//---------------------------------------------------------
bool StoreFileNamesInVector(StringVector& fileNamesVec,
                            string& errorMessage)
{
    bool hasSufficientMemory;
    bool hasNoErrorReadingFile;

    bool fileNameExists;

    string listOfFileNamesString;
    string currentFileName;

    stringstream ssBuffer;


        //------------------------------------------------

    StringBst fileNamesQueryTree(StringIsLessThan,
                                 StringIsEqualTo,
                                 StringIsMoreThan);


    hasSufficientMemory =
          fileNamesVec.EnsureCapacity(EST_NUM_OF_FILES_TO_READ);

    hasNoErrorReadingFile = false;

        //----------------------------------------------------

    if (!hasSufficientMemory)
    {
        errorMessage = "Error! Insufficient memory ";
        errorMessage += "space required for program";
        errorMessage += " to run.";
    }
    else
    {
        hasNoErrorReadingFile =
                ReadInputFile(DATA_INDEX_FILE_NAME,
                             listOfFileNamesString);

    }
        //----------------------------------------------------




    if (hasSufficientMemory && !hasNoErrorReadingFile)
    {
        errorMessage = "Error! Either ";
        errorMessage += DATA_INDEX_FILE_NAME;
        errorMessage += " does not exists or ";
        errorMessage += "it is an empty file.\n";

    }
    else if (hasSufficientMemory && hasNoErrorReadingFile)
    {

        ssBuffer << listOfFileNamesString;

        ssBuffer >> currentFileName;

        while (ssBuffer.good()  && hasSufficientMemory)
        {

            currentFileName = DATA_DIRECTORY + currentFileName;


            fileNameExists =
                    fileNamesQueryTree.Search(currentFileName);


            if (!fileNameExists)
            {
                hasSufficientMemory =
                        fileNamesQueryTree.Insert(currentFileName);


                if (hasSufficientMemory)
                {
                    hasSufficientMemory =
                        fileNamesVec.Append(currentFileName);

                }


                if (!hasSufficientMemory)
                {
                    errorMessage = "Error! There is ";
                    errorMessage += "insufficient memory ";
                    errorMessage += "for the program to run\n";
                }
            }


            if (hasSufficientMemory)
            {
                ssBuffer >> currentFileName;
            }
        }


    }

    return (hasSufficientMemory && hasNoErrorReadingFile);

}


//--------------------------------------------------------
bool StoreRawStringDataInVector(
                const StringVector& fileNamesVec,
                StringVector& rawStringDataVec,
                string& errorMessage)
{

    bool hasSufficientMemory;
    bool fileReadingNoError;

    int sizeOfFileNamesVec;

    string currentFileName;
    string returnedFileDataString;


        //-----------------------------------------------

    sizeOfFileNamesVec = fileNamesVec.GetCurrentSize();


    hasSufficientMemory = rawStringDataVec.EnsureCapacity(
                                        sizeOfFileNamesVec);



    if (hasSufficientMemory)
    {

        fileReadingNoError = true;


        for (int index = 0;
             index < sizeOfFileNamesVec &&
                    hasSufficientMemory &&
                    fileReadingNoError;
             index++)
        {

            fileNamesVec.Get(index, currentFileName);


            fileReadingNoError =
                    ReadInputFile(currentFileName.c_str(),
                                    returnedFileDataString);


            if (!fileReadingNoError)
            {
                errorMessage = "Error! Either ";
                errorMessage += currentFileName;
                errorMessage += " does not exists or ";
                errorMessage += "it is an empty file.\n";
            }
            else
            {
                hasSufficientMemory = rawStringDataVec.Append(
                                        returnedFileDataString);


                if (!hasSufficientMemory)
                {
                    errorMessage = "Error! Insufficient memory ";
                    errorMessage += "space for program";
                    errorMessage += " to run.";
                }

            }

        }


    }


        //end of while loop


    return (hasSufficientMemory && fileReadingNoError);


}


//-------------------------------------------------------------
bool ExtractAndStoreAllFileRecordsInVector(
            const StringVector& rawStringDataVec,
            UnaggregatedWeatherVector& unaggWeatherVec,
            string& errorMessage)
{

    DateTime2DBst unaggWeatherQueryMap;
    string currentRawStringData;

    int sizeOfRawStringDataVec;

    bool hasSufficientMemory;


    sizeOfRawStringDataVec =
                          rawStringDataVec.GetCurrentSize();


    hasSufficientMemory =
                unaggWeatherVec.EnsureCapacity(
                                  EST_TOTAL_NUM_OF_RECORDS);

    if (hasSufficientMemory)
    {

        for (int index = 0;
             index < sizeOfRawStringDataVec &&
                        hasSufficientMemory;
             index++)
        {

            rawStringDataVec.Get(index, currentRawStringData);

            hasSufficientMemory =
                ExtractAndStoreCurrentFileRecordInVector(
                                        currentRawStringData,
                                        unaggWeatherQueryMap,
                                        unaggWeatherVec);

            if (!hasSufficientMemory)
            {
                errorMessage = "Error! Insufficient memory ";
                errorMessage += "space for program";
                errorMessage += " to run.";
            }

        }
    }




    unaggWeatherQueryMap.Clear();

    return hasSufficientMemory;
}

//---------------------------------------------------------------
bool ExtractAndStoreCurrentFileRecordInVector (
                const string& fileDataString,
                DateTime2DBst& unaggWeatherQueryMap,
                UnaggregatedWeatherVector& unaggWeatherVec)
{

    bool hasSufficientMemory;

    stringstream ssBuffer;
    RawWeatherData rawWeatherData;



    int retrievedDay;
    int retrievedMonth;
    int retrievedYear;
    int retrievedHour;
    int retrievedMinute;
    float retrievedWindSpeed;
    float retrievedSolarRad;
    float retrievedAmbientAirTemp;

    char uselessChar;
    string uselessString;




        /*
            Step 1: Insert data from the string fileDataString
            into the string stream
        */

    ssBuffer << fileDataString;


        /*
            Step 2: Remove the file line from the string stream,
            which is the unwanted sensor codes
        */
    getline(ssBuffer, uselessString , '\n');



        /*
            Step 3: Extract the Required Date
            -----------------------------------------
            Time, Date, windspeed, solar radiation and
            temperature are extracted from the string
            stream and stored in the corresponding
            variables. These are processed line by line
            from the string fileDataString

            These data are then stored in a temporary
            struct, which is then sent to the
            helper method AppendToUnaggWeatherVector
            for processing and appending to the
            a vector (of type UnaggregatedWeather)
        */

    ssBuffer >> retrievedDay;

    hasSufficientMemory = true;

    while(ssBuffer.good() && hasSufficientMemory)
    {

        ssBuffer >> uselessChar;
        ssBuffer >> retrievedMonth;
        ssBuffer >> uselessChar;
        ssBuffer >> retrievedYear;

        ssBuffer >> retrievedHour;
        ssBuffer >> uselessChar;
        ssBuffer >> retrievedMinute;
        ssBuffer >> uselessChar;


            //discards non-essential data read
            //  from column 2 to 10
        for (int dataCol = 2 ; dataCol <= 10; dataCol++)
        {
            getline(ssBuffer, uselessString , ',');
        }



        ssBuffer >> retrievedWindSpeed;

        if (!ssBuffer.good())
        {
            // if the remaining columns have "NA/"
            ssBuffer.clear();
            getline(ssBuffer, uselessString, '\n');
        }
        else
        {
            ssBuffer >> uselessChar;
            ssBuffer >> retrievedSolarRad;
            ssBuffer >> uselessChar;


            //discards non-essential data read
            //  from column 13 to 17
            for (int dataCol = 13 ; dataCol <=17; dataCol++)
            {
                getline(ssBuffer, uselessString, ',');
            }

            ssBuffer >> retrievedAmbientAirTemp;
            //-------------------------------------------------

            rawWeatherData.m_day = retrievedDay;
            rawWeatherData.m_month = retrievedMonth;
            rawWeatherData.m_year = retrievedYear;
            rawWeatherData.m_hour = retrievedHour;
            rawWeatherData.m_minute = retrievedMinute;
            rawWeatherData.m_windSpeedMS = retrievedWindSpeed;

            rawWeatherData.m_solarRadiationWM2  = retrievedSolarRad;

            rawWeatherData.m_ambientAirTempC
                                    = retrievedAmbientAirTemp;


            hasSufficientMemory = StoreSingleRecordInVector(
                                rawWeatherData,unaggWeatherVec,
                                unaggWeatherQueryMap);

        }
        //-------------------------------------------------

        ssBuffer >> retrievedDay;
    }

        /*
            Step 4: Return outcome of creating vector of
            type UnaggregatedWeather
            ----------------------------------------------
            If there is sufficient heap memory for data
            to the vector, the a boolean value of true
            will be returned

            Otherwise, it will return false
        */





    /*
        for-loop to clear time tree data
    */



    return hasSufficientMemory;

}


//-----------------------------------------------------------

bool StoreSingleRecordInVector(
            const RawWeatherData& rawWeatherData,
            UnaggregatedWeatherVector& unaggWeatherVec,
            DateTime2DBst& unaggWeatherQueryTree)
{

    UnaggregatedWeather tempUnaggWeather;
    Date tempDate;
    Time tempTime;


    bool hasSufficientMemory = true;
    bool recordExists = false;




        /*
            Step 1: Store the respective date and time
            values in temporary object instances, before
            using these temporary object instances to set
            the date and time for the temporary
            UnaggregatedWeather object instance
            tempUnaggWeather
        */
    tempDate.SetDay(rawWeatherData.m_day);
    tempDate.SetMonth(rawWeatherData.m_month);
    tempDate.SetYear(rawWeatherData.m_year);

    tempTime.SetHour(rawWeatherData.m_hour);
    tempTime.SetMinute(rawWeatherData.m_minute);


    tempUnaggWeather.SetDate(tempDate);
    tempUnaggWeather.SetTime(tempTime);


    tempUnaggWeather.SetWindSpeed(rawWeatherData.m_windSpeedMS);


    tempUnaggWeather.SetSolarRadiation(
                           rawWeatherData.m_solarRadiationWM2);

    tempUnaggWeather.SetTemperature(
                             rawWeatherData.m_ambientAirTempC);


    hasSufficientMemory = true;

    recordExists =
        unaggWeatherQueryTree.Search(tempDate, tempTime);


    if (!recordExists)
    {

        hasSufficientMemory =
            unaggWeatherQueryTree.Insert(tempDate,
                                                tempTime);

        if (hasSufficientMemory)
        {
            hasSufficientMemory =
                unaggWeatherVec.Append(tempUnaggWeather);


            if (!hasSufficientMemory)
            {
                unaggWeatherQueryTree.Delete(tempDate,
                                                tempTime);
            }
        }
    }






        /*
            Step 2: Set the remaining windspeed,
            temperature and solar radiation values
            into the temporary UnaggregatedWeather
            object instance tempUnaggWeather
        */



        /*
            Step 3: Append the temporary UnaggregatedWeather
            object instance into the UnaggregatedWeather
            vector
        */



        /*
            Step 4: Return append outcome
            -------------------------------------------
            Return true if append succeeded, and false
            if failed due to insufficient heap memory
            available
        */



    return hasSufficientMemory;
}
