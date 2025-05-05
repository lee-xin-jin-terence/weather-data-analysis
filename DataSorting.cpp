#include "DataSorting.h"


bool MergeSortUnaggregatedWeatherVector(
        UnaggregatedWeatherVector& unaggWeatherVec)
{

    bool hasSufficientMemory;


    int leftVecIndex;
    int middleVecIndex;
    int rightVecIndex;

    UnaggregatedWeather* tempArray = nullptr;


        /*
            STEP 1:
            Create a temporary array (container) to be used
            for the sorting
        */
    int weatherVecCurrentSize =
                              unaggWeatherVec.GetCurrentSize();

    tempArray =
            new UnaggregatedWeather[weatherVecCurrentSize];


    hasSufficientMemory = (tempArray != nullptr);

        /*
            STEP 2:
            If there is sufficient memory to create the temporary
            array(container), then the sorting of the
            Vector will commence. Otherwise, no sorting will
            be done
        */
    if (hasSufficientMemory)
    {

        for (int width = 1; width < weatherVecCurrentSize;
                                            width = 2*width )
        {

            for (int index = 0; index < weatherVecCurrentSize;
                index += 2*width)
            {

                    /*
                        STEP 3:
                        Divide the vector into two and
                        delegate the sorting and merging to
                        the helper function
                        MergeUnaggregatedWeatherVector
                    */
                leftVecIndex = index;


                middleVecIndex = Min((index + width),
                                     weatherVecCurrentSize);

                rightVecIndex = Min((index + 2* width),
                                    weatherVecCurrentSize);


                MergeUnaggregatedWeatherVector(
                                    unaggWeatherVec,tempArray,
                                    leftVecIndex, middleVecIndex,
                                    rightVecIndex);

            }

        }

            /*
                STEP 4:
                Deallocate memory used by the temporary array
                (container)
            */
        delete [] tempArray;
        tempArray = nullptr;

    }//end of if (hasSufficientMemory)


        /*
            STEP 5:
            Return a boolean to indicate whether the sorting
            is successful. The only reason for unsuccessful
            sorting is insufficient memory

            true - successful
            false - unsuccessful
        */
    return hasSufficientMemory;
}


//-------------------------------------------------------------
void MergeUnaggregatedWeatherVector(
                    UnaggregatedWeatherVector& unaggWeatherVec,
                    UnaggregatedWeather* tempArray,
                    int leftVecIndex, int middleVecIndex,
                    int rightVecIndex)
{


    UnaggregatedWeather currentWeatherLeft;
    UnaggregatedWeather currentWeatherRight;



    int i = leftVecIndex;
    int j = middleVecIndex;
    int k = leftVecIndex;


        /*
            STEP 1:
            Retrieve the values from the sub-vectors and
            sort them in the temporary array
        */
    while(i < middleVecIndex || j < rightVecIndex)
    {

            /*
                It is ok even if either i or j is out
                of bounds of the vector, as it will be
                handled by the underlying Vector template
                class
            */
        unaggWeatherVec.Get(i, currentWeatherLeft);
        unaggWeatherVec.Get(j, currentWeatherRight);


        //if both sub-Vectors still have elements
        if (i < middleVecIndex && j < rightVecIndex)
        {

            if ( UnaggregatedWeatherIsLessThan(
                    currentWeatherLeft,currentWeatherRight))
            {
                tempArray[k] = currentWeatherLeft;
                i++;
            }
            else
            {
                tempArray[k] = currentWeatherRight;
                j++;
            }
        }
        else if (i == middleVecIndex)
        {
            //if left sub-Vector is empty
            tempArray[k] = currentWeatherRight;
            j++;
        }
        else if (j == rightVecIndex)
        {
            //if right sub-Vector is empty
            tempArray[k] = currentWeatherLeft;
            i++;
        }

        k++;

    }//end of while loop


        /*
            STEP 2:
            Copy the sorted elements from the temporary
            array into the actual array itself
        */

    for (int index = leftVecIndex;
         index < rightVecIndex; index++)
    {

        unaggWeatherVec.Set(index, tempArray[index] );
    }

}


//---------------------------------------------------------------
int Min(int firstNum, int secondNum)
{
        /*
            Returns the number with the lower value
        */
    if (firstNum <= secondNum)
    {
        return firstNum;
    }
    else
    {
        return secondNum;
    }
}
