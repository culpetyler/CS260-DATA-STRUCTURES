#pragma once
#ifndef _QUEUE_H
#define _QUEUE_H

#include <stdexcept>

template <typename T> class Queue
{
private:
    struct Node
    {
        T value;
        struct Node *next;
    };

    Node *first;
    Node *last;
    uint32_t _size;

public:
    uint32_t size();
    void enqueue(T value);
    T dequeue();
    T peek();

    Queue();
    ~Queue();
};

template <typename T> uint32_t Queue<T>::size()
{
    return _size;
}

template <typename T> void Queue<T>::enqueue(T value)
{
    Node *node = new Node;
    node->value = value;
    node->next = nullptr;

    if (first == nullptr) // enqueue first value
    {
        first = node;
        last = node;
    }
    else // change last value to point to new value
    {
        last->next = node;
        last = node;
    }
    ++_size;
}

template <typename T> T Queue<T>::dequeue()
{
    if (first == nullptr) // if trying to dequeue with nothing in queue
    {
        throw std::out_of_range("Tried to remove value from empty queue.");
    }

    Node *next = first->next;
    T value = first->value;

    delete first;
    first = next;

    --_size;
    return value;
}

template <typename T> T Queue<T>::peek()
{
    if (first == nullptr)
    {
        return (T)NULL;
    }
    else
    {
        return first->value;
    }
}

template <typename T> Queue<T>::Queue()
{
    first = nullptr;
    last = nullptr;
    _size = 0;
}

template <typename T> Queue<T>::~Queue()
{
    if (_size > 0)
    {
        Node *next = nullptr;
        for (uint32_t i = 0; i < _size; ++i)
        {
            next = first;
            first = first->next;

            delete next;
        }
    }
}

#endif