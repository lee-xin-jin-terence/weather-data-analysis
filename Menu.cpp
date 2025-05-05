
#include "Menu.h"

void StartMenuLoop(const AggregatedWeatherMap& aggWeatherMap,
                   const DateBst& aggWeatherQueryTree)
{
    const int NUM_OF_MENU_OPTIONS = 5;


    int menuChoiceSelected;
    bool wishToEnd = false;
    int yearValue;
    int monthValue;
    string resultString;
    string uselessString;

    bool writeToFileOutcome;

        /*
            Constantly loop the menu until the user has
            chosen to end the program, that is option 5
        */
    do
    {
        DisplayMenuText();

        menuChoiceSelected =
                PromptAndGetMenuOption(NUM_OF_MENU_OPTIONS);

        switch(menuChoiceSelected)
        {
            case 1:
                yearValue = PromptAndGetYearValue();
                monthValue = PromptAndGetMonthValue();

                ProcessOption1Result(
                    aggWeatherMap,
                    aggWeatherQueryTree,
                    yearValue, monthValue, resultString);

                cout << resultString;
                break;

            case 2:
                yearValue = PromptAndGetYearValue();

                ProcessOption2Result(
                    aggWeatherMap,
                    aggWeatherQueryTree,
                    yearValue, resultString);

                cout << resultString;
                break;

            case 3:
                yearValue = PromptAndGetYearValue();

                ProcessOption3Result(
                    aggWeatherMap,
                    aggWeatherQueryTree,
                    yearValue, resultString);


                cout << resultString;
                break;

            case 4:
                yearValue = PromptAndGetYearValue();

                ProcessOption4Result(
                    aggWeatherMap,
                    aggWeatherQueryTree,
                    yearValue, resultString);


                writeToFileOutcome =
                            WriteDataToFile(OUTPUT_FILE_NAME,
                                            resultString);

                DisplayFileWriteOutcomeMessage(
                                        writeToFileOutcome);

                break;

            case 5:
                wishToEnd = true;
                cout << "You have chosen to terminate the "
                     << "program.";
                break;
        }


        cout <<  "\n\n\n";
        cout << "<Enter to continue>" << '\n';
        getline(cin, uselessString, '\n');


    }while (!wishToEnd);

}


//--------------------------------------------------------
        //Displays the menu text only, and does nothing else
void DisplayMenuText()
{
    cout << "1. The average wind speed and average ambient "
         << "air temperature for a specified month" << '\n'
         << " and year.(print on screen only)" << "\n\n";

    cout << "2. Average wind speed and average ambient "
         << "air temperature for each month of a" << '\n'
         << " specified year.(print on screen only)" << "\n\n";

    cout << "3. Total solar radiation in kWh/m^2 for each month"
         << " of a specified year." << '\n'
         << "(print on screen only)" << "\n\n";

    cout << "4. Average wind speed (km/h), average ambient air"
         << " temperature and total solar" << '\n'
         << " radiation in kWh/m^2 for each month of a"
         << " specified year.(write to a file called"
         << '\n' << " \"WindTempSolar.csv\")" << "\n\n";

    cout << "5. Exit the program." << "\n\n";
}


//--------------------------------------------------------------
int PromptAndGetMenuOption(int numberOfOptions)
{
    int menuOption;

    bool validValueEntered = false;


        /*
            Step 1: Prompting and Getting a menu option
            ---------------------------------------------
            Prompts the user for a menu option from 1
            to numberOfOptions. Will keep prompting
            the user until the user enters a valid value
        */
    while (!validValueEntered)
    {

        cout << "Enter a menu option: " ;

        cin >> menuOption;

        cout << '\n';


        if (!cin.good())
        {
            cout << "Error! You have entered an invalid "
                << " non-numeric value. Please enter a"
                << '\n' << " valid menu option" << "\n\n";

            //clear error flags from the input stream
            cin.clear();


        }
        else if (menuOption < 1 || menuOption > numberOfOptions)
        {
            cout << "Error! You have entered an invalid numeric"
                << " option outside of the valid range."
                << '\n' << "Please enter a valid menu option"
                << "\n\n";

        }
        else
        {
            validValueEntered = true;
        }


            //clears the input stream of any stray characters
        cin.ignore(200, '\n');
    }


        /*
            Step 2: Returning the menu option that the
            user has selected
        */
    return menuOption;

}


//-------------------------------------------------------------
int PromptAndGetYearValue()
{
    int yearValue;
    bool validValueEntered = false;


        /*
            Step 1: Prompt and Get year value from the user.
            ------------------------------------------------
            Will keep prompting until user enters a valid
            year value
        */
    while(!validValueEntered)
    {
        cout << "Enter the year : " ;

        cin >> yearValue;

        cout << '\n';


        if (!cin.good())
        {
            cout << "Error! You have entered an invalid "
                << " non-numeric year value." << "\n\n";

            //clear error flags from the input stream
            cin.clear();


        }
        else if (yearValue < 1 )
        {
            cout << "Error! You have entered an invalid numeric"
                << " year value less than 1."
                << "\n\n";

        }
        else
        {
            validValueEntered = true;
        }

        //removes from the standard input stream any
        //remaining stray characters
        cin.ignore(200 , '\n');

    }

        /*
            Step 2: Return the year value that user has
            entered
        */
    return yearValue;
}


//--------------------------------------------------------------
int PromptAndGetMonthValue()
{
    int monthValue;
    bool validValueEntered = false;

        /*
            Step 1: Prompt and Get month value. Will keep
            prompting a month value from the user until the
            user enters a valid month value
        */
    while (!validValueEntered)
    {
        cout << "Enter the month (E.g. 1 to represent January,"
            << " 2 to represent February, " << '\n'
            << "... 12 to represent December) : " ;

        cin >> monthValue;


        cout << '\n';



        if (!cin.good())
        {
            cout << "Error! You have entered an invalid "
                 << "non-numeric month value." << "\n\n";


            //clear error flags from the input stream
            cin.clear();

        }
        else if (monthValue < 1 || monthValue > 12)
        {
            cout << "Error! You have entered an invalid numeric"
                << " month value outside the range of 1 to 12."
                << "\n\n";
        }
        else
        {
            validValueEntered = true;
        }

        //removes from the standard input stream any
        //remaining stray characters
        cin.ignore(200 , '\n');

    }

        /*
            Step 2: Return the month value that the user
            has entered
        */
    return monthValue;
}


//-----------------------------------------------------------
void DisplayFileWriteOutcomeMessage(bool writeToFileOutcome)
{
        /*
            Displays the outcome of writing data to an
            output file. Specifically used by option 4
        */

    if(writeToFileOutcome)
    {
        cout << "Successfully written to file "
             << OUTPUT_FILE_NAME <<'\n';
    }
    else
    {
        cout << "Failed to write to file "
             << OUTPUT_FILE_NAME << '.' << '\n'
             << "It may be due to the file already existing "
             << "as a read-only \n"
             << "file in the destination folder"
             << " or that the file is \n"
             << "currently open in another program."
             << '\n';

    }

}
