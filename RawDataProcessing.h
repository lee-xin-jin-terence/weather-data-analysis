#ifndef RAW_DATA_PROCESSING_H
#define RAW_DATA_PROCESSING_H


#include <string>
#include <sstream>
#include "FileIO.h"
#include "Constants.h"
#include "TypeDefinitions.h"
#include "DataComparisonDefinitions.h"
#include "Classes/Date/Date.h"
#include "Classes/Time/Time.h"
#include "Classes/UnaggregatedWeather/UnaggregatedWeather.h"


using std::string;
using std::stringstream;


    /*
     Brief:
        Reads all the data files, extract the necessary data
        and store them in the vector unaggWeatherVec

     Parameters:
        unaggWeatherVec - a vector that stores
            UnaggregatedWeather records. This is an output
            of the function.

        errorMessage - This is a string reference that will
            contain the error message if this function
            returns a boolean false.

     Return:
        bool - false if there is some error in storing
            UnaggregatedWeather records in the vector
            unaggWeatherVec (There is more than one type
            of error). The error message will be reflected
            in the string errorMessage. Otherwise, returns
            true.
    */
bool StoreAllUnaggregatedRecordsInVector(
                UnaggregatedWeatherVector& unaggWeatherVec,
                string& errorMessage);

    /*
     Brief:
        Opens the data index file and stores each file name
        stored in the data index file as strings in the vector
        fileNamesVec

     Parameters:
        fileNamesVec - a vector that will store the list
            of file names of the data files that will be read.
            This is a output of the function.

        errorMessage - This is a string reference that will
            contain the error message if this function
            returns a boolean false. This is an output of
            the function.

     Return:
        bool - false if there is some error in storing the
            file names in the vector fileNamesVec (There
            is more than one type of error). The type of
            error will be reflected in the string errorMessage .
            Otherwise, returns true.
    */
bool StoreFileNamesInVector(StringVector& fileNamesVec,
                            string& errorMessage);


    /*
     Brief:
        Open all the data files and store all these file
        data as strings in the vector rawStringDataVec

     Parameters:
        fileNamesVec - a vector that will store the list
            of file names of the data files that will be read.
            This is a output of the function.

        rawStringDataVec - a string vector, where each element
            stored contains the entire file
            data stored as a string. This is an output of
            the function.

        errorMessage - This is a string reference that will
            contain the error message if this function
            returns a boolean false. This is an output of
            the function.


     Return:
        bool - Returns false if there is some error in storing
        file data (as string) in the vector rawStringDataVec.
        (There is more than one type of error). The type of
        error will be reflected in the string errorMessage.
        Otherwise, returns true.

    */
bool StoreRawStringDataInVector(
                const StringVector& fileNamesVec,
                StringVector& rawStringDataVec,
                string& errorMessage);


    /*
     Brief: Extract required data from all file data (stored
        as strings) and store them in the vector unaggWeatherVec

     Parameters:
        rawStringDataVec - a string vector, where each element
            stored in each index contains the entire file
            data stored as a string.

        unaggWeatherVec - a UnaggregatedWeatherVector that
            stores UnaggregatedWeather data. This is an
            output of the function.

     Return:
        bool - false if there is insufficient memory to store
            the UnaggregatedWeather records into the vector
            unaggWeatherVec. Otherwise, returns true.

    */
bool ExtractAndStoreAllFileRecordsInVector(
                    const StringVector& rawStringDataVec,
                    UnaggregatedWeatherVector& unaggWeatherVec);


    /*
     Brief:
        Extracts all the required data from the string
        fileDataString (the string contains data of an entire
        data file) and insert all the UnaggregatedWeather record
        keys and the records themselves into
        unaggWeatherQueryTree and unaggWeatherVec respectively.


     Parameters:
        fileDataString - a string that contains an entire
            file data stored as a string

        unaggWeatherQueryTree - a two-dimensional binary
            search tree that stores the Date-Time composite
            keys for UnaggregatedWeather records. This is
            both an input and an output of the function.

        unaggWeatherVec - a vector that stores
            UnaggregatedWeather records. This is an output
            of the function.

     Return:
        bool - Returns false only if there is insufficient
            memory space to store the keys and records in
            unaggWeatherQueryTree and unaggWeatherVec
            respectively. Otherwise, returns true.
    */
bool ExtractAndStoreCurrentFileRecordsInVector (
                const string& fileDataString,
                DateTime2DBst& unaggWeatherQueryTree,
                UnaggregatedWeatherVector& unaggWeatherVec);


    /*
     Brief:
        Stores a single UnaggregatedWeather instance (record)
        in the vector unaggWeatherVec. Does not store if
        the record already exists

     Parameters:
        rawWeatherData - a struct instance that stores data
            extracted from file data, but has yet to be
            properly stored in an UnaggregatedWeather instance

        unaggWeatherQueryTree - a two-dimensional binary
            search tree that stores the Date-Time composite
            keys for UnaggregatedWeather records.  This is
            both an input and an output of the function.

        unaggWeatherVec - a vector that stores
            UnaggregatedWeather records. This is an output
            of the function.

     Return:
        bool - Returns false only if there is insufficient
            memory space to store the key and record in
            unaggWeatherQueryTree and unaggWeatherVec
            respectively. Otherwise, returns true.
    */
bool StoreSingleRecordInVector(
            const RawWeatherData& rawWeatherData,
            DateTime2DBst& unaggWeatherQueryTree,
            UnaggregatedWeatherVector& unaggWeatherVec);

#endif // RAW_DATA_PROCESSING_H
