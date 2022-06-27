#include "stdafx.h"

class Game
{
 private:
 sf::RenderWindow window;
 void initWindow();

 public:

 /// Functions

  Game();
  virtual ~Game();
  void update();
  void render();
};