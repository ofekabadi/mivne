#ifndef GRAPH_EDGE_H
#define GRAPH_EDGE_H

#include <cstddef>
#include "My_List.h"

class Graph_Node; //forward declaration

class Graph_Edge {
public:
    Graph_Edge(Graph_Node* from, Graph_Node* to):_from(from), _to(to), _next(NULL) ,
    _prev(NULL), _next_adj(NULL), _prev_adj(NULL){};
    Graph_Node* get_from() const {return _from;}
    Graph_Node* get_to() const {return _to;}

    inline void set_next (Graph_Edge * next){_next = next;}
    inline void set_prev (Graph_Edge * prev){_prev = prev;}
    inline Graph_Edge* get_next() const {return _next;}
    inline Graph_Edge* get_prev (){return _prev;}
    inline Graph_Edge* get_prev_adj() const {return _prev_adj;}
    inline Graph_Edge* get_next_adj() const {return _next_adj;}

    template <typename T> friend class My_List;

private:
    Graph_Node* _from;
    Graph_Node* _to;
    Graph_Edge* _next;
    Graph_Edge* _prev;
    Graph_Edge* _next_adj;
    Graph_Edge* _prev_adj;
};



#endif
