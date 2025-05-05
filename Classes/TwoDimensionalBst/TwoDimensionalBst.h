#ifndef TWO_DIMENSIONAL_BST_H
#define TWO_DIMENSIONAL_BST_H

#include <map>
#include "../Bst/Bst.h"


using std::map;



    /**
    * @class TwoDimensionalBst
    *
    * @brief Creates a binary search tree that stores
    * a  composite key for insertion, deletion
    * and searching
    *
    * @param FirstKeyType - a data type for the first key
    *
    * @param SecondKeyType - a data type for the second key
    *
    * @param FirstKeyTypeIsLessThanStruct - a functor (struct)
    * that overloads the ( ) operator.  Refer to the
    * doxygen comment regarding FirstKeyTypeIsLessThanStruct
    *
    * @author Terence Lee
    * @version 01
    * @date 23 March 2020
    */


    /**
    * @verbatim
    *    (Note that this is a verbatim doxygen comment)
    *    Example of FirstKeyTypeIsLessThanStruct
    *
    *    Note: This is to demonstrate how
    *          the struct FirstKeyTypeIsLessThanStruct should be
    *          written.
    *
    *    Overloaded operator ( ) parameters:
    *       firstKeyA - data to be compared to "firstKeyB"
    *       firstKeyB - data to be compared to "firstKeyA"
    *
    *    Overloaded operator ( ) return :
    *       bool - true if firstKeyA is less than secondKeyB,
    *           and false if otherwise
    *
    *    Please follow the example format strictly on
    *    writing the FirstKeyTypeIsLessThanStruct
    *
    *    Example, if you are using int as FirstKeyType,
    *
    *
    *    struct IntIsLessThan
    *    {
    *        bool operator() (const int& firstKeyA,
                              const int& firstKeyB) const
    *        {
                return firstKeyA < firstKeyB;
             };
    *    };
    *
    * @endverbatim
    */
template <typename FirstKeyType, typename SecondKeyType,
          typename FirstKeyTypeIsLessThanStruct>
class TwoDimensionalBst
{
    public:

            /**
            * @brief Typedef for callback function pointers
            * of FirstKeyType, used for data comparisons
            *
            * @param firstKeyA - a value to be compared to
            *   "firstKeyB"
            *
            * @param firstKeyB - a value to be compared to
            *   "firstKeyA"
            *
            * @return bool - true or false depending on the
            * type of comparison made
            */
        using FirstKeyTypeComparison =
                        bool (*)(const FirstKeyType& firstKeyA,
                                 const FirstKeyType& firstKeyB);


            /**
            * @brief Typedef for callback function pointers
            * of SecondKeyType, used for data comparisons
            *
            * @param secondKeyA - a value to be compared to
            *   "secondKeyB"
            *
            * @param secondKeyB - a value to be compared to
            *   "secondKeyA"
            *
            * @return bool - true or false depending on the
            * type of comparison made
            */
        using SecondKeyTypeComparison =
                        bool (*)(const SecondKeyType& secondKeyA,
                                 const SecondKeyType& secondKeyB);

            /**
            * @brief Creates an empty two-dimensional binary
            * search tree
            *
            * @param FirstKeyIsLessThan - a function pointer that
            *   defines the less-than comparison for FirstKeyType.
            *   The function pointed by the function pointer will
            *   return true if "firstKeyA" is less than "firstKeyB",
            *   and false if otherwise
            *
            * @param FirstKeyIsEqualTo - a function pointer that
            *   defines the equal-to comparison for FirstKeyType.
            *   The function pointed by the function pointer will
            *   return true if "firstKeyA" is equal to "firstKeyB",
            *   and false if otherwise
            *
            * @param FirstKeyIsMoreThan - a function pointer that
            *   defines the greater-than comparison for FirstKeyType.
            *   The function pointed by the function pointer will
            *   return true if "firstKeyA" is greater than
            *   "firstKeyB", and false if otherwise
            *
            * @param SecondKeyIsLessThan - a function pointer that
            *   defines the less-than comparison for SecondKeyType.
            *   The function pointed by the function pointer will
            *   return true if "secondKeyA" is less than "secondKeyB",
            *   and false if otherwise
            *
            * @param SecondKeyIsEqualTo - a function pointer that
            *   defines the equal-to comparison for SecondKeyType.
            *   The function pointed by the function pointer will
            *   return true if "secondKeyA" is equal to "secondKeyB",
            *   and false if otherwise
            *
            * @param SecondKeyIsMoreThan - a function pointer that
            *   defines the greater-than comparison for
            *   SecondKeyType. The function pointed by the
            *   function pointer will return true if "secondKeyA"
            *   is greater than "secondKeyB", and false if otherwise
            */
        TwoDimensionalBst(
                      FirstKeyTypeComparison FirstKeyIsLessThan,
                      FirstKeyTypeComparison FirstKeyIsEqualTo,
                      FirstKeyTypeComparison FirstKeyIsMoreThan,
                      SecondKeyTypeComparison SecondKeyIsLessThan,
                      SecondKeyTypeComparison SecondKeyIsEqualTo,
                      SecondKeyTypeComparison SecondKeyIsMoreThan);




            /**
            * @brief Clears the tree when the tree goes out of
            * scope
            */
        ~TwoDimensionalBst();


            /**
            * @brief Checks whether the tree is empty
            *
            * @return bool - true if the tree is empty and
            * false if the tree has at least one
            * FirstKeyType-SecondKeyType composite key
            * existing within the tree
            */
        bool IsEmpty() const;


            /**
            * @brief Removes all FirstKeyType-SecondKeyType
            * composite keys from
            * the tree, thereby emptying the tree
            *
            * @return void
            */
        void Clear();


            /**
            * @brief Searches the tree to check if a particular
            * FirstKeyType-SecondKeyType composite key exist
            *  within the tree
            *
            * @param firstKey - a FirstKeyType instance to be
            * paired up with the SecondKeyType instance secondKey
            *  to form a composite key
            *
            * @param secondKey - a SecondKeyType instance to be
            * paired up with the FirstKeyType instance firstKey
            *  to form a composite key
            *
            * @return bool - true if the particular
            * FirstKeyType-SecondKeyType composite key exists
            * within the tree, and false if otherwise
            */
        bool Search (const FirstKeyType& firstKey,
                     const SecondKeyType& secondKey) const;


            /**
            * @brief Inserts the FirstKeyType-SecondKeyType
            * composite key into  the tree, but only if it does
            * not already exist in the tree and there is sufficient
            * memory for the insertion to take place.
            *
            * @param firstKey - a FirstKeyType instance
            * to be paired up with the SecondKeyType instance
            * secondKey to form a composite key
            *
            * @param secondKey - a SecondKeyType instance to be
            * paired up with the FirstKeyType instance firstKey
            * to form a composite key
            *
            *
            * @return bool - true if insertion is successful,
            * meaning that the FirstKeyType-SecondKeyType composite
            * key does not already exist in the tree and there is
            * sufficient memory to insert. Otherwise, returns a
            * false
            */
        bool Insert(const FirstKeyType& firstKey,
                    const SecondKeyType& secondKey);


            /**
            * @brief Deletes the FirstKeyType-SecondKeyType composite
            * key from the tree, only if the key already
            * exist within the tree
            *
            * @param firstKey - a FirstKeyType instance to be paired
            * up with the SecondKeyType instance secondKey to form
            * a composite key
            *
            * @param secondKey - a SecondKeyType instance to be
            * paired up with the FirstKeyType instance firstKey to
            * form a composite key
            *
            * @return bool - true if the deletion is successful,
            * meaning that the FirstKeyType-SecondKeyType composite
            * key must already exist within the tree, and false
            * otherwise for failure to delete a non-existent
            * FirstKeyType-SecondKeyType composite key
            * when the composite key does not exist
            */
        bool Delete(const FirstKeyType& firstKey,
                    const SecondKeyType& secondKey);


    private:

            ///Type definition of the outer tree
        typedef Bst<FirstKeyType> OuterTree;

            ///Type definition of the inner tree
        typedef Bst<SecondKeyType> InnerTree;

            ///Type definition of a STL map where
            ///each InnerTree instance is mapped
            /// to a FirstKeyType instance
        typedef map<FirstKeyType, InnerTree*,
                FirstKeyTypeIsLessThanStruct>  KeyTreeMap;

            ///Type definition of an iterator of
            /// KeyTreeMap
        typedef typename KeyTreeMap::iterator KeyTreeMapItr;



            /// The outer FirstKeyType binary search tree
        OuterTree* m_outerTree;

            /// The map that maps a FirstKeyType instance to an inner
            /// SecondKeyType binary search tree
        KeyTreeMap m_keyTreeMap;


            /**
            * @brief A function pointer that will take two parameters.
            * Determines if the formal parameter "firstKeyA" has a
            * lower value than the formal parameter "firstKeyB".
            * Applies to the instances of FirstKeyType
            *
            * @param firstKeyA - the value to be compared to
            *  "firstKeyB"
            *
            * @param firstKeyB - the value to be compared to
            *  "firstKeyA"
            *
            * @return bool - true if "firstKeyA" has a lower value
            * than "firstKeyB", and false if otherwise
            */
        FirstKeyTypeComparison m_FirstKeyIsLessThan;


            /**
            * @brief A function pointer that will take two parameters.
            * Determines if the formal parameter "firstKeyA" is equal to
            * the formal parameter "firstKeyB". Applies to
            * the instances of FirstKeyType
            *
            * @param firstKeyA - the value to be compared to
            *   "firstKeyB"
            *
            * @param firstKeyB - the value to be compared to
            *   "firstKeyA"
            *
            * @return bool - true if "firstKeyA" is equal to
            * "firstKeyB", and false if otherwise
            */
        FirstKeyTypeComparison m_FirstKeyIsEqualTo;


            /**
            * @brief A function pointer that will take two parameters.
            * Determines if the formal parameter "firstKeyA" has a
            * greater value than the formal parameter "firstKeyB".
            * Applies to the instances of FirstKeyType
            *
            * @param firstKeyA - the value to be compared to "firstKeyB"
            *
            * @param firstKeyB - the value to be compared to "firstKeyA"
            *
            * @return bool - true if "firstKeyA" has a greater value
            * than "firstKeyB", and false if otherwise
            */
        FirstKeyTypeComparison m_FirstKeyIsMoreThan;


            /**
            * @brief A function pointer that will take two parameters.
            * Determines if the formal parameter "secondKeyA" has a
            * lower value than the formal parameter "secondKeyB".
            * Applies to the instances of SecondKeyType
            *
            * @param secondKeyA - the value to be compared to
            *   "secondKeyB"
            *
            * @param secondKeyB - the value to be compared to
            *   "secondKeyA"
            *
            * @return bool - true if "secondKeyA" has a lower value
            * than "secondKeyB", and false if otherwise
            */
        SecondKeyTypeComparison m_SecondKeyIsLessThan;


            /**
            * @brief A function pointer that will take two parameters.
            * Determines if the formal parameter "secondKeyA" is equal
            * to the formal parameter "secondKeyB". Applies to
            * the instances of SecondKeyType
            *
            * @param secondKeyA - the value to be compared to
            *   "secondKeyB"
            *
            * @param secondKeyB - the value to be compared to
            *   "secondKeyA"
            *
            * @return bool - true if "secondKeyA" is equal to
            *  "secondKeyB", and false if otherwise
            */
        SecondKeyTypeComparison m_SecondKeyIsEqualTo;


            /**
            * @brief A function pointer that will take two parameters.
            * Determines if the formal parameter "secondKeyA" has a
            * greater value than the formal parameter "secondKeyB".
            * Applies to the instances of SecondKeyType
            *
            * @param secondKeyA - the value to be compared to
            *   "secondKeyB"
            *
            * @param secondKeyB - the value to be compared to
            *   "secondKeyA"
            *
            * @return bool - true if "secondKeyA" has a greater value
            * than "secondKeyB", and false if otherwise
            */
        SecondKeyTypeComparison m_SecondKeyIsMoreThan;


            /**
            * @brief The copy constructor is not implemented
            * as the author feels that there is no need
            * to create a copy of a two dimensional
            * binary search tree
            *
            * Moreover, if there is insufficient memory and
            * the copying of the tree fails
            * mid-way,there is no way of knowing if such
            * a failure has occurred
            */
        TwoDimensionalBst ( const
                TwoDimensionalBst<FirstKeyType,
                    SecondKeyType,
                    FirstKeyTypeIsLessThanStruct>& otherTree);


            /**
            * @brief The assignment operator is not implemented
            * as the author feels that there is no need
            * to create a copy of a two dimensionl binary
            * search tree
            *
            * Moreover, if there is insufficient memory and
            * the copying of the binary search tree fails mid-way,
            * there is no way of knowing if such a failure
            * has occurred
            */
        const TwoDimensionalBst<FirstKeyType,SecondKeyType,
                FirstKeyTypeIsLessThanStruct>&

                operator =

                (const TwoDimensionalBst<FirstKeyType,
                    SecondKeyType,
                    FirstKeyTypeIsLessThanStruct>& otherTree );


};


//-----------------------------------------------------------------
template <typename FirstKeyType, typename SecondKeyType,
          typename FirstKeyTypeIsLessThanStruct>
TwoDimensionalBst <FirstKeyType,SecondKeyType,
                  FirstKeyTypeIsLessThanStruct>  ::

    TwoDimensionalBst(
              FirstKeyTypeComparison FirstKeyIsLessThan,
              FirstKeyTypeComparison FirstKeyIsEqualTo,
              FirstKeyTypeComparison FirstKeyIsMoreThan,
              SecondKeyTypeComparison SecondKeyIsLessThan,
              SecondKeyTypeComparison SecondKeyIsEqualTo,
              SecondKeyTypeComparison SecondKeyIsMoreThan)
{

    m_outerTree = nullptr;

    m_FirstKeyIsLessThan = FirstKeyIsLessThan;
    m_FirstKeyIsEqualTo =  FirstKeyIsEqualTo;
    m_FirstKeyIsMoreThan = FirstKeyIsMoreThan;

    m_SecondKeyIsLessThan = SecondKeyIsLessThan;
    m_SecondKeyIsEqualTo = SecondKeyIsEqualTo;
    m_SecondKeyIsMoreThan = SecondKeyIsMoreThan;
}


//--------------------------------------------------------
template <typename FirstKeyType, typename SecondKeyType,
          typename FirstKeyTypeIsLessThanStruct>
TwoDimensionalBst  <FirstKeyType,SecondKeyType,
        FirstKeyTypeIsLessThanStruct>  ::  ~TwoDimensionalBst()
{
        //Empties the tree
    Clear();
}


//--------------------------------------------------------
template <typename FirstKeyType, typename SecondKeyType,
          typename FirstKeyTypeIsLessThanStruct>
bool TwoDimensionalBst  <FirstKeyType,SecondKeyType,
        FirstKeyTypeIsLessThanStruct>  ::   IsEmpty() const
{
        //Returns true if the tree is empty
    return (m_outerTree == nullptr);
}


//--------------------------------------------------------
template <typename FirstKeyType, typename SecondKeyType,
          typename FirstKeyTypeIsLessThanStruct>
void TwoDimensionalBst  <FirstKeyType,SecondKeyType,
        FirstKeyTypeIsLessThanStruct>   ::   Clear()
{

    InnerTree* currentInnerTree = nullptr;

    KeyTreeMapItr itr;



    if (m_outerTree != nullptr)
    {
            /*
                STEP 1 :
                Empties and Deletes every inner Binary Search
                Tree stored within the map using the for-loop
            */

        for (itr = m_keyTreeMap.begin();
             itr != m_keyTreeMap.end();
             itr++)
        {
            currentInnerTree = itr->second;
            currentInnerTree->Clear();

            delete currentInnerTree;
            currentInnerTree = nullptr;
        }

        /*
            STEP 2:
            Empty the map and then empty the outer tree
        */

        m_keyTreeMap.clear();

        m_outerTree->Clear();

        delete m_outerTree;

        m_outerTree = nullptr;
    }



}


//------------------------------------------------------
template <typename FirstKeyType, typename SecondKeyType,
          typename FirstKeyTypeIsLessThanStruct>
bool TwoDimensionalBst <FirstKeyType,SecondKeyType,
        FirstKeyTypeIsLessThanStruct>::

            Search(const FirstKeyType& firstKey,
                   const SecondKeyType& secondKey) const
{

    bool searchOutcome;

    InnerTree* currentInnerTree = nullptr;


    searchOutcome = false;

        /*
            STEP 1:
            Check to see if the outer tree is empty
            If the outer tree is empty, it means that
            there are no keys stored in the TwoDimensionalBst
            instance, so there is nothing to search
        */
    if (m_outerTree!= nullptr)
    {

            /*
                STEP 2: First search for the
                firstKey
            */
        searchOutcome = m_outerTree->Search(firstKey);


            /*
                STEP 3: If  firstKey exists, then
                use the map to obtain the inner tree
                mapped to  firstKey
            */
        if (searchOutcome)
        {
            currentInnerTree =
                m_keyTreeMap.at(firstKey);


                /*
                    STEP 4:
                    After obtaining the inner tree, search
                    for the secondKey

                    If the searchOutcome has a boolean true,
                    it means the firstKey-secondKey composite
                    key exist within the TwoDimensionalBst
                     instance.
                */
            searchOutcome = currentInnerTree->Search(secondKey);

        }//if (searchOutcome)

    }//end of if (m_outerTree!= nullptr)

    return searchOutcome;
}


//-----------------------------------------------------------
template <typename FirstKeyType, typename SecondKeyType,
          typename FirstKeyTypeIsLessThanStruct>
bool TwoDimensionalBst <FirstKeyType,SecondKeyType,
        FirstKeyTypeIsLessThanStruct> ::

            Insert(const FirstKeyType& firstKey,
                   const SecondKeyType& secondKey)
{
    bool searchOutcome;
    bool insertOutcome;
    bool firstKeyExists;


    bool outerTreeWasCreated = false;
    bool innerTreeWasCreated  = false;


    InnerTree* newInnerTree = nullptr;
    InnerTree* currentInnerTree = nullptr;


        /*
            STEP 1:
            Search for the firstKey-secondKey composite key within
            the TwoDimensionalBst instance. There will be no
            insertion if the composite key
            already exists within the TwoDimensionalBst instance
        */

    searchOutcome = Search(firstKey, secondKey);

    if (!searchOutcome)
    {
        insertOutcome = true;
    }
    else
    {
        insertOutcome = false;
    }



        /*
            STEP 2:
            If the outer tree is empty (meaning not a single
            firstKey-secondKey composite key is stored within
            the TwoDimensionalBst instance), then memory is
            allocated to the outer tree. This step will be
            skipped if the outer tree already exists
        */
    if (insertOutcome && m_outerTree == nullptr)
    {
        m_outerTree = new OuterTree(m_FirstKeyIsLessThan,
                                    m_FirstKeyIsEqualTo,
                                    m_FirstKeyIsMoreThan);


            /*
                STEP 2.1
                If there is insufficient heap memory available
                for the allocation of memory for the outer
                tree, then insertion will fail
            */
        if (m_outerTree == nullptr)
        {
            insertOutcome = false;
        }
        else
        {
            outerTreeWasCreated = true;
        }

    }//end of if (insertOutcome && m_outerTree == nullptr)




    if (insertOutcome)
    {
            /*
                STEP 3:
                Now that there is an outer tree, the outer
                tree is searched for a matching firstKey.
            */
        firstKeyExists = m_outerTree->Search(firstKey);

            /*
                STEP 3.1
                If there is no matching firstKey, the
                firstKey is inserted into the outer tree. The
                remaining of Step 3 will be skipped be
                the firstKey already exists within the
                outer tree
            */
        if (!firstKeyExists)
        {

            insertOutcome = m_outerTree->Insert(firstKey);


                /*
                    STEP 3.2
                    If the insertion is successful, a new
                    inner tree is created with memory
                    allocated to it
                */
            if (insertOutcome)
            {
                newInnerTree = new InnerTree(
                                         m_SecondKeyIsLessThan,
                                         m_SecondKeyIsEqualTo,
                                         m_SecondKeyIsMoreThan);


                    /*
                        STEP 3.3
                        If the allocation of memory for a
                        new inner tree is not successful,
                        undo all the previous steps,
                        otherwise move on to the next step

                    */
                if (newInnerTree == nullptr)
                {
                    insertOutcome = false;
                    m_outerTree->Delete(firstKey);

                    if (outerTreeWasCreated)
                    {
                        delete m_outerTree;
                        m_outerTree = nullptr;
                    }
                }
                else
                {
                        /*
                            STEP 3.4
                            Map the outer key to the inner
                            tree. If the mapping is unsuccessful,
                            undo all the previous steps
                        */
                    try
                    {
                        m_keyTreeMap[firstKey] = newInnerTree;
                        innerTreeWasCreated = true;
                    }
                    catch(...)
                    {
                        insertOutcome = false;

                        delete newInnerTree;
                        newInnerTree = nullptr;

                        m_outerTree->Delete(firstKey);

                        if (outerTreeWasCreated)
                        {
                            delete m_outerTree;
                            m_outerTree = nullptr;
                        }


                    }//end of try...catch

                }//end of if (newInnerTree == nullptr)

            }//end of if (insertOutcome)

        }//end of if (!firstKeyExists)



            /*
                STEP 4:
                Now that the inner tree already exists,
                the secondKey will have to be inserted into
                the inner tree. If insertion is unsuccessful,
                due to the lack of memory , then undo
                all Steps 1 to 3
            */
        if (insertOutcome)
        {

            currentInnerTree = m_keyTreeMap[firstKey];

            insertOutcome =
                        currentInnerTree->Insert(secondKey);


            if (!insertOutcome)
            {

                if(innerTreeWasCreated)
                {
                    delete currentInnerTree;
                    currentInnerTree = nullptr;
                    m_keyTreeMap.erase(firstKey);
                }


                if (outerTreeWasCreated)
                {
                    m_outerTree->Clear();
                    delete m_outerTree;
                    m_outerTree = nullptr;
                }

            }//end of if (!insertOutcome)

        }//end of if (insertOutcome)

    }//end of if (insertOutcome)



        /*
            STEP 5:
            Return a boolean value on whether the insertion
            was successful.
            true - successful
            false - unsuccessful
        */
    return insertOutcome;
}


//-------------------------------------------------------------
template <typename FirstKeyType, typename SecondKeyType,
          typename FirstKeyTypeIsLessThanStruct>
bool TwoDimensionalBst <FirstKeyType,SecondKeyType,
        FirstKeyTypeIsLessThanStruct> ::

            Delete(const FirstKeyType& firstKey,
                   const SecondKeyType& secondKey)
{

    bool deleteOutcome;
    bool searchOutcome;

    InnerTree* currentInnerTree = nullptr;

    deleteOutcome = false;


        /*
            STEP 1:
            Check to see if the outer tree is empty.
            There is nothing to delete if the outer tree
            is empty
        */
    if (m_outerTree != nullptr)
    {

            /*
                STEP 2:
                Search to see if the firstKey-secondKey composite
                key exists within the TwoDimensionalBst instance

                There is nothing to delete if that particular
                composite key does not exist
            */

        searchOutcome = Search(firstKey, secondKey);


        if (!searchOutcome)
        {
            deleteOutcome = false;
        }
        else
        {
            /*
                STEP 3:
                (a)First delete the firstKey from the
                   inner tree

                (b)If after deletion that the inner tree
                   is empty, free the memory taken up
                   by that inner tree and remove its
                   mapping from the keyTreeMap

                (c) If the keyTreeMap happens to be
                    empty after that particular mapping
                    is removed, free up memory taken up
                    the outer tree
            */

            currentInnerTree =
                    m_keyTreeMap[firstKey];

            currentInnerTree->Delete(secondKey);


            deleteOutcome = true;

            if (currentInnerTree->IsEmpty())
            {
                delete currentInnerTree;
                currentInnerTree = nullptr;
                m_keyTreeMap.erase(firstKey);


                if (m_keyTreeMap.empty())
                {
                    delete m_outerTree;
                    m_outerTree = nullptr;
                }

            }//end of if (currentInnerTree->IsEmpty())

        } //end of if (!searchOutcome)

    }//end of if (m_outerTree != nullptr)


        /*
            STEP 4:
            Return a boolean value to indicate whether
            the deletion is successful
            true - successful
            false - not successful
        */
    return deleteOutcome;
}



#endif // TWO_DIMENSIONAL_BST_H
