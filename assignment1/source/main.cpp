#include <vector>

#include "marblebag.h"

int main()
{
    std::vector<char*> colors = { "red", "orange", "yellow", "green", "blue", "purple", "pink", "white", "black", "grey", "gold", "silver", "copper" };
    std::vector<char*> designs = { "solid", "striped", "dotted", "wavey", "splatter", "helix", "shattered", "picture" };
    MarbleBag mb(colors, designs, 764);
    
    mb.addMarble(7, 0xC00);
    mb.printMarbles();

    return 0;
};