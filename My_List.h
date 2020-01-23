#ifndef LIST_H
#define LIST_H

#include <cstddef>

#include <iostream> //!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

template <class T>
class My_List
{
public:
    My_List (T head = NULL): _head(head), _tail(head){}

    void Insert(T x);
    void Unlist(T x);

    void Adj_from_insert(T x);
    void Adj_to_insert(T x);
    void Adj_from_unlist(T x);
    void Adj_to_unlist(T x);

    void Insert_retraction(T x);
    void Unlist_retraction(T x);

    T Get_head() const;
    T Get_tail() const;

private:
    T _head;
    T _tail;
};


template <class T>
void My_List<T>::Insert_retraction(T x)
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
        _tail->_retractionNext = x;
        x->_retractionPrev = _tail;
        _tail = x;
    }
}


template <class T>
void My_List<T>::Unlist_retraction(T x)
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
        _head = x->_retractionNext;
        x->_retractionNext->_retractionPrev = NULL;
    }
    else if(x == _tail)
    {
        x->_retractionPrev->_retractionNext = NULL;
        _tail = x->_retractionPrev;
    }
    else{
        x->_retractionPrev->_retractionNext = x->_retractionNext;
        x->_retractionNext->_retractionPrev = x->_retractionPrev;
    }

    x->_retractionNext = NULL;
    x->_retractionPrev = NULL;
}  //does not delete!!!

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
        _head = x->_next;
        x->_next->_prev = NULL;
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

    x->_next = NULL;
    x->_prev = NULL;
}  //does not delete!!!


template <class T>
void My_List<T>::Adj_from_insert(T x)
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
        _tail->_next_adj_from = x;
        x->_prev_adj_from = _tail;
        _tail = x;
    }
}

template <class T>
void My_List<T>::Adj_to_insert(T x)
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
        _tail->_next_adj_to = x;
        x->_prev_adj_to = _tail;
        _tail = x;
    }
}

template <class T>
void My_List<T>::Adj_from_unlist(T x)   //does not delete!!!
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
        x->_next_adj_from->_prev_adj_from = NULL;
        _head = x->_next_adj_from;
    }
    else if(x == _tail)
    {
        x->_prev_adj_from->_next_adj_from = NULL;
        _tail = x->_prev_adj_from;

    }
    else{
        x->_next_adj_from->_prev_adj_from = x->_prev_adj_from;
        x->_prev_adj_from->_next_adj_from = x->_next_adj_from;
    }

    x->_next_adj_from = NULL;
    x->_prev_adj_from = NULL;
}

template <class T>
void My_List<T>::Adj_to_unlist(T x)   //does not delete!!!
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
        x->_next_adj_to->_prev_adj_to = NULL;
        _head = x->_next_adj_to;
    }
    else if(x == _tail)
    {
        x->_prev_adj_to->_next_adj_to = NULL;
        _tail = x->_prev_adj_to;

    }
    else{
        x->_next_adj_to->_prev_adj_to = x->_prev_adj_to;
        x->_prev_adj_to->_next_adj_to = x->_next_adj_to;
    }

    x->_next_adj_to = NULL;
    x->_prev_adj_to = NULL;
}

template <class T>
T  My_List<T>::Get_head() const
{
    return _head;
}


template <class T>
T  My_List<T>::Get_tail() const
{
    return _tail;
}


#endif