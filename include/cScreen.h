#ifndef CSCREEN_H
#define CSCREEN_H

#include <SFML/Graphics.hpp>

//classe pai que conter� todas as telas
class Telas {
    public :

    //m�todo virtual puro, classe abstrata
    virtual int Run (sf::RenderWindow &App) = 0;

};

#endif // CSCREEN_H
