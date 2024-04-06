#include <iostream>

#include "queue.hpp"

int main()
{
    Queue<int> q;
    
    int i;
    for (i = 1; i <= 10; ++i)
    {
        std::cout << "Adding [" << i << "] to the queue!" << std::endl;
        q.enqueue(i);
    }

    for (int i = 1; i <= 5; ++i)
    {
        std::cout << "Removing [" << q.dequeue() << "] from the queue!" << std::endl;
    }

    std::cout << "Peeking at the next value of [" << q.peek() << "] in the queue!" << std::endl;

    for (int i = 1; i <= 5; ++i)
    {
        std::cout << "Removing [" << q.dequeue() << "] from the queue!" << std::endl;
    }

    Queue<const char*> s;
    s.enqueue("Hello");
    s.enqueue("World!");
    s.enqueue("How");
    s.enqueue("are");
    s.enqueue("you");
    s.enqueue("doing");
    s.enqueue("today?");

    for (; s.peek() != nullptr; s.dequeue())
    {
        std::cout << s.peek() << " ";
    }
    std::cout << std::endl;

    if (s.size() == NULL)
    {
        std::cout << "Queue is now empty!" << std::endl;
    }
    else
    {
        std::cout << "Queue still has " << s.size() << " values left!" << std::endl;
    }

    return 0;
};