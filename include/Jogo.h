#ifndef JOGO_H
#define JOGO_H

#include <iostream>
#include "cScreen.h"
#include "Pilha.h"
#include <string>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

using namespace std;
class Jogo : public Telas {

    private:
        float movement_step;
        float posx;
        float posy;
        int placar;
        int nroVidas;
        string PATH; // isso aqui da pra tirar se a gente quiser arrumar os caminhos
        int h; // essa é a altura inicial do primeiro elemento da stack
        int i;

        Pilha<int> pilha; // nossa stack maravilhosa
        Pilha<int> paux;

        sf::Texture imagem_vidas;
        sf::Sprite vidas;
        sf::Texture imagem_jogador; // o texture do player
        sf::Sprite jogador; // e o seu respectivo sprite
        sf::Sprite background;
        sf::Texture fundoJogo;
        sf::Texture imagem_objeto[5]; // array de imagens dos 5 objetos
        sf::Sprite objeto; // sprite dos objetos


        sf::Font Font;
        sf::Text text_placar1;
        sf::Text text_placar2;

        void desenharVida(sf::RenderWindow &App);
        void desenharTela(sf::RenderWindow &App);
        void desenharPainel(sf::RenderWindow &App);
        void desenharPlacar(sf::RenderWindow &App);
        void desenhaPilhaObjetos(sf::RenderWindow &App);
    public:
        Jogo();
        virtual int Run(sf::RenderWindow &App);

};

#endif //JOGO_H
