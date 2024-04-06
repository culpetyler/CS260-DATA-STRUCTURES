#include <iostream>

#include "linkedlist.hpp"

int main()
{
    LinkedList<const char*> l;

    l.add("Burger");
    l.add("Chicken Thighs");
    l.add("Pizza");
    for (int i = 0; i < l.size(); ++i)
    {
        std::cout << "Item: [" << i << ", " << l.get(i) << "]" << std::endl;
    }
    
    l.add("'Nanners", 1);
    for (int i = 0; i < l.size(); ++i)
    {
        std::cout << "Item: [" << i << ", " << l.get(i) << "]" << std::endl;
    }

    std::cout << "Size: " << l.size() << std::endl;
    l.remove(0);
    l.remove(l.size() - 1);
    for (int i = 0; i < l.size(); ++i)
    {
        std::cout << "Item: [" << i << ", " << l.get(i) << "]" << std::endl;
    }

    return 0;
}