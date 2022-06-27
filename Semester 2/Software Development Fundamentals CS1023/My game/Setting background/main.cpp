#include "stdafx.h"

int main()
{
    
    
    sf::Event ev;

    sf::Texture texture;
    texture.loadFromFile("Setting background/title_background1.jpg");

    sf::Sprite sprite(texture);

    while(window.isOpen())
    {
        while(window.pollEvent(ev))
        {
            if(ev.type == sf::Event::EventType::Closed) window.close();
        }

        window.clear();
        window.draw(sprite);
        window.display();
    }

    return 0;
}