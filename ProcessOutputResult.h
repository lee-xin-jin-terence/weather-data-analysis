#ifndef PROCESS_OUTPUT_RESULT_H
#define PROCESS_OUTPUT_RESULT_H


#include <sstream>
#include <string>
#include <iomanip>
#include "Constants.h"
#include "Conversions.h"
#include "TypeDefinitions.h"
#include "Classes/Date/Date.h"

using std::stringstream;
using std::string;
using std::to_string;
using std::fixed;
using std::showpoint;
using std::setprecision;



    /*
     Brief:
        Process the required output for menu option 1 and
        returns the output as a string

     Parameters:
        aggWeatherMap - a STL Map that stores the actual
            aggregated weather data

        aggWeatherQueryTree - a Binary Search Tree that is
            used to query whether a particular aggregated
            weather record exists. This tree must already
            be populated beforehand

        targetYear - the year of interest

        targetMonth - the month of interest

        returnedStringResult - the output of this function.
            This string contains the required output of Menu
            option 1 and is returned via the parameter
    */
void ProcessOption1Result(
                const AggregatedWeatherMap& aggWeatherMap,
                const DateBst& aggWeatherQueryTree,
                int targetYear, int targetMonth,
                string& returnedStringResult);


    /*
     Brief:
        Process the required output for menu option 2 and
        returns the output as a string

     Parameters:
        aggWeatherMap - a STL Map that stores the actual
            aggregated weather data

        aggWeatherQueryTree - a Binary Search Tree that is
            used to query whether a particular aggregated
            weather record exists. This tree must already
            be populated beforehand

        targetYear - the year of interest

        returnedStringResult - the output of this function.
            This string contains the required output of Menu
            option 2 and is returned via the parameter
    */
void ProcessOption2Result(
            const AggregatedWeatherMap& aggWeatherMap,
            const DateBst& aggWeatherQueryTree,
            int targetYear,
            string& returnedStringResult);


    /*
     Brief:
        Process the required output for menu option 3 and
        returns the output as a string

     Parameters:
        aggWeatherMap - a STL Map that stores the actual
            aggregated weather data

        aggWeatherQueryTree - a Binary Search Tree that is
            used to query whether a particular aggregated
            weather record exists. This tree must already
            be populated beforehand

        targetYear - the year of interest

        returnedStringResult - the output of this function.
            This string contains the required output of Menu
            option 3 and is returned via the parameter
    */
void ProcessOption3Result(
            const AggregatedWeatherMap& aggWeatherMap,
            const DateBst& aggWeatherQueryTree,
            int targetYear,
            string& returnedStringResult);


    /*
     Brief:
        Process the required output for menu option 4 and
        returns the output as a string

     Parameters:
        aggWeatherMap - a STL Map that stores the actual
            aggregated weather data

        aggWeatherQueryTree - a Binary Search Tree that is
            used to query whether a particular aggregated
            weather record exists. This tree must already
            be populated beforehand

        targetYear - the year of interest

        returnedStringResult - the output of this function.
            This string contains the required output of Menu
            option 4 and is returned via the parameter
    */
void ProcessOption4Result(
            const AggregatedWeatherMap& aggWeatherMap,
            const DateBst& aggWeatherQueryTree,
            int targetYear,
            string& returnedStringResult);

#endif // PROCESS_OUTPUT_RESULT_H
