#ifndef GRAPH_EDGE_H
#define GRAPH_EDGE_H

#include "Graph_Node.h"

class Graph_Edge {
public:
    Graph_Edge(Graph_Node* from, Graph_Node* to):_from(from),_to(to),_prev_edge(NULL),
    _next_edge(NULL){};
    Graph_Node* get_from(){return _from;}
    Graph_Node* get_to(){return _to;}
    inline void set_next (Graph_Edge * next){_next_edge = next;}
    inline void set_prev (Graph_Edge * prev){_prev_edge = prev;}
    inline Graph_Edge* get_next (){ return _next_edge;}
    inline Graph_Edge* get_prev (){ return _prev_edge;}

private:
    Graph_Node* _from;
    Graph_Node* _to;
    Graph_Edge* _prev_edge;
    Graph_Edge* _next_edge;


};



#endif
