#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>  //!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
#include <cstddef>

template <class T>
class My_Queue
{
public:
    My_Queue (T front = NULL): _front(front), _end(front), _qSize(0){}
    void Push(T x);
    T Pop();
    T Get_front();
    unsigned Get_size();
    unsigned printQ();


private:
    T _front;
    T _end;
    unsigned _qSize;
};


template <class T>
void My_Queue<T>::Push(T x)
{
    if (x == NULL)
    {
        return;
    }

    if(_front == NULL)
    {
        _front = x;
        _end = x;
    }
    else
    {
        _end->_qNext = x;
        x->_qPrev = _end;
        _end = x;
    }
    _qSize++;
}

template <class T>
T My_Queue<T>::Pop()
{
    if(_end == NULL)
    {
        return NULL;
    }

    T poped = _front;

   if(_front == _end)
    {
        _front->_qNext = NULL;
        _front->_qPrev = NULL;
        _front = NULL;
        _end = NULL;

        return poped;
    }


    _front = _front->_qNext;
    poped->_qNext = NULL;
    _front->_qPrev = NULL;
    _qSize--;
    return poped;
}

template <class T>
T My_Queue<T>::Get_front()
{
    return _front;
}

template <class T>
unsigned My_Queue<T>::Get_size()
{
    return _qSize;
}

template <class T>
unsigned My_Queue<T>::printQ()
{
   // std::cout<<std::endl<<"Q print: "<<std::endl;
    T print = _front;
    while(print != NULL)
    {
        std::cout<<print->get_tree_key()<<", ";
        print = print->_qNext;
    }
    std::cout<<std::endl;
}

#endif
