/*
  StackIT: Menu.h
  UFSCAR@2017

  Esta classe é responsável por definir o menu do jogo.
*/

#ifndef VITORIA_H
#define VITORIA_H

/*
 *	Libraries
 ***********************************************************************/
#include <iostream>
#include <string>

#include "cScreen.h"
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

/*
 *	Classes
 ***********************************************************************/

class Vitoria: public Telas {

    public:
        Vitoria();
        virtual int Run(sf::RenderWindow &App);
};

#endif // VITORIA_H
