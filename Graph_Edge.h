#ifndef GRAPH_EDGE_H
#define GRAPH_EDGE_H

#include "Graph_Node.h"

class Graph_Edge {
public:
    Graph_Edge(Graph_Node* from, Graph_Node* to):from(from),to(to){};
    Graph_Node* get_from(){return from;}
    Graph_Node* get_to(){return to;}

private:
    Graph_Node* from;
    Graph_Node* to;
};



#endif
