#include "Dynamic_Graph.h"

Graph_Node* Dynamic_Graph::Insert_Node(unsigned node_key)
{
    nodes_array[num_of_nodes] = new Graph_Node(node_key);
    nodes_array[num_of_nodes]->Set_location(num_of_nodes);
    num_of_nodes++;
    return nodes_array[num_of_nodes];
}

void Dynamic_Graph::Delete_Node(Graph_Node* node)
{
    unsigned location = node->Get_location();
    delete nodes_array[location];
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


Rooted_Tree* Dynamic_Graph::SCC() const{}
Rooted_Tree* Dynamic_Graph::BFS(Graph_Node* source) const{}