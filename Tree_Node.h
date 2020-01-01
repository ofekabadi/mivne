#ifndef TREE_NODE_H
#define TREE_NODE_H

#include <cstddef>


class Tree_Node {
public:
    Tree_Node(unsigned key): _key(key), _father(NULL), _left_child(NULL),
    _right_sibling(NULL) {}

    inline unsigned get_tree_key(){return _key;}

private:
    unsigned _key;
    Tree_Node* _father;
    Tree_Node* _left_child;
    Tree_Node* _right_sibling;

    friend class Rooted_Tree;
};


#endif
