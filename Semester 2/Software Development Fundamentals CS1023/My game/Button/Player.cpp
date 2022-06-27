#include "Player.h"

void Player::initVariables()
{
    this->movementSpeed = 0.5f;
    no_of_ball_bounds = 0;
    swing = rand() % 3;
}

void Player::initTexture()
{
    //Load a texture from file
    if(!this->textureball.loadFromFile("Textures/ball.png"))
    {
        std::cout << "ERROR::PLAYER::INITTEXTURE::Could not load texture file." << "\n";
    }
    if(!this->texturebatsman.loadFromFile("Textures/batsman.png"))
    {
        std::cout << "ERROR::PLAYER::INITTEXTURE::Could not load texture file." << "\n";
    }
    if(!this->textureboard.loadFromFile("Textures/scoreboard1.png"))
    {
        std::cout << "ERROR::PLAYER::INITTEXTURE::Could not load texture file." << "\n";
    }

}

void Player::initSprite()
{
    //Set the texture to the sprite
    this->bat.setPosition(405.f,450.f);
    this->bat.setFillColor(sf::Color(240,230,140));
    this->bat.setSize(sf::Vector2f(10,30));
    this->bats.push_back(this->bat);
    this->bat.setPosition(400.f,470.f);
    this->bat.setSize(sf::Vector2f(20,80));
    this->bats.push_back(this->bat);
    this->spriteball.setTexture(this->textureball);
    this->spritebatsman.setTexture(this->texturebatsman);
    this->spriteboard.setTexture(this->textureboard);
    

    //set the position of the sprite
    this->spriteball.setPosition(190.f,10.f);
    this->spritebatsman.setPosition(190.f,340.f);
    this->spriteboard.setPosition(0.f,0.f);

    //Resize the sprite
    //this->spritebat.scale(0.24f,0.2f);
    this->spriteball.scale(0.01f,0.01f);
    this->spritebatsman.scale(0.6f,0.6f);
    this->spriteboard.scale(0.5f,0.5f);
}

void Player::initmarker()
{
    x = rand() % 225 + 228;
    y = rand() % 331 + 160;
    std::cout << "(" << x << "," << y << ")" ; 
    this->marker.setPosition(x,y);
    this->marker.setFillColor(sf::Color::White);
    this->marker.setRadius(5.f);
}

void Player::initPitch()
{
    convex.setPointCount(4);
    convex.setPoint(0,sf::Vector2f(190,560));
    convex.setPoint(1,sf::Vector2f(630,560));
    convex.setPoint(2,sf::Vector2f(470,100));
    convex.setPoint(3,sf::Vector2f(280,100));
    convex.setFillColor(sf::Color(210,105,30));

    //Two big lines   
    this->line.setSize(sf::Vector2f(420,2));
    this->line.setPosition(198.f,520.f);
    this->lines.push_back(this->line);
    this->line.setSize(sf::Vector2f(210,2));
    this->line.setPosition(272.f,130.f);
    this->lines.push_back(this->line);
    //Four Small Ones
    this->line.setSize(sf::Vector2f(2,40));
    this->line.rotate(10.f);
    this->line.setPosition(240.f,520.f);
    this->lines.push_back(this->line);
    this->line.rotate(350.f);
    this->line.setPosition(580.f,520.f);
    this->lines.push_back(this->line);
    this->line.setSize(sf::Vector2f(2,30));
    this->line.rotate(10.f);
    this->line.setPosition(310.f,100.f);
    this->lines.push_back(this->line);
    this->line.rotate(350.f);
    this->line.setPosition(440.f,100.f);
    this->lines.push_back(this->line);


    
}

void Player::initWickets()
{
  this->stump.setPosition(389.f,450.f);
  this->stump.setSize(sf::Vector2f(8.f,100.f));
  this->stump.setFillColor(sf::Color::White);
  
  for(int i=0; i<6 ;i++)
  {
      if(i<3)
      {
          stump.setPosition(389.f+(float)i*16,450.f);
          this->stumps.push_back(this->stump);
      }
      else
      {
          this->stump.setSize(sf::Vector2f(7.f,75.f));
          stump.setPosition(309.f+(float)i*16,45.f);
          this->stumps.push_back(this->stump);
      }
      
  }

  this->bail.setPosition(389.f,450.f);
  this->bail.setSize(sf::Vector2f(15.f,2.5f));
  this->bail.setFillColor(sf::Color::White);

  for(int i=0; i<4 ;i++)
  {
      if(i<2)
      {
          bail.setPosition(390.f+(float)i*20,450.f);
          this->bails.push_back(this->bail);
      }

      else
      {
          bail.setPosition(319.f+(float)i*20,45.f);
          this->bails.push_back(this->bail);
      }
  }
}


void Player::initTile()
{
    tile.setPointCount(4);
    tile.setPoint(0,sf::Vector2f(50,200));
    tile.setPoint(1,sf::Vector2f(220,200));
    tile.setPoint(2,sf::Vector2f(180,250));
    tile.setPoint(3,sf::Vector2f(50,250));
    tile.setFillColor(sf::Color(255,215,0));
}

void Player::init()
{
    this->initVariables();
    this->initTexture();
    this->initSprite();
    this->initPitch();
    this->initWickets();
    this->initmarker();
    this->initTile();
}


Player::Player()
{
    this->initVariables();
    this->initTexture();
    this->initSprite();
    this->initPitch();
    this->initWickets();
    this->initmarker();
    this->initTile();
}

Player::~Player()
{

}
//Functions

void Player::updatePitch()
{

}


void Player::updateWickets()
{
    
}

void Player::updateInput()
{
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
    {
        this->spritebatsman.move(-this->movementSpeed, 0.f);
        for(int i=0; i<2; i++)
        {
            this->bats[i].move(-this->movementSpeed, 0.f);
        }
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {
        this->spritebatsman.move(this->movementSpeed, 0.f);
        for(int i=0; i<2; i++)
        {
            this->bats[i].move(this->movementSpeed, 0.f);
        }
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
    {
        //this->spritebat.setPosition(379.f,420.f);
    }
}


void Player::updatemarker()
{
  this->initmarker();
}

void Player::updateBallMovement()
{
    float x1 = marker.getPosition().x - this->spriteball.getPosition().x;
    float y1 = marker.getPosition().y - this->spriteball.getPosition().y;
    if(x1>y1)
    {
        float z = y1/x1;
        this->spriteball.move(1.f,z);
    }
    else if(y1>x1)
    {
        float z = x1/y1;
        this->spriteball.move(z,1.f);
    }

}

void Player::updateBallMovement2()
{
    switch(swing)
    {
        case 0:
        this->spriteball.move(-1.f,1.f);
        break;
        case 1:
        this->spriteball.move(0.f,1.f);
        break;
        case 2:
        this->spriteball.move(1.f,1.f);
        break;
    }
    //std::cout << "(" << this->spriteball.getPosition().x << "," << this->spriteball.getPosition().x  << ")" ;
}

void Player::updateBallBounds(sf::RenderTarget* target)
{
    if(this->spriteball.getPosition().y >= target->getSize().y)
    {
        this->spriteball.setPosition(190.f,10.f);
        no_of_ball_bounds++;
    }
}

void Player::update(sf::RenderTarget* target)
{
    if(this->spriteball.getPosition().y < y)
    {
        this->updateInput();


        this->updateBallMovement();
    }
    else
    {
        this->updateInput();
        this->updateBallMovement2(); 
    }
    if(no_of_ball_bounds == 1)
    {
        this->updateInput();
        this->updatemarker();
        swing = rand() % 3;
        no_of_ball_bounds = 0;
    }
    this->updateBallBounds(target);
}

void Player::renderWickets(sf::RenderTarget& target)
{
    for(auto &s : this->stumps)
    {
        target.draw(s);
    }

    for(auto &b : this->bails)
    {
        target.draw(b);
    }
}

void Player::renderPitch(sf::RenderTarget& target)
{
    target.draw(convex);
    for(auto &l : this->lines)
    {
        target.draw(l);
    }
}

void Player::renderBats(sf::RenderTarget& target)
{
    for(auto &b : this->bats)
    {
        target.draw(b);
    }
}


void Player::renderTile(sf::RenderTarget& target)
{
    target.draw(tile);
}


void Player::render(sf::RenderTarget& target)
{
    this->renderPitch(target);
    //target.draw(this->spritebat);
    target.draw(this->spriteball);
    target.draw(this->spritebatsman);
    target.draw(this->spriteboard);
    target.draw(this->marker);
    this->renderBats(target);
    this->renderWickets(target);
    //this->renderTile(target);   

}