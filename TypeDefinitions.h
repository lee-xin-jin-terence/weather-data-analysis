#ifndef TYPE_DEFINITIONS_H
#define TYPE_DEFINITIONS_H

#include <string>
#include <map>

#include "Classes/Bst/Bst.h"
#include "Classes/Date/Date.h"
#include "Classes/Time/Time.h"
#include "Classes/Vector/Vector.h"
#include "Classes/UnaggregatedWeather/UnaggregatedWeather.h"
#include "Classes/AggregatedWeather/AggregatedWeather.h"
#include "DataComparisonDefinitions.h"

using std::string;
using std::map;



    /*
     Brief:
        A struct that is used to temporarily store raw data
        values extracted from a data source
    */
typedef struct
{
    int m_day;
    int m_month;
    int m_year;
    int m_hour;
    int m_minute;
    int m_second;
    float m_windSpeedMS;
    float m_ambientAirTempC;
    float m_solarRadiationWM2;

} RawWeatherData;


    /*
     Brief:
        A Vector that is used to store c++ strings
    */
typedef Vector<string> StringVector;

    /*
     Brief:
        A vector that is used to store instances of
        class UnaggregatedWeather
    */
typedef Vector<UnaggregatedWeather> UnaggregatedWeatherVector;


    /*
     Brief:
        A vector that is used to store instances of class
        AggregatedWeather
    */
typedef Vector<AggregatedWeather> AggregatedWeatherVector;


    /*
     Brief:
        A c++ string Binary Search Tree
    */
typedef Bst<string> StringBst;


    /*
     Brief:
        A c++ Date Binary Search Tree
    */
typedef Bst<Date> DateBst;


    /*
     Brief:
        A Standard Template Library map that maps
        AggregatedWeather instances to its Date
    */
typedef map<Date, AggregatedWeather, DateIsLessThanFuncObj>
                        AggregatedWeatherMap;


    /*
     Brief:
        The const iterator of the above AggregatedWeatherMap
    */
typedef AggregatedWeatherMap::const_iterator
                                AggregatedWeatherMapCItr;

#endif // TYPE_DEFINITIONS_H
