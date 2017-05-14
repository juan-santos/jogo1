/*
  StackIT: SplashState.hpp
  UFSCAR@2017
  
  Esta classe é responsável por compor a tela de Splash do jogo.
*/

#ifndef SPLASHSTATE_HPP
#define SPLASHTATE_HPP

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
class SplashState : public States {
public:
  SplashState(sf::RenderWindow *window);
  ~SplashState();
  void update(const float dt);
  void handleInput();
  void draw(const float dt);
  int hasEnded();
  void playMusic();
  void stopMusic();

private:
    sf::Texture logoTexture;
    sf::Sprite logoSprite;
    sf::RenderWindow *window;
    float splashTime;
    int ended;
};

#endif // SPLASHSTATE_HPP
