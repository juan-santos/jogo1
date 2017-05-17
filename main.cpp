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
#include <cstdlib>
#include <ctime>

#include "include/Game.hpp"
#include "include/MenuState.hpp"

using namespace std;

/*
 *	Main
 ***********************************************************************/
int main()
{
	srand(time(NULL));

	Game game;
	game.loop();

	return EXIT_SUCCESS;
}
