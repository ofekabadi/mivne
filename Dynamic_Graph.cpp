#include "Dynamic_Graph.h"

Dynamic_Graph :: ~Dynamic_Graph()
{
    /*Graph_Edge* next_edge = NULL;
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
    }*/

    Graph_Edge* front_edge = graph_edges_list.Get_head();
    while (front_edge != NULL)
    {
        Delete_Edge(front_edge);
        front_edge = graph_edges_list.Get_head();
    }

    Graph_Node* front_node = graph_nodes_list.Get_head();
    while (front_node != NULL)
    {
        Delete_Node(front_node);
        front_node = graph_nodes_list.Get_head();
    }

}

Graph_Node* Dynamic_Graph::Insert_Node(unsigned node_key)
{

    Graph_Node* new_Node = new Graph_Node (node_key);
    graph_nodes_list.Insert(new_Node);
}

void Dynamic_Graph::Delete_Node(Graph_Node* node)
{
    if(node->Get_in_Degree() == 0  && node->Get_out_Degree() == 0)
    {
        graph_nodes_list.Unlist(node);
        delete node;
    }

}

Graph_Edge* Dynamic_Graph::Insert_Edge(Graph_Node* from, Graph_Node* to)
{
    Graph_Edge *new_Graph_Edge = new Graph_Edge(from,to);
    graph_edges_list.Insert(new_Graph_Edge);

    from->Set_out_Degree(ADD);
    from->add_adj(new_Graph_Edge);
    to->Set_in_Degree(ADD);
}

void Dynamic_Graph::Delete_Edge(Graph_Edge* edge)
{
    graph_edges_list.Unlist(edge);
    edge->get_from()->remove_adj(edge);
    edge->get_from()->Set_out_Degree(SUBTRACT);
    edge->get_to()->Set_in_Degree(SUBTRACT);
    delete edge;
}


Rooted_Tree* Dynamic_Graph::SCC() const
{

}


Rooted_Tree* Dynamic_Graph::BFS(Graph_Node* source) const
{
    Rooted_Tree* tree = new Rooted_Tree;
    Tree_Node* source_node = new Tree_Node(source->Get_key());
    source->setRelatedTreeNode(source_node);
    tree->addToNodesList(source_node);

    Graph_Node_Queue Q(source);
    while (Q.Get_front() != NULL)
    {
        Graph_Node* current_node = Q.Pop();   //this is a GRAPH node
        Tree_Node* current_tree_node = current_node->getRelatedTreeNode();
        if (current_node == source)
        {
            source_node->setFather(NULL);
            tree->setSource(source_node);
        }

        Graph_Edge* adj = current_node->get_first_adj();
        while (adj != NULL)
        {
            if(adj->get_from()->getRelatedTreeNode() != NULL)
            {
                continue;               //the node has already been discovered
            }
            Tree_Node* child_node = new Tree_Node(adj->get_from()->Get_key());
            adj->get_from()->setRelatedTreeNode(child_node);
            tree->addToNodesList(child_node);
            child_node->setFather(current_tree_node);
            if (current_node == current_node->get_first_adj()->get_from())
            {
                current_tree_node->setLeftChild(child_node);
            }
            if(adj->get_prev_adj() != NULL)
            {
                adj->get_prev_adj()->get_from()->getRelatedTreeNode()->setRightSibling
                        (child_node);
            }
            Q.Push(adj->get_from());
            adj = adj->get_next_adj();
        }
        Q.Pop();
    }
    return tree;
}