/*
  StackIT: GameState.hpp
  UFSCAR@2017

  Esta classe é responsável por compor o jogo em sí.
*/

#ifndef GAMESTATE_HPP
#define GAMESTATE_HPP

/*
 *	Libraries
 ***********************************************************************/
#include <iostream>
#include "States.hpp"
#include "ResourceManager.hpp"
#include "Player.hpp"
#include "Entities.hpp"
#include "EntitieStack.hpp"
#include <string>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
/*
 *	Classes
 ***********************************************************************/
class GameState : public States {
public:
  GameState(sf::RenderWindow *window);
  ~GameState();
  void update(const float dt);
  void handleInput();
  void draw(const float dt);
  int hasEnded();
  void setScore();
  void drawStack();

private:
  sf::RenderWindow *window;

  sf::Texture texture;
  sf::Sprite sprite;
  //sf::Font font;

  // sf::Texture pTexture;
  // sf::Sprite pSprite;
  int i;

  //EntitieStack<Entities> aux, stack;
  Player *player;
  Entities *entitie;
  int ended;
};

#endif // GAMESTATE_HPP
