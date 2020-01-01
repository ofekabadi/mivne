#ifndef GRAPH_NODE_H
#define GRAPH_NODE_H

#include <cstddef>
typedef enum {SUBTRACT=0, ADD} Node_operations;

class Graph_Node
{
public:
    Graph_Node (unsigned newKey): _key(newKey), _out_Degree(0), _in_Degree(0),  _next
    (NULL), _prev(NULL){}

    inline unsigned Get_key() const {return _key;};

    inline unsigned Get_out_Degree() const {return _out_Degree;}
    inline unsigned Get_in_Degree() const {return _in_Degree;}
    void Set_out_Degree(Node_operations operation);
    void Set_in_Degree(Node_operations operation);


    inline Graph_Node* Get_next() {return _next;}
    inline Graph_Node* Get_prev() {return _prev;}
    inline void Set_next(Graph_Node* next) {_next=next;}
    inline void Set_prev(Graph_Node* prev) {_prev=prev;}





private:
    unsigned _out_Degree;
    unsigned _in_Degree;
    unsigned _key;
    Graph_Node* _next;
    Graph_Node* _prev;


};


#endif
