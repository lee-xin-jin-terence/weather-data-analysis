#ifndef DATE_IS_LESS_THAN_STRUCT_H
#define DATE_IS_LESS_THAN_STRUCT_H


#include "../Classes/Date/Date.h"


namespace TwoDimensionalBstTestSubcomponent
{
        /*
         A struct that overloads the () operator
         which defines the less-than '<' comparison.
         Such structs (called functors) are commonly
         used by the Standard Template Library(STL)
        */
    struct DateIsLessThanStruct
    {
        bool operator()( const Date& firstDate,
                         const Date& secondDate) const;
    };
}


#endif // DATE_IS_LESS_THAN_STRUCT_H
