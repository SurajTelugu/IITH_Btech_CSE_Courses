#ifndef _GAME_H
#define _GAME_H
#include "SFML.h"

class Game
{
    private:
    sf::RenderWindow* window;
    sf::Event ev;
    sf::VideoMode videomode;
    void initVariables();
    void initWindow();
    public:
    Game();
    virtual ~Game();
    const bool running() const;
    void pollEvents();
    void update();
    void render();
};
#endif