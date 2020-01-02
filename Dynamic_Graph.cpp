#include "Dynamic_Graph.h"

Dynamic_Graph :: ~Dynamic_Graph()
{
    Graph_Edge* next_edge = NULL;
    Graph_Edge* current_edge = first_edge;
    while(current_edge != NULL)
    {
        next_edge = current_edge->get_next();
        delete current_edge;
        current_edge = next_edge;
    }

    Graph_Node* next_node = NULL;
    Graph_Node* current_node = first_node;
    while(current_node != NULL)
    {
        next_node = current_node->Get_next();
        delete current_node;
        current_node = next_node;
    }


}



Graph_Node* Dynamic_Graph::Insert_Node(unsigned node_key)
{
    Graph_Node* new_Node = new Graph_Node (node_key);
    if(first_node == NULL)
    {
        first_node = new_Node;
    }
    else if(first_node != NULL)
    {
        first_node->Set_next(new_Node);
        first_node = new_Node;
    }
}

void Dynamic_Graph::Delete_Node(Graph_Node* node)
{
    if(node->Get_in_Degree() == 0  && node->Get_out_Degree() == 0)
    {
        node->Get_next()->Set_prev(node->Get_prev());
        node->Get_prev()->Set_next(node->Get_next());
        delete node;
    }

}

Graph_Edge* Dynamic_Graph::Insert_Edge(Graph_Node* from, Graph_Node* to)
{
    Graph_Edge *new_Graph_Edge = new Graph_Edge(from,to);
    if(first_edge == NULL)
    {
        first_edge = new_Graph_Edge;
    }
    else if(first_edge != NULL)
    {
        first_edge->set_next(new_Graph_Edge);
        first_edge = new_Graph_Edge;
    }

    from->Set_out_Degree(ADD);
    from->_adj.Adj_insert(new_Graph_Edge);
    to->Set_in_Degree(ADD);
}

void Dynamic_Graph::Delete_Edge(Graph_Edge* edge)
{
    edge->get_next()->set_prev(edge->get_prev());
    edge->get_prev()->set_next(edge->get_next());

    edge->get_from()->Set_out_Degree(SUBTRACT);

    edge->get_from()->_adj.Adj_unlist(edge);

    edge->get_to()->Set_in_Degree(SUBTRACT);
    delete edge;
}



Rooted_Tree* Dynamic_Graph::SCC() const
{

}
Rooted_Tree* Dynamic_Graph::BFS(Graph_Node* source) const{}