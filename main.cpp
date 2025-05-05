
#include <iostream>
#include "Menu.h"
#include "DataSorting.h"
#include "TypeDefinitions.h"
#include "DataAggregation.h"
#include "RawDataProcessing.h"
#include "ClassTesting/Testing.h"
#include "DataComparisonDefinitions.h"

using std::cout;
using std::string;

    /*
     Brief:
        Runs the actual program

     Parameters: void

     Return: void
    */
void RunProgram();


    /*
     Brief:
        Read data from data files, aggregate the data and
        store the aggregated data(records) in a map. Also, store
        the keys of aggregated records in binary search tree


     Parameters:
        aggWeatherMap - a map that stores aggregated weather
            records

        aggWeatherQueryTree - a binary search tree that stores
            the keys of the aggregated weather records


     Return:
        bool - false if the preparation fails due to some
            form of error
    */
bool PrepareProgramData(AggregatedWeatherMap& aggWeatherMap,
                        DateBst& aggWeatherQueryTree);



int main()
{
   // Remove the comment to run tests for all the classes
   // Go to ClassTesting/Testing.cpp to select the tests that you
   // do not wish to run and comment them off
   //RunAllClassTests();

    RunProgram();

    return 0;
}


//-----------------------------------------------------
void RunProgram()
{

    bool prepareOutcome;

    AggregatedWeatherMap aggWeatherMap;

    DateBst aggWeatherQueryTree(DateIsLessThan,
                                DateIsEqualTo,
                                DateIsMoreThan);


        /*-------------------------------------------------
            STEP 1: Prepare the data for the program,
               that is to populate the maps and binary
               search tree required for the program

        -------------------------------------------------*/
    prepareOutcome = PrepareProgramData(aggWeatherMap,
                                        aggWeatherQueryTree);



    if (prepareOutcome)
    {
       StartMenuLoop(aggWeatherMap,aggWeatherQueryTree);
    }

}


//--------------------------------------------------------------
bool PrepareProgramData(AggregatedWeatherMap& aggWeatherMap,
                        DateBst& aggWeatherQueryTree)
{
    bool prepareOutcome;
    string errorMessage;

    UnaggregatedWeatherVector unaggWeatherVec;


    cout << "Please wait a moment" << "\n\n\n";


        /*----------------------------------------------------
            STEP 1:
            Read the weather data files and store these data
            in the vector unaggWeatherVec

            If 'prepareOutcome' returns false, then the
            error message stored in the variable
            errorMessage will be displayed
        ----------------------------------------------------*/
    prepareOutcome =
                StoreAllUnaggregatedRecordsInVector(
                        unaggWeatherVec,errorMessage);


    if (!prepareOutcome)
    {
        cout << errorMessage << "\n\n\n";
    }
    else
    {

            /*-------------------------------------------------
                STEP 2:
                Sort the vector from Step 1 according to Date
                and Time

                If there is any error(due to insufficient memory)
                during sorting, the error message will be
                displayed
            --------------------------------------------------*/
        prepareOutcome =
            MergeSortUnaggregatedWeatherVector(unaggWeatherVec);


        if (!prepareOutcome)
        {
            cout << "Error! Insufficient memory space required "
                 << "by program to run" << "\n\n\n";
        }
        else
        {

                /*----------------------------------------------
                    STEP 3:
                    Aggregate the weather data. Store the
                    aggregated weather in the map aggWeatherMap.
                    Also, store the keys of the map in the
                    tree aggWeatherQueryTree

                    If prepareOutcome returns false, display
                    the error message (which is due to
                    insufficient memory)
                ----------------------------------------------*/
            prepareOutcome =
                CreateAggWeatherMapAndQueryTree(unaggWeatherVec,
                                                aggWeatherMap,
                                            aggWeatherQueryTree);


            if (!prepareOutcome)
            {
                cout << "Error! Insufficient memory space "
                     << "required by program to run"
                     << "\n\n\n";
            }


        }//end of if (!prepareOutcome)


    }//end of if (!prepareOutcome)



        /*-----------------------------------------------------
            STEP 4:
            Empty the vector containing unaggregated weather
            records (since it is of no use now)
        -----------------------------------------------------*/
    unaggWeatherVec.Clear();


        /*------------------------------------------------------
            STEP 5:
            Return the outcome of data preparation
            true - successful
            false - unsuccessful
        ------------------------------------------------------*/
    return prepareOutcome;
}
