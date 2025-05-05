
#include "FileIO.h"


bool ReadInputFile(const char inputFileName[],
                   string& returnedFileDataString)

{
    returnedFileDataString = "";

    bool readFileOutcome = true;

    string currentLineData;

    ifstream inputFile;


        /*
            Step 1: Attempts to open the file for reading
            ---------------------------------------------
            Sets readFileOutcome flag to false if the file is
            not found
        */
    inputFile.open(inputFileName);

    if (!inputFile.good())
    {
        readFileOutcome = false;
    }


        /*
            Step 2: Attempts to read the opened file
            -----------------------------------------
            Pre-requisite: The file must first exist

            If the file is an empty file, then the flag
            readFileOutcome is set to false
        */

    if (readFileOutcome)
    {
        //(attempts to) read the first line
        currentLineData = "";
        getline(inputFile, currentLineData, '\n');


            /*
                If the file is an empty file, the
                flag readFileOutcome will be set to false
            */
        if (!inputFile.good() && currentLineData == "")
        {
            readFileOutcome = false;
        }
    }


        /*
            Step 3: Read the file data into a string
            -----------------------------------------
            Pre-requisite:  File must exists and not
            be empty

            Reads file line by line till the end of
            the file
        */

    if (readFileOutcome)
    {
            /*
                Note that the second condition in the
                while loop is there for the final line
                of the file stream. After reading the
                final line, the file stream will go into
                a "fail" state, before the final line is
                appended to returnedFileDataString.
                In order to not miss out
                on the last line, the second condition is
                added
            */
        while(inputFile.good() || currentLineData!= "" )
        {
            returnedFileDataString += currentLineData;
            returnedFileDataString += '\n';

            currentLineData = "";
            getline(inputFile, currentLineData, '\n');
        }


    }//end of if (readFileOutcome)


        /*
            Step 4: Close the file
            -------------------------------------
            Closes the file if it is opened
        */
    if (inputFile.is_open())
    {
        inputFile.close();
    }



        /*
            Step 5: Returns file-reading outcome
            ----------------------------------------
            Returns true if file-reading is successful
            Returns false if file-to-be-read is not
            found or is empty
        */
    return readFileOutcome;
}


//------------------------------------------------------------

bool WriteDataToFile(const char outputFileName[],
                     const string& dataToWriteToFile)
{

    ofstream outputFile;
    bool writeToFileOutcome = true;


        /*
            Step 1: Attempts to open the file for writing
            -----------------------------------------------
            The flag writeToFileOutcome will be set to false
            if the output file /or the current directory the
            output file is in is read-only or is already
            opened in another program

            Otherwise, the data stored in the string
            dataToWriteToFile will be written to the
            output file
        */
    outputFile.open(outputFileName);

    if (!outputFile.is_open())
    {
        writeToFileOutcome = false;
    }
    else
    {
        outputFile << dataToWriteToFile;

        outputFile.close();
    }


        /*
            Step 2: Return file-writing outcome
            --------------------------------------
            Returns true if writing data to output file
            is successful, and false if otherwise
        */
    return writeToFileOutcome;
}
