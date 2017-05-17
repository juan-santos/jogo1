#include "../include/Game.hpp"
#include "../include/States.hpp"
#include <SFML/Window.hpp>
#include <iostream>
using namespace std;

Game::Game() {
	this->window = new sf::RenderWindow(sf::VideoMode(800, 600), "Stack it!", sf::Style::Close);
	//window->create(sf::VideoMode(800, 600), "Stack it!", sf::Style::Close);
	window->setFramerateLimit(30);
};

Game::~Game() {
		while (!stateManager.isEmpty())
		 stateManager.popState();

	 delete splash;
	 delete menu;
	 delete game;

	 delete window;
};


void Game::loop() {
	splash = new SplashState(this->window);
	stateManager.pushState(splash);
	currentState = gameStates::onSplash;
	sf::Clock clock;
	while (this->window->isOpen()) {
		sf::Time elapsed = clock.restart();
		float dt = elapsed.asSeconds();

		if (stateManager.topState() == nullptr)
			continue;

		ended = stateManager.topState()->hasEnded();

		if (ended == 0) {
			stateManager.topState()->handleInput();
			stateManager.topState()->update(dt);
			stateManager.topState()->draw(dt);
		} else {
			switch (currentState) {
				case gameStates::onSplash:
					menu = new MenuState(this->window);
					stateManager.pushState(menu);
					currentState = gameStates::onMenu;
				break;
				case gameStates::onMenu:
					if (ended == 1) {
						this->window->close();
					} else {
						game = new GameState(this->window);
						stateManager.pushState(game);
						currentState = gameStates::onPlay;
					}
				break;
				case gameStates::onPlay:
					if (ended == 1) {
						this->window->close();
					}
				break;
				case gameStates::onPause:
				break;
				case gameStates::OnGameOver:
				break;
				case gameStates::onFinish:
				break;
				default:
					window->close();
				break;
			}
		}
		this->window->display();
	}
};
