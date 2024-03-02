#pragma once
#ifndef _MARBLEBAG_H_
#define _MARBLEBAG_H_

#include <cstdint>
#include <iostream>
#include <map>
#include <vector>

class MarbleBag {
private:
    uint32_t marbles_max;
    uint32_t marbles_count;

    std::vector<const char*> colors;
    std::vector<const char*> designs;
    std::map<uint16_t, uint32_t> marbles;

public:
    MarbleBag(std::vector<const char*> colors, std::vector<const char*> designs, uint32_t marbles_max);
    ~MarbleBag();

    void addMarble(uint32_t count, uint16_t style);
    void removeMarble(uint32_t count, uint16_t style);
    void printMarbles();
};

#endif