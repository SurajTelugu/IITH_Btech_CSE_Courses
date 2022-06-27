#ifndef _Play
#define _Play
#include "tile.h"
#include "pitch.h"
#include "stump.h"
#include "bail.h"
#include "crease.h"
#include "bat.h"
#include "batsman.h"
class playWindow
{
private:
    /// objects required for window
    sf::Event event;
    sf::Text back;
    sf::Text score;
    sf::Text overs;
    sf::Text target;
    sf::Font font;
    tile _tile;
    sf::ConvexShape tile_;
    pitch _pitch;
    sf::ConvexShape pitch_;
    crease _crease;
    std::vector<sf::RectangleShape> crease_;
    bat _bat;
    sf::Sprite bat_;
    batsman _batsman;
    sf::Sprite batsman_;
    bail _bail;
    sf::RectangleShape bail_[4];
    stump _stump;
    sf::RectangleShape stump_[6];

    /// game logic variables
    unsigned chase;  

public:
    void defaultscr(sf::RenderWindow& window);
    playWindow();
    void call(unsigned tgt,sf::RenderWindow& window);
};
#endif