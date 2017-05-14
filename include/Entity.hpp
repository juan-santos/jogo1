/*

  StackIT: Entity.hpp
  UFSCAR@2017

  Esta classe é responsável por compor os elementos do jogo.

*/

#ifndef ENTITY_HPP
#define ENTITY_HPP

/*
 *	Libraries
 ***********************************************************************/
 #include <iostream>
 #include "Button.hpp"
 #include "States.hpp"
 #include <string>
 #include <SFML/Graphics.hpp>

class Entity {
public:
  Entity();
  void setVelocity(float vel);
  float getVelocity() const;
  void increaseVelocity();
  void setPosition(sf::Vector2f pos);
  sf::Vector2f getPosition() const;
private:
  float velocity;
  sf::Vector2f pos;
};
#endif
