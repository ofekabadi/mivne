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
        //std::cout<<graph_nodes_list.Get_head()
        //->Get_key()<<std::endl;

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
    Graph_Edge *new_Graph_Edge = new Graph_Edge(from, to);
    graph_edges_list.Insert(new_Graph_Edge);

    from->Set_out_Degree(ADD);
    from->add_adj(new_Graph_Edge, FROM);
    //std::cout<<"**test " <<from->get_first_adj()->get_from()->Get_key();
    to->Set_in_Degree(ADD);
    to->add_adj(new_Graph_Edge, TO);
    //std::cout<<"nodes from: "<< from->Get_key()<< " to: "<< to->Get_key()<<std::endl;
    //std::cout<<"edge from: "<< new_Graph_Edge->get_from()->Get_key()<< " to: "<<
    //new_Graph_Edge->get_to()->Get_key()<<std::endl;
}

void Dynamic_Graph::Delete_Edge(Graph_Edge* edge)
{
    graph_edges_list.Unlist(edge);
    edge->get_from()->remove_adj(edge,FROM);
    edge->get_to()->remove_adj(edge,TO);
    edge->get_from()->Set_out_Degree(SUBTRACT);
    edge->get_to()->Set_in_Degree(SUBTRACT);
    delete edge;
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
        //cout<<"Q size: "<<Q.Get_size()<<endl;
        Graph_Node* current_node = Q.Get_front();   //this is a GRAPH node
        Tree_Node* current_tree_node = current_node->getRelatedTreeNode();
        //cout<<"**current graph node: "<<current_node->Get_key()<<endl;
        cout<<"**current tree node: "<<current_tree_node->get_tree_key()<<endl;
        if (current_node == source)
        {
            source_node->setFather(NULL);
            tree->setSource(source_node);
        }

        Graph_Edge* adjPrint = current_node->get_first_adj();
       cout<<"adj list of "<<adjPrint->get_from()->Get_key()<<": "<<endl;
        while (adjPrint != NULL)
        {
            cout<<adjPrint->get_to()->Get_key()<<", ";
            adjPrint = adjPrint->get_prev_adj();
        }
        cout<<endl;

        Graph_Edge* adj = current_node->get_first_adj();
        Tree_Node* left_sibling = NULL;
        while (adj != NULL)
        {

            if(adj->get_to()->getRelatedTreeNode() != NULL)
            {
              //cout<<"**if"<<endl<<endl;
                adj = adj->get_prev_adj();
                continue;              //the node has already been discovered
            }
            Tree_Node* child_node = new Tree_Node(adj->get_to()->Get_key());
            adj->get_to()->setRelatedTreeNode(child_node);
            tree->addToNodesList(child_node);

           //cout<<"**current adj: "<<adj->get_to()->Get_key()<<endl;
            //cout<<"**current graph node child: "<<child_node->get_tree_key()<<endl;


            child_node->setFather(current_tree_node);
            if (adj == current_node->get_first_adj() || current_tree_node->getLeftChild
            () == NULL)
            {
                current_tree_node->setLeftChild(child_node);
            }

            if(left_sibling != NULL)
            {
                left_sibling->setRightSibling(child_node);
            }
            left_sibling = child_node;


            Q.Push(adj->get_to());
            adj = adj->get_prev_adj();
            if(adj == NULL)
            {
                //cout<<"***"<<endl<<endl;
            }
        }

        Q.Pop();
    }
    return tree;
}





Rooted_Tree* Dynamic_Graph::SCC()
{
    Rooted_Tree* SCC_tree = new Rooted_Tree;
    Tree_Node* root_node = new Tree_Node(0);

    SCC_tree->setSource(root_node);
    //DFS();
    return DFS();


}

Rooted_Tree*  Dynamic_Graph::DFS()
{
    //visitedInitialiser();
    Rooted_Tree* tree = new Rooted_Tree;
    Tree_Node* root_node = new Tree_Node(graph_nodes_list.Get_head()->Get_key());
    tree->addToNodesList(root_node);
    tree->setSource(root_node);
    Graph_Node * node_dfs = graph_nodes_list.Get_head();
    while (node_dfs != NULL)
        {
            node_dfs->node_color = white;
            root_node->setFather(NULL);
            node_dfs = node_dfs->Get_next();

        }
    time = 0;
    node_dfs = graph_nodes_list.Get_head();
    while (node_dfs != NULL)
        {
            if(node_dfs->node_color == white)
            {
                DFS_Visit(tree,root_node, graph_nodes_list.Get_head());
            }
            node_dfs = node_dfs->Get_next();
        }
    return tree;
}
/*
void Dynamic_Graph::visitedInitialiser()
{
    Graph_Node* front_node = graph_nodes_list.Get_head();
    while (front_node != NULL)
    {
        front_node->setDfsVisited(false);
        front_node = front_node->Get_next();
    }
}
*/
void Dynamic_Graph::DFS_Visit(Rooted_Tree* tree,Tree_Node* treeFatherNode, Graph_Node*
graphFatherNode)
{/*
    Graph_Edge* adj = graphFatherNode->get_first_adj();
    while (adj != NULL)
    {
        Tree_Node* treeNode = new Tree_Node(adj->get_from()->Get_key());
        treeNode->setFather(treeFatherNode);
        DFS_Visit(treeNode, adj->get_from());
    }*/
Graph_Edge* adj = graphFatherNode->get_first_adj();
Tree_Node* treeNode = new Tree_Node(adj->get_to()->Get_key());
time++;
graphFatherNode->node_discovery = time;
graphFatherNode->node_color = grey;
    while (adj != NULL)
    {

        if(adj->get_to()->node_color == white)
        {
           treeNode->setFather(treeFatherNode);
           DFS_Visit(tree,treeNode,adj->get_to());
           tree->addToNodesList(treeNode);
           std::cout<<"tin loop"<<std::endl;
           return;
        }

        adj = adj->get_next();
    }
    graphFatherNode->node_color = black;
    time++;
    graphFatherNode->node_f = time;
    retraction_time_list.Insert(graphFatherNode);



}

/*
Rooted_Tree*  Dynamic_Graph::Reverse_DFS()
{
    //visitedInitialiser();
    Rooted_Tree* tree = new Rooted_Tree;
    Tree_Node* root_node = new Tree_Node(graph_nodes_list.Get_head()->Get_key());
    tree->addToNodesList(root_node);
    tree->setSource(root_node);
    Graph_Node * node_dfs = retraction_time_list.Get_tail();
    while (node_dfs != NULL)
    {
        node_dfs->node_color = white;
        root_node->setFather(NULL);

        node_dfs = node_dfs->Get_prev();
    }
    time = 0;
    node_dfs = retraction_time_list.Get_tail();
    while (node_dfs != NULL)
    {
        if(node_dfs->node_color == white)
        {
            tree->addToNodesList( DFS_Visit(root_node, node_dfs));
        }
        node_dfs = node_dfs->Get_prev();
    }
    return tree;
}*/
/*
void Dynamic_Graph::visitedInitialiser()
{
    Graph_Node* front_node = graph_nodes_list.Get_head();
    while (front_node != NULL)
    {
        front_node->setDfsVisited(false);
        front_node = front_node->Get_next();
    }
}
*/
/*
Tree_Node* Dynamic_Graph::Reverse_DFS_Visit(Tree_Node* treeFatherNode, Graph_Node*
graphFatherNode)
{*//*
    Graph_Edge* adj = graphFatherNode->get_first_adj();
    while (adj != NULL)
    {
        Tree_Node* treeNode = new Tree_Node(adj->get_from()->Get_key());
        treeNode->setFather(treeFatherNode);
        DFS_Visit(treeNode, adj->get_from());
    }*//*
    Graph_Edge* adj = graphFatherNode->get_first_adj();
    Tree_Node* treeNode = new Tree_Node(adj->get_to()->Get_key());
    time++;
    graphFatherNode->node_discovery = time;
    graphFatherNode->node_color = grey;
    while (adj != NULL)
    {

        if(adj->get_from()->node_color == white)
        {
            treeNode->setFather(treeFatherNode);
            DFS_Visit(treeNode,adj->get_to());
            return treeNode;
        }
        adj = adj->get_next();
    }
    graphFatherNode->node_color = black;
    time++;
    graphFatherNode->node_f = time;



}
*/