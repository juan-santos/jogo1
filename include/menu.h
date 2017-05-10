#ifndef MENU_H
#define MENU_H

#include <iostream>
#include "cScreen.h"
#include <string>

#include <SFML/Graphics.hpp>
using namespace std;

class Menu: public Telas{

    private:

        int alpha_max;
        int alpha_div;
        bool playing;

    public:
        Menu();
        virtual int Run(sf::RenderWindow &App);
};

#endif // MENU_H
