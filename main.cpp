/*
 *
 * Stackit! é um jogo desenvolvido pelos alunos da UFSCAR com o propósito de
 * estudar o funcionamento da estrutura de pilha.
 *
 * O objetivo do jogo é pegar os objetos que caem sem deixar a pilha de objetos
 * ja coletados cair.
 *
 * @authors:
 *  + Amanda Basso RA: 727331
 *  + Bárbara Olivieri RA:
 *  + Juan Santos RA:
 *  + Matheus Vrech RA: 727349
 *
 */

/*
 *	Libraries
 ***********************************************************************/
#include <iostream>
#include <SFML/Graphics.hpp>

#include "Window.hpp"
#include "Game.hpp"
#include "Menu.hpp"

using namespace std;

/*
 *	Main
 ***********************************************************************/
int main()
{
	//vetor de ponteiros de telas
	std::vector<Telas*> listaTelas;
	int telaAtual = 0;

	//Window creation
	sf::RenderWindow App(sf::VideoMode(640, 480, 32), "SFML Demo 3");

	//retira o cursos do mouse
	App.setMouseCursorVisible(false);

	//Screens preparations
	Menu a;
	listaTelas.push_back(&a);
	Jogo b;
	listaTelas.push_back(&b);

	//Main loop
	while (telaAtual >= 0) {

		telaAtual = listaTelas[telaAtual]->Run(App);
	}

	return EXIT_SUCCESS;
}
