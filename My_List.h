#ifndef LIST_H
#define LIST_H

#include <cstddef>

template <class T>
class My_List
{
public:
    My_List (T head = NULL): _head(head), _tail(head){}
    void Insert(T x);
    void Unlist(T x);
    void Adj_insert(T x);
    void Adj_unlist(T x);

private:
    T _head;
    T _tail;
};

#endif


template <class T>
void My_List<T>::Insert(T x)
{
    if (x == NULL)
    {
        return;
    }

    if(_head == NULL && _tail==NULL)
    {
        _head = x;
        _tail = x;
    }
    else
    {
        _tail->_next = x;
        _tail = x;
    }
}


template <class T>
void My_List<T>::Unlist(T x)
{
    if (x == NULL)
    {
        return;
    }

    x->Get_next()->Set_prev(x->Get_prev());
    x->Get_prev()->Set_next(x->Get_next());
}  //does not delete!!!


template <class T>
void My_List<T>::Adj_insert(T x)
{
    if (x == NULL)
    {
        return;
    }

    if(_head == NULL && _tail==NULL)
    {
        _head = x;
        _tail = x;
    }
    else
    {
        _tail->_next_adj = x;
        _tail = x;
    }
}


template <class T>
void My_List<T>::Adj_unlist(T x)   //does not delete!!!
{
    if (x == NULL)
    {
        return;
    }

    x->_next_adj->_prev_adj = x->_prev_adj;
    x->_prev_adj->_next_adj = x->_next_adj;
    delete x;
}