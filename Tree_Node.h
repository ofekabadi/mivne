#ifndef TREE_NODE_H
#define TREE_NODE_H

#include <cstddef>
//#include "Graph_Node.h"


class Tree_Node
        {
public:
    Tree_Node(unsigned key): _key(key), _parent(NULL), _left_child(NULL),
    _right_sibling(NULL), _next(NULL), _prev(NULL), _qNext(NULL), _qPrev(NULL){}

    inline unsigned get_tree_key(){return _key;}
    inline void setFather(Tree_Node *parent) {_parent = parent;}
    inline void setLeftChild(Tree_Node *leftChild) {_left_child = leftChild;}
    inline void setRightSibling(Tree_Node *rightSibling) {_right_sibling = rightSibling;}

    inline Tree_Node* getLeftChild() {return _left_child;};


    friend class Rooted_Tree;
    template <typename T> friend class My_Queue;
    template <typename T> friend class My_List;


private:
    unsigned const _key;
    Tree_Node* _parent;
    Tree_Node* _left_child;
    Tree_Node* _right_sibling;

    Tree_Node* _next;
    Tree_Node* _prev;
    Tree_Node* _qNext;
    Tree_Node* _qPrev;
};


#endif
