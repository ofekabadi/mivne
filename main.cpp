#include <iostream>
#include <cstdlib>
#include "Dynamic_Graph.h"


#define SEED 23454
#define TEST_SIZE 30
#define INITIAL_NODES_NUM 10
#define INITIAL_EDGES_NUM 30
#define NUM_OF_OPERATIONS 8
#define INSERT_NODE 1
#define INSERT_EDGE 2
#define DELETE_NODE 3
#define DELETE_EDGE 4
#define STRONGLY_CONNECTED_COMPONENTS 5
#define RUN_BFS 6
#define OUT_DEGREE 7
#define IN_DEGREE 8

using namespace std;


class My_Edge
{
public:
    My_Edge(unsigned nfrom, unsigned nto):from(nfrom),to(nto){};
    unsigned get_from(){return from;}
    unsigned get_to(){return to;}
private:
    unsigned from;
    unsigned to;
};


unsigned generate_random_unsigned(const unsigned max_ind)
/*generates a random unsigned int in range [0,max_ind-1]*/
{
    return rand() % max_ind;
}

void shift_nodes_arrays(Graph_Node* nodes_array[],unsigned nodes_keys_array[],unsigned deleted_index, unsigned size)
{
    if (deleted_index <= size)
    {
        for (unsigned i = deleted_index;i<size-1;i++)
        {
            nodes_array[i] = nodes_array[i+1];
            nodes_keys_array[i] = nodes_keys_array[i+1];
        }
        nodes_array[size-1] = NULL;
        nodes_keys_array[size-1] = 0;
    }
}

void shift_edges_arrays(Graph_Edge* edges_array[],My_Edge* my_edge_array[],unsigned deleted_index, unsigned size)
{
    if (deleted_index <= size - 1)
    {
        delete my_edge_array[deleted_index];
        my_edge_array[deleted_index] = NULL;
        for (unsigned i = deleted_index;i<size-1;i++)
        {
            edges_array[i] = edges_array[i+1];
            my_edge_array[i] = my_edge_array[i+1];
        }
        edges_array[size-1] = NULL;
        my_edge_array[size-1] = NULL;
    }
}

bool edge_does_not_exists(My_Edge* my_edge_array[], unsigned edges_array_counter, unsigned from, unsigned to)
{
    for (unsigned i=0; i < edges_array_counter;i++)
    {
        if (my_edge_array[i]->get_from()== from && my_edge_array[i]->get_to() == to) {
            return false;
        }
    }
    return true;
}

bool deleted_node(unsigned key, My_Edge* my_edge_array[], unsigned edges_array_counter)
{
    for (unsigned i=0;i<edges_array_counter;i++)
    {
        if (my_edge_array[i]->get_from() == key || my_edge_array[i]->get_to() == key)
        {
            return false;
        }
    }
    return true;
}

int main()
{

    srand(SEED);

    unsigned node_key = 1;
    Graph_Node* nodes_array[TEST_SIZE+INITIAL_NODES_NUM] = {NULL};
    unsigned nodes_keys_array[TEST_SIZE+INITIAL_NODES_NUM] = {0};
    unsigned nodes_array_counter = 0;
    Graph_Edge* edges_array[TEST_SIZE + INITIAL_EDGES_NUM] = {NULL};
    My_Edge* my_edge_array[TEST_SIZE + INITIAL_EDGES_NUM] = {NULL};
    unsigned edges_array_counter = 0;
    unsigned operation;


    Dynamic_Graph* G = new Dynamic_Graph();
    for (unsigned i =0;i<INITIAL_NODES_NUM;i++)
    {
        nodes_array[nodes_array_counter] = G->Insert_Node(node_key);
        nodes_array_counter = nodes_array_counter + 1;
        node_key = node_key + 1;
    }
    cout<<"The out degree of node "<< nodes_array[2]->Get_key()<< " is " << nodes_array[2]->Get_out_Degree()<<"\n";
    cout<<"The in degree of node "<< nodes_array[6]->Get_key()<< " is " << nodes_array[6]->Get_in_Degree()<<"\n";
    delete G;

    for (unsigned i =0;i<INITIAL_NODES_NUM;i++)
    {
        nodes_array[i] = NULL;
    }
    node_key = 1;
    nodes_array_counter = 0;
    G = new Dynamic_Graph();

    for (unsigned i =0;i<INITIAL_NODES_NUM;i++)
    {
        nodes_array[nodes_array_counter] = G->Insert_Node(node_key);
        nodes_keys_array[nodes_array_counter] = node_key;
        nodes_array_counter = nodes_array_counter + 1;
        node_key = node_key + 1;
    }

    unsigned node_index_1;
    unsigned node_index_2;

    while(edges_array_counter < INITIAL_EDGES_NUM)
    {
        node_index_1 = generate_random_unsigned(nodes_array_counter);
        node_index_2 = generate_random_unsigned(nodes_array_counter);
        if (node_index_1 != node_index_2 && edge_does_not_exists(my_edge_array,edges_array_counter,nodes_keys_array[node_index_1],nodes_keys_array[node_index_2]))
        {
            edges_array[edges_array_counter] = G->Insert_Edge(nodes_array[node_index_1],nodes_array[node_index_2]);
            my_edge_array[edges_array_counter] = new My_Edge(nodes_keys_array[node_index_1],nodes_keys_array[node_index_2]);
            edges_array_counter = edges_array_counter + 1;
        }
    }

    unsigned edge_index;

    Rooted_Tree* T = NULL;

    for (unsigned i = 0;i < 1;i++)
    {
        operation = generate_random_unsigned(NUM_OF_OPERATIONS)+1;
        switch (5)
        {
            case STRONGLY_CONNECTED_COMPONENTS:
                G->printGraph();
                T = G->SCC();
                //T->printTree();
                break;

                cout<<"Print in layers after SCC:"<<"\n";
                T->Print_By_Layer(cout);
                cout<<"\n";
                cout<<"Preorder print after SCC:"<<"\n";
                T->Preorder_Print(cout);
                cout<<"\n";
                delete T;
                T=NULL;
                break;
        }
    }
    for (unsigned i = 0; i<edges_array_counter;i++ )
    {
        delete my_edge_array[i];
    }
    delete G;
}