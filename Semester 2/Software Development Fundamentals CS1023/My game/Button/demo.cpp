
if(button6->buttonState == BTN_ACTIVE_HOVER)
{
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
    {
        button6->buttonState = BTN_ACTIVE;
        button7->buttonState = BTN_HOVER;
        std::cout<< "Hover moved from 6 to 7" << std::endl;
        button6->updateButtonColor(button6->buttonState);
        button7->updateButtonColor(button7->buttonState);
        button8->updateButtonColor(button8->buttonState);
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
    {
        button6->buttonState = BTN_ACTIVE;
        button8->buttonState = BTN_HOVER;
        std::cout<< "Hover moved from 6 to 8" << std::endl;
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
        std::cout << "6 Selected" << std::endl;
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
      button6->updateButtonColor(button6->buttonState);
      button7->updateButtonColor(button7->buttonState);
      button8->updateButtonColor(button8->buttonState);
  }
}

if(button7->buttonState == BTN_ACTIVE_HOVER)
{
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
    {
        button7->buttonState = BTN_ACTIVE;
        button8->buttonState = BTN_HOVER;
        std::cout<< "Hover moved from 7 to 8" << std::endl;
        button6->updateButtonColor(button6->buttonState);
        button7->updateButtonColor(button7->buttonState);
        button8->updateButtonColor(button8->buttonState);
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
    {
        button7->buttonState = BTN_ACTIVE;
        button6->buttonState = BTN_HOVER;
        std::cout<< "Hover moved from 6 to 8" << std::endl;
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
        std::cout << "6 Selected" << std::endl;
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
      button6->updateButtonColor(button6->buttonState);
      button7->updateButtonColor(button7->buttonState);
      button8->updateButtonColor(button8->buttonState);
  }
}

if(button8->buttonState == BTN_ACTIVE_HOVER)
{
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
    {
        button8->buttonState = BTN_ACTIVE;
        button6->buttonState = BTN_HOVER;
        std::cout<< "Hover moved from 7 to 8" << std::endl;
        button6->updateButtonColor(button6->buttonState);
        button7->updateButtonColor(button7->buttonState);
        button8->updateButtonColor(button8->buttonState);
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
    {
        button8->buttonState = BTN_ACTIVE;
        button7->buttonState = BTN_HOVER;
        std::cout<< "Hover moved from 6 to 8" << std::endl;
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
        std::cout << "6 Selected" << std::endl;
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
      button6->updateButtonColor(button6->buttonState);
      button7->updateButtonColor(button7->buttonState);
      button8->updateButtonColor(button8->buttonState);
  }
}
