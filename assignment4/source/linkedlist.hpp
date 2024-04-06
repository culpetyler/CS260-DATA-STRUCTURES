#pragma once
#ifndef _LINKEDLIST_H
#define _LINKEDLIST_H

#include <stdexcept>

template <typename T> class LinkedList
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
    void add(T value, uint32_t index = NULL);
    T remove(uint32_t index = NULL);
    T get(uint32_t index = NULL);

    LinkedList();
    ~LinkedList();
};

template <typename T> uint32_t LinkedList<T>::size()
{
    return _size;
}

template <typename T> void LinkedList<T>::add(T value, uint32_t index)
{
    if (index > _size) // if add index is larger than LinkedList size, throw exception early
    {
        throw std::out_of_range("Tried to insert value at index out of range of LinkedList.");
    }

    Node *node = new Node;
    node->value = value;
    node->next = nullptr;

    if (first == nullptr) // add first value
    {
        first = node;
        last = node;

        ++_size;
        return;
    }

    if (index == NULL) // add onto end of LinkedList by setting index to last
    {
        last->next = node;
        last = node;
    }
    else // iterate to index, add value pointing to next value, change previous value to point to new value
    {
        Node *pre = nullptr;
        Node *cur = first;

        for (uint32_t i = 0; i <= index; ++i)
        {
            if (i < index)
            {
                pre = cur;
                cur = cur->next;
                continue;
            }
            else
            {
                node->next = cur;
                pre->next = node;
            }
        }
    }
    ++_size;
}

template <typename T> T LinkedList<T>::remove(uint32_t index)
{
    if (index >= _size) // if remove index is larger than LinkedList size, throw exception early
    {
        throw std::out_of_range("Tried to remove value at index out of range of LinkedList.");
    }
    else if (first == nullptr || _size == 0) // if trying to remove with nothing in LinkedList
    {
        throw std::out_of_range("Tried to remove value from empty LinkedList.");
    }

    Node *next;
    T value;

    if (index == NULL)
    {
        next = first->next;
        value = first->value;

        delete first;
        first = next;

        --_size;
        return value;
    }
    else
    {
        Node *pre = nullptr;
        Node *cur = first;

        for (uint32_t i = 0; i <= index; ++i)
        {
            if (i < index)
            {
                pre = cur;
                cur = cur->next;
                continue;
            }
            else
            {
                if (cur->next == nullptr) // if last or only value
                {
                    last = cur;

                    next = cur->next;
                    value = cur->value;

                    delete cur;
                    cur = next;

                    --_size;
                    return value;
                }
                else
                {
                    if(index == 0) first = cur->next;
                    
                    pre->next = cur->next;
                    value = cur->value;

                    delete cur;
                    cur = nullptr;

                    --_size;
                    return value;
                }
            }
        }
    }
    return (T)NULL;
}

template <typename T> T LinkedList<T>::get(uint32_t index)
{
    if (index >= _size) // if get index is larger than LinkedList size, throw exception early
    {
        throw std::out_of_range("Tried to get at value of index out of range of LinkedList.");
    }

    if (index == NULL)
    {
        return first->value;
    }

    Node *pre = nullptr;
    Node *cur = first;

    for (uint32_t i = 0; i <= index; ++i)
    {
        if (i < index)
        {
            pre = cur;
            cur = cur->next;
            continue;
        }
        else
        {
            return cur->value;
        }
    }
    return (T)NULL;
}

template <typename T> LinkedList<T>::LinkedList()
{
    first = nullptr;
    last = nullptr;
    _size = 0;
}

template <typename T> LinkedList<T>::~LinkedList()
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