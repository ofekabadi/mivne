#ifndef MIVNE_DYNAMIC_GRAPH_H
#define MIVNE_DYNAMIC_GRAPH_H
#include "Graph_Node.h"
#include "Graph_Edge.h"
#include "Rooted_Tree.h"

typedef My_List<Graph_Edge*> Edge_List;
typedef My_List<Graph_Node*> Node_List;

class Dynamic_Graph
{
public:
    Dynamic_Graph(): num_of_edges(0),first_edge(NULL),first_node(NULL){}
    ~Dynamic_Graph();
    Graph_Node* Insert_Node(unsigned node_key);
    void Delete_Node(Graph_Node* node);
    Graph_Edge* Insert_Edge(Graph_Node* from, Graph_Node* to);
    void Delete_Edge(Graph_Edge* edge);
    Rooted_Tree* SCC() const;
    Rooted_Tree* BFS(Graph_Node* source) const;


private:
    Graph_Edge* first_edge;
    Graph_Node* first_node;
    unsigned num_of_edges;

};

#endif
