#include "Dynamic_Graph.h"

Graph_Node* Dynamic_Graph::Insert_Node(unsigned node_key)
{
    Graph_Node* newNode = new Graph_Node (node_key);
    unsigned location = hash_function(node_key);
    if (nodes_hash_array[location] != NULL)
    {
        newNode->Set_prev(nodes_hash_array[location]);
        nodes_hash_array[location]->Set_next(newNode);
        nodes_hash_array[location] = newNode;
    }
    else if  (nodes_hash_array[location] == NULL)
    {
        nodes_hash_array[location] = newNode;
    }
}

void Dynamic_Graph::Delete_Node(Graph_Node* node)
{
    node->Get_next()->Set_prev(node->Get_prev());
    node->Get_prev()->Set_next(node->Get_next());
    delete node;
}

Graph_Edge* Dynamic_Graph::Insert_Edge(Graph_Node* from, Graph_Node* to)
{
    //is the given edge unique?
    //do the nodes exist in the graph?
    from->Set_out_Degree(ADD);
    to->Set_in_Degree(ADD);
}

void Dynamic_Graph::Delete_Edge(Graph_Edge* edge)
{
    edge->get_from()->Set_out_Degree(SUBTRACT);
    edge->get_to()->Set_in_Degree(SUBTRACT);
}


unsigned Dynamic_Graph::hash_function (unsigned node_key)
{
    return node_key%10;
}

Rooted_Tree* Dynamic_Graph::SCC() const{}
Rooted_Tree* Dynamic_Graph::BFS(Graph_Node* source) const{}