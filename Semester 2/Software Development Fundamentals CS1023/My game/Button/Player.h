#ifndef PLAYER_H
#define PLAYER_H

#include<SFML/Graphics.hpp>
#include<SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>


#include<iostream>
#include<vector>
class Player
{
    private:
      sf::Sprite spritebatsman;
      sf::Texture texturebatsman;
      sf::Sprite spriteball;
      sf::Texture textureball;
      sf::Sprite spriteboard;
      sf::Texture textureboard;
      
      sf::ConvexShape convex;
      sf::ConvexShape tile;

      float movementSpeed;

      
      sf::RectangleShape stump;
      std::vector<sf::RectangleShape> stumps;

      sf::CircleShape marker;
      
      sf::RectangleShape line;
      std::vector<sf::RectangleShape> lines;

      sf::RectangleShape bat;
      std::vector<sf::RectangleShape> bats;
      
      sf::RectangleShape bail;
      std::vector<sf::RectangleShape> bails;
      float x,y;
      unsigned no_of_ball_bounds;
      unsigned swing;


      //Private functions
      void initVariables();
      void initTexture();
      void initSprite();
      void initPitch();
      void initmarker();
      void initWickets();
      void initTile();

    public:
      Player();
      virtual ~Player();


      //Functions
      void init();
      void updatePitch();
      void updateWickets();
      void updatemarker();
      void updateInput();
      void updateBallMovement();
      void updateBallMovement2();
      void updateBallBounds(sf::RenderTarget* target);
      void update(sf::RenderTarget* target);

      void renderPitch(sf::RenderTarget& target);
      void renderWickets(sf::RenderTarget& target);
      void renderBats(sf::RenderTarget& target);
      void renderTile(sf::RenderTarget& target);
      void render(sf::RenderTarget& target);
};


#endif