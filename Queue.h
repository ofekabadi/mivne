#ifndef QUEUE_H
#define QUEUE_H

#include <cstddef>

template <class T>
class Queue
{
public:
    Queue (T front): _front(front), _end(NULL){}
    void Push(T x);
    void Pop();
    T Get_front();

private:
    T _front;
    T _end;

};


template <class T>
void Queue<T>::Push(T x)
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
void Queue<T>::Pop()
{
    _front = _front->_next;
}

template <class T>
T Queue<T>::Get_front()
{
    return _front;
}

#endif
