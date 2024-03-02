#include "marblebag.h"

MarbleBag::MarbleBag(std::vector<const char*> colors, std::vector<const char*> designs, uint32_t marbles_max) : colors(colors), designs(designs), marbles_max(marbles_max)
{
    marbles_count = 0;
};

void MarbleBag::printMarbles()
{
    std::cout << "In the bag of marbles is:" << std::endl;

    for (auto const& marble : marbles)
    {
        std::printf(" - %d %s %s marble(s)\n", marble.second, colors[(marble.first & 0xFF00) >> 8], designs[marble.first & 0x00FF]);
    }
};

void MarbleBag::addMarble(uint32_t count, uint16_t style)
{
    if (marbles.find(style) == marbles.end())
    {
        if ((style & 0xFF00) >> 8 >= colors.size()) // not enough colors implemented
        {
            std::printf("Unable to add marble with color [%u] greater than colors available [%llu]\n", (style & 0xFF00) >> 8, colors.size());
            return;
        }
        if ((style & 0x00FF) >= designs.size()) // not enough designs implemented
        {
            std::printf("Unable to add marble with design [%u] greater than designs available [%llu]\n", (style & 0x00FF), designs.size());
            return;
        }
        if (count <= marbles_max)
        {
            marbles[style] = count;
        }
        else
        {
            std::printf("Unable to add marble with count of [%u] with only [%u] space left in bag\n", count, (marbles_max - marbles_count));
            return;
        }
    }
    else
    {
        if ((marbles[style] + count) + marbles_count > marbles_max) // only add marbles if enough space is left
        {
            std::printf("Unable to add marble with count of [%u] with only [%u] space left in bag\n", count, (marbles_max - marbles_count));
            return;
        }
        else
        {
            marbles[style] = marbles[style] + count;
            marbles_count = marbles_count + count;
        }
    }
    std::printf("Added [%u %s %s] marble(s) to the bag\n", count, colors[(style & 0xFF00) >> 8], designs[style & 0x00FF]);
};

void MarbleBag::removeMarble(uint32_t count, uint16_t style) // marble does not exist in bag
{
    if (marbles.find(style) == marbles.end())
    {
        std::printf("Cannot remove [%s %s] marbles as they do not exist in the bag\n", colors[(style & 0xFF00) >> 8], designs[style & 0x00FF]);
        return;
    }
    else
    {
        if (marbles[style] - count >= 0) // remove if there are enough marbles to remove
        {
            marbles[style] = marbles[style] - count;
        }
        else // set marbles to zero if trying to remove more than available
        {
            marbles[style] = 0;
        }
        std::printf("Removed [%u %s %s] marble(s) from the bag\n", count, colors[(style & 0xFF00) >> 8], designs[style & 0x00FF]);
        marbles_count = marbles_count - count;
    }
};

MarbleBag::~MarbleBag()
{
    std::cout << "Destroyed the bag of marbles, you monster." << std::endl;
};