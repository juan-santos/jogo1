#include <iostream>
#include <SFML/Graphics.hpp>

#include "cScreen.h"
#include "Jogo.h"
#include "menu.h"

using namespace std;

int main(int argc, char** argv)
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
