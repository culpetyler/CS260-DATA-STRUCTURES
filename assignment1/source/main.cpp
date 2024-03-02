#include <vector>

#include "marblebag.h"

int main()
{
    std::vector<const char*> colors = { "red", "orange", "yellow", "green", "blue", "purple", "pink", "white", "black", "grey", "gold", "silver", "copper" };
    std::vector<const char*> designs = { "solid", "striped", "dotted", "wavey", "splatter", "helix", "shattered", "picture" };
    MarbleBag mb(colors, designs, 764);
    
    mb.addMarble(1000, 0x0303); // should fail because [1000] marbles is more than the available [764] we set above
    mb.addMarble(3, 0xFF00);
    mb.addMarble(3, 0x00FF); // both of these fail due to there not being [255] colors or designs in the vectors above
    mb.removeMarble(19, 0x0500); // fails as there are no marbles of this type to remove
    mb.addMarble(15, 0x0C00); // adds a marble with color at [0xFF00] ([12] after bit shift, aka [copper]) and design at [0x00FF] ([0], aka [solid])
    mb.removeMarble(7, 0x0C00); // removes [7] of the marbles correctly added above
    mb.printMarbles(); // prints that we should have [8 copper solid] marbles in our bag

    return 0;
};