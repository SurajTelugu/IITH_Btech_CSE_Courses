#include "Menu.h"

int main()
{
    sf::VideoMode desktop = sf::VideoMode::getDesktopMode();
    float factorX = desktop.width/1920.0;
    float factorY = desktop.height/1080.0;
    sf::Sprite spritebg;
    sf::Texture bg;
    
   Menu menu;

    if(!bg.loadFromFile("C:/Users/Admin/OneDrive/Desktop/Menu/Title_Background.jpg")) /// Address of image
    {
        std::cout << "ERROR::OBJECTS::BAT::BAT::Could not load texture file." << "\n";
    }
    spritebg.setTexture(bg);
    spritebg.setPosition(0.f,0.f);
    sf::Vector2u v1=bg.getSize();
    spritebg.setScale(desktop.width/static_cast<float>(v1.x),desktop.height/static_cast<float>(v1.y));
    sf::RenderWindow* window = new sf::RenderWindow(desktop,"Crazy Cricketing Champs",sf::Style::Fullscreen);
    window->setFramerateLimit(60);
    

    sf::Event event;
    while(window->isOpen())
    {
        while (window->pollEvent(event))
	    {
		    if(event.type == sf::Event::KeyPressed)
		    {
			    switch (event.key.code)
		        {
		            case sf::Keyboard::Up:menu.MoveUp(); break;

				    case sf::Keyboard::Down:menu.MoveDown(); break;

				    case sf::Keyboard::Return:
					switch (menu.GetPressedItem())
					{
					  case 0:
						std::cout << "Play button has been pressed" << std::endl;
						break;
					  case 1:
						std::cout << "Option button has been pressed" << std::endl;
						break;
					  case 2:
						window.close();
						break;
					} break;

			         case sf::Event::Closed:
				      window.close(); break;

                }

			}
		}
    }

        window->clear();
        window->draw(spritebg);
        menu.draw(window);
        window->display();
    
    return 0;
}