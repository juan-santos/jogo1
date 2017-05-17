/*
  StackIT: Player.hpp
  UFSCAR@2017

  Esta classe é responsável por definir o comportamento da personagem.
*/

#ifndef PLAYER_HPP
#define PLAYER_HPP

/*
 *	Libraries
 ***********************************************************************/
#include <iostream>
#include "ResourceManager.hpp"
#include "EntitieStack.hpp"
#include "Entities.hpp"
#include <string>
#include <SFML/Graphics.hpp>

/*
 *	Classes
 ***********************************************************************/
class Player {
public:
  Player();
  ~Player();

  void setStep(float speed = 15);
  void setPos(float x, float y);
  void setPosX(float x);
  void setPosY(float y);

  float getStep() const;
  int getScore() const;
  sf::Vector2f getPos() const;
  float getPosX() const;
  float getPosY() const;
  float getWaist() const;

  void increaseSpeed(float inc = 10.0);
  void increaseScore(int inc = 0);
  void stepRight();
  void stepLeft();
  //sf::Text scoreText;

private:

  float step;
  int score;
  int alpha;
  float waist;
  sf::Vector2f pos;
  sf::Vector2f dim;

};

#endif // PLAYER_HPP
