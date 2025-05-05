
#include "VectorTest.h"


void VectorTest::RunTest()
{
        //Testing Constructor , .GetCurrentSize()
        //and .GetCapacitySize()
    Test1();

        //Testing .EnsureCapacity() with valid number as parameter
    Test2();

        //Testing .EnsureCapacity() with invalid number (negative
        // number) as parameter
    Test3();

        //Testing .Append() for vector instance
        //with zero capacity
    Test4();

        //Testing .Append() for full capacity vector instance
    Test5();

        //Testing .Append() & .Get()
    Test6();

        //Testing .Get() with invalid non-negative index
        //parameter value
    Test7();

        //Testing .Get() with negative parameter value
    Test8();

        //Testing .Insert() for value insertion
    Test9();

        //Testing .Insert(),
        //attempting to use it to append (Invalid usage)
    Test10();

        //Testing .Insert()
        //with negative parameter value (invalid usage)
    Test11();

        //Testing .Set() with valid parameter index value
    Test12();

        //Testing .Set(), attempting to use it to append
        // (invalid usage)
    Test13();

        //Testing .Set() with negative
        //index parameter value (invalid usage)
    Test14();

        //Testing .TrimToCurrentSize() for valid parameter
        // value on unfilled vector with some capacity
    Test15();

        //Testing .TrimToCurrentSize() for partially filled
        //vector
    Test16();

        //Testing .TrimToCurrentSize()
        //for a vector instance with 0 capacity
    Test17();

        //Testing .Remove() to remove elements from the
        //  front of a vector instance
    Test18();

        //Testing .Remove() to remove elements
        //from the back of a vector instance
    Test19();

        //Testing .Remove() where index is a negative
        // number (invalid usage)
    Test20();

        //Testing .Remove() where the index is greater than or
        // equal to the current size of the vector instance
    Test21();


        //Testing the Clear() method to clear the entire vector
    Test22();

};



//------------------------------------------------------------
//Testing Constructor , .GetCurrentSize()
//and .GetCapacitySize()
void VectorTest::Test1()
{
    Vector<int> vectorObj;

    cout << "Vector Test 1: Testing Constructor, GetCurrentSize()"
         << " and GetCapacitySize()" << '\n';
    cout << setfill('#') << setw(75) << "" << '\n';

    cout << "After creating a Vector instance of type integer,"
         << '\n';

    cout << setfill('-') << setw(50) << "" <<'\n';

    cout << "the current size of vectorObj obtained using "
         << ".GetCurrentSize() : "
         << vectorObj.GetCurrentSize() << '\n';
    cout << "the capacity size of vectorObj obtained using "
         << ".GetCapacitySize() : "
         << vectorObj.GetCapacitySize() << "\n\n\n\n\n";
}


//--------------------------------------------------------------
//Testing .EnsureCapacity() with valid number as parameter
void VectorTest::Test2()
{
    Vector<int> vectorObj;
    bool ensureCapacityOutcome;

    cout << "Vector Test 2: Testing .EnsureCapacity() with valid "
         << "number as parameter" << '\n';

    cout << setfill('#') << setw(75) << "" << '\n';

    cout << "After creating a Vector instance of type integer,"
         << '\n';

    cout << setfill('-') << setw(50) << "" <<'\n';

    cout << "the current size of vectorObj obtained using "
         << ".GetCurrentSize() : "
         << vectorObj.GetCurrentSize() << '\n';

    cout << "the capacity size of vectorObj obtained using "
         << ".GetCapacitySize() : "
         << vectorObj.GetCapacitySize() << "\n\n\n";

        //-------------------------------------------

    ensureCapacityOutcome = vectorObj.EnsureCapacity(40);

    cout << "After calling .EnsureCapacity(40), " << '\n';

    cout << setfill('-') << setw(50) << "" <<'\n';

    cout << "The return value of .EnsureCapacity(40): "
         << boolalpha << ensureCapacityOutcome
         << "\n\n";

    cout << "the current size of vectorObj obtained using "
         << ".GetCurrentSize() : "
         << vectorObj.GetCurrentSize() << '\n';

    cout << "the capacity size of vectorObj obtained using "
         << ".GetCapacitySize() : "
         << vectorObj.GetCapacitySize() << "\n\n\n\n\n";

}


//------------------------------------------------------------
//Testing .EnsureCapacity() with invalid number (negative
// number) as parameter
void VectorTest::Test3()
{
    Vector<int> vectorObj;
    bool ensureCapacityOutcome;

    cout << "Vector Test 3: Testing .EnsureCapacity() with "
         << "invalid number(negative number) as parameter"
         << '\n';

    cout << setfill('#') << setw(75) << "" << '\n';

    cout << "After creating a Vector instance of type integer,"
         << '\n';

    cout << setfill('-') << setw(50) << "" <<'\n';

    cout << "the current size of vectorObj obtained using "
         << ".GetCurrentSize() : "
         << vectorObj.GetCurrentSize() << '\n';

    cout << "the capacity size of vectorObj obtained using "
         << ".GetCapacitySize() : "
         << vectorObj.GetCapacitySize() << "\n\n\n";

        //-------------------------------------------

    ensureCapacityOutcome = vectorObj.EnsureCapacity(-4);

    cout << "After calling .EnsureCapacity(-4), " << '\n';

    cout << setfill('-') << setw(50) << "" <<'\n';

    cout << "The return value of .EnsureCapacity(-4): "
         <<  ensureCapacityOutcome
         << "\n\n";

    cout << "the current size of vectorObj obtained using "
         << ".GetCurrentSize() : "
         << vectorObj.GetCurrentSize() << '\n';

    cout << "the capacity size of vectorObj obtained using "
         << ".GetCapacitySize() : "
         << vectorObj.GetCapacitySize() << "\n\n\n\n\n";

}


//------------------------------------------------------------
//Testing .Append() for vector instance
//with zero capacity
void VectorTest::Test4()
{
    Vector<int> vectorObj;
    bool appendOutcome;

    cout << "Vector Test 4: Testing .Append() for vector instance"
         << " with zero capacity" << '\n';
    cout << setfill('#') << setw(75) << "" << '\n';

    cout << "After creating a Vector instance of type integer,"
         << '\n';

    cout << setfill('-') << setw(50) << "" <<'\n';

    cout << "the current size of vectorObj obtained using "
         << ".GetCurrentSize() : "
         << vectorObj.GetCurrentSize() << '\n';

    cout << "the capacity size of vectorObj obtained using "
         << ".GetCapacitySize() : "
         << vectorObj.GetCapacitySize() << "\n\n\n";

         //----------------------------------------

    appendOutcome = vectorObj.Append(453);

    cout << "After calling .Append(453),"
         << '\n';

    cout << setfill('-') << setw(50) << "" <<'\n';

    cout << "the return value of .Append(453) : "
         << boolalpha << appendOutcome << "\n\n";

    cout << "the current size of vectorObj obtained using "
         << ".GetCurrentSize() : "
         << vectorObj.GetCurrentSize() << '\n';

    cout << "the capacity size of vectorObj obtained using "
         << ".GetCapacitySize() : "
         << vectorObj.GetCapacitySize() << "\n\n\n";

        //-----------------------------------------

    appendOutcome = vectorObj.Append(99);

    cout << "After calling .Append(99),"
         << '\n';

    cout << setfill('-') << setw(50) << "" <<'\n';

    cout << "the return value of .Append(99) : "
         << boolalpha << appendOutcome << "\n\n";

    cout << "the current size of vectorObj obtained using "
         << ".GetCurrentSize() : "
         << vectorObj.GetCurrentSize() << '\n';

    cout << "the capacity size of vectorObj obtained using "
         << ".GetCapacitySize() : "
         << vectorObj.GetCapacitySize() << "\n\n\n\n\n";


}


//-------------------------------------------------------------
//Testing .Append() for full capacity vector instance
void VectorTest::Test5()
{
    Vector<int> vectorObj;
    bool ensureCapacityOutcome;
    bool appendOutcome;

    cout << "Vector Test 5: Testing .Append() for full capacity "
         << "vector instance" << '\n';
    cout << setfill('#') << setw(75) << "" << '\n';

    cout << "After creating a Vector instance of type integer,"
         << '\n';

    cout << setfill('-') << setw(50) << "" <<'\n';

    cout << "the current size of vectorObj obtained using "
         << ".GetCurrentSize() : "
         << vectorObj.GetCurrentSize() << '\n';

    cout << "the capacity size of vectorObj obtained using "
         << ".GetCapacitySize() : "
         << vectorObj.GetCapacitySize() << "\n\n\n";


         //----------------------------------------

    ensureCapacityOutcome = vectorObj.EnsureCapacity(2);

    cout << "After calling .EnsureCapacity(2), " << '\n';

    cout << setfill('-') << setw(50) << "" <<'\n';

    cout << "return value of .EnsureCapacity(2): "
         << boolalpha << ensureCapacityOutcome
         << "\n\n";

    cout << "the current size of vectorObj obtained using "
         << ".GetCurrentSize() : "
         << vectorObj.GetCurrentSize() << '\n';

    cout << "the capacity size of vectorObj obtained using "
         << ".GetCapacitySize() : "
         << vectorObj.GetCapacitySize() << "\n\n\n";



         //----------------------------------------

    appendOutcome = vectorObj.Append(453);

    cout << "After calling .Append(453),"
         << '\n';

    cout << setfill('-') << setw(50) << "" <<'\n';

    cout << "return value of .Append(453) : "
         <<  appendOutcome << "\n\n";

    cout << "the current size of vectorObj obtained using "
         << ".GetCurrentSize() : "
         << vectorObj.GetCurrentSize() << '\n';

    cout << "the capacity size of vectorObj obtained using "
         << ".GetCapacitySize() : "
         << vectorObj.GetCapacitySize() << "\n\n\n";



        //-----------------------------------------

    appendOutcome = vectorObj.Append(99);

    cout << "After calling .Append(99),"
         << '\n';

    cout << setfill('-') << setw(50) << "" <<'\n';

    cout << "the return value of .Append(99) : "
         <<  appendOutcome << "\n\n";

    cout << "the current size of vectorObj obtained using "
         << ".GetCurrentSize() : "
         << vectorObj.GetCurrentSize() << '\n';

    cout << "the capacity size of vectorObj obtained using "
         << ".GetCapacitySize() : "
         << vectorObj.GetCapacitySize() << "\n\n\n";



        //-------------------------------------

    appendOutcome = vectorObj.Append(777);

    cout << "After calling .Append(777),"
         << '\n';

    cout << setfill('-') << setw(50) << "" <<'\n';

    cout << "the return value of .Append(777) : "
         << appendOutcome << "\n\n";

    cout << "the current size of vectorObj obtained using "
         << ".GetCurrentSize() : "
         << vectorObj.GetCurrentSize() << '\n';

    cout << "the capacity size of vectorObj obtained using "
         << ".GetCapacitySize() : "
         << vectorObj.GetCapacitySize() << "\n\n\n\n\n";


}


//--------------------------------------------------------------
//Testing .Append() & .Get()
void VectorTest::Test6()
{

    Vector<int> vectorObj;
    bool appendOutcome1;
    bool appendOutcome2;
    bool getOutcome1;
    bool getOutcome2;

    int numReceived1 = 0;
    int numReceived2 = 0;


    cout << "Vector Test 6: Testing .Append() & .Get() " << '\n';
    cout << setfill('#') << setw(75) << "" << '\n';

    cout << "After creating a Vector instance of type integer,"
         << '\n';

    cout << setfill('-') << setw(50) << "" <<'\n';

    cout << "the current size of vectorObj obtained using "
         << ".GetCurrentSize() : "
         << vectorObj.GetCurrentSize() << '\n';

    cout << "the capacity size of vectorObj obtained using "
         << ".GetCapacitySize() : "
         << vectorObj.GetCapacitySize() << "\n\n\n";


        //----------------------------------------

    appendOutcome1 = vectorObj.Append(221);
    appendOutcome2 = vectorObj.Append(423);

    cout << "After appending \'221\' , \'423\' : "
         << '\n';

    cout << setfill('-') << setw(50) << "" <<'\n';

    cout << "the return value of Append(221) : "
         << appendOutcome1 << '\n';

    cout << "the return value of Append(423) : "
         << appendOutcome2 << "\n\n";

    cout << "the current size of vectorObj obtained using "
         << ".GetCurrentSize() : "
         << vectorObj.GetCurrentSize() << '\n';

    cout << "the capacity size of vectorObj obtained using "
         << ".GetCapacitySize() : "
         << vectorObj.GetCapacitySize() << "\n\n\n";


         //--------------------------------------

    getOutcome1 = vectorObj.Get(0, numReceived1 );
    getOutcome2 = vectorObj.Get(1, numReceived2 );

    cout << "After calling .Get(0, numReceived1 )"
         << " and .Get(1, numReceived2 ) , "
         << '\n';

    cout << setfill('-') << setw(50) << "" <<'\n';

    cout << "return value of Get(0, numReceived1) "
         << " call: " << getOutcome1 << '\n';

    cout << "return value of Get(1, numReceived2) "
         << " call: " << getOutcome2 << "\n\n";

    cout << "the value of numReceived1 : "
         << numReceived1 << '\n';

    cout << "the value of numReceived2 : "
         << numReceived2 << "\n\n\n\n\n";
}


//-------------------------------------------------------------
//Testing .Get() with invalid non-negative index
//parameter value
void VectorTest::Test7()
{
    Vector<int> vectorObj;
    bool getOutcome = false;
    int numReceived = 0;

    cout << "Vector Test 7: Testing .Get() with invalid  "
         <<  "non-negative index parameter value "
         << '\n' << "greater that its current size"
         << '\n';

    cout << setfill('#') << setw(75) << "" << '\n';

    cout << "After creating a Vector instance of type integer,"
         << '\n';

    cout << setfill('-') << setw(50) << "" <<'\n';

    cout << "the current size of vectorObj obtained using "
         << ".GetCurrentSize() : "
         << vectorObj.GetCurrentSize() << '\n';

    cout << "the capacity size of vectorObj obtained using "
         << ".GetCapacitySize() : "
         << vectorObj.GetCapacitySize() << "\n\n\n";

        //-----------------------------------------------

    getOutcome = vectorObj.Get(7, numReceived);

    cout << "After calling .Get(7, numReceived),"
         << '\n';

    cout << setfill('-') << setw(50) << "" <<'\n';

    cout << "the return value of Get(7, numReceived) call : "
         << getOutcome << "\n\n\n\n\n";
}


//-------------------------------------------------------------
//Testing .Get() with negative parameter value
void VectorTest::Test8()
{
    Vector<int> vectorObj;
    bool getOutcome = false;
    int numReceived = 0;

    cout << "Vector Test 8: Testing .Get() with negative "
         << "parameter value" << '\n';

    cout << setfill('#') << setw(75) << "" << '\n';

        //------------------------------------------------

    cout << "After creating a Vector instance of type integer,"
         << '\n';

    cout << setfill('-') << setw(50) << "" <<'\n';

    cout << "the current size of vectorObj obtained using "
         << ".GetCurrentSize() : "
         << vectorObj.GetCurrentSize() << '\n';

    cout << "the capacity size of vectorObj obtained using "
         << ".GetCapacitySize() : "
         << vectorObj.GetCapacitySize() << "\n\n\n";

         //---------------------------------------

    getOutcome = vectorObj.Get(-1, numReceived);

    cout << "After calling .Get(-1, numReceived),"
         << '\n';

    cout << setfill('-') << setw(50) << "" <<'\n';

    cout << "the return value of Get( -1, numReceived) call : "
         << getOutcome << "\n\n\n\n\n";
}


//-------------------------------------------------------------
//Testing .Insert() for value insertion
void VectorTest::Test9()
{
    Vector<int> vectorObj;
    bool insertOutcome;

    int index0Val = 0;
    int index1Val =0;
    int index2Val = 0;
    int index3Val = 0;


    cout << "Vector Test 9: Testing .Insert() for value insertion"
         << '\n';

         //-----------------------------------------------

    cout << setfill('#') << setw(75) << "" << '\n';

    cout << "After creating a Vector instance of type integer,"
         << '\n';

    cout << setfill('-') << setw(50) << "" <<'\n';

    cout << "the current size of vectorObj obtained using "
         << ".GetCurrentSize() : "
         << vectorObj.GetCurrentSize() << '\n';

    cout << "the capacity size of vectorObj obtained using "
         << ".GetCapacitySize() : "
         << vectorObj.GetCapacitySize() << "\n\n\n";

         //-----------------------------------------

    vectorObj.Append(987);
    vectorObj.Append(555);
    vectorObj.Append(-343);

    vectorObj.Get(0, index0Val);
    vectorObj.Get(1, index1Val);
    vectorObj.Get(2, index2Val);


    cout << "After appending (in order): "
         << " \'987\' , \'555\' , \'-343\'  "
         << '\n';


    cout << setfill('-') << setw(50) << "" <<'\n';

    cout << "the current size of vectorObj obtained using "
         << ".GetCurrentSize() : "
         << vectorObj.GetCurrentSize() << '\n';

    cout << "the capacity size of vectorObj obtained using "
         << ".GetCapacitySize() : "
         << vectorObj.GetCapacitySize() << "\n\n";

    cout << "Value stored at index 0 : " << index0Val << '\n';
    cout << "Value stored at index 1 : " << index1Val << '\n';
    cout << "Value stored at index 2 : " << index2Val << '\n';

    cout << "\n\n";

        //---------------------------------------------

    insertOutcome = vectorObj.Insert(0,9090);

    vectorObj.Get(0, index0Val);
    vectorObj.Get(1, index1Val);
    vectorObj.Get(2, index2Val);
    vectorObj.Get(3, index3Val);

    cout << "After calling .Insert(0,9090)" << '\n';

    cout << setfill('-') << setw(50) << "" <<'\n';

    cout << "return value of .Insert(0, 9090) call : "
         << insertOutcome << "\n\n";

    cout << "the current size of vectorObj obtained using "
         << ".GetCurrentSize() : "
         << vectorObj.GetCurrentSize() << '\n';

    cout << "the capacity size of vectorObj obtained using "
         << ".GetCapacitySize() : "
         << vectorObj.GetCapacitySize() << "\n\n";

    cout << "Value stored at index 0 : " << index0Val << '\n';
    cout << "Value stored at index 1 : " << index1Val << '\n';
    cout << "Value stored at index 2 : " << index2Val << '\n';
    cout << "Value stored at index 3 : " << index3Val << '\n';

    cout << "\n\n\n";
}


//-------------------------------------------------------------
//Testing .Insert(),
//attempting to use it to append (Invalid usage)
void VectorTest::Test10()
{
    Vector<int> vectorObj;
    bool insertOutcome;


    cout << "Vector Test 10: Testing .Insert(),"
         << "attempting to use it to append (Invalid usage)"
         << '\n';

         //-----------------------------------------------

    cout << setfill('#') << setw(75) << "" << '\n';

    cout << "After creating a Vector instance of type integer,"
         << '\n';

    cout << setfill('-') << setw(50) << "" <<'\n';

    cout << "the current size of vectorObj obtained using "
         << ".GetCurrentSize() : "
         << vectorObj.GetCurrentSize() << '\n';

    cout << "the capacity size of vectorObj obtained using "
         << ".GetCapacitySize() : "
         << vectorObj.GetCapacitySize() << "\n\n\n";

        //-----------------------------------------

    insertOutcome = vectorObj.Insert(0, 77);

    cout << "After Calling .Insert(0, 77) : "
         <<  '\n';

    cout << setfill('-') << setw(50) << "" <<'\n';

    cout << "return value of .Insert(0, 77) call : "
         << insertOutcome << "\n\n";

    cout << "the current size of vectorObj obtained using "
         << ".GetCurrentSize() : "
         << vectorObj.GetCurrentSize() << '\n';

    cout << "the capacity size of vectorObj obtained using "
         << ".GetCapacitySize() : "
         << vectorObj.GetCapacitySize() << "\n\n";


    cout << "\n\n\n\n\n";
}


//-------------------------------------------------------------
//Testing .Insert()
//with negative parameter value (invalid usage)
void VectorTest::Test11()
{
    Vector<int> vectorObj;
    bool insertOutcome = false;

    cout << "Vector Test 11: Testing .Insert() "
            " with negative parameter value (invalid usage) "
            << '\n';

    cout << setfill('#') << setw(75) << "" << '\n';

        //------------------------------------------------

    cout << "After creating a Vector instance of type integer,"
         << '\n';

    cout << setfill('-') << setw(50) << "" <<'\n';

    cout << "the current size of vectorObj obtained using "
         << ".GetCurrentSize() : "
         << vectorObj.GetCurrentSize() << '\n';

    cout << "the capacity size of vectorObj obtained using "
         << ".GetCapacitySize() : "
         << vectorObj.GetCapacitySize() << "\n\n\n";

         //----------------------------------------------

    insertOutcome = vectorObj.Insert(-1 , 47 );

    cout << "After calling .Insert(-1, 47),"
         << '\n';

    cout << setfill('-') << setw(50) << "" <<'\n';

    cout << "the return value of Insert(-1, 47) call : "
         << insertOutcome << "\n\n";

    cout << "the current size of vectorObj obtained using "
         << ".GetCurrentSize() : "
         << vectorObj.GetCurrentSize() << '\n';

    cout << "the capacity size of vectorObj obtained using "
         << ".GetCapacitySize() : "
         << vectorObj.GetCapacitySize() << "\n\n\n\n\n";



}


//--------------------------------------------------------------
//Testing .Set() with valid parameter index value
void VectorTest::Test12()
{
    Vector<int> vectorObj;
    bool appendOutcome;
    bool setOutcome;

    int numReceived = 0;


    cout << "Vector Test 12: Testing .Set() with valid parameter "
         << "index value " << '\n';

    cout << setfill('#') << setw(75) << "" << '\n';

    cout << "After creating a Vector instance of type integer,"
         << '\n';

    cout << setfill('-') << setw(50) << "" <<'\n';

    cout << "the current size of vectorObj obtained using "
         << ".GetCurrentSize() : "
         << vectorObj.GetCurrentSize() << '\n';

    cout << "the capacity size of vectorObj obtained using "
         << ".GetCapacitySize() : "
         << vectorObj.GetCapacitySize() << "\n\n\n";

         //------------------------------------------

    appendOutcome = vectorObj.Append(425);
    vectorObj.Get(0, numReceived );

    cout << "After calling .Append(425),"
         << '\n';

    cout << setfill('-') << setw(50) << "" <<'\n';

    cout << "the return value of .Append(425) : "
         <<  appendOutcome << "\n\n";

    cout << "the current size of vectorObj obtained using "
         << ".GetCurrentSize() : "
         << vectorObj.GetCurrentSize() << '\n';

    cout << "the capacity size of vectorObj obtained using "
         << ".GetCapacitySize() : "
         << vectorObj.GetCapacitySize() << "\n\n";

    cout << "the value stored at index 0 : " << numReceived
         << "\n\n\n";


         //----------------------------------------

    setOutcome = vectorObj.Set(0, -999 );
    vectorObj.Get(0, numReceived );


    cout << "After calling .Set(0, -999),"
         << '\n';

    cout << setfill('-') << setw(50) << "" <<'\n';

    cout << "the return value of Set(0, -999) call : "
         << setOutcome << "\n\n";

    cout << "the current size of vectorObj obtained using "
         << ".GetCurrentSize() : "
         << vectorObj.GetCurrentSize() << '\n';

    cout << "the capacity size of vectorObj obtained using "
         << ".GetCapacitySize() : "
         << vectorObj.GetCapacitySize() << "\n\n";

    cout << "value stored at index 0 : "<< numReceived
         << "\n\n\n\n\n";
}


//--------------------------------------------------------------
//Testing .Set(), attempting to use it to append
// (invalid usage)
void VectorTest::Test13()
{
    Vector<int> vectorObj;
    bool setOutcome;

    cout << "Vector Test 13: Testing .Set(), attempting to "
         << "use it to append (invalid usage)" << '\n';

    cout << setfill('#') << setw(75) << "" << '\n';

    cout << "After creating a Vector instance of type integer,"
         << '\n';

    cout << setfill('-') << setw(50) << "" <<'\n';

    cout << "the current size of vectorObj obtained using "
         << ".GetCurrentSize() : "
         << vectorObj.GetCurrentSize() << '\n';

    cout << "the capacity size of vectorObj obtained using "
         << ".GetCapacitySize() : "
         << vectorObj.GetCapacitySize() << "\n\n\n";

         //-------------------------------------------


    setOutcome = vectorObj.Set(0, 54 );

    cout << "After calling .Set(0, 54),"
         << '\n';

    cout << setfill('-') << setw(50) << "" <<'\n';

    cout << "the return value of Set(0, 54) call : "
         << setOutcome << "\n\n";

    cout << "the current size of vectorObj obtained using "
         << ".GetCurrentSize() : "
         << vectorObj.GetCurrentSize() << '\n';

    cout << "the capacity size of vectorObj obtained using "
         << ".GetCapacitySize() : "
         << vectorObj.GetCapacitySize() << "\n\n\n\n\n";

}


//--------------------------------------------------------------
//Testing .Set() with negative
//index parameter value (invalid usage)
void VectorTest::Test14()
{

    Vector<int> vectorObj;
    bool setOutcome;


    cout << "Vector Test 14: Testing .Set() with negative "
         << "index parameter value (invalid usage) "
         << '\n';

    cout << setfill('#') << setw(75) << "" << '\n';

    cout << "After creating a Vector instance of type integer,"
         << '\n';

    cout << setfill('-') << setw(50) << "" <<'\n';

    cout << "the current size of vectorObj obtained using "
         << ".GetCurrentSize() : "
         << vectorObj.GetCurrentSize() << '\n';

    cout << "the capacity size of vectorObj obtained using "
         << ".GetCapacitySize() : "
         << vectorObj.GetCapacitySize() << "\n\n\n";


         //----------------------------------------

    setOutcome = vectorObj.Set(-1 , 200 );

    cout << "After calling .Set(-1, 200),"
         << '\n';

    cout << setfill('-') << setw(50) << "" <<'\n';

    cout << "the return value of Set(-1, -200) call : "
         << setOutcome << "\n\n";

    cout << "the current size of vectorObj obtained using "
         << ".GetCurrentSize() : "
         << vectorObj.GetCurrentSize() << '\n';

    cout << "the capacity size of vectorObj obtained using "
         << ".GetCapacitySize() : "
         << vectorObj.GetCapacitySize() << "\n\n\n\n\n";

}


//--------------------------------------------------------------
//Testing .TrimToCurrentSize() for valid parameter
// value on unfilled vector with some capacity
void VectorTest::Test15()
{
    Vector<int> vectorObj;
    bool ensureCapacityOutcome;
    bool trimOutcome;


    cout << "Vector Test 15: Testing .TrimToCurrentSize() "
         << "for on unfilled vector with some capacity"
         <<'\n';

    cout << setfill('#') << setw(75) << "" << '\n';

        //----------------------------------------------

    cout << "After creating a Vector instance of type integer,"
         << '\n';

    cout << setfill('-') << setw(50) << "" <<'\n';

    cout << "the current size of vectorObj obtained using "
         << ".GetCurrentSize() : "
         << vectorObj.GetCurrentSize() << '\n';

    cout << "the capacity size of vectorObj obtained using "
         << ".GetCapacitySize() : "
         << vectorObj.GetCapacitySize() << "\n\n\n";


        //-----------------------------------------

    ensureCapacityOutcome = vectorObj.EnsureCapacity(40);

    cout << "After calling .EnsureCapacity(40), " << '\n';

    cout << setfill('-') << setw(50) << "" <<'\n';

    cout << "The return value of .EnsureCapacity(40): "
         << boolalpha << ensureCapacityOutcome
         << "\n\n";

    cout << "the current size of vectorObj obtained using "
         << ".GetCurrentSize() : "
         << vectorObj.GetCurrentSize() << '\n';

    cout << "the capacity size of vectorObj obtained using "
         << ".GetCapacitySize() : "
         << vectorObj.GetCapacitySize() << "\n\n\n";


         //---------------------------------------

    trimOutcome = vectorObj.TrimToCurrentSize();

    cout << "After calling .TrimToCurrentSize(), " << '\n';

    cout << setfill('-') << setw(50) << "" <<'\n';

    cout << "The return value of .TrimToCurrentSize(): "
         <<  trimOutcome  << "\n\n";

    cout << "the current size of vectorObj obtained using "
         << ".GetCurrentSize() : "
         << vectorObj.GetCurrentSize() << '\n';

    cout << "the capacity size of vectorObj obtained using "
         << ".GetCapacitySize() : "
         << vectorObj.GetCapacitySize() << "\n\n\n\n\n";


}


//-------------------------------------------------------------
//Testing .TrimToCurrentSize() for partially filled
//vector
void VectorTest::Test16()
{
    Vector<int> vectorObj;
    bool appendOutcome;
    bool trimOutcome;

    cout << "Vector Test 16: Testing .TrimToCurrentSize() for"
         << " partially filled vector instance" << '\n';

    cout << setfill('#') << setw(75) << "" << '\n';

        //----------------------------------------------

    cout << "After creating a Vector instance of type integer,"
         << '\n';

    cout << setfill('-') << setw(50) << "" <<'\n';

    cout << "the current size of vectorObj obtained using "
         << ".GetCurrentSize() : "
         << vectorObj.GetCurrentSize() << '\n';

    cout << "the capacity size of vectorObj obtained using "
         << ".GetCapacitySize() : "
         << vectorObj.GetCapacitySize() << "\n\n\n";


        //-----------------------------------------

    appendOutcome = vectorObj.Append(412);

    cout << "After calling .Append(412),"
         << '\n';

    cout << setfill('-') << setw(50) << "" <<'\n';

    cout << "the return value of .Append(412) : "
         <<  appendOutcome << "\n\n";

    cout << "the current size of vectorObj obtained using "
         << ".GetCurrentSize() : "
         << vectorObj.GetCurrentSize() << '\n';

    cout << "the capacity size of vectorObj obtained using "
         << ".GetCapacitySize() : "
         << vectorObj.GetCapacitySize() << "\n\n\n";



         //-----------------------------------------

    trimOutcome = vectorObj.TrimToCurrentSize();

    cout << "After calling .TrimToCurrentSize(), " << '\n';

    cout << setfill('-') << setw(50) << "" <<'\n';

    cout << "The return value of .TrimToCurrentSize(): "
         <<  trimOutcome  << "\n\n";

    cout << "the current size of vectorObj obtained using "
         << ".GetCurrentSize() : "
         << vectorObj.GetCurrentSize() << '\n';

    cout << "the capacity size of vectorObj obtained using "
         << ".GetCapacitySize() : "
         << vectorObj.GetCapacitySize() ;

    cout << "\n\n\n\n\n";
}


//-------------------------------------------------------------
//Testing .TrimToCurrentSize()
//for a vector instance with 0 capacity
void VectorTest::Test17()
{
    Vector<int> vectorObj;
    bool trimOutcome;


    cout << "Vector Test 17: Testing .TrimToCurrentSize() "
         << "for a vector instance with 0 capacity"
         << '\n';

    cout << setfill('#') << setw(75) << "" << '\n';

        //----------------------------------------------

    cout << "After creating a Vector instance of type integer,"
         << '\n';

    cout << setfill('-') << setw(50) << "" <<'\n';

    cout << "the current size of vectorObj obtained using "
         << ".GetCurrentSize() : "
         << vectorObj.GetCurrentSize() << '\n';

    cout << "the capacity size of vectorObj obtained using "
         << ".GetCapacitySize() : "
         << vectorObj.GetCapacitySize() << "\n\n\n";


        //-------------------------------------------

    trimOutcome = vectorObj.TrimToCurrentSize();

    cout << "After calling .TrimToCurrentSize(), " << '\n';

    cout << setfill('-') << setw(50) << "" <<'\n';

    cout << "The return value of .TrimToCurrentSize(): "
         <<  trimOutcome  << "\n\n";

    cout << "the current size of vectorObj obtained using "
         << ".GetCurrentSize() : "
         << vectorObj.GetCurrentSize() << '\n';

    cout << "the capacity size of vectorObj obtained using "
         << ".GetCapacitySize() : "
         << vectorObj.GetCapacitySize() << "\n\n\n\n\n";
}


//------------------------------------------------------------
//Testing .Remove() to remove elements from the
//  front of a vector instance
void VectorTest::Test18()
{
    Vector<int> vectorObj;
    bool removeOutcome;
    int index0Val = 0;
    int index1Val = 0;
    int index2Val = 0;
    int index3Val = 0;


    cout << "Vector Test 18: Testing .Remove() "
         << "to remove elements from the front of "
         << "a vector instance" << '\n';

    cout << setfill('#') << setw(75) << "" << '\n';

        //----------------------------------------------


    cout << "After creating a Vector instance of type integer,"
         << '\n';

    cout << setfill('-') << setw(50) << "" <<'\n';

    cout << "the current size of vectorObj obtained using "
         << ".GetCurrentSize() : "
         << vectorObj.GetCurrentSize() << '\n';

    cout << "the capacity size of vectorObj obtained using "
         << ".GetCapacitySize() : "
         << vectorObj.GetCapacitySize() << "\n\n\n";

         //-------------------------------------------

    vectorObj.Append(987);
    vectorObj.Append(555);
    vectorObj.Append(-343);
    vectorObj.Append(717);

    vectorObj.Get(0, index0Val);
    vectorObj.Get(1, index1Val);
    vectorObj.Get(2, index2Val);
    vectorObj.Get(3, index3Val);

    cout << "After appending (in order): "
         << " \'987\' , \'555\' , \'-343\' , \'717\' "
         << '\n';

    cout << setfill('-') << setw(50) << "" <<'\n';

    cout << "the current size of vectorObj obtained using "
         << ".GetCurrentSize() : "
         << vectorObj.GetCurrentSize() << '\n';

    cout << "the capacity size of vectorObj obtained using "
         << ".GetCapacitySize() : "
         << vectorObj.GetCapacitySize() << "\n\n";

    cout << "Value stored at index 0 : " << index0Val << '\n';
    cout << "Value stored at index 1 : " << index1Val << '\n';
    cout << "Value stored at index 2 : " << index2Val << '\n';
    cout << "Value stored at index 3 : " << index3Val << '\n';

    cout << "\n\n\n";

        //----------------------------------------------

    removeOutcome = vectorObj.Remove(0);
    vectorObj.Get(0, index0Val);
    vectorObj.Get(1, index1Val);
    vectorObj.Get(2, index2Val);


    cout << "After calling .Remove(0)," << '\n';

    cout << setfill('-') << setw(50) << "" <<'\n';

    cout << "The return value of .Remove(0): "
         <<  removeOutcome  << "\n\n";

    cout << "the current size of vectorObj obtained using "
         << ".GetCurrentSize() : "
         << vectorObj.GetCurrentSize() << '\n';

    cout << "the capacity size of vectorObj obtained using "
         << ".GetCapacitySize() : "
         << vectorObj.GetCapacitySize() << "\n\n";

    cout << "Value stored at index 0 : " << index0Val << '\n';
    cout << "Value stored at index 1 : " << index1Val << '\n';
    cout << "Value stored at index 2 : " << index2Val << '\n';

    cout << "\n\n\n\n\n";
}


//--------------------------------------------------------------
//Testing .Remove() to remove elements
//from the back of a vector instance
void VectorTest::Test19()
{
    Vector<int> vectorObj;
    bool removeOutcome;
    int index0Val = 0;
    int index1Val = 0;
    int index2Val = 0;
    int index3Val = 0;


    cout << "Vector Test 19: Testing .Remove() to remove elements"
         << " from the back of a vector instance" << '\n';

    cout << setfill('#') << setw(75) << "" << '\n';

        //----------------------------------------------


    cout << "After creating a Vector instance of type integer,"
         << '\n';

    cout << setfill('-') << setw(50) << "" <<'\n';

    cout << "the current size of vectorObj obtained using "
         << ".GetCurrentSize() : "
         << vectorObj.GetCurrentSize() << '\n';

    cout << "the capacity size of vectorObj obtained using "
         << ".GetCapacitySize() : "
         << vectorObj.GetCapacitySize() << "\n\n\n";

         //-------------------------------------------

    vectorObj.Append(987);
    vectorObj.Append(555);
    vectorObj.Append(-343);
    vectorObj.Append(717);

    vectorObj.Get(0, index0Val);
    vectorObj.Get(1, index1Val);
    vectorObj.Get(2, index2Val);
    vectorObj.Get(3, index3Val);

    cout << "After appending (in order): "
         << " \'987\' , \'555\' , \'-343\' , \'717\' "
         << '\n';

    cout << setfill('-') << setw(50) << "" <<'\n';

    cout << "the current size of vectorObj obtained using "
         << ".GetCurrentSize() : "
         << vectorObj.GetCurrentSize() << '\n';

    cout << "the capacity size of vectorObj obtained using "
         << ".GetCapacitySize() : "
         << vectorObj.GetCapacitySize() << "\n\n";

    cout << "Value stored at index 0 : " << index0Val << '\n';
    cout << "Value stored at index 1 : " << index1Val << '\n';
    cout << "Value stored at index 2 : " << index2Val << '\n';
    cout << "Value stored at index 3 : " << index3Val << '\n';

    cout << "\n\n\n";

        //----------------------------------------------

    removeOutcome = vectorObj.Remove(3);
    vectorObj.Get(0, index0Val);
    vectorObj.Get(1, index1Val);
    vectorObj.Get(2, index2Val);


    cout << "After calling .Remove(3)," << '\n';

    cout << setfill('-') << setw(50) << "" <<'\n';

    cout << "The return value of .Remove(3): "
         <<  removeOutcome  << "\n\n";

    cout << "the current size of vectorObj obtained using "
         << ".GetCurrentSize() : "
         << vectorObj.GetCurrentSize() << '\n';

    cout << "the capacity size of vectorObj obtained using "
         << ".GetCapacitySize() : "
         << vectorObj.GetCapacitySize() << "\n\n";

    cout << "Value stored at index 0 : " << index0Val << '\n';
    cout << "Value stored at index 1 : " << index1Val << '\n';
    cout << "Value stored at index 2 : " << index2Val << '\n';

    cout << "\n\n\n\n\n";
}



//-------------------------------------------------------------
//Testing .Remove() where index is a negative
// number (invalid usage)
void VectorTest::Test20()
{
    Vector<int> vectorObj;
    bool removeOutcome;

    cout << "Vector Test 20: Testing .Remove() where index "
         << "is a negative number (invalid usage) "
         << '\n';


    cout << setfill('#') << setw(75) << "" << '\n';

        //----------------------------------------------

    cout << "After creating a Vector instance of type integer,"
         << '\n';

    cout << setfill('-') << setw(50) << "" <<'\n';

    cout << "the current size of vectorObj obtained using "
         << ".GetCurrentSize() : "
         << vectorObj.GetCurrentSize() << '\n';

    cout << "the capacity size of vectorObj obtained using "
         << ".GetCapacitySize() : "
         << vectorObj.GetCapacitySize() << "\n\n\n";

         //---------------------------------------

    removeOutcome = vectorObj.Remove(-1);

    cout << "After calling .Remove(-1)," << '\n';

    cout << setfill('-') << setw(50) << "" <<'\n';

    cout << "The return value of .Remove(-1): "
         <<  removeOutcome << "\n\n" ;

    cout << "the current size of vectorObj obtained using "
         << ".GetCurrentSize() : "
         << vectorObj.GetCurrentSize() << '\n';

    cout << "the capacity size of vectorObj obtained using "
         << ".GetCapacitySize() : "
         << vectorObj.GetCapacitySize();

    cout << "\n\n\n\n\n";
}


//--------------------------------------------------------------
//Testing .Remove() where the index is greater than or
// equal to the current size of the vector instance
void VectorTest::Test21()
{

    Vector<int> vectorObj;
    bool removeOutcome;
    int index0Val = 0;
    int index1Val = 0;
    int index2Val = 0;
    int index3Val = 0;


    cout << "Vector Test 21: Testing .Remove() where the "
         << "parameter value is greater than or equal to the "
         << '\n' << "current size "
         << "of the vector instance " << '\n';

    cout << setfill('#') << setw(75) << "" << '\n';

        //----------------------------------------------


    cout << "After creating a Vector instance of type integer,"
         << '\n';

    cout << setfill('-') << setw(50) << "" <<'\n';

    cout << "the current size of vectorObj obtained using "
         << ".GetCurrentSize() : "
         << vectorObj.GetCurrentSize() << '\n';

    cout << "the capacity size of vectorObj obtained using "
         << ".GetCapacitySize() : "
         << vectorObj.GetCapacitySize() << "\n\n\n";

         //-------------------------------------------

    vectorObj.Append(987);
    vectorObj.Append(555);
    vectorObj.Append(-343);
    vectorObj.Append(717);

    vectorObj.Get(0, index0Val);
    vectorObj.Get(1, index1Val);
    vectorObj.Get(2, index2Val);
    vectorObj.Get(3, index3Val);

    cout << "After appending (in order): "
         << " \'987\' , \'555\' , \'-343\' , \'717\' "
         << '\n';

    cout << setfill('-') << setw(50) << "" <<'\n';

    cout << "the current size of vectorObj obtained using "
         << ".GetCurrentSize() : "
         << vectorObj.GetCurrentSize() << '\n';

    cout << "the capacity size of vectorObj obtained using "
         << ".GetCapacitySize() : "
         << vectorObj.GetCapacitySize() << "\n\n";

    cout << "Value stored at index 0 : " << index0Val << '\n';
    cout << "Value stored at index 1 : " << index1Val << '\n';
    cout << "Value stored at index 2 : " << index2Val << '\n';
    cout << "Value stored at index 3 : " << index3Val << '\n';

    cout << "\n\n\n";

        //----------------------------------------------

    removeOutcome = vectorObj.Remove(4);
    vectorObj.Get(0, index0Val);
    vectorObj.Get(1, index1Val);
    vectorObj.Get(2, index2Val);
    vectorObj.Get(3, index3Val);


    cout << "After calling .Remove(4)," << '\n';

    cout << setfill('-') << setw(50) << "" <<'\n';

    cout << "The return value of .Remove(4): "
         <<  removeOutcome  << "\n\n";

    cout << "the current size of vectorObj obtained using "
         << ".GetCurrentSize() : "
         << vectorObj.GetCurrentSize() << '\n';

    cout << "the capacity size of vectorObj obtained using "
         << ".GetCapacitySize() : "
         << vectorObj.GetCapacitySize() << "\n\n";

    cout << "Value stored at index 0 : " << index0Val << '\n';
    cout << "Value stored at index 1 : " << index1Val << '\n';
    cout << "Value stored at index 2 : " << index2Val << '\n';
    cout << "Value stored at index 3 : " << index3Val << '\n';

    cout << "\n\n\n\n\n";
}


//--------------------------------------------------------------
void VectorTest::Test22()
{
    Vector<int> vectorObj;


    cout << "Vector Test 22: Testing the .Clear() Method "
         << '\n';

    cout << setfill('#') << setw(75) << "" << '\n';

        //-------------------------------------------

    cout << "After creating a Vector instance of type integer,"
         << '\n';

    cout << setfill('-') << setw(50) << "" <<'\n';

    cout << "the current size of the vector "
         << " object obtained using .GetCurrentSize() : "
         << vectorObj.GetCurrentSize() << '\n';

    cout << "the capacity size of the vector "
         << " object obtained using .GetCapacitySize() : "
         << vectorObj.GetCapacitySize() << "\n\n\n";

         //-----------------------------------------

    vectorObj.Append(987);
    vectorObj.Append(555);
    vectorObj.Append(-343);


    cout << "After appending three values: "
         << '\n';

    cout << setfill('-') << setw(50) << "" <<'\n';

    cout << "the current size of the original vector "
         << " object obtained using .GetCurrentSize() : "
         << vectorObj.GetCurrentSize() << '\n';

    cout << "the capacity size of the original vector "
         << " object obtained using .GetCapacitySize() : "
         << vectorObj.GetCapacitySize() << "\n\n\n";


         //-------------------------------------------------

    vectorObj.Clear();

    cout << "After calling .Clear() for the "
         << "vector object : " << '\n';

    cout << setfill('-') << setw(50) << "" <<'\n';

    cout << "the current size of vectorObj obtained "
         << "using .GetCurrentSize() : "
         << vectorObj.GetCurrentSize() << '\n';

    cout << "the capacity size of vectorObj obtained "
         << "using .GetCapacitySize() : "
         << vectorObj.GetCapacitySize() << "\n\n\n\n\n";

}


