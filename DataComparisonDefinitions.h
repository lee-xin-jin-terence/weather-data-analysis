#ifndef DATA_COMPARISON_DEFINITIONS_H
#define DATA_COMPARISON_DEFINITIONS_H



#include <string>
#include "Classes/Date/Date.h"
#include "Classes/Time/Time.h"
#include "Classes/UnaggregatedWeather/UnaggregatedWeather.h"


using std::string;



    /*
     Brief:
        Compares two Date instances and returns a boolean
        value on whether the first Date instance is smaller
        than the second Date instance

     Parameters:
        firstDate - A Date instance to be compared to
            secondDate

        secondDate - A Date instance to be compaared to
            firstDate

     Return:
      bool - true if firstDate is smaller than secondDate,
            and false if otherwise

    */
bool DateIsLessThan(const Date& firstDate,
                    const Date& secondDate);


    /*
     Brief:
        Compares two Date instances and returns a boolean value
        on whether the first Date instance is equal to the
        second Date instance

     Parameters:
        firstDate - a Date instance to be compared to secondDate

        secondDate - a Date instance to be compared to firstDate


     Return:
        bool - true if firstDate is equal to secondDate, and
               false if otherwise

    */
bool DateIsEqualTo(const Date& firstDate,
                   const Date& secondDate);


    /*
     Brief :
        Compares two Date instances and returns a boolean
        value on whether the first Date instance is greater
        than the second Date instance

     Parameters:
        firstDate - a Date instance to be compared to secondDate

        secondDate - a Date instance to be compared to firstDate


     Return:
        bool - true of firstDate is greater than secondDate,
             and false if otherwise
    */
bool DateIsMoreThan(const Date& firstDate,
                    const Date& secondDate);


    /*
     Brief:
        Compares two Time instances and returns a boolean value
        on whether the first Time instance is less than the
        second Time instance

     Parameters:
        firstTime - a Time instance to be compared to secondTime

        secondTime - a Time instance to be compared to firstTime

     Return:
        bool - true if firstTime is less/smaller than secondTime,
             and false if otherwise
    */
bool TimeIsLessThan(const Time& firstTime,
                    const Time& secondTime);


    /*
     Brief:
        Compares two c++ string objects and returns a boolean
        value on whether the first string object lexically
        comes before the second string object.

     Parameters:
        firstString - a c++ string object that is to be compared
            to secondString

        secondString - a c++ string object that is to be compared
            to firstString

     Return:
        bool - true if  firstString lexically comes before
            secondString, and false if otherwise
    */
bool StringIsLessThan(const string& firstString,
                      const string& secondString);


    /*
     Brief:
        Compares two c++ string objects and returns a boolean
        value on whether the first string object lexically
        equal to the second string object

     Parameters:
        firstString - a c++ string object to be compared to
            secondString

        secondString - a c++ string object to be compared to
            firstString

     Return:
        bool - true of firstString is lexically equal to
            secondString, and false if otherwise
    */
bool StringIsEqualTo(const string& firstString,
                     const string& secondString);


    /*
     Brief:
        Compares two c++ string objects and returns a boolean
        value on whether the first string object lexically
        comes after the second string object

     Parameters:
        firstString - a c++ string object to be compared to
                    secondString

        secondString - a c++ string object to be compared to
                    firstString

     Return:
        bool - true if firstString lexically comes after
            secondString, and false if otherwise

    */
bool StringIsMoreThan(const string& firstString,
                      const string& secondString);


    /*
     Brief:
        Compares two UnaggregatedWeather instances and returns
        a boolean value on whether the first
        UnaggregatedWeather instance is less than the second
        UnaggregatedWeather instance

     Parameters:
        firstWeather - an UnaggregatedWeather instance to be
            compared to secondWeather

        secondWeather - an UnaggregatedWeather instance to be
            compared to firstWeather

     Return:
        bool - true if firstWeather is less than secondWeather,
             and false if otherwise
    */
bool UnaggregatedWeatherIsLessThan(
            const UnaggregatedWeather& firstWeather,
            const UnaggregatedWeather& secondWeather);


    /*
     Brief:
        A struct that overloads the () operator
        which defines the less-than '<' comparison.
        Such structs are commonly
        used by the Standard Template Library(STL)
    */
struct DateIsLessThanFuncObj
{
        /*
         Brief:
            Compares two Date instances and returns a boolean
            value on whether the first Date instance is equal
            to the second Date instance

        Parameters:
            firstDate - a Date instance to be compared to
                    secondDate

            secondDate - a Date instance to be compared to
                    firstDate


        Return:
            bool - true if firstDate is equal to secondDate, and
                    false if otherwise

        */

    bool operator()(const Date& firstDate,
                    const Date& secondDate) const;
};




#endif // DATA_COMPARISON_DEFINITIONS_H
