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
#include "MenuState.hpp"
#include "SplashState.hpp"
#include "StateManager.hpp"

/*
 *	Classes
 ***********************************************************************/
class Game {
public:
  Game();
  void loop();
  
private:
  sf::RenderWindow window;
  static const sf::Time fps;
  StateManager stateManager;
  bool isPlaying;

  enum gameStates {onSplash, onMenu, onPlay, onPause, OnGameOver, onFinish};
  int currentState;
  int ended;

  SplashState *splash;
  MenuState *menu;
};

#endif // GAME_HPP
