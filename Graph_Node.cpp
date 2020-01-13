#include "Graph_Node.h"
#include "Graph_Edge.h"



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


