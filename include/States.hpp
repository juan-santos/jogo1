/*

  StackIT: States.hpp
  UFSCAR@2017

  Essa classe é responsável por definir o escopo dos estados de jogo.

*/

#ifndef STATES_HPP
#define STATES_HPP


/*
 *	Libraries
 ***********************************************************************/
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include "States.hpp"

/*
 *	Classes
 ***********************************************************************/
class States {
public:
  States();
  virtual void update(sf::Time dt) = 0;
  virtual void handleEvent(const sf::Event &event) = 0;
  virtual void draw() = 0;
};

#endif // STATES_HPP
