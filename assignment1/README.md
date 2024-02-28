
# Assignment 1 (Bag of Marbles)

Modeling a bag of marbles in a program will require creating some sort of object to represent said bag. That object will then need variables to represent features of the bag, such as: how many marbles the bag can carry, how many marbles are currently *in* the bag, and depending on how marbles are represented, a way to interpret the marbles as their color, design, and so on.

The bag will also require a way to add and remove marbles from the bag, by way of methods. The remove method could also be created to allow removal of a random marble.

A basic example of such a design could be the following:

> ##### **Marble Object**
>
> **Variables**:
> - uint32 marbles_max
> - uint32 marbles_count
>
> **Methods**
> - addMarble(uint32 count, *type* style) // leave **style** blank for random
> - removeMarble(uint32 count, *type* style) // leave **style** blank for random