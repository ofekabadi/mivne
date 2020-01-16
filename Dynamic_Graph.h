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
    Dynamic_Graph(): graph_nodes_list(NULL), graph_edges_list(NULL){}
    ~Dynamic_Graph();
    Graph_Node* Insert_Node(unsigned node_key);
    void Delete_Node(Graph_Node* node);
    Graph_Edge* Insert_Edge(Graph_Node* from, Graph_Node* to);
    void Delete_Edge(Graph_Edge* edge);

    Rooted_Tree* SCC();
    Rooted_Tree* DFS();
    void visitedInitialiser();
    Rooted_Tree* DFS_Visit(Tree_Node* fatherNode, Graph_Node* graphFatherNode);

    Rooted_Tree* BFS(Graph_Node* source) const;


   void printGraph() const
    {
        cout<<"nodes:"<<endl;
        Graph_Node* nodePrint = graph_nodes_list.Get_tail(); //from newest to oldest
        while (nodePrint != NULL)
        {
            cout<<"node key: "<<nodePrint->Get_key()<<endl;
            nodePrint = nodePrint->Get_prev();
        }

        cout<<endl<<"edges:"<<endl;
        Graph_Edge* edgePrint = graph_edges_list.Get_tail();   //from newest to oldest
        while (edgePrint != NULL)
        {
            cout<<"edge from: "<<edgePrint->get_from()->Get_key()<<" to: "<<
            edgePrint->get_to()->Get_key()<<endl;
            edgePrint = edgePrint->get_prev();
        }

        cout<<endl<<"end of graph"<<endl<<endl;
    }


private:
    Node_List graph_nodes_list;
    Edge_List graph_edges_list;
};

#endif
