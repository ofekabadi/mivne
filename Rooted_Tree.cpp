#include "Rooted_Tree.h"

Rooted_Tree::~Rooted_Tree()
{
    Tree_Node* front_node = _nodes_List.Get_head();
    while (front_node != NULL)
    {
        _nodes_List.Unlist(front_node);
        front_node = _nodes_List.Get_head();
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
        current_print = currentQ->Pop();
        stream << current_print->get_tree_key();
        nextQ->Push(current_print->_left_child);

        current_print = current_print->_right_sibling;
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

        stream << std::endl;
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
    stream << std::endl;
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