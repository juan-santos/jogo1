/*

  StackIT: Game.hpp
  UFSCAR@2017

  Essa classe é responsável por organizar o jogo e suas subdivisões

*/

#ifndef GAME_HPP
#define GAME_HPP


/*
 *	Libraries
 ***********************************************************************/
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "Screen.hpp"
#include "StateManager.hpp"
#include "MenuState.hpp"

/*
 *	Classes
 ***********************************************************************/
class Game {
public:
  Game();
  void init();
private:
  void handleInput();
  void update(sf::Time dt);
  void draw();

  sf::RenderWindow  screen;
  static const sf::Time fps;
  StateManager states;
  Menu menu;
  bool isPlaying;
};

#endif // GAME_HPP
