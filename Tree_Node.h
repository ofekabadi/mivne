#ifndef TREE_NODE_H
#define TREE_NODE_H

#include <cstddef>


class Tree_Node {
public:
    Tree_Node(unsigned key): _key(key), _father(NULL), _left_child(NULL),
    _right_sibling(NULL), _next(NULL){}

    inline unsigned get_tree_key(){return _key;}

    friend class Rooted_Tree;

    template <typename T>
    friend class Queue;


private:
    unsigned _key;
    Tree_Node* _father;
    Tree_Node* _left_child;
    Tree_Node* _right_sibling;
    Tree_Node* _next;


};


#endif
