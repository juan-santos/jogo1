/*

  StackIT: Menu.hpp
  UFSCAR@2017

  Esta classe é responsável por compor o menu do jogo.

*/

#ifndef MENU_HPP
#define MENU_HPP

/*
 *	Libraries
 ***********************************************************************/
#include <iostream>
#include "Screen.hpp"
#include "Button.hpp"
#include "States.hpp"
#include <string>
#include <SFML/Graphics.hpp>

/*
 *	Classes
 ***********************************************************************/
class Menu : public States, public Screen {
public:
  Menu(sf::RenderWindow &window);
  virtual void update(sf::Time dt);
  virtual void handleEvent(const sf::Event &event);
  virtual void draw();
  void playMusic();
  void stopMusic();

private:
    enum class Layer {background, top, layers};
    enum class LayerText {logo, player, misc, start1, start2, quit1, quit2, layers};
    void loadTextures();
    void render();

    sf::RenderWindow &window;
    //sf::Music song;
    //std::array<>
    //std::array<>

    Button play;
    Button quit;
};

#endif // MENU_HPP
