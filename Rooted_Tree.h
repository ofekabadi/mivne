#ifndef ROOTED_TREE_H
#define ROOTED_TREE_H

#include <cstddef>
#include <ostream>
#include "Tree_Node.h"

class Rooted_Tree
{
public:
    Rooted_Tree(): _source(NULL){}
    ~Rooted_Tree(){}
    void Print_By_Layer(std::ostream& stream) const;
    void Preorder_Print(std::ostream& stream) const;

private:
    Tree_Node* _source;
};

#endif
