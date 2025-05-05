#include "RawDataProcessing.h"


bool StoreAllUnaggregatedRecordsInVector(
                UnaggregatedWeatherVector& unaggWeatherVec,
                string& errorMessage)
{
    StringVector fileNamesVec;
    StringVector rawStringDataVec;

    bool hasNoErrors;


        /*------------------------------------------------------
            STEP 1:
            Initialise the error message
        ------------------------------------------------------*/
    errorMessage = "No error found";


        /*-----------------------------------------------------
            STEP 2:
            Read the data index file containing the list
            of file names and store these file names in
            a vector
        ------------------------------------------------------*/
    hasNoErrors = StoreFileNamesInVector(fileNamesVec,
                                         errorMessage);


        /*----------------------------------------------------
            STEP 3:
            If there are no errors with step 2,
            Open each of the file (from the file names
            stored in fileNamesVec) and store each of
            the read data as string in rawStringDataVec
        ------------------------------------------------------*/
    if (hasNoErrors)
    {
        hasNoErrors =
                StoreRawStringDataInVector(fileNamesVec,
                                           rawStringDataVec,
                                           errorMessage);


            /*-------------------------------------------------
                STEP 4:
                If there are no errors with step 3, extract
                all the data from the string-form records stored
                in rawStringDataVec, and store the extracted
                records in the vector unaggWeatherVec

                If there is insufficient memory to store
                the records, the error message will be set
            --------------------------------------------------*/
        if (hasNoErrors)
        {
            hasNoErrors =
                ExtractAndStoreAllFileRecordsInVector(
                                        rawStringDataVec,
                                        unaggWeatherVec);

            if (!hasNoErrors)
            {
                errorMessage = "Error! Insufficient memory ";
                errorMessage += "space for program";
                errorMessage += " to run.";
            }

        }

    }

        /*-----------------------------------------------------
            STEP 5:
            Empty the memory of vectors fileNamesVec and
            rawStringDataVec as they are not needed anymore
        ------------------------------------------------------*/
    fileNamesVec.Clear();
    rawStringDataVec.Clear();


        /*-----------------------------------------------------
            STEP 6:
            Return the outcome

            true - successful
            false - unsuccessful
        -----------------------------------------------------*/
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


    StringBst fileNamesQueryTree(StringIsLessThan,
                                 StringIsEqualTo,
                                 StringIsMoreThan);

        /*-----------------------------------------------------
            STEP 0:
            Initialise the value of errorMessage
        ------------------------------------------------------*/
    errorMessage = "No error found";


        /*------------------------------------------------------
            STEP 1:
            Makes sure that the vector storing all the file names
            has sufficient memory to store at least
            EST_NUM_OF_FILES_TO_READ number of strings

            If there is insufficient memory, set the error
            message
        -------------------------------------------------------*/

    hasSufficientMemory =
          fileNamesVec.EnsureCapacity(EST_NUM_OF_FILES_TO_READ);

    hasNoErrorReadingFile = false;


    if (!hasSufficientMemory)
    {
        errorMessage = "Error! Insufficient memory ";
        errorMessage += "space required for program";
        errorMessage += " to run.";
    }
    else
    {
            /*-------------------------------------------------
                STEP 2:
                Read the data index file. If there is any
                error reading file, it means that the data
                index file either does not exist or is an
                empty file

                If there is any error, set the error message
            --------------------------------------------------*/
        hasNoErrorReadingFile =
                ReadInputFile(DATA_INDEX_FILE_NAME,
                             listOfFileNamesString);


        if (!hasNoErrorReadingFile)
        {
            errorMessage = "Error! Either ";
            errorMessage += DATA_INDEX_FILE_NAME;
            errorMessage += " does not exist or ";
            errorMessage += "it is an empty file\n ";
            errorMessage += "with zero characters ";
            errorMessage += " or it is a non-empty file ";
            errorMessage += "containing only whitespace\n";
            errorMessage += "characters (empty strings).\n";
        }

    }//end of if (!hasSufficientMemory)



        /*------------------------------------------------
            STEP 3:
            Read all the file names and store them in
            the string vector
        -------------------------------------------------*/
    if (hasSufficientMemory && hasNoErrorReadingFile)
    {

            /*-------------------------------------------------
                STEP 3A:
                Store the entire list of file names (as string
                extracted from the file DATA_INDEX_FILE_NAME)
                into the stringstream
            --------------------------------------------------*/
        ssBuffer << listOfFileNamesString;


            /*-------------------------------------------------
                STEP 3B:
                Read the first file name from the string stream
            --------------------------------------------------*/
        ssBuffer >> currentFileName;


        while (ssBuffer.good()  && hasSufficientMemory)
        {

                /*--------------------------------------------
                    STEP 3C:
                    Add the file directory to the file name
                ---------------------------------------------*/
            currentFileName = DATA_DIRECTORY + currentFileName;


                /*-------------------------------------------
                    STEP 3D:
                    Search the query tree to see if the file
                    name is already stored in the vector
                    fileNamesVec.

                    If the file name does not exist, store the
                    file name in both the query tree
                    (fileNamesQueryTree) and the vector
                    (fileNamesVec)

                    If there is insufficient memory to store the
                    data in both the query tree and the vector,
                    set the error message
                -----------------------------------------------*/
            fileNameExists =
                    fileNamesQueryTree.Search(currentFileName);


            if (!fileNameExists)
            {
                hasSufficientMemory =
                        fileNamesQueryTree.Insert(
                                            currentFileName);


                if (hasSufficientMemory)
                {
                    hasSufficientMemory =
                        fileNamesVec.Append(currentFileName);


                    if (!hasSufficientMemory)
                    {
                        fileNamesQueryTree.Delete(
                                             currentFileName);
                    }

                }


                if (!hasSufficientMemory)
                {
                    errorMessage = "Error! There is ";
                    errorMessage += "insufficient memory ";
                    errorMessage += "for the program to run\n";
                }

            }//end of if (!fileNameExists)


                /*----------------------------------------------
                    STEP 3E:
                    Retrieve the next file name in the
                    string stream
                -----------------------------------------------*/
            if (hasSufficientMemory)
            {
                ssBuffer >> currentFileName;
            }

        }//end of while loop

    }//end of if (hasSufficientMemory && hasNoErrorReadingFile)



        /*----------------------------------------------------
            STEP 4:
            Clear the memory taken up by the query tree.
            The fileNamesVec is not cleared as it is the
            output of this function
        ------------------------------------------------------*/
    fileNamesQueryTree.Clear();


        /*----------------------------------------------------
            STEP 5:
            Return the outcome
                true - successful
                false - unsuccessful
        ------------------------------------------------------*/
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

        /*--------------------------------------------------
            Step 0:
            Initialise the value of errorMessage
        ---------------------------------------------------*/


    errorMessage = "No error found";

        /*--------------------------------------------------
            STEP 1:
            Ensure that the vector rawStringDataVec
            has sufficient memory to store all the raw data
            strings (entire file data read from the source
            file and stored as strings)
        ------------------------------------------------------*/

    sizeOfFileNamesVec = fileNamesVec.GetCurrentSize();


    hasSufficientMemory = rawStringDataVec.EnsureCapacity(
                                        sizeOfFileNamesVec);



        /*-------------------------------------------------
            STEP 2:
            If there is sufficient memory, open and read
            every single file from the file names stored
            in fileNamesVec and store the read data(raw
            string data) into the vector rawStringDataVec
        ---------------------------------------------------*/

    if (hasSufficientMemory)
    {

        fileReadingNoError = true;


        for (int index = 0;
             (index < sizeOfFileNamesVec) && fileReadingNoError;
             index++)
        {

                /*---------------------------------------------
                    STEP 2A:
                    Retrieve the file name to be read and
                    attempt to open and read it

                    Set the error message if there is any
                    error
                -----------------------------------------------*/
            fileNamesVec.Get(index, currentFileName);


            fileReadingNoError =
                    ReadInputFile(currentFileName.c_str(),
                                    returnedFileDataString);


            if (!fileReadingNoError)
            {
                errorMessage = "Error! Either ";
                errorMessage += currentFileName;
                errorMessage += " does not exist \n";
                errorMessage += "or it is an empty file ";
                errorMessage += "with zero characters ";
                errorMessage += " or it is \n";
                errorMessage += "a non-empty file ";
                errorMessage += "containing only whitespace ";
                errorMessage += "characters (empty strings).\n";
            }
            else
            {
                    /*-------------------------------------------
                        STEP 2B:
                        Store the entire file data as a string
                        into the vector rawStringDataVec
                    --------------------------------------------*/
                rawStringDataVec.Append(returnedFileDataString);


            }//end of if (!fileReadingNoError)

        }//end of for-loop

    }//end of if (hasSufficientMemory)




        /*-------------------------------------------------------
            STEP 3:
            Return the outcome of storing raw file data
            strings into the vector rawString

            true - successful
            false - unsuccessful
        -------------------------------------------------------*/
    return (hasSufficientMemory && fileReadingNoError);


}


//-------------------------------------------------------------
bool ExtractAndStoreAllFileRecordsInVector(
            const StringVector& rawStringDataVec,
            UnaggregatedWeatherVector& unaggWeatherVec)
{

    DateTime2DBst unaggWeatherQueryTree(DateIsLessThan,
                                        DateIsEqualTo,
                                        DateIsMoreThan,
                                        TimeIsLessThan,
                                        TimeIsEqualTo,
                                        TimeIsMoreThan);
    string currentRawStringData;

    int sizeOfRawStringDataVec;

    bool hasSufficientMemory;


        /*------------------------------------------------
            STEP 1:
            Ensure that the vector storing unaggregated
            weather records (unaggWeatherVec) can store
            the estimated number of records
        -------------------------------------------------*/
    sizeOfRawStringDataVec =
                          rawStringDataVec.GetCurrentSize();

    hasSufficientMemory =
                unaggWeatherVec.EnsureCapacity(
                                  EST_TOTAL_NUM_OF_RECORDS);


        /*--------------------------------------------------
            STEP 2:
            If there is sufficient memory, extract from each
            file data stored in string (currentRawStringData)
            and store the extracted data into the
            vector unaggregatedWeatherVec
        --------------------------------------------------*/
    if (hasSufficientMemory)
    {

        for (int index = 0;
             index < sizeOfRawStringDataVec &&
                        hasSufficientMemory;
             index++)
        {

            rawStringDataVec.Get(index, currentRawStringData);

                /*--------------------------------------------
                    STEP 2A:
                    If hasSufficientMemory returns false,
                    that means that there is not enough
                    memory to store any more weather records
                    in the vector unaggWeatherVec
                ---------------------------------------------*/
            hasSufficientMemory =
                ExtractAndStoreCurrentFileRecordsInVector(
                                        currentRawStringData,
                                        unaggWeatherQueryTree,
                                        unaggWeatherVec);

        }//end of for-loop

    }//end of if (hasSufficientMemory)



        /*---------------------------------------------------
            STEP 3:
            Emptying the query tree (binary search tree)
            as it is no longer needed
        -----------------------------------------------------*/
    unaggWeatherQueryTree.Clear();


        /*-----------------------------------------------------
            STEP 4:
            Return the outcome of storing the all the weather
            records into the vector unaggWeatherVec

            true - successful
            false - unsuccessful
        ------------------------------------------------------*/
    return hasSufficientMemory;
}


//---------------------------------------------------------------
bool ExtractAndStoreCurrentFileRecordsInVector (
                const string& fileDataString,
                DateTime2DBst& unaggWeatherQueryTree,
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


        /*----------------------------------------------------
            Step 1:
            Insert data from the string fileDataString
            into the string stream
        -----------------------------------------------------*/

    ssBuffer << fileDataString;


        /*-------------------------------------------------------
            Step 2:
            Remove the file line from the string stream,
            which is the unwanted sensor codes
        -------------------------------------------------------*/
    getline(ssBuffer, uselessString , '\n');



        /*-----------------------------------------------------
            Step 3:
            EXTRACT THE REQUIRED VALUES
            -----------------------------------------
            Time, Date, windspeed, solar radiation and
            temperature are extracted from the string
            stream and stored in the corresponding
            variables.
        ----------------------------------------------------*/

    hasSufficientMemory = true;

    ssBuffer >> retrievedDay;


    while(ssBuffer.good() && hasSufficientMemory)
    {

        ssBuffer >> uselessChar; //removes '/'
        ssBuffer >> retrievedMonth;
        ssBuffer >> uselessChar;  //removes '/'
        ssBuffer >> retrievedYear;

        ssBuffer >> retrievedHour;
        ssBuffer >> uselessChar; //removes ':'
        ssBuffer >> retrievedMinute;
        ssBuffer >> uselessChar; //removes ','


            //discards non-essential data read
            //  from column 2 to 10
        for (int dataCol = 2 ; dataCol <= 10; dataCol++)
        {
            getline(ssBuffer, uselessString , ',');
        }



        ssBuffer >> retrievedWindSpeed;

            /*--------------------------------------------------
                STEP 4:
                Check if the entire row has 'N/A' values
                (e.g. The record from 8 Feb 2010 at 9 a.m. )

                If the entire row contains 'N/A', then discard
                the entire record
            --------------------------------------------------*/
        if (!ssBuffer.good())
        {
                /*
                    Note: the .clear() here does not empty the
                    string stream. It simply restores it
                    from a "fail" state to a "good" state
                */
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

                /*--------------------------------------------
                    STEP 5:
                    Store the values in a struct and
                    call the method StoreSingleRecordInVector()
                    to store that particular record in
                    the vector unaggWeatherVec
                --------------------------------------------*/
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
                                    rawWeatherData,
                                    unaggWeatherQueryTree,
                                    unaggWeatherVec);

        }//end of if (!ssBuffer.good())

            /*--------------------------------------------------
                STEP 6:
                Retrieve the day value from the next record
                if available
            --------------------------------------------------*/
        ssBuffer >> retrievedDay;


    }//end of while loop


        /*-----------------------------------------------------
            Step 7:
            Return the outcome

                true - successful
                false - unsuccessful due to the lack of memory
        -----------------------------------------------------*/


    return hasSufficientMemory;

}


//-----------------------------------------------------------
bool StoreSingleRecordInVector(
            const RawWeatherData& rawWeatherData,
            DateTime2DBst& unaggWeatherQueryTree,
            UnaggregatedWeatherVector& unaggWeatherVec)
{

    bool hasSufficientMemory;
    bool recordExists;


    UnaggregatedWeather tempUnaggWeather;
    Date tempDate;
    Time tempTime;


        /*----------------------------------------------------
            STEP 1:
            Store the respective date and time
            values in temporary object instances, before
            using these temporary object instances to set
            the date and time for the temporary
            UnaggregatedWeather object instance
            tempUnaggWeather
        ----------------------------------------------------*/
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

        /*-------------------------------------------------
            STEP 2:
            Search the binary search tree to see if the
            record exists
        --------------------------------------------------*/
    recordExists =
        unaggWeatherQueryTree.Search(tempDate, tempTime);


    if (!recordExists)
    {

            /*-----------------------------------------------
                STEP 3:
                Insert the record keys into the binary
                search tree
            ------------------------------------------------*/
        hasSufficientMemory =
            unaggWeatherQueryTree.Insert(tempDate,tempTime);


            /*-----------------------------------------------
                STEP 4:
                Insert the actual record into the vector
                unaggWeatherVec

                If there is error inserting, undo step 3
            ------------------------------------------------*/
        if (hasSufficientMemory)
        {
            hasSufficientMemory =
                unaggWeatherVec.Append(tempUnaggWeather);


            if (!hasSufficientMemory)
            {
                unaggWeatherQueryTree.Delete(tempDate,
                                             tempTime);
            }

        }//end of if (hasSufficientMemory)

    }//end of if (!recordExists)



        /*---------------------------------------------------
            STEP 5:
            Note that this function's return is a little
            different. It only returns false if there
            is insufficient memory.

            Does not return false if the record already
            exists and is not inserted into the vector
        ----------------------------------------------------*/
    return hasSufficientMemory;
}
