#include "Rooted_Tree.h"


void Rooted_Tree::Print_By_Layer(std::ostream& stream) const
{
    if (_source == NULL)
    {
        return;
    }
    stream << _source->_key << std::endl;

    if (_source->_left_child == NULL)
    {
        return;
    }

    Tree_Node* current_print =_source->_left_child;
    Tree_Node_Queue Q(current_print);

    while (current_print != NULL)
    {
        stream << current_print->_key;
        Q.Push(current_print->_left_child);
        current_print = current_print->_right_sibling;
        Q.Pop();
        while(current_print != NULL)
        {
            stream << DELIMITER << current_print->_key;
            Q.Push(current_print->_left_child);
            current_print = current_print->_right_sibling;
            stream << std::endl;
        }
        current_print = Q.Get_front();
    }
}



void Rooted_Tree::Preorder_Print(std::ostream& stream) const
{

}