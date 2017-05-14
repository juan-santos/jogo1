#include "../include/Game.hpp"
#include "../include/States.hpp"
#include <SFML/Window.hpp>

Game::Game() : window(sf::VideoMode(1300, 765), "Stack it!", sf::Style::Fullscreen) {
	window.setFramerateLimit(60);
};

void Game::init() {
	MenuState menu;
	states.pushState(&menu);
	sf::Clock clock;

	while (this->window.isOpen()) {
		sf::Time elapsed = clock.restart();
		float dt = elapsed.asSeconds();

		if (states.topState() == nullptr)
			continue;

		//states.topState()->handleInput();
		states.topState()->update(dt);
		this->window.clear(sf::Color::Black);
		states.topState()->draw();
		this->window.display();
	}
};

void Game::handleInput() {

};

void Game::update(sf::Time dt)  {

};

void Game::draw() {

};
