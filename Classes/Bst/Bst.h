#ifndef BST_H
#define BST_H

#include "Node.h"

using BstSubcomponent::Node;


    /**
    * @class Bst template
    *
    * @brief Creates a binary search tree template which
    * is designed for very fast queries on the existence
    * of a certain key
    *
    * @author Terence Lee
    * @version 01
    * @date 7 March 2020
    */
template <typename ElemType>
class Bst
{
    public:

            /**
            * @brief Typedef for callback function pointers
            * of ElemType, used for data comparisons
            *
            * @param firstKey - a value to be compared to
            *   "secondKey"
            *
            * @param secondKey - a value to be compared to
            *   "firstKey"
            *
            * @return bool - true or false depending on the
            * type of comparison made
            */
        using ElemTypeComparison =
            bool (*)(const ElemType& firstKey,
                     const ElemType& secondKey);


            /**
            * @brief Typedef for callback function pointers
            * of ElemType, used for traversals across the
            * binary search tree
            *
            * @param currentKey - the key where the traversal
            * method is currently parsing
            *
            * @return void
            */
        using TraversalCallbackFunction =
            void (*)(const ElemType& currentKey);


            /**
            * @brief The constructor of the binary search tree.
            * Requires the client user to define what less-than,
            * equal-to and more-than for the template data-type
            * using callback functions.
            *
            * @param IsLessThan - a function pointer that defines
            * the less-than comparison. The function pointed by
            * the function pointer will return true if "firstKey"
            * is less than "secondKey", and false if otherwise
            *
            * @param IsEqualTo - a function pointer that defines
            * the equal-comparison. The function pointed by the
            * function pointer will return true if "firstKey" is
            * equal to "secondKey", and false if otherwise
            *
            * @param IsMoreThan - a function pointer that defines
            * the greater-than comparison. The function pointed by
            * the function pointer will return true if "firstKey"
            * is greater than "secondKey", and false if otherwise
            */
        Bst(  ElemTypeComparison IsLessThan ,
              ElemTypeComparison IsEqualTo ,
              ElemTypeComparison IsMoreThan);


            /**
            * @brief Empties the binary search tree and
            * de-allocate all the heap memory used
            */
        virtual ~Bst();


            /**
            * @brief Checks if the binary search tree is empty
            *
            * @return bool - true if the binary search tree is
            * empty and false if otherwise
            */
        bool IsEmpty() const;


            /**
            * @brief Remove all the keys within the binary
            * search tree, making it empty
            *
            * @return void
            */
        void Clear();


            /**
            * @brief Inserts an key into the binary search tree
            *
            * @param insertKey - the key to be inserted into
            * the binary search tree
            *
            * @return bool - true if the key is successfully
            * inserted into the binary search tree.  Returns false
            * if it fails to insert, which occurs when there
            * is insufficient heap memory or that the key
            * insertKey already exists within the binary search
            * tree
            */
        bool Insert(const ElemType& insertKey);


            /**
            * @brief Deletes/Removes a key from the binary
            * search tree
            *
            * @param deleteKey - the key to be deleted from
            * the binary search tree
            *
            * @return bool - true if the key deleteKey is
            * successfully deleted from the binary search tree.
            * Returns false if the key deleteKey does not
            * exists within the binary search tree (therefore
            * cannot be deleted)
            */
        bool Delete(const ElemType& deleteKey);


            /**
            * @brief Search to see whether a key exists within
            * the binary search tree
            *
            * @param searchKey - the key to be searched for
            * within the binary search tree
            *
            * @return bool - true if the key searchKey exists
            * within the binary search tree, and false if
            * otherwise
            */
        bool Search(const ElemType& searchKey) const;


            /**
            * @brief Traverses the binary search tree in in-order
            * sequence. Client user must define the callback function
            * when using this method
            *
            * @param Func - a callback function that
            * takes a binary search tree key as parameter
            *
            * @return void
            */
        void InOrderTraversal(
                TraversalCallbackFunction Func )const;


            /**
            * @brief Traverses the binary search tree in pre-order
            * sequence. Client user must define the callback function
            * when using this method.
            *
            * @param Func - a callback function that
            * takes a binary search tree key as parameter
            *
            * @return void
            */
        void PreOrderTraversal(
                TraversalCallbackFunction Func ) const;


            /**
            * @brief Traverses the binary search tree in post-order
            * sequence. Client user must define the callback
            * function when using this method
            *
            * @param Func - a callback function that
            * takes a binary search tree key as parameter
            *
            * @return void
            */
        void PostOrderTraversal(
                TraversalCallbackFunction Func ) const;



    protected:
            /// the root node of the binary search tree
        Node<ElemType>* m_root;


            /**
            * @brief A function pointer that will take two
            * parameters. Determines if the formal parameter
            * "firstKey" has a lower value than the formal
            *  parameter "secondKey"
            *
            * @param firstKey - the value to be compared to
            *   "secondKey"
            *
            * @param secondKey - the value to be compared to
            *   "firstKey"
            *
            * @return bool - true if "firstKey" has a lower value
            * than "secondKey", and false if otherwise
            */
        ElemTypeComparison m_IsLessThan;


            /**
            * @brief A function pointer that will take two
            * parameters. Determines if the formal parameter
            * "firstKey" is equal to the formal
            *  parameter "secondKey"
            *
            * @param firstKey - the value to be compared to
            *   "secondKey"
            *
            * @param secondKey - the value to be compared to
            *   "firstKey"
            *
            * @return bool - true if "firstKey" is equal to
            * the "secondKey", and false if otherwise
            */
        ElemTypeComparison m_IsEqualTo;


            /**
            * @brief A function pointer that will take two
            * parameters. Determines if the formal parameter
            * "firstKey" has a higher value than the formal
            *  parameter "secondKey"
            *
            * @param firstKey - the value to be compared to
            *   "secondKey"
            *
            * @param secondKey - the value to be compared to
            *   "firstKey"
            *
            * @return bool - true if "firstKey" has a higher value
            * than "secondKey", and false if otherwise
            */
        ElemTypeComparison m_IsMoreThan;

        //----------------------------------------------

    private:
            /**
            * @brief Remove all the keys within the binary
            * search tree, making it empty
            *
            * @param currentNode - the node to be deleted. As this
            * is a recursive method, currentNode will always start
            * with the root of the tree, that is m_root. This is
            * a helper method to the destructor and the method
            * .Clear()
            *
            * @post m_root will have a value of nullptr
            *
            * @return void
            */
        void DestroyTree(Node<ElemType>* &currentNode);


            /**
            * @brief Inserts a node into a binary search tree. This
            * is a helper method to the overloaded method Insert()
            *
            * @param newNode - the node to be inserted into the binary
            * search tree
            *
            * @param currentNode - the node that is currently parsed
            *  by the method . The key stored in
            * "currentNode" is compared to the key stored in
            * "newNode"
            *
            * @param parentOfCurrentNode - the node that is a parent
            * of the node "currentNode"
            *
            * @post the binary search tree will remain as a balanced
            * tree after insertion
            *
            * @return bool - true if the node is successfully inserted
            * into the binary search tree, and false if the
            * the node is not inserted, due to insufficient heap
            * memory or that there is an existing node storing
            * the same key as "newNode"
            */
        bool Insert(Node<ElemType>* newNode,
                Node<ElemType>* currentNode,
                Node<ElemType>* parentOfCurrentNode);


            /**
            * @brief Deletes/Removes an key from the binary
            * search tree. This is a helper method to the overloaded
            * method Delete()
            *
            * @param deleteKey - the key to be deleted from
            * the binary search tree
            *
            * @param currentNode - the node that is currently
            * parsed by the method . The key stored in
            * "currentNode" is compared to "deleteKey"
            *
            * @param parentOfCurrentNode - the node that is a parent
            * of the node "currentNode"
            *
            * @post the binary search tree will remain as a balanced
            * tree after deletion
            *
            * @return bool - true if the key deleteKey is
            * successfully deleted from the binary search tree.
            * Returns false if the key deleteKey does not
            * exists within the binary search tree (therefore cannot
            * be deleted)
            */
        bool Delete(const ElemType& deleteItem,
                Node<ElemType>* &currentNode,
                Node<ElemType>* parentOfCurrentNode);


            /**
            * @brief Traverses the binary search tree in in-order
            * sequence. This is a helper method to the overloaded
            * method InOrderTraversal()
            *
            * @param currentNode - the node that is currently
            * parsed by the method.
            *
            * @param Func - a callback function that
            * takes a binary search tree key as parameter
            *
            * @return void
            */
        void InOrderTraversal(
                    Node<ElemType>* currentNode,
                    TraversalCallbackFunction Func) const;


            /**
            * @brief Traverses the binary search tree in pre-order
            * sequence. This is a helper method to the overloaded
            * method PreOrderTraversal
            *
            * @param currentNode - the node that is currently
            * parsed by the method.
            *
            * @param Func - a callback function that
            * takes a binary search tree key as parameter
            *
            * @return void
            */
        void PreOrderTraversal(
                    Node<ElemType>* currentNode,
                    TraversalCallbackFunction Func) const;


            /**
            * @brief Traverses the binary search tree in post-order
            * sequence. This is a helper method to the overloaded
            * method PostOrderTraversal()
            *
            * @param currentNode - the node that is currently
            * parsed by the method.
            *
            * @param Func - a callback function that
            * takes a binary search tree key as parameter
            *
            * @return void
            */
        void PostOrderTraversal(
                    Node<ElemType>* currentNode,
                    TraversalCallbackFunction Func) const;

            /**
            * @brief Checks if the node "currentNode" is imbalanced.
            * If "currentNode" is imbalanced, it will re-balance
            * "currentNode"
            *
            * @param currentNode - the node that is to be checked
            * whether it is balanced
            *
            * @param parentOfCurrentNode - the parent node of
            * "currentNode"
            *
            * @return void
            */
        void BalanceCurrentNode(
                    Node<ElemType>* currentNode,
                    Node<ElemType>* parentOfCurrentNode);


            /**
            * @brief Finds out how balanced the node "currentNode"
            * is with respect to its left sub-tree and right sub-tree
            *
            * @param currentNode - the node that is currently
            * of interest to this method
            *
            * @return int - if it returns a negative value, it means
            * the left sub-tree of currentNode is heavier than the
            * right sub-tree. Returns 0 if currentNode is equally
            * balanced on both left and right sub-tree. Returns
            * a positive number if the right sub-tree is heavier
            * than the left sub-tree. If the modulus of the return
            * value is greater than 1, then it means that the node
            * "currentNode" needs re-balancing
            */
        int GetNodeBalanceFactor(
                    Node<ElemType>* currentNode) const;


            /**
            * @brief Gets the node height of the current node
            *
            * @param currentNode - the current node that is of
            * interest
            *
            * @return int - the height of the current node
            */
        int GetNodeHeight(Node<ElemType>* currentNode) const;


            /**
            * @brief Returns the larger of the two numbers num1 and
            * num2
            *
            * @param num1 - the number to be compared to "num2"
            *
            * @param num2 - the number to be compared to "num1"
            *
            * return int - the value of the larger number between
            * num1 and num2
            */
        static int Max(int num1,int num2);


            /**
            * @brief Rotates a node (currentNode) that has a left-left
            * imbalance such that the node becomes balanced
            *
            * @param currentNode - the node that is currently
            * left-left imbalanced
            *
            * @param parentOfCurrentNode - the parent node of
            * "currentNode"
            *
            * @return void
            */
        void LeftLeftRotate(
                Node<ElemType>* currentNode,
                Node<ElemType>* parentOfCurrentNode);


            /**
            * @brief Rotates a node (currentNode) that has a
            * right-right imbalance such that it becomes balanced
            *
            * @param currentNode - the node that is currently
            * right-right imbalanced
            *
            * @param parentOfCurrentNode - the parent node of
            * "currentNode"
            *
            * @return void
            */
        void RightRightRotate(
                Node<ElemType>* currentNode,
                Node<ElemType>* parentOfCurrentNode);


            /**
            * @brief Rotates a node (currentNode)  that has a
            * left-right imbalance such that it becomes balanced
            *
            * @param currentNode - the node that is currently
            * left-right imbalanced
            *
            * @param parentOfCurrentNode - the parent node of
            * "currentNode"
            *
            * @return void
            */
        void LeftRightRotate(
                Node<ElemType>* currentNode,
                Node<ElemType>* parentOfCurrentNode);


            /**
            * @brief Rotates a node (currentNode) that has a
            * right-left imbalance such that it becomes
            * balanced
            *
            * @param currentNode - the node that is currently
            * right-left imbalanced
            *
            * @param parentOfCurrentNode - the parent node of
            * "currentNode"
            *
            * @return void
            */
        void RightLeftRotate(
                Node<ElemType>* currentNode,
                Node<ElemType>* parentOfCurrentNode);


            /**
            * @brief The copy constructor is not implemented
            * as the author feels that there is no need
            * to create a copy of a binary search tree
            *
            * Moreover, if there is insufficient memory and
            * the copying of the binary search tree fails mid-way,
            * there is no way of knowing if such a failure has
            * occurred
            */
        Bst(const Bst<ElemType>& otherTree);


            /**
            * @brief The assignment operator is not implemented
            * as the author feels that there is no need
            * to create a copy of a binary search tree
            *
            * Moreover, if there is insufficient memory and
            * the copying of the binary search tree fails mid-way,
            * there is no way of knowing if such a failure has
            * occurred
            */
        const Bst<ElemType>& operator =
                                    (const Bst<ElemType>& otherTree);

};


//-------------------------------------------------------------
template <typename ElemType>
Bst<ElemType> ::Bst( ElemTypeComparison IsLessThan ,
                     ElemTypeComparison IsEqualTo ,
                     ElemTypeComparison IsMoreThan)
{
    m_root = nullptr;
    m_IsLessThan = IsLessThan;
    m_IsEqualTo = IsEqualTo;
    m_IsMoreThan = IsMoreThan;
}


//-------------------------------------------------------------
template <typename ElemType>
Bst<ElemType>::~Bst()
{
    DestroyTree(m_root);
}


//------------------------------------------------------------
template <typename ElemType>
void Bst<ElemType>::DestroyTree( Node<ElemType>* &currentNode)
{

    if (currentNode != nullptr)
    {
        DestroyTree(currentNode->m_leftNode);
        DestroyTree(currentNode->m_rightNode);

        delete currentNode;
        currentNode = nullptr;
    }

}


//------------------------------------------------------------
template <typename ElemType>
bool Bst<ElemType>::IsEmpty() const
{
    return (m_root == nullptr);
}


//-------------------------------------------------------------
template <typename ElemType>
void Bst<ElemType>::Clear()
{
    DestroyTree(m_root);
}


//-------------------------------------------------------------
template <typename ElemType>
bool Bst<ElemType>:: Insert(const ElemType& insertKey)
{

    bool insertOutcome = false;

    Node<ElemType>* newNode = nullptr;

        // Read the comment below on why this emptyNode is required
    Node<ElemType>* emptyNode = nullptr;

    newNode = new Node<ElemType>;


        /*
            Check if there is sufficient heap memory to create a
            a node "newNode" to store a binary search tree element
        */
    if (newNode != nullptr)
    {

        newNode->m_data = insertKey;
        newNode->m_leftNode = nullptr;
        newNode->m_rightNode = nullptr;


        if (m_root == nullptr)
        {
            m_root = newNode;
            insertOutcome = true;

        }
        else
        {
            /*
                The overloaded method of the same name Insert()
                is used to insert the element into the binary
                search tree. If the node fails to be inserted,
                due to it already existing within the binary
                search tree, then newNode's memory will be
                de-allocated

                Note : a third variable is required
                to call the recursive method Insert() even
                though the root m_root has no parent node, so
                that is why the node emptyNode is created
            */

            insertOutcome = Insert(newNode, m_root,emptyNode);

            if (!insertOutcome)
            {
                delete newNode;
                newNode = nullptr;
            }

        }//end of if (m_root == nullptr)

    }//end of if (newNode != nullptr)


        /*
            Return true if the new key containing the value
            "insertKey" is successfully inserted into the binary
            search tree, and false if there is insufficient heap
            memory or that the key already exists within the
            binary search tree
        */
    return insertOutcome;
}


//------------------------------------------------------------
template <typename ElemType>
bool Bst<ElemType>::Insert(
                    Node<ElemType>* newNode,
                    Node<ElemType>* currentNode,
                    Node<ElemType>* parentOfCurrentNode)
{

    bool insertOutcome = false;

        // means if newNode->m_data < currentNode->m_data
    if ( m_IsLessThan(newNode->m_data, currentNode->m_data))
    {

        if (currentNode->m_leftNode == nullptr)
        {
            currentNode->m_leftNode = newNode;

            insertOutcome = true;
        }
        else
        {
            insertOutcome = Insert(newNode,
                               currentNode->m_leftNode,
                               currentNode);
        }

            /*
                If there is a successful insertion, then the
                node must be checked for imbalance,and re-balance
                it if necessary
            */
        if (insertOutcome)
        {
            BalanceCurrentNode(currentNode,
                               parentOfCurrentNode);
        }

    }
        //means if newNode->m_data > currentNode->m_data
    else if (m_IsMoreThan (newNode->m_data, currentNode->m_data) )
    {

        if (currentNode->m_rightNode == nullptr)
        {
            currentNode->m_rightNode = newNode;

            insertOutcome = true;
        }
        else
        {
            insertOutcome = Insert(newNode,
                                  currentNode->m_rightNode,
                                  currentNode);

        }


         /*
            If there is a successful insertion, then the
            node must be checked for imbalance,and re-balance
            it if necessary
        */
        if (insertOutcome)
        {
            BalanceCurrentNode(currentNode,
                               parentOfCurrentNode);
        }

    }


        /*
            Return true if there is a successful insertion, and
            false if the element already exists within the binary'
            search tree
        */
    return insertOutcome;
}


//-------------------------------------------------------------
template <typename ElemType>
bool Bst<ElemType>::Delete(const ElemType& deleteKey)
{

    bool deleteOutcome = false;

    Node<ElemType>* emptyNode = nullptr;


    if (m_root != nullptr)
    {
            // The third parameter is emptyNode as m_root
            // does not have a parent node, but the method
            // requires a third parameter
        deleteOutcome = Delete(deleteKey, m_root, emptyNode);

    }//end of if (m_root != nullptr)


    return deleteOutcome;
}


//------------------------------------------------------------
template <typename ElemType>
bool Bst<ElemType>::Delete(
                  const ElemType& deleteKey,
                  Node<ElemType>* &currentNode,
                  Node<ElemType>* parentOfCurrentNode)
{
    bool deleteOutcome = false;

        /*
            Keep in mind for now
            that is variable is used for scenario 4A/ 4B
            (it will contain the key that is to be copied into
            the node to be deleted (it is okay if you do not
            understand it right now). You will understand it later
        */
    Node<ElemType>* tempNode = nullptr;


        /*
            for now, keep in mind that trailCurrentNode will be
            trailing (be right behind) the tempNode. You will
            understand it later
        */
    Node<ElemType>* trailTempNode = nullptr;



    if (currentNode != nullptr)
    {
            // means deleteKey < currentNode->m_data
        if ( m_IsLessThan(deleteKey, currentNode->m_data))
        {
            deleteOutcome = Delete(deleteKey,
                                   currentNode->m_leftNode,
                                   currentNode);


                /*
                    If deletion is successful, then the tree will
                    be re-balanced if necessary
                */
            if (deleteOutcome)
            {
                BalanceCurrentNode(currentNode,
                                   parentOfCurrentNode);

            }

        }
            // means deleteKey > currentNode->m_data
        else if ( m_IsMoreThan(deleteKey, currentNode->m_data ))
        {
            deleteOutcome =
                Delete(deleteKey,currentNode->m_rightNode,
                        currentNode);


                /*
                    If deletion is successful, then the tree will
                    be re-balanced if necessary
                */
            if (deleteOutcome)
            {

                BalanceCurrentNode(currentNode,
                                   parentOfCurrentNode);
            }

        }
        else
        {

            if (currentNode->m_leftNode == nullptr &&
                currentNode->m_rightNode == nullptr)
            {
                /*
                    Case 1:

                    If the node to be deleted (currentNode)
                    has no left or right child,
                     then the node can be
                    deleted straight away
                */
                delete currentNode;
                currentNode = nullptr;


            }
            else if (currentNode->m_leftNode == nullptr)
            {
                /*
                    Case 2:

                    If the node to be deleted has a right
                    child and has no left child, the address of the
                    node to be deleted will be copied
                    to a temporary node (tempNode).
                    Then, the node will itself become its
                    right child (no creation of new node)

                    The memory pointed to by tempNode will
                    be de-allocated
                */

                tempNode = currentNode;
                currentNode = currentNode->m_rightNode;

                delete tempNode;
                tempNode = nullptr;

            }
            else if (currentNode->m_rightNode == nullptr)
            {
                /*
                    Case 3:

                    If the node to be deleted(currentNode) has a left
                    child and has no right child, the address of the
                    node to be deleted will be copied
                    to a temporary node (tempNode).
                    Then, the node (currentNode) will itself become its
                    left child (no creation of new node)

                    The memory pointed to by tempNode will
                    be de-allocated
                */
                tempNode = currentNode;
                currentNode = currentNode->m_leftNode;

                delete tempNode;
                tempNode = nullptr;
            }
            else
            {

                /*  Warning : This is not easy to understand.
                        You need to draw it out on paper!


                    Case 4A:
                    If the node to be deleted (currentNode) has
                    both a left child and a right child,
                    then we'll pick
                    the right-most node (Lets call it RMN)
                    of the direct left child (Lets call it DLC)
                    of currentNode and copy the key stored in
                    the RMN into the node to be
                    deleted. The memory stored within
                    RMN will then be de-allocated.

                    (This means that the actual node to be deleted
                     is actually not deleted)

                     Case 4B(continued from case A):
                     However, if DLC has no right
                     child at all, then
                     the key stored within the left child of the
                     node to be deleted will be copied into the
                     node to be deleted. The memory of the
                     left child will then be de-allocated

                     (This also means that the actual node to be
                      deleted is actually not deleted)

                */
                tempNode = currentNode->m_leftNode;
                trailTempNode = nullptr;


                while (tempNode->m_rightNode != nullptr)
                {
                    /*
                        This loop is used to find the RMN. tempNode
                        will represent RMN


                        trailTempNode will be the direct parent
                        of RMN
                    */

                    trailTempNode = tempNode;
                    tempNode = tempNode->m_rightNode;
                }


                    /*
                        Copy the key stored in tempNode
                        into currentNode (which is the
                        node to be deleted)

                        Note that the node to be deleted is
                        actually not deleted at all
                    */
                currentNode->m_data = tempNode->m_data;


                if (trailTempNode != nullptr)
                {
                    /*
                        Warning : This is not easy to understand.
                        You need to draw it out on paper!

                        For Case 4A:  tempNode will represent
                        RMN, while trailTempNode will represent direct
                        parent of RN.

                        trailTempNode's right pointer will now point
                        to RMN's left child

                        We do not have to worry about RMN's
                        right child since it
                        has no right child (That's why it's called
                        right-most child !)
                    */
                    trailTempNode->m_rightNode =
                                tempNode->m_leftNode;
                }
                else
                {
                    /*
                        Warning : This is not easy to understand.
                        You need to draw it out on paper!

                        For Case 4B: currentNode (node to be deleted)
                        will now has its left pointer pointing
                        to the left tree of its left tree (left, and
                        then left again)

                        Since DLC( direct left child) of currentNode
                          has no right child, we do not have to worry
                        about DLC's right sub-tree
                    */
                    currentNode->m_leftNode =
                                tempNode->m_leftNode;
                }

                delete tempNode;
                tempNode = nullptr;


                    /*
                        This extra re-balancing for
                        Case 4A and 4B is required as the
                        sub-trees of currentNode is altered
                    */
                BalanceCurrentNode(currentNode,
                                   parentOfCurrentNode);



            }//end of if-else ladder when deleteKey is found
             //determine how to delete the node

            deleteOutcome = true;

        }//end of outer if-else ladder that looks for
         //deleteItem within the binary search tree

    }//end of if(currentNode != nullptr)


        /*
            Return true if deletion is successful, and
            false if the element to be deleted does not exist
            within the binary search tree
        */
    return deleteOutcome;
}


//-------------------------------------------------------------
template <typename ElemType>
bool Bst<ElemType>::Search( const ElemType& searchKey) const
{

    Node<ElemType>* currentNode = nullptr;

    bool foundMatch = false;


    if (m_root != nullptr)
    {

        currentNode = m_root;


        while (currentNode != nullptr && !foundMatch)
        {

            if ( m_IsEqualTo (currentNode->m_data, searchKey))
            {
                foundMatch = true;
            }
            else if (m_IsMoreThan(currentNode->m_data,
                                                    searchKey))
            {
                currentNode = currentNode->m_leftNode;
            }
            else
            {
                currentNode = currentNode->m_rightNode;

            }//end of if-else ladder

        }//end of while-loop

    }//end of if (m_root != nullptr)


        /*
            Returns true if the element searchItem exists within
            the binary search tree, and false if otherwise
        */
    return foundMatch;

}


//-------------------------------------------------------------
template <typename ElemType>
void Bst<ElemType>::InOrderTraversal(
        TraversalCallbackFunction Func) const
{
        /*
            Call the overloaded method of the same name to
            start the in-order traversal

            Since its overloaded method is a recursive method and
            has to start somewhere, thereby it will start from
            the root (m_root) of the binary search tree
        */
    InOrderTraversal(m_root, Func);
}


//-------------------------------------------------------------
template <typename ElemType>
void Bst<ElemType>::InOrderTraversal(
            Node<ElemType>* currentNode,
            TraversalCallbackFunction Func) const
{

        /*
            This is a recursive method that will traverse the
            binary search tree in an in-order sequence

            Callback function will execute whatever callback
            function that the client user has defined
        */
    if (currentNode != nullptr)
    {
        InOrderTraversal(currentNode->m_leftNode,Func);

        Func (currentNode->m_data);

        InOrderTraversal(currentNode->m_rightNode, Func);
    }
}


//-------------------------------------------------------------
template <typename ElemType>
void Bst<ElemType>::PreOrderTraversal(
            TraversalCallbackFunction Func) const
{

        /*
            Call the overloaded method of the same name to
            start the pre-order traversal

            Since its overloaded method is a recursive method and
            has to start somewhere, thereby it will start from
            the root (m_root) of the binary search tree
        */
    PreOrderTraversal(m_root, Func);
}


//------------------------------------------------------------
template <typename ElemType>
void Bst<ElemType>::PreOrderTraversal(
                Node<ElemType>* currentNode ,
                TraversalCallbackFunction Func) const
{

        /*
            This is a recursive method that will traverse the
            binary search tree in an pre-order sequence

            Callback function will execute whatever callback
            function that the client user has defined
        */
    if (currentNode != nullptr)
    {
        Func( currentNode->m_data );

        PreOrderTraversal(currentNode->m_leftNode,Func);

        PreOrderTraversal(currentNode->m_rightNode,Func);
    }
}


//------------------------------------------------------------
template <typename ElemType>
void Bst<ElemType>::PostOrderTraversal(
            TraversalCallbackFunction Func) const
{

        /*
            Call the overloaded method of the same name to
            start the post-order traversal

            Since its overloaded method is a recursive method and
            has to start somewhere, thereby it will start from
            the root (m_root) of the binary search tree
        */
    PostOrderTraversal(m_root, Func);
}


//--------------------------------------------------------------
template <typename ElemType>
void Bst<ElemType>::PostOrderTraversal(
                Node<ElemType>* currentNode,
                TraversalCallbackFunction Func)const
{

        /*
            This is a recursive method that will traverse the
            binary search tree in an post-order sequence

            Callback function will execute whatever callback
            function that the client user has defined
        */
    if (currentNode != nullptr)
    {

        PostOrderTraversal(currentNode->m_leftNode,Func);

        PostOrderTraversal(currentNode->m_rightNode,Func);

        Func( currentNode->m_data );
    }
}


//---------------------------------------------------------------
template <typename ElemType>
void Bst<ElemType>::BalanceCurrentNode(
                Node<ElemType>* currentNode,
                Node<ElemType>* parentOfCurrentNode)
{

    int currentNodeBalanceFactor
            = GetNodeBalanceFactor(currentNode);


        /*
            Re-balance the node currentNode if it is imbalanced
            (left and right sub-tree have a height difference
             of more than modulus 1)
        */
    if (currentNodeBalanceFactor > 1)
    {

        if (GetNodeBalanceFactor(currentNode->m_leftNode) > 0)
        {
            LeftLeftRotate(currentNode, parentOfCurrentNode);
        }
        else
        {
            LeftRightRotate(currentNode, parentOfCurrentNode);
        }
    }
    else if (currentNodeBalanceFactor < -1 )
    {

        if (GetNodeBalanceFactor(currentNode->m_rightNode) < 0)
        {
            RightRightRotate(currentNode, parentOfCurrentNode);
        }
        else
        {
            RightLeftRotate(currentNode, parentOfCurrentNode);
        }
    }

}


//-------------------------------------------------------------
template <typename ElemType>
int Bst<ElemType>::GetNodeBalanceFactor(
                Node<ElemType>* currentNode) const
{
        /*
            Basically the difference in height between the
            left and right sub-tree
        */
    int leftSubtreeHeight =
                          GetNodeHeight(currentNode->m_leftNode);
    int rightSubtreeHeight =
                        GetNodeHeight(currentNode->m_rightNode);

    return (leftSubtreeHeight - rightSubtreeHeight);
}


//---------------------------------------------------------------
template <typename ElemType>
int Bst<ElemType>::GetNodeHeight(
                        Node<ElemType>* currentNode) const
{
        /*
            Using recursion to find out the height of the node
        */
    if (currentNode == nullptr)
    {
        return 0;
    }
    else
    {
        return 1 + Max(GetNodeHeight(currentNode->m_leftNode),
                       GetNodeHeight(currentNode->m_rightNode));
    }

}


//---------------------------------------------------------------
template <typename ElemType>
int Bst<ElemType>::Max(int num1, int num2)
{
        /*
            Returns the number with the greater value
        */
    if ( num1 > num2)
    {
        return num1;
    }
    else
    {
        return num2;
    }
}


//---------------------------------------------------------------
template <typename ElemType>
void Bst<ElemType>::LeftLeftRotate(
                    Node<ElemType>* currentNode,
                    Node<ElemType>* parentOfCurrentNode)
{

    Node<ElemType>* newChildOfParentNode =
                                        currentNode->m_leftNode;


    currentNode->m_leftNode = newChildOfParentNode->m_rightNode;

    newChildOfParentNode->m_rightNode = currentNode;


    if (parentOfCurrentNode == nullptr)
    {
            /*
                If the node (currentNode) to be rebalanced is actually
                the tree root, then assign the node
                "newChildOfParentNode" to become the new tree root
            */
        m_root = newChildOfParentNode;
    }
    else
    {
            /*
                After re-balancing the node "currentNode", the
                parent node (parentOfCurrentNode) must now
                point to the correct node
            */
            // means parentOfCurrentNode->m_data > currentNode->m_data
        if ( m_IsMoreThan(parentOfCurrentNode->m_data,
                                            currentNode->m_data))
        {
            parentOfCurrentNode->m_leftNode =
                                            newChildOfParentNode;

        }
        else
        {
            parentOfCurrentNode->m_rightNode =
                                            newChildOfParentNode;
        }
    }

}

//--------------------------------------------------------------
template <typename ElemType>
void Bst<ElemType>::RightRightRotate(
                        Node<ElemType>* currentNode,
                        Node<ElemType>* parentOfCurrentNode)
{

    Node<ElemType>* newChildOfParentNode =
                                    currentNode->m_rightNode;


    currentNode->m_rightNode = newChildOfParentNode->m_leftNode;


    newChildOfParentNode->m_leftNode = currentNode;



    if (parentOfCurrentNode == nullptr)
    {
            /*
                If the node (currentNode) to be rebalanced is actually
                the tree root, then assign the node
                "newChildOfParentNode" to become the new tree root
            */
        m_root = newChildOfParentNode;
    }
    else
    {
            /*
                After re-balancing the node "currentNode", the
                parent node (parentOfCurrentNode) must now
                point to the correct node
            */
            // means parentOfCurrentNode->m_data > currentNode->m_data
        if ( m_IsMoreThan(parentOfCurrentNode->m_data,
                                            currentNode->m_data))
        {
            parentOfCurrentNode->m_leftNode =
                                         newChildOfParentNode;

        }
        else
        {
            parentOfCurrentNode->m_rightNode =
                                        newChildOfParentNode;
        }
    }
}


//--------------------------------------------------------------
template <typename ElemType>
void Bst<ElemType>::LeftRightRotate(
                Node<ElemType>* currentNode,
                Node<ElemType>* parentOfCurrentNode)
{

    Node<ElemType>* tempNode = currentNode->m_leftNode;


        /*
            A left-right imbalance involves two steps. It must
            first undergo a right-right re-balancing, before going
            through a left-left re-balancing
        */
    RightRightRotate(tempNode,currentNode);

    LeftLeftRotate(currentNode, parentOfCurrentNode);

}


//-------------------------------------------------------------
template <typename ElemType>
void Bst<ElemType>::RightLeftRotate(
                Node<ElemType>* currentNode,
                Node<ElemType>* parentOfCurrentNode)
{

    Node<ElemType>* tempNode = currentNode->m_rightNode;


        /*
            A right-left imbalance involves two steps. It must
            first undergo a left-left re-balancing, before going
            through a right-right re-balancing
        */

    LeftLeftRotate(tempNode, currentNode);

    RightRightRotate(currentNode,parentOfCurrentNode);

}



#endif // BST_H
