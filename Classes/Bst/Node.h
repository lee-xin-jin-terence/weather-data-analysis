#ifndef NODE_H
#define NODE_H


namespace BstSubcomponent
{
        /*
          A sub-component required for the Bst
         template class
        */
    template <typename ElemType>
    struct Node
    {

        ElemType m_data;

        Node<ElemType>* m_leftNode;
        Node<ElemType>* m_rightNode;

    };

}




#endif // NODE_H
