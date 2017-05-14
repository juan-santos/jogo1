#include "../include/SplashState.hpp"
#include <iostream>
using namespace std;

SplashState::SplashState(sf::RenderWindow *window) {
	this->window = window;
	ended = 0;
	splashTime = 0.f;
	if (logoTexture.loadFromFile("bin/Release/files/images/imagem.png"))
		logoSprite.setTexture(logoTexture);
};

SplashState::~SplashState() {
	// nothing to see here
};

void SplashState::update(const float dt) {
	splashTime += dt;
	if (splashTime >= 2.f)
		ended = 1;
};

void SplashState::draw(const float dt) {
	this->window->clear(sf::Color(200, 200, 200));
	this->window->draw(logoSprite);
};

void SplashState::handleInput() {
	sf::Event event;

	while (this->window->pollEvent(event)) {
		switch (event.type) {
			case sf::Event::Closed:
				this->window->close();
			break;
			case sf::Event::KeyPressed:
				if (event.key.code == sf::Keyboard::Escape)
					this->window->close();
				// Deixei só a opcao de sair para a Splash
				else if (event.key.code == sf::Keyboard::Space)
					ended = 1;
			break;
				default:
			break;
		}
	}
};

int SplashState::hasEnded() {
	return this->ended;
};

void SplashState::playMusic() {

};

void SplashState::stopMusic() {

};
