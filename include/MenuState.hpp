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
#include "States.hpp"
#include "ResourceManager.hpp"
#include <string>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>


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
  void loadResources();
  void playMusic();
  void stopMusic();
  int getOption();

private:
    int ended;
    sf::Texture texture;
    sf::Sprite sprite;
    sf::Music music;
    sf::Font font;
    sf::Text playgame;
    sf::Text exitgame;
    //enum Elements {BACKGROUND, LOGO};
    //ResourceManager<sf::Texture> texture;

    //enum Fonts {FONT1};
    //ResourceManager<sf::Font> font;

    sf::RenderWindow *window;
};

#endif // MENUSTATE_HPP
