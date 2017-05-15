#include "../include/MenuState.hpp"

MenuState::MenuState(sf::RenderWindow *window) {
	this->window = window;
	ended = 0;
};

MenuState::~MenuState() {
};

void MenuState::update(const float dt) {

};

void MenuState::draw(const float dt) {
	this->window->clear(sf::Color::Black);
};

void MenuState::handleInput() {
	sf::Event event;

	while (this->window->pollEvent(event)) {
		switch (event.type) {
			case sf::Event::Closed:
				this->window->close();
			break;
			case sf::Event::KeyPressed:
				if (event.key.code == sf::Keyboard::Escape)
					this->window->close();
				else if (event.key.code == sf::Keyboard::Space)
					ended = 1;
			break;
			default:
			break;
		}
	}
};

int MenuState::hasEnded() {
	return this->ended;
};

void MenuState::playMusic() {

};

void MenuState::stopMusic() {

};
