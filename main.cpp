
#include <iostream>
#include "Menu.h"
#include "TypeDefinitions.h"
#include "DataComparisonDefinitions.h"
#include "RawDataProcessing.h"
#include "DataAggregation.h"
#include "ClassTesting/Testing.h"

using std::cout;
using std::string;

    //Runs the actual program
void RunProgram();



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


    prepareOutcome = PrepareProgramData(aggWeatherMap,
                                        aggWeatherQueryTree);



    if (prepareOutcome)
    {
       StartMenuLoop(aggWeatherMap,aggWeatherQueryTree);
    }


    aggWeatherMap.clear();
    aggWeatherQueryTree.Clear();

}


//--------------------------------------------------------------
bool PrepareProgramData(AggregatedWeatherMap& aggWeatherMap,
                        DateBst& aggWeatherQueryTree)
{
    bool prepareOutcome;
    string errorMessage;

    UnaggregatedWeatherVector unaggWeatherVec;


    cout << "Please wait a moment" << "\n\n\n";

    prepareOutcome =
                StoreAllUnaggregatedRecordsInVector(
                        unaggWeatherVec,errorMessage);


    if (prepareOutcome)
    {

        MergeSortUnaggregatedWeatherVector(unaggWeatherVec);

        prepareOutcome =
                CreateAggWeatherMapAndQueryTree(unaggWeatherVec,
                                                aggWeatherMap,
                                                aggWeatherQueryTree);


        if (!prepareOutcome)
        {
            cout << "Error! Insufficient memory space required "
                 << "by program to run" << "\n\n\n";
        }
    }
    else
    {
        cout << errorMessage << "\n\n\n";
    }


    unaggWeatherVec.Clear();

    return prepareOutcome;
}
