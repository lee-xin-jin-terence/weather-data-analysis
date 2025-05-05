#ifndef CONSTANTS_H
#define CONSTANTS_H


    /*
     Brief:
        Location of where all the data files are stored
    */
const char DATA_DIRECTORY[] = "data/";


    /*
     Brief:
        The name of the index file that contains the list
        of data files to read
    */
const char DATA_INDEX_FILE_NAME[] = "data/met_index.txt";


    /*
     Brief:
        The estimated number of files to read

     Note:
        If the number here is far less than the actual number
        of files to read, it may lead to reduced program
        efficiency

    */
const int EST_NUM_OF_FILES_TO_READ = 10;


    /*
     Brief:
        The estimated number of records per file.

     Note:
        If the number here is far less than the
        actual number of records, it may lead to reduced
        program efficiency
    */
const int EST_NUM_OF_RECORDS_PER_FILE = 53000;


    /*
     Brief:
        The estimated total number of records to read
    */
const int EST_TOTAL_NUM_OF_RECORDS =
                            (EST_NUM_OF_FILES_TO_READ *
                            EST_NUM_OF_RECORDS_PER_FILE);



    /*
     Brief:
        The name of the output file to be created
        by the program
    */
const char OUTPUT_FILE_NAME[] = "WindTempSolar.csv";


    /*
     Brief:
        The level of precision(number of decimal places)
        expected in the output results
    */
const int FLOATING_POINT_PRECISION = 1;

#endif // CONSTANTS_H
