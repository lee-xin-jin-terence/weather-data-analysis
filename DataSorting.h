#ifndef DATA_SORTING_H
#define DATA_SORTING_H


#include "TypeDefinitions.h"
#include "DataComparisonDefinitions.h"
#include "Classes/UnaggregatedWeather/UnaggregatedWeather.h"


    /*
     Brief:
        Sorts the vector (UnaggregatedWeatherVector)
        in ascending order according to Date and Time


     Parameter:
        unaggWeatherVec - the vector that is to be sorting
            according to Date and Time


     Return:
        bool - true if sorting is successful , meaning that
            there is sufficient memory available for sorting,
            and false if sorting is unsuccessful
    */
bool MergeSortUnaggregatedWeatherVector(
        UnaggregatedWeatherVector& unaggWeatherVec);


    /*
     Brief:
        Merges and sorts a portion of the Vector
        UnaggregatedWeatherVector

        This is a helper function to the above
        MergeSortUnaggregatedWeatherVector function

     Parameters:
        unaggWeatherVec - the vector to be sorted

        tempArray - a pointer to the array that is used as a
                    temporary container for sorting

        leftVecIndex - the starting index of the portion of the
                       vector to be sorted


        middleVecIndex - The middle index of the portion of the
                        vector to be sorted

        rightVecIndex - One index position after the end of
                        the end portion of the vector to be
                        sorted

     Return: void
    */
void MergeUnaggregatedWeatherVector(
        UnaggregatedWeatherVector& unaggWeatherVec,
        UnaggregatedWeather* tempArray,
        int leftVecIndex, int middleVecIndex,
        int rightVecIndex);


    /*
     Brief:
        Compares two numbers and returns the number with
        the lower value

        This is a helper function to the above
        MergeSortUnaggregatedWeatherVector function


     Parameters:
        firstNum - the number to be compared to secondNum

        secondNum - the number to be compared to firstNum


     Return:
        int - the number with the lower value between
              firstNum and secondNum
    */
int Min(int firstNum, int secondNum);

#endif // DATA_SORTING_H
