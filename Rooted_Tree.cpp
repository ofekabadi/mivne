#include "Rooted_Tree.h"

Rooted_Tree::~Rooted_Tree()
{
    Tree_Node* front_node = _nodes_List.Get_tail();
    while (front_node != NULL && front_node != _source)
    {
        _nodes_List.Unlist(front_node);
        delete front_node;
        front_node = _nodes_List.Get_tail();
    }
    delete _source;
}


void Rooted_Tree::Print_By_Layer(std::ostream& stream) const
{
    if (_source == NULL)
    {
        return;
    }

    Tree_Node* current_print = _source;
    Tree_Node_Queue Q1(current_print), Q2(NULL);

    Tree_Node_Queue *currentQ = &Q1;
    Tree_Node_Queue *nextQ = &Q2;

    while(currentQ->Get_front() != NULL)
    {
        if(currentQ->Get_front() != _source)
        {
            stream << std::endl;
        }
        current_print = currentQ->Pop();
        stream << current_print->get_tree_key();
        nextQ->Push(current_print->_left_child);

        current_print = current_print->_right_sibling;
        if (current_print == NULL)
        {
            current_print = currentQ->Pop();
        }
        while(current_print != NULL)
        {
            stream << DELIMITER << current_print->_key;
            nextQ->Push(current_print->_left_child);
            current_print = current_print->_right_sibling;
            if(current_print == NULL)
            {
                current_print = currentQ->Pop();
            }
        }

        if(currentQ == &Q1)
        {
            currentQ = &Q2;
            nextQ = &Q1;
            continue;
        }
        else if(currentQ == &Q2)
        {
            currentQ = &Q1;
            nextQ = &Q2;
        }
    }
}


void Rooted_Tree::Preorder_Print(std::ostream& stream) const
{
    if (_source == NULL)
    {
        return;
    }
    stream << _source->_key;
    Preorder(_source->_left_child,stream);
    //stream << std::endl;
}

void Rooted_Tree:: Preorder(Tree_Node* _current,std::ostream& stream) const
{
    if (_current == NULL)
    {
        return;
    }
    stream<<DELIMITER<<_current->_key;
    Preorder(_current->_left_child,stream);
    Preorder(_current->_right_sibling,stream);

}




void Rooted_Tree::printTree() const
{
    Tree_Node* printNode = _nodes_List.Get_head();
    while(printNode != NULL)
    {
        std::cout<<"node: "<<printNode->get_tree_key()<<std::endl;
        if(printNode->_parent != NULL)
        {
            std::cout<<"parent: "<<printNode->_parent->get_tree_key();
        }
        if(printNode->_left_child != NULL)
        {
            std::cout<<", left child: "<<printNode->_left_child->get_tree_key();
        }
        if(printNode->_right_sibling != NULL)
        {
            std::cout<<", right sibling: "<<printNode->_right_sibling->get_tree_key();
        }
        std::cout<<std::endl<<std::endl;
        printNode = printNode->_next;
    }
}
