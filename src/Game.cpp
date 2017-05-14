#include "../include/Game.hpp"
#include "../include/States.hpp"
#include <SFML/Window.hpp>
#include <iostream>
using namespace std;

Game::Game() : window(sf::VideoMode(800, 600), "Stack it!", sf::Style::Close) {
	window.setFramerateLimit(60);
};

void Game::loop() {
	splash = new SplashState(&this->window);
	stateManager.pushState(splash);
	currentState = gameStates::onSplash;
	sf::Clock clock;

	while (this->window.isOpen()) {
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
						currentState = -1;
						menu = new MenuState(&this->window);
						stateManager.pushState(menu);
						currentState = gameStates::onMenu;
				break;
				case gameStates::onMenu:
					currentState = -1;
				break;
				case gameStates::onPlay:
				break;
				case gameStates::onPause:
				break;
				case gameStates::OnGameOver:
				break;
				case gameStates::onFinish:
				break;
				default:
					window.close();
				break;
			}
		}
		this->window.display();
	}
};
