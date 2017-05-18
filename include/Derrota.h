/*
  StackIT: Menu.h
  UFSCAR@2017

  Esta classe é responsável por definir o menu do jogo.
*/

#ifndef DERROTA_H
#define DERROTA_H


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
class Derrota: public Telas {

    public:
        Derrota();
        virtual int Run(sf::RenderWindow &App);
};

#endif // DERROTA_H
