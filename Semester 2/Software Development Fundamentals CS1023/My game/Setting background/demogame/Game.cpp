#include <iostream>
#include "Game.h"

void Game::initVariables()
{
    this->window=nullptr;
}
void Game::initWindow()
{
    this->videomode.height=720;
    this->videomode.width=1080;
    this->window=new sf::RenderWindow(this->videomode,"Game 1",sf::Style::Titlebar | sf::Style::Close | sf::Style::Fullscreen);
    this->window->setFramerateLimit(60);
}
Game::Game()
{
    initVariables();
    initWindow();
}
Game::~Game()
{
    delete this->window;
}
const bool Game::running() const
{
    return this->window->isOpen();
}
void Game::pollEvents()
{
    while(this->window->pollEvent(this->ev))
    {
        switch(ev.type)
        {
            case sf::Event::Closed: this->window->close(); break;
            case sf::Event::KeyPressed:
            if(ev.key.code==sf::Keyboard::Escape)
            this->window->close();
        }
    }
}
void Game::update()
{
    pollEvents();
}
void Game::render()
{
    this->Game::window->clear(sf::Color(255,255,0));
    this->window->display();
}