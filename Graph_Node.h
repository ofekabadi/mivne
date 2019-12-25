#ifndef GRAPH_NODE_H
#define GRAPH_NODE_H

#include <cstddef>
typedef enum {SUBTRACT=0, ADD} Node_operations;

class Graph_Node
{
public:
    Graph_Node (unsigned const newKey): key(newKey), out_Degree(0), in_Degree(0),
        father(NULL), left_child(NULL), right_sibling(NULL), location(0){}
    unsigned Get_out_Degree() const {return out_Degree;}
    void Set_out_Degree(Node_operations operation);
    unsigned Get_in_Degree() const {return in_Degree;}
    void Set_in_Degree(Node_operations operation);
    inline unsigned Get_key() const {return key;};
    inline void Set_location(unsigned array_location) {location = array_location;}
    inline unsigned Get_location() {return location;}

private:
    unsigned out_Degree;
    unsigned in_Degree;
    unsigned key;
    Graph_Node* father;
    Graph_Node* left_child;
    Graph_Node* right_sibling;
    unsigned location;
};


#endif
