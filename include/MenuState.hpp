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
  MenuState(sf::RenderWindow *window);
  ~MenuState();
  void update(const float dt);
  void handleInput();
  void draw(const float dt);
  int hasEnded();
  void playMusic();
  void stopMusic();

private:
    int ended;
    enum class Layer {background, top, layers};
    enum class LayerText {logo, player, misc, start1, start2, quit1, quit2, layers};
    void loadTextures();
    void render();

    sf::RenderWindow *window;
};

#endif // MENUSTATE_HPP
