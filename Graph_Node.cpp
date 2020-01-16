#include "Graph_Node.h"
#include "Graph_Edge.h"

void Graph_Node::add_adj(Graph_Edge *adj_edge, Edge_Sides side)
{
    if(side == FROM)
    {
        _adj_from.Adj_from_insert(adj_edge);
    }

    else if(side == TO)
    {
        _adj_to.Adj_to_insert(adj_edge);
    }


}

void Graph_Node:: remove_adj(Graph_Edge *adj_edge, Edge_Sides side)
{

    if(side == FROM)
    {
        _adj_from.Adj_from_unlist(adj_edge);
    }

    else if(side == TO)
    {
        _adj_to.Adj_to_unlist(adj_edge);
    }
}

void Graph_Node::Set_out_Degree(Node_operations operation)
{
    if(operation == SUBTRACT)
    {
        _out_Degree--;
    }
    else if(operation == ADD)
    {
        _out_Degree++;
    }
}

void Graph_Node::Set_in_Degree(Node_operations operation)
{
    if(operation == SUBTRACT)
    {
        _in_Degree--;
    }
    else if(operation == ADD)
    {
        _in_Degree++;
    }
}




