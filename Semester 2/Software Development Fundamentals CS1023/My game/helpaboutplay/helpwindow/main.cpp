#include "helpWindow.h"
//#include "menuWindow.h"
//#include "levelsWindow.h"
//#include "playWindow.h"
//#include "aboutWindow.h"
int main()
{
    /// creating object for window
    sf::RenderWindow* window = new sf::RenderWindow(sf::VideoMode::getDesktopMode(),"Crazy Cricketing Champs",sf::Style::Fullscreen);
    /// creating objects for the various windows
    helpWindow help;
    //menuWindow menu;
    //levelsWindow levels;
    //playWindow play;
    //aboutWindow about;

    /// switching between the various windows
    /*jump_t jumpTo;
    Menu: jumpTo = menu.call();
    switch(jumpTo)
    {
        case jump_t::CLOSE: goto Close;
        case jump_t::PLAY: goto Levels;
        case jump_t::HELP: goto Help;
        case jump_t::ABOUT: goto About;
    }
    Levels: levels.call();
    play.call();
    goto Menu;
    Help: help.call();
    goto Menu;
    About: about.call();
    goto Menu;
    */
    //play.call(10);
    help.call(*window);
    Close: return 0;
}