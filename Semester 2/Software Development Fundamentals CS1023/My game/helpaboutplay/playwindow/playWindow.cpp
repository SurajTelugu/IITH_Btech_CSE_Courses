#include "playWindow.h"
playWindow::playWindow()
{
    /// position the crease
    this->crease_ = this->_crease.getObject();
    (*this->crease_.begin()).setPosition(198.f,520.f);
    (*(this->crease_.begin()+1)).setPosition(272.f,130.f);
    (*(this->crease_.begin()+2)).rotate(10.f);
    (*(this->crease_.begin()+2)).setPosition(240.f,520.f);
    (*(this->crease_.begin()+3)).rotate(350.f);
    (*(this->crease_.begin()+3)).setPosition(580.f,520.f);
    (*(this->crease_.begin()+4)).rotate(10.f);
    (*(this->crease_.begin()+4)).setPosition(310.f,100.f);
    (*(this->crease_.begin()+5)).rotate(350.f);
    (*(this->crease_.begin()+5)).setPosition(440.f,100.f);

    /// position the bat
    this->bat_ = this->_bat.getObject();
    this->bat_.setPosition(379.f,420.f);

    /// position the batsman
    this->batsman_ = this->_batsman.getObject();
    this->batsman_.setPosition(190.f,340.f);

    /// position the pitch
    this->pitch_ = this->_pitch.getObject();
    
    /// position the stumps
    for(int i=0;i<3;i++)
    {
        this->stump_[i] = this->_stump.getObject();
        this->stump_[i].setPosition(389.f+(float)i*16,450.f);
    }
    for(int i=3;i<6;i++)
    {
        this->stump_[i] = this->_stump.getObject();
        this->stump_[i].setSize(sf::Vector2f(7.f,75.f));
        this->stump_[i].setPosition(309.f+(float)i*16,45.f);
    }

    /// position the bails
    for(int i=0;i<2;i++)
    {
        this->bail_[i] = this->_bail.getObject();
        this->bail_[i].setPosition(390.f+(float)i*20,450.f);
    }
    for(int i=2;i<4;i++)
    {
        this->bail_[i] = this->_bail.getObject();
        this->bail_[i].setPosition(319.f+(float)i*20,45.f);
    }

    /// position the tile
    this->tile_ = this->_tile.getObject();
    tile_.setScale(0.3f,0.3f);
    tile_.setPosition(640.f,540.f);
    tile_.setOutlineColor(sf::Color::Yellow);
    tile_.setFillColor(sf::Color::Red);
    tile_.setOutlineThickness(10);

    /// setting up "back" text
    font.loadFromFile("Fonts/LibreBaskerville-Italic.ttf");
    back.setFillColor(sf::Color::Blue);
    back.setString("Back(Esc)");
    back.setCharacterSize(20);
    back.setFont(font);
    back.setPosition(670.f,550.f); 

    /// setting up scores, overs and targets
    this->score.setFont(font);
    score.setCharacterSize(20);
    this->overs.setFont(this->font);
    overs.setCharacterSize(20);
    overs.setPosition(0.f,20.f);
    this->target.setPosition(700.f,0.f);
    target.setCharacterSize(20);
    target.setFont(font);
}

void playWindow::defaultscr(sf::RenderWindow& window)
{
    /// resetting scores, overs and targets
    score.setString("Score: 0/0");
    overs.setString("Overs: 0.0");
    target.setString("Target: "+std::to_string(chase));

    /// rendering default screen
    window.clear(sf::Color::Green);
    window.draw(pitch_);
    for(auto& c: crease_)
        window.draw(c);
    window.draw(bat_);
    window.draw(batsman_);
    for(int i=0;i<6;i++)
        window.draw(stump_[i]);
    for(int i=0;i<4;i++)
        window.draw(bail_[i]);
    window.draw(score);
    window.draw(overs);
    window.draw(target);
    window.setView(sf::View(sf::Vector2f(400.f,300.f),sf::Vector2f(800.f,600.f)));
    window.draw(tile_);
    window.draw(back);
    window.display();
}

void playWindow::call(unsigned tgt,sf::RenderWindow& window)
{
    this->chase = tgt;
    while(true)
    {
        while(window.pollEvent(this->event))
        {
            if(this->event.type==sf::Event::KeyPressed && this->event.key.code==sf::Keyboard::Escape)
            return;
        }
        this->defaultscr(window);          
    }
}