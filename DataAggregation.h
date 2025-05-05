#ifndef DATA_AGGREGATION_H
#define DATA_AGGREGATION_H

#include <string>
#include "Classes/UnaggregatedWeather/UnaggregatedWeather.h"
#include "Classes/AggregatedWeather/AggregatedWeather.h"
#include "TypeDefinitions.h"
#include "Conversions.h"


using std::string;


    /*
     Brief:
        Using data (fileDataString) obtained from an input data
        file to create a vector unaggWeatherList which contains
        of unaggregated data.

     Parameters:
        fileDataString - a string containing input
        data copied directly from an input file. This
        is the input of this function

        unaggWeatherList - a vector containing
         unaggregated weather data of type
         UnaggregatedWeather(Refer to TypeDefinitions.h
         for more details). The unaggregated data would contain
         many records of weather data recorded over a day over
         many days. unaggWeatherList is the output of this
         function

     Return :
        Returns true if there is enough heap memory to
        store all the records extracted from
        fileDataString into unaggWeatherList, and false
        if otherwise.
    */

    /*
     Brief:
        This is a helper function to the above method
        CreateUnaggregatedWeatherVector. This function
        is used to append unaggregated weather data(records)
        to the vector unaggWeatherList (of type
        UnaggregatedWeather).

     Parameters:
        rawWeatherData - a struct containing data extracted from
            the string read from CreateUnaggregatedWeatherVector,
            which has yet to be stored in object instances

        unaggWeatherList - a vector of type UnaggregatedWeather
            containing unaggregated weather data. This is the
            output of this function


     Return:
        bool - true if the append of record to the vector
            unaggWeatherList is successful, and false if
            there is a failure, which is due to insufficient
            heap memory available

        unaggWeatherList - the vector of type UnaggregatedWeather
            containing unaggregated data. This is to be returned
            by reference via the parameter
    */



    /*
     Brief:
        Create a vector of type AggregatedWeather containing
        aggregated weather data based on the vector of
        type UnaggregatedWeather. Basically, this means that
        this functions aggregates weather data by month

     Parameters:
        unaggWeatherList - a vector of type UnaggregatedWeather
            containing unaggregated weather data

        aggWeatherList - a vector og type AggregatedWeather
            containing aggregated weather data. This is the
            output of this function

     Return:
        bool - true if the vector containing aggregated data
            is successfully created, and false if there is
            insufficient heap memory available for creating
            the vector

        aggWeatherList - a vector of type AggregatedWeather
            containing aggregated weather data. This is to
            be returned by reference via the parameter
    */
bool CreateAggWeatherMapAndQueryTree(
            const UnaggregatedWeatherVector& unaggWeatherVec,
            AggregatedWeatherMap& aggWeatherMap,
            DateBst& aggWeatherQueryTree);

void CreateAggregatedWeatherMap(
            const UnaggregatedWeatherVector& unaggWeatherVec,
            AggregatedWeatherMap& aggWeatherMap);


bool CreateAggWeatherQueryTree(
                const AggregatedWeatherMap& aggWeatherMap,
                DateBst& aggWeatherQueryTree);


#endif // DATA_PROCESSING_VECTOR_H
