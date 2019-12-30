#ifndef MIVNE_DYNAMIC_GRAPH_H
#define MIVNE_DYNAMIC_GRAPH_H
#include "Graph_Node.h"
#include "Rooted_Tree.h"
#include "Graph_Edge.h"

#define TEST_SIZE 30
#define INITIAL_NODES_NUM 10
#define INITIAL_EDGES_NUM 30
#define NUM_OF_OPERATIONS 8

class Dynamic_Graph
{
public:
    Dynamic_Graph(): nodes_array(), edges_array(), num_of_nodes(0){}     //should be
    // initialized to NULL
    ~Dynamic_Graph(){}
    Graph_Node* Insert_Node(unsigned node_key);
    void Delete_Node(Graph_Node* node);
    Graph_Edge* Insert_Edge(Graph_Node* from, Graph_Node* to);
    void Delete_Edge(Graph_Edge* edge);
    Rooted_Tree* SCC() const;
    Rooted_Tree* BFS(Graph_Node* source) const;

private:
    Graph_Node* nodes_array[TEST_SIZE+INITIAL_NODES_NUM];
    unsigned num_of_nodes;
    Graph_Edge* edges_array[TEST_SIZE + INITIAL_EDGES_NUM];
};

#endif
