#include "Button.h"


Button::Button(float x,float y,float width1,float width2,float height,sf::Font* font,std::string text,
               sf::Color idleColor,sf::Color hoverColor,sf::Color activeColor,unsigned BTN_STATE)
{
    switch(BTN_STATE)
    {
        case 0:
        this->buttonState = BTN_IDLE;
        shape.setFillColor(idleColor);
        shape.setOutlineColor(sf::Color::White); break;
        case 1:
        this->buttonState = BTN_HOVER;
        shape.setFillColor(idleColor);
        shape.setOutlineColor(hoverColor); break;
        case 2:
        this->buttonState = BTN_ACTIVE;
        shape.setFillColor(activeColor);
        shape.setOutlineColor(sf::Color::White); break;
        case 3:
        this->buttonState = BTN_ACTIVE_HOVER; 
        shape.setFillColor(activeColor);
        shape.setOutlineColor(hoverColor); break;
    }
    
    shape.setPointCount(4);
    shape.setPoint(0,sf::Vector2f(x,y));
    shape.setPoint(1,sf::Vector2f(x+width1,y));
    shape.setPoint(2,sf::Vector2f(x+width2,y+height));
    shape.setPoint(3,sf::Vector2f(x,y+height));
    shape.setOutlineThickness(20.f);
    //this->shape.setPosition(sf::Vector2f(x,y));
    

    this->font = font;
    this->text.setFont(*this->font);
    this->text.setFillColor(sf::Color::Blue);
    this->text.setCharacterSize(55);
    this->text.setString(text);
    this->text.setPosition(sf::Vector2f(x+200,y+50));
    /*
    (
        this->shape.getPosition().x + (this->text.getGlobalBounds().width /2.f)  - this->text.getGlobalBounds().width /2.f,
        this->shape.getPosition().y + (this->text.getGlobalBounds().height /2.f) - this->text.getGlobalBounds().height /2.f
    );
    */

    this->idleColor = idleColor;
    this->hoverColor = hoverColor;
    this->activeColor = activeColor;

}   

Button::~Button()
{

}

/*
const bool Button::isPressed() const
{
    if(this->buttonState == BTN_ACTIVE)
    {return true;}

    return false;
}
*/

void Button::updateButtonColor(unsigned BTN_STATE)
{
    switch(BTN_STATE)
    {
        case 0:
        this->buttonState = BTN_IDLE;
        shape.setFillColor(idleColor);
        shape.setOutlineColor(sf::Color::White); break;
        case 1:
        this->buttonState = BTN_HOVER;
        shape.setFillColor(idleColor);
        shape.setOutlineColor(hoverColor); break;
        case 2:
        this->buttonState = BTN_ACTIVE;
        shape.setFillColor(activeColor);
        shape.setOutlineColor(sf::Color::White); break;
        case 3:
        this->buttonState = BTN_ACTIVE_HOVER; 
        shape.setFillColor(activeColor);
        shape.setOutlineColor(hoverColor); break;
    }
}


/*
void Button::update(sf::Vector2f mousepos)
{
    ///Idle
    this->buttonState = BTN_IDLE;
    Update the booleans for hover and pressed
    ///Hover
    if(this->shape.getGlobalBounds().contains(mousePos))
    {
        this->buttonState = BTN_HOVER;
    }
    ///Pressed
    if(sf::Mouse::isButtonPressed(sf::Mouse::Left))
    {
        this->buttonState = BTN_ACTIVE;
    }

    switch (this->buttonState)
    {
      case BTN_IDLE:
      this->shape.setFillColor(this->idleColor);   break;
      case BTN_HOVER:  
      this->shape.setFillColor(this->hoverColor);  break;
      case BTN_ACTIVE:
      this->shape.setFillColor(this->activeColor);  break;

      default:
      this->shape.setFillColor(sf::Color::Red);     break;
    }
    

}
*/

void Button::renderButton()
{

}

void Button::render(sf::RenderTarget* target)
{
    target->draw(this->shape);
    target->draw(text);
}