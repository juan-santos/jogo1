#include <iostream>
#include <SFML/Graphics.hpp>

#include "cScreen.h"
#include "Jogo.h"
#include "Instrucao.h"
#include "menu.h"

using namespace std;

int main(int argc, char** argv)
{
	//vetor de ponteiros de telas
	std::vector<Telas*> listaTelas;
	int telaAtual = 0;

	//Window creation
	//sf::RenderWindow App(sf::VideoMode(1280, 753, 32), "TITULO DO JOGO");
	sf::RenderWindow App(sf::VideoMode(800, 600), "StackIT");
	//App.setFramerateLimit(30);
	//retira o cursos do mouse
	//App.setMouseCursorVisible(false);

	//Screens preparations
	Menu a;
	listaTelas.push_back(&a);

	Jogo c;
	listaTelas.push_back(&c);

	Instrucao b;
	listaTelas.push_back(&b);

	//Main loop
	while (telaAtual >= 0) {
		telaAtual = listaTelas[telaAtual]->Run(App);
	}

	return EXIT_SUCCESS;
}
