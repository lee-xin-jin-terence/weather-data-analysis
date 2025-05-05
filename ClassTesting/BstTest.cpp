#include "BstTest.h"

void BstTest::RunTest()
{
        // Test constructor and  .IsEmpty()
    Test1();


        // Test .Insert() and .IsEmpty()
    Test2();


        // Test .Insert() for inserting the same number
        // into the binary search tree twice
        // (invalid second insertion)
    Test3();


        // Test .Insert() for inserting two different
        // numbers into the binary search tree
        // (valid insertions)
    Test4();


        // Test .Delete() for a number that exists
        // in the binary search tree
    Test5();


        // Test .Delete() from an empty binary
        // search tree
    Test6();


        // Test .Delete() for a number that does not
        // exist in a non-empty binary search
        // tree
    Test7();


        // Test .Search() for an existing number
        // within the binary search tree
    Test8();


        // Test .Search() for an empty binary search
        // tree
    Test9();


        // Test .Search() for a number that does not
        // exist in a non-empty binary search tree
    Test10();


        // Test .Clear()
    Test11();


        // Test various traversal methods for insertion
        // of numbers in ascending order
    Test12();


        // Test various traversal methods for insertion
        // of numbers in descending order
    Test13();


        // Test various traversal methods for insertion
        // of numbers in random order
    Test14();


        // Test time taken to insert and search from
        // 20,000 integers(numbers)
    Test15();
}


//----------------------------------------------------------
bool BstTest::IsLessThan(const int& firstNum,
                         const int& secondNum)
{
    if (firstNum < secondNum)
    {
        return true;
    }
    else
    {
        return false;
    }
}


//----------------------------------------------------------
bool BstTest::IsEqualTo(const int& firstNum,
                        const int& secondNum)
{
    if (firstNum == secondNum)
    {
        return true;
    }
    else
    {
        return false;
    }
}


//-----------------------------------------------------------
bool BstTest::IsMoreThan(const int& firstNum,
                         const int& secondNum)
{

    if (firstNum > secondNum)
    {
        return true;
    }
    else
    {
        return false;
    }
}


//----------------------------------------------------------
void BstTest::PrintNum(const int& num)
{
    cout << num << " , ";
}


//----------------------------------------------------------
void BstTest::Test1()
{

    Bst<int> intTree(IsLessThan,
                     IsEqualTo,
                     IsMoreThan);

    bool isEmpty = intTree.IsEmpty();


    cout << "Bst Template Class Test 1 : Test Constructor "
         << " and IsEmpty() "
         << '\n';

    cout << setfill('#') << setw(60) << "" << '\n';

    cout << "After creating a Bst instance " << '\n';

    cout << setfill('-') << setw(35) << "" << '\n';

    cout << "the return value of .IsEmpty() is : "
         << boolalpha << isEmpty << '\n';

    cout << "\n\n\n\n\n";
}


//-----------------------------------------------------------
void BstTest::Test2()
{

    Bst<int> intTree(IsLessThan,
                     IsEqualTo,
                     IsMoreThan);

    bool isEmpty;
    bool insertOutcome;

        //------------------------------------------------

    isEmpty = intTree.IsEmpty();


    cout << "Bst Template Class Test 2 : Test Insert() "
         << " and IsEmpty() "
         << '\n';

    cout << setfill('#') << setw(60) << "" << '\n';

    cout << "After creating a Bst instance " << '\n';

    cout << setfill('-') << setw(35) << "" << '\n';

    cout << "the return value of .IsEmpty() is : "
         << boolalpha << isEmpty
         << "\n\n\n";

         //----------------------------------------------

    insertOutcome = intTree.Insert(56);
    isEmpty = intTree.IsEmpty();

    cout << "After inserting \'56\' into the binary "
         << "search tree " << '\n' << "using the "
         << "method .Insert()" << '\n';

    cout << setfill('-') << setw(35) << "" << '\n';

    cout << "the return value of .IsEmpty() is : "
         << boolalpha << isEmpty
         << "\n\n";

    cout << "the return value of .Insert(56) is : "
         << boolalpha << insertOutcome
         << "\n\n\n\n\n";
}


//----------------------------------------------------------
void BstTest::Test3()
{

    Bst<int> intTree(IsLessThan,
                     IsEqualTo,
                     IsMoreThan);

    bool insertOutcome;

    bool isEmpty;


        //---------------------------------------------------

    cout << "Bst Template Class Test 3 : Test calling Insert() "
         << "for inserting the " << '\n'
         << "same number into the binary search tree twice "
         << "(invalid second insertion)" << '\n';

    cout << setfill('#') << setw(60) << "" << '\n';

    cout << "After creating a Bst instance " << '\n';

    cout << setfill('-') << setw(35) << "" << '\n';

    cout << "the return value of .IsEmpty() is : "
         << boolalpha << intTree.IsEmpty()
         << "\n\n\n";

        //------------------------------------------------


    insertOutcome = intTree.Insert(56);
    isEmpty = intTree.IsEmpty();


    cout << "After inserting \'56\' into the binary "
         << "search tree " << '\n' << "using the "
         << "method .Insert()" << '\n';

    cout << setfill('-') << setw(35) << "" << '\n';

    cout << "the return value of .IsEmpty() is : "
         << boolalpha << isEmpty
         << '\n';

    cout << "the return value of .Insert(56) is : "
         << boolalpha << insertOutcome
         << "\n\n\n";

        //------------------------------------------------


    insertOutcome = intTree.Insert(56);
    isEmpty = intTree.IsEmpty();


    cout << "Now, trying to insert \'56\' into the binary "
         << "search tree " << '\n' << "again "
         << '\n';

    cout << setfill('-') << setw(35) << "" << '\n';

    cout << "the return value of .IsEmpty() is : "
         << boolalpha << isEmpty
         << '\n';

    cout << "the return value of .Insert(56) is : "
         << boolalpha << insertOutcome
         << "\n\n\n\n\n";

}


//----------------------------------------------------------
void BstTest::Test4()
{

    Bst<int> intTree(IsLessThan,
                     IsEqualTo,
                     IsMoreThan);

    bool insertOutcome;

    bool isEmpty;


        //---------------------------------------------------

    cout << "Bst Template Class Test 4 : Test calling Insert() "
         << "for inserting two different " << '\n'
         << "numbers into the binary search tree (valid "
         << "insertions) " << '\n';

    cout << setfill('#') << setw(60) << "" << '\n';

    cout << "After creating a Bst instance " << '\n';

    cout << setfill('-') << setw(35) << "" << '\n';

    cout << "the return value of .IsEmpty() is : "
         << boolalpha << intTree.IsEmpty()
         << "\n\n\n";

        //------------------------------------------------


    insertOutcome = intTree.Insert(56);
    isEmpty = intTree.IsEmpty();


    cout << "After inserting \'56\' into the binary "
         << "tree instance " << '\n' << "using the "
         << "method .Insert()" << '\n';

    cout << setfill('-') << setw(35) << "" << '\n';

    cout << "the return value of .IsEmpty() is : "
         << boolalpha << isEmpty
         << '\n';

    cout << "the return value of .Insert(56) is : "
         << boolalpha << insertOutcome
         << "\n\n\n";

        //------------------------------------------------


    insertOutcome = intTree.Insert(28);
    isEmpty = intTree.IsEmpty();


     cout << "After inserting \'28\' into the binary "
         << "search tree " << '\n' << "using the "
         << "method .Insert()" << '\n';

    cout << setfill('-') << setw(35) << "" << '\n';

    cout << "the return value of .IsEmpty() is : "
         << boolalpha << isEmpty
         << '\n';

    cout << "the return value of .Insert(28) is : "
         << boolalpha << insertOutcome
         << "\n\n\n\n\n";

}


//----------------------------------------------------------
void BstTest::Test5()
{


    Bst<int> intTree(IsLessThan,
                     IsEqualTo,
                     IsMoreThan);

    bool insertOutcome;
    bool deleteOutcome;

    bool isEmpty;

        //--------------------------------------------------

    isEmpty = intTree.IsEmpty();


    cout << "Bst Template Class Test 5 : Test Delete() "
         << " for a number that exists "
         << '\n' << "in the binary search tree" << '\n';


    cout << setfill('#') << setw(60) << "" << '\n';

    cout << "After creating a Bst instance " << '\n';

    cout << setfill('-') << setw(35) << "" << '\n';

    cout << "the return value of .IsEmpty() is : "
         << boolalpha << isEmpty
         << "\n\n\n";

        //------------------------------------------------


    insertOutcome = intTree.Insert(56);
    isEmpty = intTree.IsEmpty();



    cout << "After inserting \'56\' into the binary "
         << "search tree " << '\n' << "using the "
         << "method .Insert()" << '\n';

    cout << setfill('-') << setw(35) << "" << '\n';

    cout << "the return value of .IsEmpty() :"
         << boolalpha << isEmpty << '\n';

    cout << "the return value of .Insert(56) is : "
         << boolalpha << insertOutcome
         << "\n\n\n";

        //--------------------------------------------------

    deleteOutcome = intTree.Delete(56);
    isEmpty = intTree.IsEmpty();



    cout << "After deleting \'56\' from the binary search tree"
         << '\n' << "using the method .Delete()" << '\n';

    cout << setfill('-') << setw(35) << "" << '\n';

    cout << "the return value of .IsEmpty() :"
         << boolalpha << isEmpty << '\n';

    cout << "the return value of .Delete(56) is : "
         << boolalpha << deleteOutcome
         << "\n\n\n\n\n";
}


//-----------------------------------------------------------
void BstTest::Test6()
{

    Bst<int> intTree(IsLessThan,
                     IsEqualTo,
                     IsMoreThan);

    bool deleteOutcome;

    bool isEmpty;

        //-------------------------------------------------

    isEmpty = intTree.IsEmpty();

    cout << "Bst Template Class Test 6 : Test Delete() "
         << " from an empty binary search tree "
         << '\n';

    cout << setfill('#') << setw(60) << "" << '\n';

    cout << "After creating a Bst instance " << '\n';

    cout << setfill('-') << setw(35) << "" << '\n';

    cout << "the return value of .IsEmpty() is : "
         << boolalpha << isEmpty
         << "\n\n\n";

        //------------------------------------------------

    deleteOutcome = intTree.Delete(56);
    isEmpty = intTree.IsEmpty();



    cout << "After deleting \'56\' from the empty binary search "
         << '\n' << "tree using the method .Delete()" << '\n';

    cout << setfill('-') << setw(35) << "" << '\n';

    cout << "the return value of .IsEmpty() after "
         << "deleting \'56\' :"
         << boolalpha << isEmpty << '\n';

    cout << "the return value of .Delete(56) is : "
         << boolalpha << deleteOutcome
         << "\n\n\n\n\n";
}


//-----------------------------------------------------------
void BstTest::Test7()
{

    Bst<int> intTree(IsLessThan,
                     IsEqualTo,
                     IsMoreThan);

    bool insertOutcome;
    bool deleteOutcome;

    bool isEmpty;

        //--------------------------------------------------

    isEmpty = intTree.IsEmpty();


    cout << "Bst Template Class Test 7 : Test Delete() "
         << "for an number that does not exist"
         << '\n' << "in a non-empty binary search tree"
         << '\n';


    cout << setfill('#') << setw(60) << "" << '\n';

    cout << "After creating a Bst instance " << '\n';

    cout << setfill('-') << setw(35) << "" << '\n';

    cout << "the return value of .IsEmpty() is : "
         << boolalpha << isEmpty
         << "\n\n\n";

        //------------------------------------------------


    insertOutcome = intTree.Insert(56);
    isEmpty = intTree.IsEmpty();



    cout << "After inserting \'56\' into the binary "
         << "search tree " << '\n' << "using the "
         << "method .Insert()" << '\n';

    cout << setfill('-') << setw(35) << "" << '\n';

    cout << "the return value of .IsEmpty() :"
         << boolalpha << isEmpty << '\n';

    cout << "the return value of .Insert(56) is : "
         << boolalpha << insertOutcome
         << "\n\n\n";

        //--------------------------------------------------

    deleteOutcome = intTree.Delete(28);
    isEmpty = intTree.IsEmpty();



    cout << "After deleting \'28\' from the binary search tree"
         << '\n' << "using the method .Delete()" << '\n';

    cout << setfill('-') << setw(35) << "" << '\n';

    cout << "the return value of .IsEmpty() :"
         << boolalpha << isEmpty << '\n';

    cout << "the return value of .Delete(28) is : "
         << boolalpha << deleteOutcome
         << "\n\n\n\n\n";
}


//----------------------------------------------------------
void BstTest::Test8()
{

    Bst<int> intTree(IsLessThan,
                     IsEqualTo,
                     IsMoreThan);

    bool insertOutcome;
    bool searchOutcome;

    bool isEmpty;


         //--------------------------------------------------

    isEmpty = intTree.IsEmpty();

    cout << "Bst Template Class Test 8 : Test calling Search() "
         << " to search" << '\n'
         << " from an existing number within "
         << "the binary search tree"
         << '\n';


    cout << setfill('#') << setw(60) << "" << '\n';

    cout << "After creating a Bst instance " << '\n';

    cout << setfill('-') << setw(35) << "" << '\n';

    cout << "the return value of .IsEmpty() is : "
         << boolalpha << isEmpty
         << "\n\n\n";

        //-----------------------------------------------

    insertOutcome = intTree.Insert(56);
    isEmpty = intTree.IsEmpty();


    cout << "After inserting hour as \'56\' into the binary "
         << "search tree " << '\n' << "using the "
         << "method .Insert()" << '\n';

    cout << setfill('-') << setw(35) << "" << '\n';

    cout << "the return value of .IsEmpty() is : "
         << boolalpha << isEmpty
         << '\n';

    cout << "the return value of .Insert(56) is : "
         << boolalpha << insertOutcome
         << "\n\n\n";

        //-------------------------------------------------

    searchOutcome = intTree.Search(56);
    isEmpty = intTree.IsEmpty();

    cout << "After searching \'56\' from the  "
         << "binary tree " << '\n' << "instance "
         << '\n';

    cout << setfill('-') << setw(35) << "" << '\n';

    cout << "the return value of .IsEmpty() is : "
         << boolalpha << isEmpty
         << '\n';

    cout << "the return value of .Search(56) is : "
         << boolalpha << searchOutcome
         << "\n\n\n\n\n";
}


//---------------------------------------------------------
void BstTest::Test9()
{

    Bst<int> intTree(IsLessThan,
                     IsEqualTo,
                     IsMoreThan);

    bool searchOutcome;

    bool isEmpty;

        //--------------------------------------------------

    isEmpty = intTree.IsEmpty();

    cout << "Bst Template Class Test 9 : Test calling Search() "
         << " to search" << '\n'
         << " from an empty binary search tree"
         << '\n';


    cout << setfill('#') << setw(60) << "" << '\n';

    cout << "After creating a Bst instance " << '\n';

    cout << setfill('-') << setw(35) << "" << '\n';

    cout << "the return value of .IsEmpty() is : "
         << boolalpha << isEmpty
         << "\n\n\n";

        //-----------------------------------------------

    searchOutcome = intTree.Search(56);
    isEmpty = intTree.IsEmpty();

    cout << "Now, trying to search \'56\' from the empty "
         << "binary search " << '\n' << "tree"
         << '\n';

    cout << setfill('-') << setw(35) << "" << '\n';

    cout << "the return value of .IsEmpty() is : "
         << boolalpha << isEmpty
         << '\n';

    cout << "the return value of .Search(56) is : "
         << boolalpha << searchOutcome
         << "\n\n\n\n\n";

}


//---------------------------------------------------------
void BstTest::Test10()
{

    Bst<int> intTree(IsLessThan,
                     IsEqualTo,
                     IsMoreThan);

    bool insertOutcome;
    bool searchOutcome;

    bool isEmpty;


         //--------------------------------------------------

    isEmpty = intTree.IsEmpty();

    cout << "Bst Template Class Test 10 : Test calling Search() "
         << "for an number that does not exist"
         << '\n' << "in a non-empty binary search tree"
         << '\n';


    cout << setfill('#') << setw(60) << "" << '\n';

    cout << "After creating a Bst instance " << '\n';

    cout << setfill('-') << setw(35) << "" << '\n';

    cout << "the return value of .IsEmpty() is : "
         << boolalpha << isEmpty
         << "\n\n\n";

        //-----------------------------------------------

    insertOutcome = intTree.Insert(56);
    isEmpty = intTree.IsEmpty();


    cout << "After inserting \'56\' into the binary "
         << "search tree " << '\n' << "using the "
         << "method .Insert()" << '\n';

    cout << setfill('-') << setw(35) << "" << '\n';

    cout << "the return value of .IsEmpty() is : "
         << boolalpha << isEmpty
         << '\n';

    cout << "the return value of .Insert(56) is : "
         << boolalpha << insertOutcome
         << "\n\n\n";

        //-------------------------------------------------

    searchOutcome = intTree.Search(29);
    isEmpty = intTree.IsEmpty();

    cout << "After searching \'29\' from the  "
         << "binary tree " << '\n' << "instance "
         << '\n';

    cout << setfill('-') << setw(35) << "" << '\n';

    cout << "the return value of .IsEmpty() is : "
         << boolalpha << isEmpty
         << '\n';

    cout << "the return value of .Search(29) is : "
         << boolalpha << searchOutcome
         << "\n\n\n\n\n";
}


//----------------------------------------------------------
void BstTest::Test11()
{

    Bst<int> intTree(IsLessThan,
                     IsEqualTo,
                     IsMoreThan);

    bool insertOutcome;
    bool isEmpty;


         //--------------------------------------------------

    isEmpty = intTree.IsEmpty();

    cout << "Bst Template Class Test 11 : Testing .Clear()"
         << '\n';


    cout << setfill('#') << setw(60) << "" << '\n';

    cout << "After creating a Bst instance " << '\n';

    cout << setfill('-') << setw(35) << "" << '\n';

    cout << "the return value of .IsEmpty() is : "
         << boolalpha << isEmpty
         << "\n\n\n";

        //-----------------------------------------------

    insertOutcome = intTree.Insert(56);
    isEmpty = intTree.IsEmpty();


    cout << "After inserting hour as \'56\' into the binary "
         << "search tree " << '\n' << "using the "
         << "method .Insert()" << '\n';

    cout << setfill('-') << setw(35) << "" << '\n';

    cout << "the return value of .IsEmpty() is : "
         << boolalpha << isEmpty
         << '\n';

    cout << "the return value of .Insert(56) is : "
         << boolalpha << insertOutcome
         << "\n\n\n";

        //-------------------------------------------------

    insertOutcome = intTree.Insert(28);
    isEmpty = intTree.IsEmpty();


    cout << "After inserting  \'28\' into the binary "
         << "search tree " << '\n' << "using the "
         << "method .Insert()" << '\n';

    cout << setfill('-') << setw(35) << "" << '\n';

    cout << "the return value of .IsEmpty() is : "
         << boolalpha << isEmpty
         << '\n';

    cout << "the return value of .Insert(28) is : "
         << boolalpha << insertOutcome
         << "\n\n\n";

        //-----------------------------------------------

    insertOutcome = intTree.Insert(11);
    isEmpty = intTree.IsEmpty();


    cout << "After inserting \'11\' into the binary "
         << "search tree " << '\n' << "using the "
         << "method .Insert()" << '\n';

    cout << setfill('-') << setw(35) << "" << '\n';

    cout << "the return value of .IsEmpty() is : "
         << boolalpha << isEmpty
         << '\n';

    cout << "the return value of .Insert(11) is : "
         << boolalpha << insertOutcome
         << "\n\n\n";

        //--------------------------------------------

    intTree.Clear();
    isEmpty = intTree.IsEmpty();

    cout << "After calling the method .Clear() " << '\n';

    cout << setfill('-') << setw(35) << "" << '\n';

    cout << "the return value of .IsEmpty() is : "
         << boolalpha << isEmpty
         << "\n\n\n\n\n";
}


//---------------------------------------------------------
void BstTest::Test12()
{

    Bst<int> intTree(IsLessThan,
                     IsEqualTo,
                     IsMoreThan);

    bool isEmpty;


         //--------------------------------------------------

    isEmpty = intTree.IsEmpty();

    cout << "Bst Template Class Test 12 : Testing various "
         << "traversals with "
         << '\n' << "insertions in ascending order "
         << '\n';


    cout << setfill('#') << setw(60) << "" << '\n';

    cout << "After creating a Bst instance " << '\n';

    cout << setfill('-') << setw(35) << "" << '\n';

    cout << "the return value of .IsEmpty() is : "
         << boolalpha << isEmpty
         << "\n\n\n";

        //---------------------------------------------

    for (int num = 1; num <= 15 ; num++)
    {
        intTree.Insert(num);
    }

    cout << "After inserting numbers \'1\' to \'15\' "
         << "in ascending order : " << '\n';

    cout << setfill('-') << setw(35) << "" << '\n';

        //-----------------------------------------------

    cout << "In-order traversal : " << '\n';

    intTree.InOrderTraversal(PrintNum);

    cout << "\n\n\n";

        //---------------------------------------------

    cout << "Pre-order traversal : " << '\n';

    intTree.PreOrderTraversal(PrintNum);

    cout << "\n\n\n";

        //-------------------------------------------------

    cout << "Post-order traversal : " << '\n';

    intTree.PostOrderTraversal(PrintNum);

    cout << "\n\n\n\n\n";
}


//---------------------------------------------------------
void BstTest::Test13()
{

    Bst<int> intTree(IsLessThan,
                     IsEqualTo,
                     IsMoreThan);

    bool isEmpty;


         //--------------------------------------------------

    isEmpty = intTree.IsEmpty();

    cout << "Bst Template Class Test 13 : Testing various "
         << "traversals with " << '\n'
         << "insertions in descending order "
         << '\n';


    cout << setfill('#') << setw(60) << "" << '\n';

    cout << "After creating a Bst instance " << '\n';

    cout << setfill('-') << setw(35) << "" << '\n';

    cout << "the return value of .IsEmpty() is : "
         << boolalpha << isEmpty
         << "\n\n\n";

        //---------------------------------------------

    for (int num = 15; num >= 1 ; num--)
    {
        intTree.Insert(num);
    }

    cout << "After inserting numbers \'15\' to \'1\' "
         << "in descending order : " << '\n';

    cout << setfill('-') << setw(35) << "" << '\n';

        //-----------------------------------------------

    cout << "In-order traversal : " << '\n';

    intTree.InOrderTraversal(PrintNum);

    cout << "\n\n\n";

        //---------------------------------------------

    cout << "Pre-order traversal : " << '\n';

    intTree.PreOrderTraversal(PrintNum);

    cout << "\n\n\n";

        //-------------------------------------------------

    cout << "Post-order traversal : " << '\n';

    intTree.PostOrderTraversal(PrintNum);

    cout << "\n\n\n\n\n";
}


//---------------------------------------------------------
void BstTest::Test14()
{

    int numArr[15] = {7 , 15, 12, 3, 1,
                      13, 10,  4, 6, 9,
                      2 ,  5,  8, 11,14};


    Bst<int> intTree(IsLessThan,
                     IsEqualTo,
                     IsMoreThan);

    bool isEmpty;


         //--------------------------------------------------

    isEmpty = intTree.IsEmpty();

    cout << "Bst Template Class Test 14 : Testing various "
         << "traversals with " << '\n'
         << "insertions in random order "
         << '\n';


    cout << setfill('#') << setw(60) << "" << '\n';

    cout << "After creating a Bst instance " << '\n';

    cout << setfill('-') << setw(35) << "" << '\n';

    cout << "the return value of .IsEmpty() is : "
         << boolalpha << isEmpty
         << "\n\n\n";

        //---------------------------------------------

    for (int index = 0; index < 15 ; index++)
    {
        intTree.Insert(numArr[index]);
    }

    cout << "After inserting numbers \'1\' to \'15\' "
         << "in random order : " << '\n';

    cout << setfill('-') << setw(35) << "" << '\n';

        //-----------------------------------------------

    cout << "In-order traversal : " << '\n';

    intTree.InOrderTraversal(PrintNum);

    cout << "\n\n\n";

        //---------------------------------------------

    cout << "Pre-order traversal : " << '\n';

    intTree.PreOrderTraversal(PrintNum);

    cout << "\n\n\n";

        //-------------------------------------------------

    cout << "Post-order traversal : " << '\n';

    intTree.PostOrderTraversal(PrintNum);

    cout << "\n\n\n\n\n";

}


//---------------------------------------------------------
void BstTest::Test15()
{

    Bst<int> intTree(IsLessThan,
                     IsEqualTo,
                     IsMoreThan);

    time_t startTime;
    time_t endTime;
    time_t timeTaken;

         //--------------------------------------------------

    cout << "Bst Template Class Test 15 : Testing insertion "
         << "of and search " << '\n'
         << "from 20,000 integers "
         << '\n';


    cout << setfill('#') << setw(60) << "" << '\n';

    cout << "Please be patient while the insertion of "
         << "20,000 integers " << '\n'
         << "takes place "
         << "\n\n";

        //------------------------------------------------

    startTime = time(nullptr);

    for (int num = 1; num <= 20000; num++)
    {

        intTree.Insert(num);

    }

    endTime = time(nullptr);

    timeTaken = endTime - startTime;

    cout << "Time taken to insert 20,000 integers "
         << "is " << timeTaken << " seconds "
         << '\n';

        //----------------------------------------------------

    cout << "Time taken to search for the last inserted integer"
         << " is ";

    startTime = time(nullptr);

    intTree.Search(20000);

    endTime = time(nullptr);

    timeTaken =  endTime - startTime;

    cout <<  timeTaken << " seconds";

    cout << "\n\n\n\n\n";

}
