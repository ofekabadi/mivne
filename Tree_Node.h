#ifndef TREE_NODE_H
#define TREE_NODE_H

#include <cstddef>
#include "definitions.h"

typedef enum {WHITE =0 , GREY, BLACK} DFS_color;


class Tree_Node
        {
public:
    Tree_Node(unsigned key): _key(key), _parent(NULL), _left_child(NULL),
    _right_sibling(NULL), dfs_discovery(0), dfs_retraction(0), dfs_color(WHITE), _next(NULL),
    _prev(NULL), _qNext(NULL), _qPrev(NULL){}

    inline unsigned get_tree_key(){return _key;}
    inline Tree_Node* getLeftChild() {return _left_child;};

    inline void setParent(Tree_Node *parent) {_parent = parent;}
    inline void setLeftChild(Tree_Node *leftChild) {_left_child = leftChild;}
    inline void setRightSibling(Tree_Node *rightSibling) {_right_sibling = rightSibling;}

    inline void setDfsDiscovery(unsigned dfsDiscovery) {dfs_discovery = dfsDiscovery;}

    inline void setDfsRetraction(unsigned dfsRetraction) {dfs_retraction = dfsRetraction;}

    inline void setDfsColor(DFS_color color) {Tree_Node::dfs_color = color;}


    friend class Rooted_Tree;
    template <typename T> friend class My_Queue;
    template <typename T> friend class My_List;

private:
    unsigned const _key;
    Tree_Node* _parent;
    Tree_Node* _left_child;
    Tree_Node* _right_sibling;

    unsigned dfs_discovery;
    unsigned dfs_retraction;
    DFS_color dfs_color;

    Tree_Node* _next;
    Tree_Node* _prev;
    Tree_Node* _qNext;
    Tree_Node* _qPrev;
};


#endif
