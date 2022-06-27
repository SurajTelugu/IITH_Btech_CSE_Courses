#ifndef _Bat
#define _Bat
#include "SFML/Graphics.hpp"
#include <iostream>
class bat
{
    sf::Sprite spritebat;
    sf::Texture texturebat;
    public:
    /// initialise sprite
    bat();
    /// function to return bat 
    sf::Sprite getObject();
};
#endif