#include "../include/Game.hpp"
#include <SFML/Window.hpp>
const sf::Time Game::fps = sf::seconds(1.f/90.f);

Game::Game() : screen(sf::VideoMode(1300, 765), "Stack it!", sf::Style::Fullscreen), menu(screen) {
	screen.setFramerateLimit(60);
};

void Game::init() {
states.pushState(&menu);
/*	sf::Clock clock;
	sf::Time timeSinceLastUpdate = sf::Time::Zero;
	while (screen.isOpen()) {
		timeSinceLastUpdate += clock.restart();

		if (timeSinceLastUpdate > fps) {
			timeSinceLastUpdate = sf::Time::Zero;
			handleInput();
			update(fps);
		}

		draw();
	} */
};

void Game::handleInput() {

};

void Game::update(sf::Time dt)  {

};

void Game::draw() {

};
