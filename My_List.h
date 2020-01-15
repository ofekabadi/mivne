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
    T Get_head();
    T Get_tail();

private:
    T _head;
    T _tail;
};


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
        x->_prev = _tail;
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

    if(x == _head && x == _tail)
    {
        _head = NULL;
        _tail = NULL;
    }
    else if(x == _head)
    {
        x->_next->_prev = NULL;
        _head = x->_next;
    }
    else if(x == _tail)
    {
        x->_prev->_next = NULL;
        _tail = x->_prev;
    }
    else{
        x->_prev->_next = x->_next;
        x->_next->_prev = x->_prev;
    }
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

    if(x == _head && x == _tail)
    {
        _head = NULL;
        _tail = NULL;
    }
    else if(x == _head)
    {
        x->_next_adj->_prev_adj = NULL;
        _head = x->_next_adj;
    }
    else if(x == _tail)
    {
        x->_prev_adj->_next_adj = NULL;
        _tail = x->_prev_adj;
    }
    else{
        x->_prev_adj->_next_adj = x->_next;
        x->_next_adj->_prev_adj = x->_prev;
    }


    if (x == NULL)
    {
        return;
    }
}


template <class T>
T  My_List<T>::Get_head()
{
    return _head;
}


template <class T>
T  My_List<T>::Get_tail()
{
    return _tail;
}


#endif