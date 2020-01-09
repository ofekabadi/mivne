#ifndef QUEUE_H
#define QUEUE_H

#include <cstddef>

template <class T>
class My_Queue
{
public:
    My_Queue (T front = NULL): _front(front), _end(front){}
    void Push(T x);
    T Pop();
    T Get_front();

private:
    T _front;
    T _end;

};


template <class T>
void My_Queue<T>::Push(T x)
{
    if (x == NULL)
    {
        return;
    }

    if(_front == NULL && _end==NULL)
    {
        _front = x;
        _end = x;
    }
    else
    {
        _end->_next = x;
        _end = x;
    }
}

template <class T>
T My_Queue<T>::Pop()
{
    T poped = _front;
    _front = _front->_next;
    return poped;
}

template <class T>
T My_Queue<T>::Get_front()
{
    return _front;
}

#endif
