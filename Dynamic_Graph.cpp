#include "Dynamic_Graph.h"

unsigned Dynamic_Graph::time = 0;
Node_List Dynamic_Graph::retraction_time_list(NULL);

Dynamic_Graph::~Dynamic_Graph()
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
    DFS_Initialize(graph_nodes_list, REVERSED);
    Rooted_Tree* tree = new Rooted_Tree;
    Tree_Node* source_node = new Tree_Node(source->Get_key());
    source->setRelatedTreeNode(source_node);
    tree->addToNodesList(source_node);

    Graph_Node_Queue Q(source);
    while (Q.Get_front() != NULL)
    {
        Graph_Node* current_node = Q.Get_front();   //this is a GRAPH node
        Tree_Node* current_tree_node = current_node->getRelatedTreeNode();
        if (current_node == source)
        {
            source_node->setParent(NULL);
            tree->setSource(source_node);
        }

        Graph_Edge* adj = current_node->get_first_adj();
        Tree_Node* left_sibling = NULL;
        while (adj != NULL)
        {
            if(adj->get_to()->getRelatedTreeNode() != NULL)
            {
                adj = adj->get_prev_adj();
                continue;
            }
            Tree_Node* child_node = new Tree_Node(adj->get_to()->Get_key());
            adj->get_to()->setRelatedTreeNode(child_node);
            tree->addToNodesList(child_node);

            child_node->setParent(current_tree_node);
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
        }

        Q.Pop();
    }
    return tree;
}



Rooted_Tree* Dynamic_Graph::SCC() const
{
   Rooted_Tree* first_tree = DFS(graph_nodes_list, REGULAR);
   cout<<"first:"<<endl;

   first_tree->printTree();

    Graph_Node* node = retraction_time_list.Get_tail();
    cout<<"ret time order:"<<endl;
    while(node!=NULL)
    {
        cout<<"key: "<<node->Get_key()<<", ";
        node = node->Get_retraction_prev();
    }
    cout<<endl<<endl;

    Rooted_Tree* SCC_tree = DFS(retraction_time_list, REVERSED);


    cout<<"second:"<<endl;
    SCC_tree->printTree();

    delete first_tree;
    return SCC_tree;
}

Rooted_Tree*  Dynamic_Graph::DFS(Node_List nodes_order, DFS_Type dfsType) const
{
    DFS_Initialize(nodes_order, dfsType);
    Rooted_Tree* tree = new Rooted_Tree;
    Tree_Node* source_node = new Tree_Node(0);
    tree-> setSource(source_node);
    tree->addToNodesList(source_node);
    Dynamic_Graph::time = 0;
    Graph_Node* currentNode = nodes_order.Get_tail();
    while(currentNode != NULL)
    {
        cout<<"**"<<endl;
        if(currentNode->getRelatedTreeNode() == NULL)
        {
            cout<<"**curr node key "<<currentNode->Get_key()<<endl;
            DFS_Visit(tree, currentNode, source_node, dfsType);
        }
        switch (dfsType)
        {
            case REGULAR:
                currentNode = currentNode->Get_prev();
            case REVERSED:
                currentNode = currentNode->Get_retraction_prev();
        }
    }
    return tree;
}

Tree_Node* Dynamic_Graph::DFS_Visit(Rooted_Tree* tree, Graph_Node* graphNode, Tree_Node*
parent, DFS_Type dfsType) const
{
    Dynamic_Graph::time++;
    Tree_Node* treeNode = new Tree_Node(graphNode->Get_key());
    treeNode->setDfsDiscovery(time);
    treeNode->setDfsColor(GREY);
    treeNode->setParent(parent);
    graphNode->setRelatedTreeNode(treeNode);
    tree->addToNodesList(treeNode);

    cout<<"**DFS_Visit of node "<<treeNode->get_tree_key()<<", "<<graphNode->Get_key()
    <<endl;

    switch (dfsType)
    {
        case REGULAR:
            if( graphNode->get_first_adj() != NULL)
            {
                Graph_Edge* adj = graphNode->get_first_adj();
                Tree_Node* left_sibling = NULL;
                while(adj != NULL)
                {
                    if(adj->get_to()->getRelatedTreeNode() == NULL)
                    {
                        Tree_Node* child = DFS_Visit(tree, adj->get_to(), treeNode,
                                                     REGULAR);
                        if(adj == graphNode->get_first_adj() || treeNode->getLeftChild
                                () == NULL)
                        {
                            treeNode->setLeftChild(child);
                        }

                        if(left_sibling != NULL)
                        {
                            left_sibling->setRightSibling(child);
                        }
                        left_sibling = child;
                    }
                    adj = adj->get_prev_adj();
                }
            }
            break;

        case REVERSED:
            if( graphNode->get_first_adj_to() != NULL)
            {
                Graph_Edge* adj = graphNode->get_first_adj_to();
                Tree_Node* left_sibling = NULL;
                while(adj != NULL)
                {
                    cout<<"##"<<endl;
                    if(adj->get_from()->getRelatedTreeNode() == NULL)
                    {
                        Tree_Node* child = DFS_Visit(tree, adj->get_from(), treeNode,
                                                     REVERSED);

                        if(adj == graphNode->get_first_adj_to())
                        {
                            treeNode->setLeftChild(child);
                        }
                        if(left_sibling != NULL)
                        {
                            left_sibling->setRightSibling(child);
                        }

                        left_sibling = child;
                    }
                    adj = adj->get_prev_adj_to();
                }
            }
            break;
    }


    treeNode->setDfsColor(BLACK);
    Dynamic_Graph::time++;
    treeNode->setDfsRetraction(time);
    if(dfsType == REGULAR)
    {
        retraction_time_list.Insert_retraction(graphNode);
    }

    return treeNode;
}



void Dynamic_Graph::DFS_Initialize(Node_List nodes_oreder, DFS_Type dfsType) const
{
    Graph_Node* front_node = nodes_oreder.Get_head();
    if(dfsType == REGULAR)
    {
        while (front_node != NULL)
        {
            front_node->setRelatedTreeNode(NULL);
            front_node = front_node->Get_next();
        }
        return;
    }
    if(dfsType == REVERSED)
    {
        while (front_node != NULL)
        {
            front_node->setRelatedTreeNode(NULL);
            front_node = front_node->Get_retraction_next();
        }
        return;
    }
}

void Dynamic_Graph::printGraph() const
{
    cout << "nodes:" << endl;
    Graph_Node *nodePrint = graph_nodes_list.Get_tail(); //from newest to oldest
    while (nodePrint != NULL) {
        cout << "node key: " << nodePrint->Get_key() << endl;
        nodePrint = nodePrint->Get_prev();
    }

    cout << endl << "edges:" << endl;
    Graph_Edge *edgePrint = graph_edges_list.Get_tail();   //from newest to oldest
    while (edgePrint != NULL) {
        cout << "edge from: " << edgePrint->get_from()->Get_key() << " to: " <<
             edgePrint->get_to()->Get_key() << endl;
        edgePrint = edgePrint->get_prev();
    }

    cout << endl << "adj lists:" << endl;
    Graph_Node *currNode = graph_nodes_list.Get_tail();
    while(currNode != NULL)
    {
        Graph_Edge *adjPrint =currNode->get_first_adj();
        cout << "adj list of " << currNode->Get_key() << ": ";
        while (adjPrint != NULL) {
            cout << adjPrint->get_to()->Get_key() << ", ";
            adjPrint = adjPrint->get_prev_adj();
        }
        cout << endl;
        currNode = currNode->Get_prev();
    }

    cout << endl << "end of graph" << endl << endl;
}
