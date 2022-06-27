#include "game.h"
#include <iostream>
int main()
{
    game g;
    while(g.running() && !g.getEndGame())
    {
        g.update();
        g.render();
    }
    return 0;
}