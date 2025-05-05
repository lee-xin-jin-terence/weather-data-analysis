#include "Conversions.h"


void GetMonthString(int month, string& returnedMonthString)
{
    string returnedString;

        /*
            Depending on integer value of the month given
            from the parameter, return the corresponding
            word-equivalent month values in string
        */
    switch (month)
    {
        case 1:
            returnedMonthString = "January";
            break;

        case 2:
            returnedMonthString = "February";
            break;

        case 3:
            returnedMonthString = "March";
            break;

        case 4:
            returnedMonthString = "April";
            break;

        case 5:
            returnedMonthString = "May";
            break;

        case 6:
            returnedMonthString = "June";
            break;

        case 7:
            returnedMonthString = "July";
            break;

        case 8:
            returnedMonthString = "August";
            break;

        case 9:
            returnedMonthString = "September";
            break;

        case 10:
            returnedMonthString = "October";
            break;

        case 11:
            returnedMonthString = "November";
            break;

        case 12:
            returnedMonthString = "December";
            break;

        default:
            returnedMonthString = "Invalid month parameter!";
            break;
    }
}


//-------------------------------------------------------------
float ConvertWindSpeedMSToKMH(float windSpeedMS)
{
        //Return the windspeed in km/h
    return windSpeedMS *3.6;
}


//-------------------------------------------------------------
float Convert10MinRadEnergyToKWHM2 (float radiationWM2)
{
        //Return the resulting amount of radiation
        //energy in kWh/m^2
    return radiationWM2/6000;
}

