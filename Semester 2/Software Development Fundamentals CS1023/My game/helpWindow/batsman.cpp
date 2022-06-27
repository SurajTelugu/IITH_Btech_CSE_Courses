#include "batsman.h"
batsman::batsman()
{
    /// loading texture from file
    if(!this->texturebatsman.loadFromFile("Textures/batsman.png"))
    {
        std::cout << "ERROR::OBJECTS::BATSMAN::BATSMAN::Could not load texture file." << "\n";
    }
    /// setting texture to the sprite
    this->spritebatsman.setTexture(this->texturebatsman);
    spritebatsman.setScale(0.7f,0.7f);
}
sf::Sprite batsman::getObject()
{
    return this->spritebatsman;
}