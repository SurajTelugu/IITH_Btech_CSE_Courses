#include "stdafx.h"

int main()
{
    sf::VideoMode desktop = sf::VideoMode::getDesktopMode();
    float factorX = desktop.width/1920.0;
    float factorY = desktop.height/1080.0;
    sf::Sprite spritebg;
    sf::Texture bg;
   
    if(!bg.loadFromFile("C:/Users/Admin/OneDrive/Desktop/Background/Title_Background.jpg"))
    {
        std::cout << "ERROR::OBJECTS::BAT::BAT::Could not load texture file." << "\n";
    }
    spritebg.setTexture(bg);
    spritebg.setPosition(0.f,0.f);
    sf::Vector2u v1=bg.getSize();
    spritebg.setScale(desktop.width/static_cast<float>(v1.x),desktop.height/static_cast<float>(v1.y));
    sf::RenderWindow* window = new sf::RenderWindow(desktop,"Crazy Cricketing Champs",sf::Style::Fullscreen);
    window->setFramerateLimit(60);
    //std::cout<< window->getSize().x<<"\n"<<window->getSize().y;
    sf::Event event;
    while(window->isOpen())
    {
        while (window->pollEvent(event))
	    {
		    if(event.type == sf::Event::KeyPressed)
		    {
			    switch (event.key.code)
		        {
		            case sf::Keyboard::Escape: window->close();
			        break;
			    }
		    }
	    }
        window->clear();
        window->draw(spritebg);
        window->display();
    }


 return 0;
}
