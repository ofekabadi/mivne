#ifndef DEFINITIONS_H
#define DEFINITIONS_H

#include "Graph_Edge.h"
#include "My_Queue.h"
#include "Tree_Node.h"

typedef My_List<Graph_Edge*> Edge_List;
typedef My_List<Graph_Node*> Node_List;
typedef My_Queue<Graph_Node*> Graph_Node_Queue;
typedef My_List<Graph_Edge*> Adj_List;
typedef My_Queue<Tree_Node*> Tree_Node_Queue;
typedef My_List<Tree_Node*> Tree_Nodes_List;


typedef enum {SUBTRACT=0, ADD} Node_operations;
typedef enum {FROM=0, TO} Edge_Sides;
typedef enum {REGULAR=0, REVERSED} DFS_Type;


#endif
