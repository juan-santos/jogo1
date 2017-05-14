/*

  StackIT: StateManager.hpp
  UFSCAR@2017

  Essa classe é responsável por organizar os estados do jogo.

*/

#ifndef STATEMANAGER_HPP
#define STATEMANAGER_HPP

/*
 *	Libraries
 ***********************************************************************/
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <stack>
#include "States.hpp"

/*
 *	Classes
 ***********************************************************************/
class StateManager {
public:
  StateManager();
  void pushState(States state);
  void changeState(States state);
  void popState();
  void clearStates();
  States *topState();
  bool isEmpty();

private:
  std::stack<States *> states;
};

#endif // STATEMANAGER_HPP
