#ifndef DATE_H
#define DATE_H


    /**
    * @class Date
    *
    * @brief Used to create an instance of the Date that
    *  stores the day, month, and year values
    *
    * @author Terence Lee
    * @version 01
    * @date 28 January 2020 Terence Lee, Created
    */

class Date
{
    public:
            /**
            *@brief Initialises the values of m_day, m_month
            * and m_year to all 0
            */
        Date();


            /**
            * @brief Assigns the value of day to the instance
            *  variable m_day, only if the value of day is
            *  a valid day value between 1 (inclusive) and
            *  31 (inclusive)
            *
            * @param day - Used to set the value of m_day
            *
            * @warning Does a simple check for the day. Does
            *  not prevent invalid day values such as 31
            *   for m_day if the current month(m_month)
            *   value is 2 (February)
            *
            * @return bool - true if the value of day is between
            *  1 (inclusive) and 31 (inclusive), and false
            *  if otherwise
            */
        bool SetDay(int day);


            /**
            * @brief Returns the value of m_day (day).
            *    Returns -1 if the value of m_month
            *    is not yet set
            *
            * @return int - value of day in integer
            */
        int GetDay() const;


            /**
            * @brief Assigns the value of month to the instance
            *   variable m_month, only if the value of month
            *   is valid, that is between 1 (inclusive) and
            *   12 (inclusive)
            *
            * @param month - Used to set the value of m_month
            *
            * @warning Does a simple check on the month value.
            *  Does not check if the month value is truly
            *  valid against the day value, such as month value
            *  of 2 (February) when the day value is 31 .
            *
            * @return bool - true if the value of month is a valid
            *  month value between 1(inclusive) and
            *  12 (inclusive), and false if otherwise
            */
        bool SetMonth(int month);


            /**
            * @brief Returns the value of m_month (month)
            *  Returns -1 if the value of m_month is not
            *   yet set
            *
            * @return int - Value of month in integer
            */
        int GetMonth() const;


            /**
            * @brief Assigns the value of year to the instance
            *  variable m_year, only if the year value is a
            *  valid value starting from 1 (inclusive) onwards
            *
            * @param year - Used to set the value of m_year
            *
            * @return bool - true if the value of year is from
            *  1 (inclusive) onwards,and false if otherwise
            */
        bool SetYear(int year);


            /**
            * @brief Returns the value of m_year (year)
            *  Returns -1 if the value of m_year is not yet set
            *
            * @return int - Value of year in integer
            */
        int GetYear() const;


    protected:
            /// Stores the day of the Date instance
        int m_day;

            /// Stores the month of the Date instance
        int m_month;

            /// Stores the year of the Date instance
        int m_year;

};//end of class



#endif // DATE_H
