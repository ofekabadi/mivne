#include "Dynamic_Graph.h"

Dynamic_Graph :: ~Dynamic_Graph()
{
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
    return new_Node;
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
    //std::cout<<"**test " <<from->get_first_adj()->get_from()->Get_key();
    to->Set_in_Degree(ADD);
    //std::cout<<"nodes from: "<< from->Get_key()<< " to: "<< to->Get_key()<<std::endl;
    //std::cout<<"edge from: "<< new_Graph_Edge->get_from()->Get_key()<< " to: "<<
    //new_Graph_Edge->get_to()->Get_key()<<std::endl;
}

void Dynamic_Graph::Delete_Edge(Graph_Edge* edge)
{
    graph_edges_list.Unlist(edge);
    edge->get_from()->remove_adj(edge);
    edge->get_from()->Set_out_Degree(SUBTRACT);
    edge->get_to()->Set_in_Degree(SUBTRACT);
    delete edge;
}


Rooted_Tree* Dynamic_Graph::SCC()
{

}


Rooted_Tree*  Dynamic_Graph::DFS()
{
    visitedInitialiser();
    Rooted_Tree* tree = new Rooted_Tree;
    Tree_Node* root_node = new Tree_Node(graph_nodes_list.Get_head()->Get_key());
    tree->addToNodesList(root_node);
    tree->setSource(root_node);

    DFS_Visit(root_node, graph_nodes_list.Get_head());

}

void Dynamic_Graph::visitedInitialiser()
{
    Graph_Node* front_node = graph_nodes_list.Get_head();
    while (front_node != NULL)
    {
        front_node->setDfsVisited(false);
        front_node = front_node->Get_next();
    }
}

Rooted_Tree*  Dynamic_Graph::DFS_Visit(Tree_Node* treeFatherNode, Graph_Node*
graphFatherNode)
{
    Graph_Edge* adj = graphFatherNode->get_first_adj();
    while (adj != NULL)
    {
        Tree_Node* treeNode = new Tree_Node(adj->get_from()->Get_key());
        treeNode->setFather(treeFatherNode);
        DFS_Visit(treeNode, adj->get_from());
    }
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
                adj = adj->get_prev_adj();
                std::cout<<"**in if"<<std::endl;
                continue;              //the node has already been discovered
            }
            Tree_Node* child_node = new Tree_Node(adj->get_from()->Get_key());
            adj->get_from()->setRelatedTreeNode(child_node);
            tree->addToNodesList(child_node);
            child_node->setFather(current_tree_node);
            std::cout<<"**in bfs"<<std::endl;
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
            adj = adj->get_prev_adj();

            std::cout<<"**curr adj"<<adj->get_from()->Get_key()<<std::endl;
        }
        Q.Pop();
    }
    return tree;
}

