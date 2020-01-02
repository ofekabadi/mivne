#ifndef GRAPH_EDGE_H
#define GRAPH_EDGE_H

#include <cstddef>

class Graph_Node; //forward declaration

class Graph_Edge {
public:
    Graph_Edge(Graph_Node* from, Graph_Node* to):_from(from), _to(to), _next(NULL) ,
    _prev(NULL), _next_adj(NULL), _prev_adj(NULL){};
    Graph_Node* get_from(){return _from;}
    Graph_Node* get_to(){return _to;}
    inline void set_next (Graph_Edge * next){_next = next;}
    inline void set_prev (Graph_Edge * prev){_prev = prev;}
    inline Graph_Edge* get_next (){ return _next;}
    inline Graph_Edge* get_prev (){ return _prev;}

    Graph_Edge* _next_adj;   //edges used in adjacency lists
    Graph_Edge* _prev_adj;

private:
    Graph_Node* _from;
    Graph_Node* _to;
    Graph_Edge* _next;
    Graph_Edge* _prev;


};



#endif
