#ifndef ROOTED_TREE_H
#define ROOTED_TREE_H

#include <cstddef>
#include <ostream>
#include "definitions.h"
#include "Tree_Node.h"
#include "My_Queue.h"
#include "My_List.h"

#define DELIMITER ","



class Rooted_Tree
{
public:
    Rooted_Tree(): _source(NULL), _nodes_List(NULL){}
    ~Rooted_Tree();

    void Print_By_Layer(std::ostream& stream) const;

    void Preorder_Print(std::ostream& stream) const;
    void Preorder(Tree_Node* _current,std::ostream& stream)
    const;

    void setSource(Tree_Node *source) {_source = source;}
    void addToNodesList(Tree_Node* node) {_nodes_List.Insert(node);}

    void printTree() const;

private:
    Tree_Node* _source;

    Tree_Nodes_List _nodes_List;

};
#endif




