#ifndef MIVNE_ROOTED_TREE_H
#define MIVNE_ROOTED_TREE_H

#include <cstddef>
#include <ostream>

class Rooted_Tree
{
public:
    Rooted_Tree(){}
    ~Rooted_Tree(){}
    void Print_By_Layer(std::ostream& stream) const;
    void Preorder_Print(std::ostream& stream) const;

private:

};

#endif
