#ifndef CSCREEN_H
#define CSCREEN_H

#include <SFML/Graphics.hpp>

//classe pai que conterá todas as telas
class Telas {
    public :

    //método virtual puro, classe abstrata
    virtual int Run (sf::RenderWindow &App) = 0;

};

#endif // CSCREEN_H
