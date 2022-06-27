#ifndef GAME_H
#define GAME_H
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <utility>

/// enum class for game level
enum class level {EASY, MEDIUM, TOUGH};

/// class that controls overall game flow
class game
{
    private:/// Variables

    /// Window variables
    sf::RenderWindow* window;
	//sf::VideoMode videoMode;
	sf::Event event;

    /*
        /// Mouse positions
	    sf::Vector2i mPosWindow;
	    sf::Vector2f mPosView;
    */

    /// Game logic Variables
    bool endGame;
    std::pair<level,unsigned> level_target;
    std::pair<unsigned, unsigned> overs_wickets;

    public:/// Constructors and destructor
    game();
    virtual ~game();

    /// Functions

    /// Accessors
    const bool getEndGame() const;
    const bool running() const;

    /// functions to control, update and execute game logic on window
    void pollEvent();
    void update();
    void render();
};
#endif