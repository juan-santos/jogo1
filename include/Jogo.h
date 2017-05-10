#ifndef JOGO_H
#define JOGO_H

#include <iostream>
#include "cScreen.h"
#include <SFML/Graphics.hpp>

class Jogo : public Telas {

    private:
        float movement_step;
        float posx;
        float posy;
        sf::RectangleShape Rectangle;

    public:
        Jogo();
        virtual int Run(sf::RenderWindow &App);
};

#endif // JOGO_H
