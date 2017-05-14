/*

  StackIT: Screen.hpp
  UFSCAR@2017

  Esta classe é responsável por administrar as telas do jogo.

*/
#ifndef SCREEN_H
#define SCREEN_H

/*
 *	Libraries
 ***********************************************************************/
 #include <SFML/System.hpp>
 #include <SFML/Window.hpp>
 #include <SFML/Graphics.hpp>

/*
 *	Classes
 ***********************************************************************/
class Screen {
public:
  Screen(sf::RenderWindow &screen);
  void update();
  void handleInput();
  void draw();

private:
  sf::RenderWindow &window;
  std::array<sf::Texture, 8> textures;
};

#endif // SCREEN_HPP
