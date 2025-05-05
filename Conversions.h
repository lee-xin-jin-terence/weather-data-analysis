#ifndef CONVERSIONS_H
#define CONVERSIONS_H

#include <string>


using std::string;


    /*
     Brief:
        Depending on integer value of the month given
        from the parameter, return the corresponding
        word-equivalent month values in string
        E.g. 1 will return "January", 2 will return "February",
            ... 12 will return "December", any other number
            will return "Invalid month parameter!"


     Parameters:
        month - the month value that is to be converted
              into a word-string

        returnedMonthString - This is the value that is
              to be returned by parameter. It contains the
              string value word-form of the month parameter
              in [1]

     Return:
        returnedMonthString - the c++ string object reference
            of month in word-form, to be returned by
            parameterised reference

    */
void GetMonthString(int month, string& returnedMonthString);


    /*
     Brief:
        Returns the value of wind speed in km/h from m/s

     Parameter:
        windSpeedMS - the wind speed to be converted in m/s

     Return:
        float - the wind speed in km/h
    */
float ConvertWindSpeedMSToKMH (float windSpeedMS);


    /*
      Brief:
        Return the resulting amount of radiation
        energy in kWh/m^2

      Parameter:
         radiationWM2 - the amount of radiation
                per 10 minutes in W/m^2

      Return:
        float - the amount of radiation in kWh/m^2
    */
float Convert10MinRadEnergyToKWHM2 (float radiationWM2);

#endif // CONVERSIONS_H
