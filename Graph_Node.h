#ifndef GRAPH_NODE_H
#define GRAPH_NODE_H

#include <cstddef>
#include <iostream>
#include "definitions.h"
#include "My_List.h"
#include "Tree_Node.h"

using namespace std;

class Graph_Edge; //forward declaration


class Graph_Node {
public:
    Graph_Node(unsigned newKey): _key(newKey), _out_Degree(0), _in_Degree(0),
                                  _next(NULL), _prev(NULL), _qNext(NULL), _qPrev(NULL),
                                  _retractionNext(NULL), _retractionPrev(NULL),
                                  _adj_from(NULL), _adj_to(NULL), _related_Tree_Node
                                  (NULL) , _DFS_visited(false),node_discovery(0),
                                 node_color(0),node_f(0){}

    inline unsigned Get_key() const {return _key;}

    inline unsigned Get_out_Degree() const {return _out_Degree;}
    inline unsigned Get_in_Degree() const {return _in_Degree;}
    void Set_out_Degree(Node_operations operation);
    void Set_in_Degree(Node_operations operation);

    inline Graph_Edge *get_first_adj() { _adj_from.Get_tail(); }
    inline Graph_Edge *get_first_adj_to() { _adj_to.Get_tail();}
     void add_adj(Graph_Edge *adj_edge,Edge_Sides side);
     void remove_adj(Graph_Edge *adj_edge,Edge_Sides side);

    //void setInTree(bool inTree) {_in_tree = inTree;}

    inline Tree_Node *getRelatedTreeNode() const { return _related_Tree_Node; }
    inline void setRelatedTreeNode(Tree_Node* related) {_related_Tree_Node = related;}


    inline Graph_Node *Get_next() { return _next; }
    inline Graph_Node *Get_prev() { return _prev; }
    inline Graph_Node *Get_retraction_next() { return _retractionNext; }
    inline Graph_Node *Get_retraction_prev() { return _retractionPrev; }

    inline void Set_next(Graph_Node *next) { _next = next; }
    inline void Set_prev(Graph_Node *prev) { _prev = prev; }

    void setDfsVisited(bool dfsVisited) {_DFS_visited = dfsVisited;}

    template<typename T> friend
    class My_List;
    template<typename T> friend
    class My_Queue;
    unsigned node_discovery;
    unsigned node_f;
    unsigned node_color;

private:

    unsigned const _key;
    unsigned _out_Degree;
    unsigned _in_Degree;

    Graph_Node *_next;
    Graph_Node *_prev;

    Graph_Node *_qNext;
    Graph_Node *_qPrev;

    Graph_Node *_retractionNext;    //used in scc
    Graph_Node *_retractionPrev;

    Adj_List _adj_from;
    Adj_List _adj_to;

    Tree_Node *_related_Tree_Node;

    bool _DFS_visited;
};



#endif
