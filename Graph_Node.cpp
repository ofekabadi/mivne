#include "Graph_Node.h"


void Graph_Node::Set_out_Degree(Node_operations operation)
{
    if(operation == SUBTRACT)
    {
        out_Degree--;
    }
    else if(operation == ADD)
    {
        out_Degree++;
    }
}

void Graph_Node::Set_in_Degree(Node_operations operation)
{
    if(operation == SUBTRACT)
    {
        in_Degree--;
    }
    else if(operation == ADD)
    {
        in_Degree++;
    }
}