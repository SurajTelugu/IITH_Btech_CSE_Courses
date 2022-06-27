#include "stdafx.h"

#ifndef BUTTON_H
#define BUTTON_H

enum button_states{BTN_IDLE = 0 , BTN_HOVER , BTN_ACTIVE , BTN_ACTIVE_HOVER};

class Button
{
    private:

    sf::ConvexShape shape;
    sf::Font* font;
    sf::Text text;
    
    sf::Color idleColor;
    sf::Color hoverColor;
    sf::Color activeColor;

    public:
    short unsigned buttonState;
    Button(float x,float y,float width1,float width2,float height,sf::Font* font,std::string text
           ,sf::Color idleColor,sf::Color hoverColor,sf::Color activeColor,unsigned BTN_STATE);

    ~Button();
    //const sf::Vector2f mousePos;

    ///Accessors
    //const bool isPressed() const;

    ///Functions
    void updateButtonColor(unsigned BTN_STATE);
    //void update(sf::Vector2f mousePos);
    void renderButton();
    void render(sf::RenderTarget* target);
};

#endif