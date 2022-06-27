#include "Button.h"
#include "Player.h"

int main()
{
    sf::VideoMode desktop = sf::VideoMode::getDesktopMode();
    float factorX = desktop.width/1920.0;
    float factorY = desktop.height/1080.0;
    bool otherwindow = false;
    bool playlevelwindow = false;
    bool playlevelcompleted = false;
    bool playcricket = false;

    sf::Font font;
    if (!font.loadFromFile("fonts/LibreBaskerville-Italic.ttf"))
	{
		std::cout << "ERROR::GAME::INITFONTS::Failed to load font!" << "\n";
	}
    
     Player* player = new Player();
     Button* button1 = new Button(500,250,500,450,150,&font,"Play",
                       sf::Color(255,215,0),sf::Color::Green,sf::Color::Red,3);
     Button* button2 = new Button(500,450,500,450,150,&font,"Help",
                       sf::Color(255,215,0),sf::Color::Green,sf::Color::Red,0);
     Button* button3 = new Button(500,650,500,450,150,&font,"About",
                       sf::Color(255,215,0),sf::Color::Green,sf::Color::Red,0);
     Button* button4 = new Button(500,850,500,450,150,&font,"Close",
                       sf::Color(255,215,0),sf::Color::Green,sf::Color::Red,0);

     Button* button5 = new Button(0,50,500,450,150,&font,"Level",
                       sf::Color(255,215,0),sf::Color::Green,sf::Color::Red,0);
     Button* button6 = new Button(1000,50,500,450,150,&font,"Easy",
                       sf::Color(255,215,0),sf::Color::Green,sf::Color::Red,3);
     Button* button7 = new Button(1000,250,500,450,150,&font,"Medium",
                       sf::Color(255,215,0),sf::Color::Green,sf::Color::Red,0);
     Button* button8 = new Button(1000,450,500,450,150,&font,"Hard",
                       sf::Color(255,215,0),sf::Color::Green,sf::Color::Red,0);
     Button* button9 = new Button(0,650,500,450,150,&font,"Overs",
                       sf::Color(255,215,0),sf::Color::Green,sf::Color::Red,0);
     Button* button10 = new Button(1000,650,500,450,150,&font,"2",
                       sf::Color(255,215,0),sf::Color::Green,sf::Color::Red,3);
     Button* button11 = new Button(1000,850,500,450,150,&font,"5",
                       sf::Color(255,215,0),sf::Color::Green,sf::Color::Red,0);

     





    sf::Sprite spritebg;
    sf::Sprite spritehelp;
    sf::Sprite spriteabout;
    sf::Texture bg;
    sf::Texture texturehelp;
    sf::Texture textureabout;
    sf::Text text1;
    sf::Text text2;
   
    if(!bg.loadFromFile("Title_Background.jpg")) /// Address of image
    {
        std::cout << "ERROR::OBJECTS::BAT::BAT::Could not load texture file." << "\n";
    }
    if(!texturehelp.loadFromFile("helpbg.jpg")) /// Address of image
    {
        std::cout << "ERROR::OBJECTS::BAT::BAT::Could not load texture file." << "\n";
    }
    if(!textureabout.loadFromFile("aboutbg.jpg")) /// Address of image
    {
        std::cout << "ERROR::OBJECTS::BAT::BAT::Could not load texture file." << "\n";
    }
    spritebg.setTexture(bg);
    spritebg.setPosition(0.f,0.f);
    spritehelp.setTexture(texturehelp);
    spritehelp.setPosition(0.f,0.f);
    spriteabout.setTexture(textureabout);
    spriteabout.setPosition(0.f,0.f);
    sf::Vector2u v1=bg.getSize();
    sf::Vector2u v2=texturehelp.getSize();
    sf::Vector2u v3=textureabout.getSize();
    spritebg.setScale(desktop.width/static_cast<float>(v1.x),desktop.height/static_cast<float>(v1.y));
    spritehelp.setScale(desktop.width/static_cast<float>(v2.x),desktop.height/static_cast<float>(v2.y));
    spriteabout.setScale(desktop.width/static_cast<float>(v3.x),desktop.height/static_cast<float>(v3.y));
    sf::RenderWindow* mainwindow = new sf::RenderWindow(desktop,"Crazy Cricketing Champs",sf::Style::Fullscreen);
    mainwindow->setFramerateLimit(60);
    sf::View defaultview = mainwindow->getDefaultView();
    text1.setFont(font);
    text1.setFillColor(sf::Color::Blue);
    text1.setCharacterSize(15);
    text1.setString("Score:");
    text1.setPosition(sf::Vector2f(50,60));
    text2.setFont(font);
    text2.setFillColor(sf::Color::Blue);
    text2.setCharacterSize(15);
    text2.setString("Overs:");
    text2.setPosition(sf::Vector2f(50,95));
    //std::cout<< window->getSize().x<<"\n"<<window->getSize().y;
    sf::Event event;
    while(mainwindow->isOpen())
    {
        
            
        while (mainwindow->pollEvent(event))
	    {
		    if(event.type == sf::Event::KeyPressed)
		    {
          /*
			    switch (event.key.code)
		        {
		            case sf::Keyboard::Escape: 
                mainwindow->close(); break;
			      }
            */
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
            {
              otherwindow = true;
            }
            if(playlevelwindow == false)
            {
            if(button1->buttonState == BTN_ACTIVE_HOVER) 
            {
              
               if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
               {
                  button1->buttonState = BTN_ACTIVE;
                  button2->buttonState = BTN_HOVER;
                  std::cout<< "Hover moved from 1 to 2" << std::endl;
                  button1->updateButtonColor(button1->buttonState);
                  button2->updateButtonColor(button2->buttonState);
                  button3->updateButtonColor(button3->buttonState);
                  button4->updateButtonColor(button4->buttonState);
               }

               else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
               {
                    button1->buttonState = BTN_ACTIVE_HOVER;
                    if(button2->buttonState == BTN_ACTIVE)
                    {
                      button2->buttonState = BTN_IDLE;
                    }
                    else if(button3->buttonState == BTN_ACTIVE)
                    {
                      button3->buttonState = BTN_IDLE;
                    }
                    else if(button4->buttonState == BTN_ACTIVE)
                    {
                      button4->buttonState = BTN_IDLE;
                    }
                    std::cout << "Selected 1" << std::endl;
                    button1->updateButtonColor(button1->buttonState);
                    button2->updateButtonColor(button2->buttonState);
                    button3->updateButtonColor(button3->buttonState);
                    button4->updateButtonColor(button4->buttonState);
               }

               else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
               {
                  button1->buttonState = BTN_ACTIVE;
                  button4->buttonState = BTN_HOVER;
                  std::cout << "Hover moved from 1 to 4" << std::endl;
                  button1->updateButtonColor(button1->buttonState);
                  button2->updateButtonColor(button2->buttonState);
                  button3->updateButtonColor(button3->buttonState);
                  button4->updateButtonColor(button4->buttonState);
               }
            }
            else if(button1->buttonState == BTN_HOVER)
            {
              if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
               {
                  if(button2->buttonState == BTN_ACTIVE)
                  {
                    button1->buttonState = BTN_IDLE;
                    button2->buttonState = BTN_ACTIVE_HOVER;
                  }
                  else
                  {
                    button1->buttonState = BTN_IDLE;
                    button2->buttonState = BTN_HOVER;
                  }
                  
                  std::cout << "Hover moved from 1 to 2" << std::endl;
                  button1->updateButtonColor(button1->buttonState);
                  button2->updateButtonColor(button2->buttonState);
                  button3->updateButtonColor(button3->buttonState);
                  button4->updateButtonColor(button4->buttonState);
               }

               else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
               {
                    button1->buttonState = BTN_ACTIVE_HOVER;
                    if(button2->buttonState == BTN_ACTIVE)
                    {
                      button2->buttonState = BTN_IDLE;
                    }
                    else if(button3->buttonState == BTN_ACTIVE)
                    {
                      button3->buttonState = BTN_IDLE;
                    }
                    else if(button4->buttonState == BTN_ACTIVE)
                    {
                      button4->buttonState = BTN_IDLE;
                    }
                    std::cout << "Selected 1" << std::endl;
                    button1->updateButtonColor(button1->buttonState);
                    button2->updateButtonColor(button2->buttonState);
                    button3->updateButtonColor(button3->buttonState);
                    button4->updateButtonColor(button4->buttonState);
               }

               else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
               {
                  if(button4->buttonState == BTN_ACTIVE)
                  {
                    button1->buttonState = BTN_IDLE;
                    button4->buttonState = BTN_ACTIVE_HOVER;
                  }
                  else
                  {
                    button1->buttonState = BTN_IDLE;
                    button4->buttonState = BTN_HOVER;
                  }
                  std::cout << "Hover moved from 1 to 4" << std::endl;
                  button1->updateButtonColor(button1->buttonState);
                  button2->updateButtonColor(button2->buttonState);
                  button3->updateButtonColor(button3->buttonState);
                  button4->updateButtonColor(button4->buttonState);
               }
            }

            else if(button2->buttonState == BTN_ACTIVE_HOVER)
            {
              if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
              {
                 button2->buttonState = BTN_ACTIVE;
                 button3->buttonState = BTN_HOVER;
                 std::cout << "Hover moved from 2 to 3" << std::endl;
                 button1->updateButtonColor(button1->buttonState);
                 button2->updateButtonColor(button2->buttonState);
                 button3->updateButtonColor(button3->buttonState);
                 button4->updateButtonColor(button4->buttonState);
              }
        
              else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
              {
                button1->buttonState = BTN_HOVER;
                button2->buttonState = BTN_ACTIVE;
                std::cout << "Hover moved from 2 to 1" << std::endl;
                button1->updateButtonColor(button1->buttonState);
                button2->updateButtonColor(button2->buttonState);
                button3->updateButtonColor(button3->buttonState);
                button4->updateButtonColor(button4->buttonState);
              }
        
  
              else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
              {
                button2->buttonState = BTN_ACTIVE_HOVER;
                if(button1->buttonState == BTN_ACTIVE)
                    {
                      button1->buttonState = BTN_IDLE;
                    }
                    else if(button3->buttonState == BTN_ACTIVE)
                    {
                      button3->buttonState = BTN_IDLE;
                    }
                    else if(button4->buttonState == BTN_ACTIVE)
                    {
                      button4->buttonState = BTN_IDLE;
                    }
                std::cout << "2 Selected" << std::endl;
                button1->updateButtonColor(button1->buttonState);
                button2->updateButtonColor(button2->buttonState);
                button3->updateButtonColor(button3->buttonState);
                button4->updateButtonColor(button4->buttonState);
              }
            }
            
            else if(button2->buttonState == BTN_HOVER)
            {
              if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
              {
                 if(button3->buttonState == BTN_ACTIVE)
                 {
                   button2->buttonState = BTN_IDLE;
                   button3->buttonState = BTN_ACTIVE_HOVER;
                 }
                 else
                 {
                   button2->buttonState = BTN_IDLE;
                   button3->buttonState = BTN_HOVER;
                 }
                 std::cout << "Hover moved from 2 to 3 **" << std::endl;
                 button1->updateButtonColor(button1->buttonState);
                 button2->updateButtonColor(button2->buttonState);
                 button3->updateButtonColor(button3->buttonState);
                 button4->updateButtonColor(button4->buttonState);
              }
        
              else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
              {
                if(button1->buttonState == BTN_ACTIVE)
                {
                  button1->buttonState = BTN_ACTIVE_HOVER;
                  button2->buttonState = BTN_IDLE;
                }
                else
                {
                  button1->buttonState = BTN_HOVER;
                  button2->buttonState = BTN_IDLE;
                }
                std::cout << "Hover moved from 2 to 1" << std::endl;
                button1->updateButtonColor(button1->buttonState);
                button2->updateButtonColor(button2->buttonState);
                button3->updateButtonColor(button3->buttonState);
                button4->updateButtonColor(button4->buttonState);
              }
        
  
              else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
              {
                button2->buttonState = BTN_ACTIVE_HOVER;
                if(button1->buttonState == BTN_ACTIVE)
                    {
                      button1->buttonState = BTN_IDLE;
                    }
                    else if(button3->buttonState == BTN_ACTIVE)
                    {
                      button3->buttonState = BTN_IDLE;
                    }
                    else if(button4->buttonState == BTN_ACTIVE)
                    {
                      button4->buttonState = BTN_IDLE;
                    }
                std::cout << "2 Selected" << std::endl;
                button1->updateButtonColor(button1->buttonState);
                button2->updateButtonColor(button2->buttonState);
                button3->updateButtonColor(button3->buttonState);
                button4->updateButtonColor(button4->buttonState);
              }
            }

            else if(button3->buttonState == BTN_ACTIVE_HOVER)  
            {
               if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
               {
                 button3->buttonState = BTN_ACTIVE;
                 button4->buttonState = BTN_HOVER;
                 std::cout << "Hover moved from 3 to 4" << std::endl;
                 button1->updateButtonColor(button1->buttonState);
                 button2->updateButtonColor(button2->buttonState);
                 button3->updateButtonColor(button3->buttonState);
                 button4->updateButtonColor(button4->buttonState);
               }
        
               else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
               {
                 button2->buttonState = BTN_HOVER;
                 button3->buttonState = BTN_ACTIVE;
                 std::cout << "Hover moved from 3 to 2" << std::endl;
                 button1->updateButtonColor(button1->buttonState);
                 button2->updateButtonColor(button2->buttonState);
                 button3->updateButtonColor(button3->buttonState);
                 button4->updateButtonColor(button4->buttonState);
               }
        

               else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
               {
                 button3->buttonState = BTN_ACTIVE_HOVER;
                 if(button2->buttonState == BTN_ACTIVE)
                    {
                      button2->buttonState = BTN_IDLE;
                    }
                    else if(button1->buttonState == BTN_ACTIVE)
                    {
                      button1->buttonState = BTN_IDLE;
                    }
                    else if(button4->buttonState == BTN_ACTIVE)
                    {
                      button4->buttonState = BTN_IDLE;
                    }
                 std::cout << "3 Selected" << std::endl;
                 button1->updateButtonColor(button1->buttonState);
                 button2->updateButtonColor(button2->buttonState);
                 button3->updateButtonColor(button3->buttonState);
                 button4->updateButtonColor(button4->buttonState);
               }
            }

            else if(button3->buttonState == BTN_HOVER)
            {
              if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
               {
                 if(button4->buttonState == BTN_ACTIVE)
                 {
                   button3->buttonState = BTN_IDLE;
                   button4->buttonState = BTN_ACTIVE_HOVER;
                 }
                 else
                 {
                   button3->buttonState = BTN_IDLE;
                   button4->buttonState = BTN_HOVER;
                 }
                 std::cout << " **Hover moved from 3 to 4" << std::endl;
                 button1->updateButtonColor(button1->buttonState);
                 button2->updateButtonColor(button2->buttonState);
                 button3->updateButtonColor(button3->buttonState);
                 button4->updateButtonColor(button4->buttonState);
               }
        
               else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
               {
                 if(button2->buttonState == BTN_ACTIVE)
                 {
                    button2->buttonState = BTN_ACTIVE_HOVER;
                    button3->buttonState = BTN_IDLE;
                 }
                 else
                 {
                    button2->buttonState = BTN_HOVER;
                    button3->buttonState = BTN_IDLE;
                 }
                 std::cout << "Hover moved from 3 to 2" << std::endl;
                 button1->updateButtonColor(button1->buttonState);
                 button2->updateButtonColor(button2->buttonState);
                 button3->updateButtonColor(button3->buttonState);
                 button4->updateButtonColor(button4->buttonState);
               }
        

               else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
               {
                 button3->buttonState = BTN_ACTIVE_HOVER;
                 if(button2->buttonState == BTN_ACTIVE)
                    {
                      button2->buttonState = BTN_IDLE;
                    }
                    else if(button1->buttonState == BTN_ACTIVE)
                    {
                      button1->buttonState = BTN_IDLE;
                    }
                    else if(button4->buttonState == BTN_ACTIVE)
                    {
                      button4->buttonState = BTN_IDLE;
                    }
                 std::cout << "3 Selected" << std::endl;
                 button1->updateButtonColor(button1->buttonState);
                 button2->updateButtonColor(button2->buttonState);
                 button3->updateButtonColor(button3->buttonState);
                 button4->updateButtonColor(button4->buttonState);
               }
            }
     

            else if(button4->buttonState == BTN_ACTIVE_HOVER) 
            {
               if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
               {
                 button1->buttonState = BTN_HOVER;
                 button4->buttonState = BTN_ACTIVE;
                 std::cout << "Hover moved from 4 to 1" << std::endl;
                 button1->updateButtonColor(button1->buttonState);
                 button2->updateButtonColor(button2->buttonState);
                 button3->updateButtonColor(button3->buttonState);
                 button4->updateButtonColor(button4->buttonState);
               }
        
               else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
               {
                 button3->buttonState = BTN_HOVER;
                 button4->buttonState = BTN_ACTIVE;
                 std::cout << "Hover moved from 4 to 3" << std::endl;
                 button1->updateButtonColor(button1->buttonState);
                 button2->updateButtonColor(button2->buttonState);
                 button3->updateButtonColor(button3->buttonState);
                 button4->updateButtonColor(button4->buttonState);
               }
        

               else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
               {
                 button4->buttonState = BTN_ACTIVE_HOVER;
                 if(button2->buttonState == BTN_ACTIVE)
                    {
                      button2->buttonState = BTN_IDLE;
                    }
                    else if(button3->buttonState == BTN_ACTIVE)
                    {
                      button3->buttonState = BTN_IDLE;
                    }
                    else if(button1->buttonState == BTN_ACTIVE)
                    {
                      button1->buttonState = BTN_IDLE;
                    }
                 std::cout << "4 Selected" << std::endl;
                 button1->updateButtonColor(button1->buttonState);
                 button2->updateButtonColor(button2->buttonState);
                 button3->updateButtonColor(button3->buttonState);
                 button4->updateButtonColor(button4->buttonState);
               }
	          }
            else if(button4->buttonState == BTN_HOVER)
            {
              if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
               {
                 if(button1->buttonState == BTN_ACTIVE)
                 {
                   button1->buttonState = BTN_ACTIVE_HOVER;
                   button4->buttonState = BTN_IDLE;
                 }
                 else
                 {
                   button1->buttonState = BTN_HOVER;
                   button4->buttonState = BTN_IDLE;
                 }
                 std::cout << "Hover moved from 4 to 1" << std::endl;
                 button1->updateButtonColor(button1->buttonState);
                 button2->updateButtonColor(button2->buttonState);
                 button3->updateButtonColor(button3->buttonState);
                 button4->updateButtonColor(button4->buttonState);
               }
        
               else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
               {
                 if(button3->buttonState == BTN_ACTIVE)
                 {
                   button3->buttonState = BTN_ACTIVE_HOVER;
                   button4->buttonState = BTN_IDLE;
                 }
                 else
                 {
                   button3->buttonState = BTN_HOVER;
                   button4->buttonState = BTN_IDLE;
                 }
                 std::cout << "Hover moved from 4 to 3" << std::endl;
                 button1->updateButtonColor(button1->buttonState);
                 button2->updateButtonColor(button2->buttonState);
                 button3->updateButtonColor(button3->buttonState);
                 button4->updateButtonColor(button4->buttonState);
               }
        

               else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
               {
                 button4->buttonState = BTN_ACTIVE_HOVER;
                 if(button2->buttonState == BTN_ACTIVE)
                    {
                      button2->buttonState = BTN_IDLE;
                    }
                    else if(button3->buttonState == BTN_ACTIVE)
                    {
                      button3->buttonState = BTN_IDLE;
                    }
                    else if(button1->buttonState == BTN_ACTIVE)
                    {
                      button1->buttonState = BTN_IDLE;
                    }
                 std::cout << "4 selected" << std::endl;
                 button1->updateButtonColor(button1->buttonState);
                 button2->updateButtonColor(button2->buttonState);
                 button3->updateButtonColor(button3->buttonState);
                 button4->updateButtonColor(button4->buttonState);
               }
            }
            }
            else if(playlevelwindow == true)
            {
              if(playlevelcompleted == false)
              {
              if(button6->buttonState == BTN_ACTIVE_HOVER)
{   
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
    {
        button6->buttonState = BTN_ACTIVE;
        button7->buttonState = BTN_HOVER;
        std::cout<< "Hover moved from 6 active to 7 hover" << std::endl;
        button6->updateButtonColor(button6->buttonState);
        button7->updateButtonColor(button7->buttonState);
        button8->updateButtonColor(button8->buttonState);
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
    {
        button6->buttonState = BTN_ACTIVE;
        button8->buttonState = BTN_HOVER;
        std::cout<< "Hover moved from 6 active to 8 hover" << std::endl;
        button6->updateButtonColor(button6->buttonState);
        button7->updateButtonColor(button7->buttonState);
        button8->updateButtonColor(button8->buttonState);
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
    {
        button6->buttonState = BTN_ACTIVE_HOVER;
        if(button7->buttonState == BTN_ACTIVE)
        {
          button7->buttonState = BTN_IDLE;
        }
        else if(button8->buttonState == BTN_ACTIVE)
        {
          button8->buttonState = BTN_IDLE;
        }
        playlevelcompleted = true;            
        std::cout << "6 active Selected" << std::endl;
        button6->updateButtonColor(button6->buttonState);
        button7->updateButtonColor(button7->buttonState);
        button8->updateButtonColor(button8->buttonState);
    }
}

else if(button6->buttonState == BTN_HOVER)
{
  if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
  {
    if(button7->buttonState == BTN_ACTIVE)
    {
      button6->buttonState = BTN_IDLE;
      button7->buttonState = BTN_ACTIVE_HOVER;
    }
    else
    {
     button6->buttonState = BTN_IDLE;
     button7->buttonState = BTN_HOVER;
    }
    std::cout << "Hover moved from 6 hover to 7 hover" << std::endl;
    button6->updateButtonColor(button6->buttonState);
    button7->updateButtonColor(button7->buttonState);
    button8->updateButtonColor(button8->buttonState);
  }
  else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
  {
      if(button8->buttonState == BTN_ACTIVE)
      {
          button8->buttonState = BTN_ACTIVE_HOVER;
          button6->buttonState = BTN_IDLE;
      }
      else
      {
          button8->buttonState = BTN_HOVER;
          button6->buttonState = BTN_IDLE;
      }
      std::cout << "Hover moved from 6 hover to 8 hover" << std::endl;
      button6->updateButtonColor(button6->buttonState);
      button7->updateButtonColor(button7->buttonState);
      button8->updateButtonColor(button8->buttonState);
  }
  else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
  {
      button6->buttonState = BTN_ACTIVE_HOVER;
      if(button7->buttonState == BTN_ACTIVE)
      {
          button7->buttonState = BTN_IDLE;
      }
      else if(button8->buttonState == BTN_ACTIVE)
      {
          button8->buttonState = BTN_IDLE;
      }
      playlevelcompleted = true; 
      std::cout << "6 selected" << std::endl;
      button6->updateButtonColor(button6->buttonState);
      button7->updateButtonColor(button7->buttonState);
      button8->updateButtonColor(button8->buttonState);
  }
}

else if(button7->buttonState == BTN_ACTIVE_HOVER)
{
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
    {
        button7->buttonState = BTN_ACTIVE;
        button8->buttonState = BTN_HOVER;
        std::cout<< "Hover moved from 7 active to 8 hover" << std::endl;
        button6->updateButtonColor(button6->buttonState);
        button7->updateButtonColor(button7->buttonState);
        button8->updateButtonColor(button8->buttonState);
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
    {
        button7->buttonState = BTN_ACTIVE;
        button6->buttonState = BTN_HOVER;
        std::cout<< "Hover moved from 7 active to 6 hover" << std::endl;
        button6->updateButtonColor(button6->buttonState);
        button7->updateButtonColor(button7->buttonState);
        button8->updateButtonColor(button8->buttonState);
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
    {
        button7->buttonState = BTN_ACTIVE_HOVER;
        if(button6->buttonState == BTN_ACTIVE)
        {
          button6->buttonState = BTN_IDLE;
        }
        else if(button8->buttonState == BTN_ACTIVE)
        {
          button8->buttonState = BTN_IDLE;
        } 
        playlevelcompleted = true;            
        std::cout << "7 Selected" << std::endl;
        button6->updateButtonColor(button6->buttonState);
        button7->updateButtonColor(button7->buttonState);
        button8->updateButtonColor(button8->buttonState);
    }
}

else if(button7->buttonState == BTN_HOVER)
{
  if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
  {
    if(button8->buttonState == BTN_ACTIVE)
    {
      button7->buttonState = BTN_IDLE;
      button8->buttonState = BTN_ACTIVE_HOVER;
    }
    else
    {
     button7->buttonState = BTN_IDLE;
     button8->buttonState = BTN_HOVER;
    }
    std::cout << "Hover moved from 7 to 8" << std::endl;
    button6->updateButtonColor(button6->buttonState);
    button7->updateButtonColor(button7->buttonState);
    button8->updateButtonColor(button8->buttonState);
  }
  else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
  {
      if(button6->buttonState == BTN_ACTIVE)
      {
          button6->buttonState = BTN_ACTIVE_HOVER;
          button7->buttonState = BTN_IDLE;
      }
      else
      {
          button6->buttonState = BTN_HOVER;
          button7->buttonState = BTN_IDLE;
      }
      std::cout << "Hover moved from 7 to 6" << std::endl;
      button6->updateButtonColor(button6->buttonState);
      button7->updateButtonColor(button7->buttonState);
      button8->updateButtonColor(button8->buttonState);
  }
  else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
  {
      button7->buttonState = BTN_ACTIVE_HOVER;
      if(button6->buttonState == BTN_ACTIVE)
      {
          button6->buttonState = BTN_IDLE;
      }
      else if(button8->buttonState == BTN_ACTIVE)
      {
          button8->buttonState = BTN_IDLE;
      }
      playlevelcompleted = true; 
      std::cout << "7 selected" << std::endl;
      button6->updateButtonColor(button6->buttonState);
      button7->updateButtonColor(button7->buttonState);
      button8->updateButtonColor(button8->buttonState);
  }
}

else if(button8->buttonState == BTN_ACTIVE_HOVER)
{
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
    {
        button8->buttonState = BTN_ACTIVE;
        button6->buttonState = BTN_HOVER;
        std::cout<< "Hover moved from 8 to 6" << std::endl;
        button6->updateButtonColor(button6->buttonState);
        button7->updateButtonColor(button7->buttonState);
        button8->updateButtonColor(button8->buttonState);
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
    {
        button8->buttonState = BTN_ACTIVE;
        button7->buttonState = BTN_HOVER;
        std::cout<< "Hover moved from 8 to 7" << std::endl;
        button6->updateButtonColor(button6->buttonState);
        button7->updateButtonColor(button7->buttonState);
        button8->updateButtonColor(button8->buttonState);
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
    {
        button8->buttonState = BTN_ACTIVE_HOVER;
        if(button6->buttonState == BTN_ACTIVE)
        {
          button6->buttonState = BTN_IDLE;
        }
        else if(button7->buttonState == BTN_ACTIVE)
        {
          button7->buttonState = BTN_IDLE;
        }
        playlevelcompleted = true;             
        std::cout << "8 Selected" << std::endl;
        button6->updateButtonColor(button6->buttonState);
        button7->updateButtonColor(button7->buttonState);
        button8->updateButtonColor(button8->buttonState);
    }
}

else if(button8->buttonState == BTN_HOVER)
{
  if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
  {
    if(button6->buttonState == BTN_ACTIVE)
    {
      button8->buttonState = BTN_IDLE;
      button6->buttonState = BTN_ACTIVE_HOVER;
    }
    else
    {
     button8->buttonState = BTN_IDLE;
     button6->buttonState = BTN_HOVER;
    }
    std::cout << "Hover moved from 8 to 6" << std::endl;
    button6->updateButtonColor(button6->buttonState);
    button7->updateButtonColor(button7->buttonState);
    button8->updateButtonColor(button8->buttonState);
  }
  else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
  {
      if(button7->buttonState == BTN_ACTIVE)
      {
          button7->buttonState = BTN_ACTIVE_HOVER;
          button8->buttonState = BTN_IDLE;
      }
      else
      {
          button7->buttonState = BTN_HOVER;
          button8->buttonState = BTN_IDLE;
      }
      std::cout << "Hover moved from 8 to 7" << std::endl;
      button6->updateButtonColor(button6->buttonState);
      button7->updateButtonColor(button7->buttonState);
      button8->updateButtonColor(button8->buttonState);
  }
  else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
  {
      button8->buttonState = BTN_ACTIVE_HOVER;
      if(button6->buttonState == BTN_ACTIVE)
      {
          button6->buttonState = BTN_IDLE;
      }
      else if(button7->buttonState == BTN_ACTIVE)
      {
          button7->buttonState = BTN_IDLE;
      }
      playlevelcompleted = true; 
      std::cout << "8 selected" << std::endl;
      button6->updateButtonColor(button6->buttonState);
      button7->updateButtonColor(button7->buttonState);
      button8->updateButtonColor(button8->buttonState);
  }
}
            }
            else if(playlevelcompleted == true)
            {
              if(button10->buttonState == BTN_ACTIVE_HOVER)
              {
                if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up) || sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
                {
                  button10->buttonState = BTN_ACTIVE;
                  button11->buttonState = BTN_HOVER;
                  button10->updateButtonColor(button10->buttonState);
                  button11->updateButtonColor(button11->buttonState);
                }
                else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
                {
                  button10->buttonState = BTN_ACTIVE_HOVER;
                  playcricket = true;
                  button10->updateButtonColor(button10->buttonState);
                  button11->updateButtonColor(button11->buttonState);
                }
              }
              else if(button10->buttonState == BTN_HOVER)
              {
                if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up) || sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
                {
                  button10->buttonState = BTN_IDLE;
                  button11->buttonState = BTN_ACTIVE_HOVER;
                  button10->updateButtonColor(button10->buttonState);
                  button11->updateButtonColor(button11->buttonState);
                }
                else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
                {
                  button10->buttonState = BTN_ACTIVE_HOVER;
                  button11->buttonState = BTN_IDLE;
                  playcricket = true;
                  button10->updateButtonColor(button10->buttonState);
                  button11->updateButtonColor(button11->buttonState);
                }
              }
              else if(button11->buttonState == BTN_ACTIVE_HOVER)
              {
                if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up) || sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
                {
                  button11->buttonState = BTN_ACTIVE;
                  button10->buttonState = BTN_HOVER;
                  button10->updateButtonColor(button10->buttonState);
                  button11->updateButtonColor(button11->buttonState);
                }
                else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
                {
                  button11->buttonState = BTN_ACTIVE_HOVER;
                  playcricket = true;
                  button10->updateButtonColor(button10->buttonState);
                  button11->updateButtonColor(button11->buttonState);
                }
              }
              else if(button11->buttonState == BTN_HOVER)
              {
                if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up) || sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
                {
                  button11->buttonState = BTN_IDLE;
                  button10->buttonState = BTN_ACTIVE_HOVER;
                  button10->updateButtonColor(button10->buttonState);
                  button11->updateButtonColor(button11->buttonState);
                }
                else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
                {
                  button11->buttonState = BTN_ACTIVE_HOVER;
                  button10->buttonState = BTN_IDLE;
                  playcricket = true;
                  button10->updateButtonColor(button10->buttonState);
                  button11->updateButtonColor(button11->buttonState);
                }
              }
            }
            }  
		    }
        
        }
        if(playcricket == true)
        {
          player->update(mainwindow);
          sf::View view(sf::Vector2f(400.f, 300.f), sf::Vector2f(800.f, 600.f));
          mainwindow->setView(view);
          mainwindow->clear(sf::Color::Green);
        }
        else
        {
          mainwindow->clear();
        }
        if(otherwindow==true)
        {
          if(button1->buttonState == BTN_ACTIVE || button1->buttonState == BTN_ACTIVE_HOVER)
          {
            if(playcricket == false)
            {
              mainwindow->draw(spritebg);
              playlevelwindow = true;
              std::cout << "Play window Opened!" << std::endl;
              button5->render(mainwindow);
              button6->render(mainwindow);
              button7->render(mainwindow);
              button8->render(mainwindow);
              button9->render(mainwindow);
              button10->render(mainwindow);
              button11->render(mainwindow);
            }
            else if(playcricket == true)
            {
              player->render(*mainwindow);
              mainwindow->draw(text1);
              mainwindow->draw(text2);
            }
          }
          else if(button2->buttonState == BTN_ACTIVE || button2->buttonState == BTN_ACTIVE_HOVER)
          {
            mainwindow->draw(spritehelp);
          }
          else if(button3->buttonState == BTN_ACTIVE || button3->buttonState == BTN_ACTIVE_HOVER)
          {
            mainwindow->draw(spriteabout);
          }
          else if(button4->buttonState == BTN_ACTIVE || button4->buttonState == BTN_ACTIVE_HOVER)
          {
            mainwindow->close();
          }
          if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
          {
            otherwindow = false;
            playlevelwindow = false;
            playlevelcompleted = false;
            playcricket = false;
            player->init();
            mainwindow->setView(defaultview);
          }
        }
        else
        {
          mainwindow->draw(spritebg);
          button1->render(mainwindow);
          button2->render(mainwindow);
          button3->render(mainwindow);
          button4->render(mainwindow);
        }
        mainwindow->display();
        
        }


 return 0;
}
