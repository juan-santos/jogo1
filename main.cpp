/*
 *
 * StackitCH é um jogo desenvolvido pelos alunos da UFSCAR com o propósito de
 * estudar o funcionamento da estrutura de pilha.
 *
 * O objetivo do jogo é pegar os objetos que caem do céu.
 *
 * @authors:
 *  + Amanda Basso RA: 727331
 *  + Bárbara Olivieri RA: 727334
 *  + Juan Santos RA: 594946
 *  + Matheus Vrech RA: 727349
 *
 */


/*
*	Libraries
***********************************************************************/
#include <iostream>
#include <SFML/Graphics.hpp>
#include <ctime>

#include "Jogo.h"
#include "Menu.h"
#include "Vitoria.h"
#include "Derrota.h"

using namespace std;

/*
 *	Main
 ***********************************************************************/
int main(int argc, char** argv)
{
	srand(time(NULL));

	//vetor de ponteiros de telas
	std::vector<Telas*> listaTelas;
	int telaAtual = 0;

	sf::RenderWindow App(sf::VideoMode(800, 600), "StackITCH");
	App.setFramerateLimit(30);

	Menu a;
	listaTelas.push_back(&a);

	Jogo b;
	listaTelas.push_back(&b);

	Vitoria c;
	listaTelas.push_back(&c);

	Derrota d;
	listaTelas.push_back(&d);

	//Main loop
	while (telaAtual >= 0){
        telaAtual = listaTelas[telaAtual]->Run(App);
	}


	return EXIT_SUCCESS;
}
