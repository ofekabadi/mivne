#include "Rooted_Tree.h"

#define DELIMITER ","


void Rooted_Tree::Print_By_Layer(std::ostream& stream) const
{
    if (_source == NULL)
    {
        return;
    }

    unsigned height  = 0;
    stream << _source->_key << std::endl;

    if (_source->_left_child != NULL)
    {
        return;
    }

    height++;

    Tree_Node* current_node = _source->_left_child;

    while(current_node->_right_sibling != NULL)
    {
        current_node = current_node->_right_sibling;
        stream << current_node->_key <<DELIMITER;
    }

    if (current_node->_father->_right_sibling == NULL)
    {
        return;
    }

}


void Rooted_Tree::Preorder_Print(std::ostream& stream) const
{

}