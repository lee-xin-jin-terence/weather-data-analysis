#ifndef TIME_H
#define TIME_H


    /**
    * @class Time
    *
    * @brief Used to create an instance of the Time that
    *  stores the hour, minute and second values
    *
    * @author Terence Lee
    * @version 01
    * @date 12 February 2020 Terence Lee, Created
    *
    */
class Time
{
    public:
            /**
            * @brief Creates an instance of Time, and
            * initialises the values of m_hour, m_minute,
            * m_second all to 0
            */
        Time();


            /**
            * @brief Sets the value of m_hour, only if
            * the parameter value of hour is a valid value
            * between 0 (inclusive) and 23 (inclusive)
            *
            * @param hour - Used to set the value of m_hour
            *
            * @return bool - true if the setHour() operation is
            * successful, where hour is a valid parameter
            * value between 0 (inclusive) and 23 (inclusive),
            * and false if otherwise
            */
        bool SetHour(int hour);


            /**
            * @brief Returns the value of hour (m_hour).
            *
            * @return int - the value of hour
            */
        int GetHour() const;


            /**
            * @brief Sets the value of m_minute, only if
            * the parameter value of minute is a valid value
            * between 0 (inclusive) and 59 (inclusive)
            *
            * @param minute - Used to set the value of m_minute
            *
            * @return bool - true if the setMinute() operation is
            * successful, where minute is a valid parameter
            * value between 0 (inclusive) and 59 (inclusive),
            * and false if otherwise
            */
        bool SetMinute(int minute);


            /**
            * @brief Returns the value of minute (m_minute).
            *
            * @return int - the value of minute
            */
        int GetMinute() const;


            /**
            * @brief Sets the value of m_second, only if
            * the parameter value of second is a valid value
            * between 0 (inclusive) and 59 (inclusive)
            *
            * @param second - Used to set the value of m_second
            *
            * @return bool - true if the setSecond() operation is
            * successful, where second is a valid parameter
            * value between 0 (inclusive) and 59 (inclusive),
            * and false if otherwise
            */
        bool SetSecond(int second);


            /**
            * @brief Returns the value of second (m_second).
            *
            * @return int - the value of second
            */
        int GetSecond() const;


    protected:
            /// Stores the hour value of Time
        int m_hour;

            /// Stores the minute value of Time
        int m_minute;

            /// Stores the second value of Time
        int m_second;
};

#endif // TIMES_H
