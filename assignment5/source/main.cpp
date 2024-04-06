#include <iostream>
#include <array>
#include <random>
#include <chrono>

#include "linkedlist.hpp"

int main()
{
    LinkedList<uint64_t> c;

    std::chrono::duration<long, std::nano> seed = std::chrono::high_resolution_clock::now().time_since_epoch();
    std::mt19937_64 mt64(seed.count());
    
    for (uint16_t i = 0; i < 10000; ++i)
    {
        c.add(mt64());
    }

    auto start = std::chrono::high_resolution_clock::now();

    c.sort();

    auto finish = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> elapsed = finish - start;

    std::string l = std::to_string(c.get(c.size()-1));
    std::string m;

    printf("[\n  ");
    for (uint16_t i = 0; i < 10000; ++i)
    {
        m = std::to_string(c.get(i));
        printf("%s%s", std::string(l.length() - m.length(), ' ').c_str(), m.c_str());
        if (i != 9999)
        {
            printf(", ");
            if (i && i % 5 == 4) printf("\n  ");
        }
        else printf("\n");
    }
    printf("]\n\n");
    std::cout << "Sort Time: " << elapsed.count() / 1000 << " seconds\n" << std::endl;
    
    return 0;
}