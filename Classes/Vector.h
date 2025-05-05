#ifndef VECTOR_H
#define VECTOR_H

    /**
    * @class Vector Template Class
    *
    * @brief A vector class that allows very fast appending
    *        of data to the end of vector instance, behaving
    *        somewhat like an array
    *
    * @author Terence Lee
    * @version 01
    * @date 7 February 2020 Terence Lee, Created
    */
template <typename ElemType>
class Vector
{
    public:
            /**
            * @brief Initialises the instance variables
            *  m_capacitySize and m_currentSize to 0.
            *  Sets pointer m_arrayPointer to nullptr
            */
        Vector();


            /**
            * @brief Frees up the memory on the heap taken
            * up by m_arrayPointer
            */
        virtual ~Vector();


            /**
            * @brief Makes sures that the vector has a
            *  m_capacitySize that is at least the value
            *  of formal parameter capacitySize
            *
            * If capacitySize is a negative number (invalid
            * value), then the method will fail, but the
            * current value of m_capacitySize will not be
            * changed.
            *
            * If capacitySize has a value less or equal
            * to the current value of m_capacitySize ,
            * then the method will succeed, but the current
            * value of m_capacitySize will not change
            *
            * If capacitySize has a value greater than the
            * current value of m_capacitySize, then the
            * method will attempt to reallocate memory
            * so that the value of m_capacitySize is changed
            * to the value of capacitySize. When reallocation
            * succeeds then the value of m_capacitySize would
            * be changed to capacitySize.
            *
            * In any case if there is not enough heap memory
            * for reallocation to occur, then this method
            * fail and return a boolean value of false.
            * Otherwise, this method succeeds and returns
            * a boolean value of true.
            *
            *
            * @return bool - true if the method succeeds and false
            *  if the method fails due to invalid
            *  capacitySize value or insufficient memory
            *  for reallocation
            */
        bool EnsureCapacity(int capacitySize);


            /**
            * @brief Returns the current size of the vector
            *   instance
            *
            * @return int - Value of current size of
            *   the vector instance
            */
        int GetCurrentSize() const;


            /**
            * @brief Returns the maximum capacity currently
            * allocated to the vector instance. This value
            *  is not a fixed value and can change when
            *  there is memory reallocation
            *
            * @return int - Maximum capacity of the
            *   vector instance
            */
        int GetCapacitySize() const;


            /**
            * @brief Adds an element to the back of the vector
            * Increases the value of m_currentSize by 1, only
            * on successful appending.
            *
            * If the vector instance has a m_capacitySize
            * value of 0 when this method is called. It will
            * reallocate memory and increase the
            * m_capacitySize value to 10. After successful
            * reallocation, appending would occur.
            *
            * If the vector instance has the value of
            * m_capacitySize equals to  m_currentSize when
            * this method is called, the method will attempt
            * to reallocate to a new memory where the current
            * value of m_capacitySize is doubled. After
            * successful reallocation, appending would occur.
            *
            * If the value of m_currentSize is smaller than
            * m_capacitySize when this method is called,
            * appending will still occur, but there will
            * be no reallocation of memory
            *
            * In any case where there is not enough heap memory
            * for reallocation to occur, the appending will
            * fail (not occur) and return a boolean value of
            * false. Otherwise, this method will successfully
            * append and return a boolean value of true.
            *
            *
            * @return bool - true if successful appending occurs
            * and false if failed to append
            *
            * @see Insert() if you wish to insert values into
            * the vector at anywhere except to append
            */
        bool Append(const ElemType& elemTypeObj);


            /**
            * @brief Inserts data anywhere into the vector
            * instance denoted by formal parameter index
            * except for appending. All current data values
            * in the vector from position index onwards will
            * be shifted by one value to their new position
            * by 1 (moved towards the back of the vector by
            * one position).
            *
            * The value of m_currentSize would be increased
            * by one upon successful insertion.
            *
            *
            * When this method is called when the value of
            * m_currentSize is smaller than m_capacitySize,
            * insertion would occur, but there will be no
            * memory reallocation.
            *
            * When this method is called when the value of
            * m_currentSize == m_capacitySize , the method
            * will attempt to reallocate to a new memory. After
            * a successful reallocation, the value will be
            * inserted.
            *
            * If the value of index is less than 0, or
            * more or equal to the value of m_currentSize,
            * insertion will fail (and not occur), as index
            * would be an invalid value
            *
            * In any case there is insufficient heap memory
            * during reallocation, insertion will also fail.
            *
            *
            * @return bool - true if insertion successfully takes
            * place and false if insertion fails
            *
            * @see Append() for adding values to the end of the
            * vector instance
            */
        bool Insert(int index , const ElemType& elemTypeObj);


            /**
            * @brief Re-assigns the value currently stored
            * in position index in the vector instance with
            * the value of elemTypeObj
            *
            * If the value of the index is less than 0,
            * or is more or equal to the value of m_currentSize,
            * the re-assigning will fail as the value of
            * index is invalid
            *
            * @return bool - true if re-assigning succeeds and false
            *  if re-assigning fails due to invalid index
            *  value
            *
            *
            * @see Append() to add values to the end of the
            * vector instance
            *
            * @see Insert() to add values to anywhere in the
            * vector instance except to the end
            */
        bool Set(int index, const ElemType& elemTypeObj);


            /**
            * @brief Returns by reference the value stored
            * at position index, through the formal
            * parameter returnObj
            *
            * If index has a value of less than 0 or
            * more or equals to m_currentSize (invalid
            * index value), then the Get() would fail and
            * not change the value of returnObj
            *
            * If the Get() method fails due to invalid
            * index value, the method will return a
            * boolean false value, otherwise the method
            * would return true
            *
            *
            * @return bool - true if the Get() method is successful
            *   in retrieving a value from position index
            *   and stores it in returnObj, and false if
            *   otherwise
            *
            * @return returnObj - the value stored in position
            *   index that will be returned by reference. Would
            *   not contain the expected return value if index
            *   represents an invalid position in the vector
            *   instance
            */
        bool Get(int index, ElemType& returnObj) const;


            /**
            * @brief Trims the size of the vector instance
            * so that the value of m_capacitySize equals
            * m_currentSize
            *
            * If the value of m_capacitySize is already equals
            * to the value of m_currentSize, then the trimming
            * already succeeds and no reallocation will occur
            *
            * If the value of m_capacitySize is greater than
            * value of m_currentSize, then the method will
            * attempt to trim the size of the vector instance
            * through a memory reallocation. If there is
            * sufficient heap memory, trimming will succeed.
            *
            * If there is insufficient heap memory for
            * reallocation to occur, trimming will fail and
            * this method will return a boolean false.
            * Otherwise, this method will succeed and return
            * a boolean true.
            *
            *
            * @return bool - true if trimming succeeds and false
            * if trimming fails due to lack of heap memory
            * for reallocation
            */
        bool TrimToCurrentSize();


            /**
            * @brief Removes the element from position index
            * and shifts the position of the elements starting
            * from (index + 1) onwards by -1 (Moves the elements
            * affected towards the front of the vector)
            *
            * Upon successful removal, the value of
            * m_currentSize will be reduced by one.
            *
            * In order for successful removal, the value of
            * index must be more or equal to 0 and also
            * less than m_currentSize, otherwise removal will
            * fail
            *
            * There is no memory reallocation involved whenever
            * this method is called. Therefore, the value of
            * vector capacity size (m_capacitySize) will not be
            * affected.
            *
            * @return bool - true upon successful removal and
            *   false otherwise
            */
        bool Remove(int index);


            /**
            * @brief Empties the contents of the entire vector
            * instance. The current size (m_currentSize) and
            * capacity size (m_capacitySize) of the vector will
            * be reset to 0 after this method is called.
            * Deallocates heap memory taken up by the vector
            * instance
            *
            * @return void
            */
        void Clear();

    protected:

            /// Current size of the vector instance
        int m_currentSize;


            /// Capacity size of the vector instance, which is
            /// the maximum number of elements the vector can hold
        int m_capacitySize;


            /// A array pointer that points to the array of
            /// values that the vector instance is containing.
        ElemType* m_arrayPointer;


    private:
            /**
            * @brief to be used internally by the defined
            *  public methods for copying arrays from
            *  one vector instances to another
            */
        static void CopyArray(ElemType* destination,
                    const ElemType* source, int copySize);


            /**
            * @brief This copy constructor is not
            * implemented as it can be replaced by calling
            * [1] the constructor, [2] EnsureCapacity()
            * using [3] GetCapacitySize() as parameter,
            * and [4] Append() using a for-loop that
            * loops for [5] GetCurrentSize() number of times
            *
            * Main reason why not implemented because it can
            * fail if there
            * is insufficient heap memory
            */
        Vector(const Vector<ElemType>& vectorObj);


            /**
            * @brief This assignment operator is not
            * implemented as it can be replaced by calling
            * [1] the constructor, [2] EnsureCapacity()
            * using [3] GetCapacitySize() as parameter,
            * and [4] Append() using a for-loop that
            * loops for [5] GetCurrentSize() number of times
            *
            * Main reason why implemented because it can fail
            * if there is insufficient heap memory
            */
        const Vector<ElemType>& operator =(const
                                Vector<ElemType>& vectorObj);




};


//------------------------------------------------------------
template <typename ElemType>
Vector<ElemType>::Vector()
{
    m_capacitySize = 0;
    m_currentSize = 0;
    m_arrayPointer = nullptr;
}


//--------------------------------------------------------------
template <typename ElemType>
Vector<ElemType>:: ~Vector()
{
    if (m_arrayPointer != nullptr)
    {
        delete [] m_arrayPointer;
        m_arrayPointer = nullptr;
    }
}


//--------------------------------------------------------------
template <typename ElemType>
bool Vector<ElemType>::EnsureCapacity(int capacitySize)
{

    ElemType* tempArrayPointer = nullptr;

    bool ensureCapacityOutcome = false;;



    if (capacitySize < 0)
    {
        // if capacitySize is an invalid value less than 0
        // the act of ensuring capacity is considered to have
        // failed and therefore return a boolean false

        ensureCapacityOutcome = false;

    }
    else if (capacitySize <= m_capacitySize)
    {
        // the act of ensuring capacity is considered to have
        // succeeded as the current m_capacitySize is already
        // equal or more than the value of capacitySize

        ensureCapacityOutcome = true;

    }
    else
    {
        tempArrayPointer = new ElemType[capacitySize];


        if (tempArrayPointer != nullptr)
        {
            // Reallocating the array to a new heap memory
            // when the requested capacitySize has a greater
            // value than the current value of m_capacitySize
            // and there is sufficient heap memory for such
            // reallocation

            CopyArray(tempArrayPointer, m_arrayPointer,
                                            m_currentSize);


            if (m_arrayPointer != nullptr)
            {

                delete [] m_arrayPointer;
            }

            m_arrayPointer = tempArrayPointer;
            m_capacitySize = capacitySize;

           ensureCapacityOutcome = true;

        }
        else
        {
            // If there is not enough heap memory to create
            // a new dynamic array and reallocate, then
            // the act of ensuring capacity would have failed
            // and would return a boolean false

            ensureCapacityOutcome = false;

        }
    }

    return ensureCapacityOutcome;
}


//--------------------------------------------------------------
template <typename ElemType>
int Vector<ElemType>::GetCurrentSize() const
{
    return m_currentSize;
}


//--------------------------------------------------------------
template <typename ElemType>
int Vector<ElemType>::GetCapacitySize() const
{
    return m_capacitySize;
}


//--------------------------------------------------------------
template <typename ElemType>
bool Vector<ElemType>::Append(const ElemType& elemTypeObj)
{
    bool appendOutcome = true;


    if (m_capacitySize == 0)
    {
        // the default size will be set to 10
        appendOutcome = EnsureCapacity(10);

    }
    else if (m_currentSize == m_capacitySize)
    {
        // if the capacity of the vector instance is already
        // full, then there will be an attempt to
        // double the capacity of the vector instance
        appendOutcome = EnsureCapacity(m_capacitySize*2);
    }


    // If there is sufficient heap memory available
    // for appending, then appending will occur
    if (appendOutcome)
    {
        m_arrayPointer[m_currentSize] = elemTypeObj;
        m_currentSize++;
    }

    return appendOutcome;
}


//--------------------------------------------------------------
template <typename ElemType>
bool Vector<ElemType>::Insert(int index, const ElemType&
                                                    elemTypeObj)
{
    bool insertOutcome = true;


    if (index >= m_currentSize || index < 0)
    {
        // if index has a invalid value, then the insert
        // is considered to have failed and would return
        // a boolean false
        insertOutcome = false;

    }
    else if (m_currentSize == m_capacitySize)
    {
        // if the capacity of the vector is already
        // full, then there will be attempt to double
        // the capacity of the vector
        insertOutcome = EnsureCapacity(m_capacitySize * 2);
    }


    // If there is sufficient heap memory available
    // for insertion, then insertion will occur
    if (insertOutcome)
    {
        for (int tempIndex = m_currentSize ;
                            tempIndex > index ; tempIndex--)
        {
            m_arrayPointer[tempIndex] =
                                m_arrayPointer[tempIndex-1];

        }

        m_arrayPointer[index] = elemTypeObj;

        m_currentSize++;
    }


    return insertOutcome;
}


//--------------------------------------------------------------
template <typename ElemType>
bool Vector<ElemType>::Set(int index, const ElemType&
                                                    elemTypeObj)
{

    if (index >= m_currentSize || index < 0)
    {
        return false;
    }
    else
    {
        m_arrayPointer[index] = elemTypeObj;
        return true;
    }
}


//--------------------------------------------------------------
template <typename ElemType>
bool Vector<ElemType>::Get(int index,
                            ElemType& returnObj) const
{
    if (index >= m_currentSize || index < 0)
    {
        return false;
    }
    else
    {
        returnObj = m_arrayPointer[index];
        return true;
    }
}


//---------------------------------------------------------------
template <typename ElemType>
bool Vector<ElemType>::TrimToCurrentSize()
{
    bool trimOutcome;
    ElemType* tempArrayPointer;


    if (m_currentSize == m_capacitySize)
    {
        // trimming is considered to have succeeded if the
        // current size of the vector is the same as the
        // capacity size
        trimOutcome= true;
    }
    else
    {
        tempArrayPointer = new ElemType[m_currentSize];

        //if the capacity size of the vector instance
        // is greater than its current size, then there
        // will be an attempt to trim. If there is sufficient
        // heap memory for reallocation, then trimming
        // will succeed. Otherwise, it will fail

        if (tempArrayPointer != nullptr)
        {
            CopyArray(tempArrayPointer,m_arrayPointer,
                            m_currentSize);

            delete [] m_arrayPointer;

            m_arrayPointer = tempArrayPointer;

            tempArrayPointer = nullptr;

            m_capacitySize = m_currentSize;

            trimOutcome = true;
        }
        else
        {
            trimOutcome = false;
        }
    }

    return trimOutcome;
}


//---------------------------------------------------------------
template <typename ElemType>
bool Vector<ElemType>::Remove(int index)
{
    bool removeOutcome;


    if (index >= m_currentSize || index < 0)
    {
        // if the index is an invalid index, the removal
        // is considered to have failed and would return
        // a false value

        removeOutcome = false;
    }
    else
    {
        for (int tempIndex=index;
                    tempIndex < m_currentSize -1; tempIndex++)
        {
            m_arrayPointer[tempIndex] =
                            m_arrayPointer[tempIndex+1];
        }

        m_currentSize--;

        removeOutcome = true;
    }

    return removeOutcome;
}


//------------------------------------------------------------
template <typename ElemType>
void Vector<ElemType>::Clear()
{
    m_capacitySize = 0;
    m_currentSize = 0;

    delete [] m_arrayPointer;
    m_arrayPointer = nullptr;
}


//------------------------------------------------------------
template <typename ElemType>
void Vector<ElemType>::CopyArray(ElemType* destination,
                        const ElemType* source,
                        int copySize)
{
    if (copySize > 0)
    {
        for (int index=0; index < copySize; index++)
        {
            destination[index] = source[index];
        }
    }
}

//--------------------------------------------------------------

#endif // VECTOR_H
