#ifndef DATA_AGGREGATION_H
#define DATA_AGGREGATION_H

#include <string>
#include "Conversions.h"
#include "TypeDefinitions.h"
#include "DataComparisonDefinitions.h"
#include "Classes/UnaggregatedWeather/UnaggregatedWeather.h"
#include "Classes/AggregatedWeather/AggregatedWeather.h"



using std::string;


    /*
     Brief:
        Aggregates data and store the aggregated data in
        a map. Also, stores the keys of the aggregated data
        in a binary search tree

     Parameters:
        unaggWeatherVec - A vector that contains unaggregated
            weather (UnaggregatedWeather) records.

        aggWeatherMap - A map that stores aggregated weather
            records as value (AggregatedWeather), where the
            corresponding keys are the date (Date) of the
            aggregated weather records. This is the output
            of this function

        aggWeatherQueryTree - the binary search tree that
            stores the keys (Date) of the aggregated weather
            records stored in the map aggWeatherMap. This
            is the output of this function

     Return:
        bool - returns false if there is any error encountered.
            Otherwise, returns true.
    */
bool CreateAggWeatherMapAndQueryTree(
            const UnaggregatedWeatherVector& unaggWeatherVec,
            AggregatedWeatherMap& aggWeatherMap,
            DateBst& aggWeatherQueryTree);


    /*
     Brief:
        Aggregates Weather data and stores the aggregated
        weather data(records) in a map


     Parameters:
        unaggWeatherVec - A vector that contains unaggregated
            weather (UnaggregatedWeather) records.

        aggWeatherMap - A map that stores aggregated weather
            records as value (AggregatedWeather), where the
            corresponding keys are the date (Date) of the
            aggregated weather records. This is the output
            of this function

     Return:
        bool - false if there is an error in storing the
            key-value pairs (Date-AggregatedWeather) into
            the map aggWeatherMap. Otherwise, returns true.
    */
bool CreateAggregatedWeatherMap(
            const UnaggregatedWeatherVector& unaggWeatherVec,
            AggregatedWeatherMap& aggWeatherMap);



    /*
     Brief:
        Populate the binary search tree aggWeatherQueryTree.
        This binary search tree contains the keys of the
        aggregated weather data stored in the map
        aggWeatherMap

     Parameters:
        aggWeatherMap - A map that stores aggregated weather
            records as value (AggregatedWeather), where the
            corresponding keys are the date (Date) of the
            aggregated weather records.

        aggWeatherQueryTree - the binary search tree that
            stores the keys (Date) of the aggregated weather
            records stored in the map aggWeatherMap. This
            is the output of this function

     Return:
        bool - false if there is insufficient memory space
            to store the keys (Date) in the binary
            search tree aggWeatherQueryTree. Otherwise,
            returns true
    */
bool CreateAggWeatherQueryTree(
                const AggregatedWeatherMap& aggWeatherMap,
                DateBst& aggWeatherQueryTree);


#endif // DATA_AGGREGATION_H
