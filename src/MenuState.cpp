#include "../include/MenuState.hpp"


MenuState::MenuState() {
};

void MenuState::update(sf::Time dt) {

};

void MenuState::draw() {
	this->window.clear(Color::Black);
};

void MenuState::handleInput() {
	sf::Event event;

	while (this->window.pollEvent(event)) {
		switch (event.type) {
			case sf::Event:Closed:
				this->window.close();
			break;
			case sf::Event:KeyPressed:
				if (event.key.code == Keyboard::Escape)
					this->window.close();
				else if (event.key.code == Keyboard::Space)
					this->startGame();
			break;
			default:
			break;
		}
	}
};

void MenuState::playMusic() {

};

void MenuState::stopMusic() {

};
