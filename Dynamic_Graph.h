#ifndef MIVNE_DYNAMIC_GRAPH_H
#define MIVNE_DYNAMIC_GRAPH_H
#include "Graph_Node.h"
#include "Graph_Edge.h"
#include "Rooted_Tree.h"
#include "Tree_Node.h"

typedef My_List<Graph_Edge*> Edge_List;
typedef My_List<Graph_Node*> Node_List;
typedef My_Queue<Graph_Node*> Graph_Node_Queue;

class Dynamic_Graph
{
public:
    Dynamic_Graph(): num_of_edges(0), graph_nodes_list(NULL), graph_edges_list(NULL){}
    ~Dynamic_Graph();
    Graph_Node* Insert_Node(unsigned node_key);
    void Delete_Node(Graph_Node* node);
    Graph_Edge* Insert_Edge(Graph_Node* from, Graph_Node* to);
    void Delete_Edge(Graph_Edge* edge);
    Rooted_Tree* SCC() const;
    Rooted_Tree* BFS(Graph_Node* source) const;


private:
    Node_List graph_nodes_list;
    Edge_List graph_edges_list;
    //Graph_Edge* first_edge;
    //Graph_Node* first_node;
    unsigned num_of_edges;
};

#endif
