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

/*
 *	Classes
 ***********************************************************************/
class States {
public:
  virtual ~States(){};
  virtual void update(const float dt) = 0;
  virtual void handleInput() = 0;
  virtual void draw(const float dt) = 0;
  virtual int hasEnded() = 0;
};

#endif // STATES_HPP
