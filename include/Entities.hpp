/*
  StackIT: Entities.hpp
  UFSCAR@2017

  Esta classe é responsável por definir os objetos do jogo.
*/

#ifndef ENTITIES_HPP
#define ENTITIES_HPP

/*
 *	Libraries
 ***********************************************************************/
#include <iostream>
#include "ResourceManager.hpp"
#include <string>
#include <SFML/Graphics.hpp>

/*
 *	Classes
 ***********************************************************************/
class Entities {
public:
  Entities();
  ~Entities();

  sf::Sprite *entitieData();
  void updateEntitie();

  void setScore(int score);
  void setSpeed(float speed);
  void setPos(float x, float y);
  void setPosX(float x);
  void setPosY(float y);

  int getScore() const;
  int getAlpha() const;
  float getSpeed() const;
  sf::Vector2f getPos() const;
  float getPosX() const;
  float getPosY() const;

  void initPos();
  void initType();
  void initEntitie();
  void increaseSpeed(float inc = 10.0);
  void increaseScore(int inc = 10);
  void destroy();

  string filename;

private:

  sf::Texture objTexture;
  sf::Sprite objSprite;
  //sf::Texture obj2;
  //sf::Texture obj3;
  //sf::Texture obj4;
  int type;
  int score;
  float speed;
  int alpha;
  sf::Vector2f pos;
  sf::Vector2f dim;
};

#endif // ENTITIES_HPP
