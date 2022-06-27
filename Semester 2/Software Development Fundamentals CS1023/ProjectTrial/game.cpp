#include "game.h"
game::game()
{
    /// initialise window
    //this->videoMode.height=1000;
    //this->videoMode.width=1000;
    this->window = new sf::RenderWindow(sf::VideoMode(1080,720,32),"Crazy Cricketing Champs",sf::Style::Fullscreen);
    this->window->setFramerateLimit(60);

    /// initialise game logic variables
    endGame = false;
    level_target = {level::EASY,10};
    overs_wickets = {2,3};
}

/// defining accessors
const bool game::running() const
{
	return this->window->isOpen();
}
const bool game::getEndGame() const
{
	return this->endGame;
}

/// window catching an event
void game::pollEvent()
{
    while (this->window->pollEvent(this->event))
	{
		switch (this->event.type)
		{
		case sf::Event::Closed:
			this->window->close();
			break;
		case sf::Event::KeyPressed:
			if (this->event.key.code == sf::Keyboard::Escape)
				this->window->close();
			break;
		}
	}
}

/// updating game logic
void game::update()
{
	this->pollEvent();
}

/// rendering output on window
void game::render()
{
	this->window->clear();
	this->window->display();
}

/// deleting window
game::~game()
{
    delete this->window;
}