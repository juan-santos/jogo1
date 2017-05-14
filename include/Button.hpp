/*

  StackIT: Button.hpp
  UFSCAR@2017

  Esta classe é responsável por formatar os botões do jogo.

*/

#ifndef BUTTON_HPP
#define BUTTON_HPP

/*
 *	Libraries
 ***********************************************************************/
#include <iostream>
#include "Screen.hpp"
#include "Button.hpp"
#include <string>

#include <SFML/Graphics.hpp>
using namespace std;

/*
 *	Classes
 ***********************************************************************/
class Button {
public:
  Button(const sf::Texture &d, const sf::Texture &s);
  bool onFocus(sf::RenderWindow &window);
  bool onClick(sf::RenderWindow &window);
  sf::FloatRect getBoundingRect() const;
private:
  virtual void update();
  virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;
  bool mouseIntersects(sf::RenderWindow &window);

  sf::Sprite deselected;
  sf::Sprite selected;
  bool state;
};

#endif // BUTTON_HP
