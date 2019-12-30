#ifndef GRAPH_NODE_H
#define GRAPH_NODE_H

#include <cstddef>
typedef enum {SUBTRACT=0, ADD} Node_operations;

class Graph_Node
{
public:
    Graph_Node (unsigned newKey): key(newKey), out_Degree(0), in_Degree(0),
    father(NULL), left_child(NULL), right_sibling(NULL), _next(NULL), _prev(NULL){}

    inline unsigned Get_key() const {return key;};

    inline unsigned Get_out_Degree() const {return out_Degree;}
    inline unsigned Get_in_Degree() const {return in_Degree;}
    void Set_out_Degree(Node_operations operation);
    void Set_in_Degree(Node_operations operation);


    inline Graph_Node* Get_next() {return _next;}
    inline Graph_Node* Get_prev() {return _prev;}
    inline void Set_next(Graph_Node* next) {_next=next;}
    inline void Set_prev(Graph_Node* prev) {_prev=prev;}





private:
    unsigned out_Degree;
    unsigned in_Degree;
    unsigned key;
    Graph_Node* father;
    Graph_Node* left_child;
    Graph_Node* right_sibling;
    Graph_Node* _next;
    Graph_Node* _prev;
};


#endif
