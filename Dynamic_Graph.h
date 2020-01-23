#ifndef MIVNE_DYNAMIC_GRAPH_H
#define MIVNE_DYNAMIC_GRAPH_H

#include "definitions.h"
#include "Graph_Node.h"
#include "Graph_Edge.h"
#include "Rooted_Tree.h"
#include "Tree_Node.h"



class Dynamic_Graph {
public:
    Dynamic_Graph() : graph_nodes_list(NULL), graph_edges_list(NULL){}

    ~Dynamic_Graph();

    Graph_Node *Insert_Node(unsigned node_key);

    void Delete_Node(Graph_Node *node);

    Graph_Edge *Insert_Edge(Graph_Node *from, Graph_Node *to);

    void Delete_Edge(Graph_Edge *edge);

    Rooted_Tree *BFS(Graph_Node *source) const;

    Rooted_Tree *SCC() const;

    Rooted_Tree *DFS(Node_List nodes_order, DFS_Type) const;

    Tree_Node *DFS_Visit(Rooted_Tree *tree, Graph_Node *graphNode, Tree_Node *parent,
            DFS_Type) const;

    void DFS_Initialize(Node_List nodes_order, DFS_Type dfsType) const;

    void printGraph() const;

    //Rooted_Tree *Reverse_DFS();

    //Tree_Node *Reverse_DFS_Visit(Tree_Node *fatherNode, Graph_Node *graphFatherNode);

private:
    Node_List graph_nodes_list;
    Edge_List graph_edges_list;
    static Node_List retraction_time_list;
    static unsigned time;
};

#endif



