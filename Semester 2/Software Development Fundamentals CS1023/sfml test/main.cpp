#include <iostream>

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

int main()
{
    //windows
    sf::RenderWindow window(sf::VideoMode(800,600),"Start Game",sf::style::Titlebar | sf::style::Close);
    sf::Event ev;

    //game loop
    while (window.isOpen())
    {
      while(window.pollEvent(ev))
      {
          switch(ev.type)
          {
              case sf::Event::Closed ;
              window.close();
              break;
              case sf::Event::KeyPressed:
              if(ev.key.code == sf::Keyboard::Escape)
              window.close();
              break;

          }
      }
    }

    //update 

    //render 
    window.clear(); //clear old frame

    //draw your game
    window.display(); 

    return 0;
}

