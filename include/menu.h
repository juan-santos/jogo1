/*
  StackIT: Menu.h
  UFSCAR@2017

  Esta classe é responsável por definir o menu do jogo.
*/

#ifndef MENU_H
#define MENU_H

/*
 *	Libraries
 ***********************************************************************/
#include <iostream>
#include <string>

#include "cScreen.h"
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

using namespace std;

/*
 *	Classes
 ***********************************************************************/
class Menu: public Telas {

    private:
        int alpha_max;
        int alpha_div;
        bool playing;

    public:
        Menu();
        virtual int Run(sf::RenderWindow &App);
};

#endif // MENU_H
