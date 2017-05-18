/*
  StackIT: Jogo.h
  UFSCAR@2017

  Esta classe é responsável por definir o jogo em si.
*/

#ifndef JOGO_H
#define JOGO_H

#include "../src/Pilha.cpp"
/*
 *	Libraries
 ***********************************************************************/
#include <iostream>
#include "cScreen.h"
#include "Pilha.h"
#include <string>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <sstream>
/*
 *	Classes
 ***********************************************************************/
using namespace std;
class Jogo : public Telas {

private:
    float movement_step;
    float posx;
    float posy;
    int placar;
    int nroVidas;
    int h;
    int i;

    Pilha<int> pilha;
    Pilha<int> paux;

    sf::Texture imagem_vidas;
    sf::Sprite vidas;
    sf::Texture imagem_jogador[5];
    sf::Sprite jogador;
    sf::Sprite background;
    sf::Texture fundoJogo;
    sf::Texture imagem_objeto[5];
    sf::Sprite objeto;

    sf::Sprite lancamento;
    int objetoLancamento;

    sf::Font Font;
    sf::Text text_placar1;
    sf::Text text_placar2;

    void lancarObjeto(sf::RenderWindow &App);
    void colisao(sf::RenderWindow &App);
    void desenharVida(sf::RenderWindow &App);
    void desenharTela(sf::RenderWindow &App);
    void desenharPainel(sf::RenderWindow &App);
    void desenharPlacar(sf::RenderWindow &App);
    void desenhaPilhaObjetos(sf::RenderWindow &App);
    void desenhaObjetos(sf::RenderWindow &App);

public:
    Jogo();
    virtual int Run(sf::RenderWindow &App);

};

#endif //JOGO_H
