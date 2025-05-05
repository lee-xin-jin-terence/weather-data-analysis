#ifndef FILE_IO_H
#define FILE_IO_H

#include <fstream>
#include <string>
#include "Constants.h"

using std::string;
using std::ifstream;
using std::ofstream;


    /*
     Brief:
        Reads from a file and returns the data read as
        a string

     Parameters:
        inputFileName - the file name to be opened and read

        returnedFileDataString - the string reference that
            contains the data read from the input file

     Return:
        float - boolean true if the file exists and is not
            empty, and false if otherwise.

        returnedFileDataString -  a c++ string object reference
            which contains the data read from inputFileName. If
            the file inputFileName does not exists or is empty,
            then returnedFileDataString  will be an empty string
    */
bool ReadInputFile(const char inputFileName[],
                   string& returnedFileDataString);


    /*
     Brief:
        Writes data stored in a string to a file

     Parameter:
        outputFileName - the name of the output file

        dataToWriteToFile - a c++ string object reference
            that contains the data to write to the output
            file outputFileName

     Return:
        boolean - true if writing to the file
            outputFileName is successful ,and
            false if outputFileName is a read-only
            file or is currently opened in another program)
    */
bool WriteDataToFile(const char outputFileName[],
                     const string& dataToWriteToFile);

#endif // FILE_IO_H
