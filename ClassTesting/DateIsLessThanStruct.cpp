#include "DateIsLessThanStruct.h"

bool TwoDimensionalBstTestSubcomponent::
     DateIsLessThanStruct::operator()(
                            const Date& firstDate,
                            const Date& secondDate) const
{

        /*
            STEP 1:
            Extract the day, month and year values from
            both Date instances
        */
    int firstDateDay = firstDate.GetDay();
    int firstDateMonth = firstDate.GetMonth();
    int firstDateYear = firstDate.GetYear();

    int secondDateDay = secondDate.GetDay();
    int secondDateMonth = secondDate.GetMonth();
    int secondDateYear = secondDate.GetYear();


        /*
            Step 2:
            Return a boolean value on whether firstDate
            is less than secondDate
        */
    return ((firstDateYear < secondDateYear)
                          ||
            (firstDateYear == secondDateYear &&
             firstDateMonth < secondDateMonth)
                          ||
            (firstDateYear == secondDateYear &&
             firstDateMonth == secondDateMonth &&
             firstDateDay < secondDateDay));
}
