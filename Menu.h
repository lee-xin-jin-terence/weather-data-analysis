#ifndef MENU_H
#define MENU_H

#include <string>
#include <iostream>
#include "FileIO.h"
#include "TypeDefinitions.h"
#include "ProcessOutputResult.h"


using std::cout;
using std::cin;
using std::string;


    /*
     Brief:
        Displays the menu, prompts the user for menu option,
        display results and repeats until the user wishes
        to exit the program


     Parameters:
        aggWeatherMap - a STL Map that stores the actual
            aggregated weather data. This map must already
            be populated beforehand

        aggWeatherQueryTree - a Binary Search Tree that is
            used to query whether a particular aggregated
            weather record exists. This tree must already
            be populated beforehand


     Return: void
    */
void StartMenuLoop(const AggregatedWeatherMap& aggWeatherMap,
                   const DateBst& aggWeatherQueryTree);


    /*
     Brief:
        Displays the menu text, and does nothing else

     Return: void
    */
void DisplayMenuText();


    /*
     Brief:
        Prompt a user for a menu option

     Parameter:
        numberOfOptions - the number of options available in
            the menu

     Return:
        int - the option that the user has selected from the
            menu, between 1(inclusive) and numberOfOptions
            (inclusive)
    */
int PromptAndGetMenuOption(int numberOfOptions);


    /*
     Brief:
        Prompt from the user a year value of interest
        for searching purposes

     Return:
        int - a year value to be used for searching

    */
int PromptAndGetYearValue();


    /*
     Brief:
        Prompt from the user a month value of interest
        for searching purposes

     Return:
        int - a month value to be used for searching
    */
int PromptAndGetMonthValue();


    /*
     Brief:
        Displays a message to the screen the outcome
        of writing data to an output file

     Parameter:
        writeToFileOutcome - a boolean value to signify
            whether writing to the output file is successful.
            True represents successful writing and false
            to represent failure.
    */
void DisplayFileWriteOutcomeMessage(bool writeToFileOutcome);

#endif // MENU_H
