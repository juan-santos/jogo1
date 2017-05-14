/*

  StackIT: MenuState.hpp
  UFSCAR@2017

  Esta classe é responsável por compor o menu do jogo.

*/

#ifndef MENUSTATE_HPP
#define MENUSTATE_HPP

/*
 *	Libraries
 ***********************************************************************/
#include <iostream>
#include "Button.hpp"
#include "States.hpp"
#include <string>
#include <SFML/Graphics.hpp>

/*
 *	Classes
 ***********************************************************************/
class MenuState : public States {
public:
  MenuState();
  virtual void update(sf::Time dt);
  virtual void handleInput();
  virtual void draw();
  void playMusic();
  void stopMusic();

private:
    enum class Layer {background, top, layers};
    enum class LayerText {logo, player, misc, start1, start2, quit1, quit2, layers};
    void loadTextures();
    void render();

    sf::RenderWindow window;
    //sf::Music song;
    //std::array<>
    //std::array<>

    //Button play;
    //Button quit;
};

#endif // MENUSTATE_HPP
