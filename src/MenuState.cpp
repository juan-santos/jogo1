#include "../include/MenuState.hpp"

MenuState::MenuState(sf::RenderWindow *window) {
	this->window = window;
	ended = 0;

	texture.loadFromFile("bin/Release/files/images/menu/background.png");
	sprite.setTexture(texture);

	music.openFromFile("bin/Release/files/sounds/menu.ogg");
	music.setLoop(true);

	font.loadFromFile("bin/Release/files/fonts/crackman.ttf");

	playgame.setFont(font);
	playgame.setString("PLAY");
	playgame.setCharacterSize(100);
	playgame.setColor(sf::Color(0, 0, 0, 100));
	playgame.setPosition({ 275.f, 210.f });



	exitgame.setFont(font);
	exitgame.setString("EXIT");
	exitgame.setCharacterSize(70);
	exitgame.setColor(sf::Color(50, 50, 50, 100));
	exitgame.setPosition({ 315.f, 310.f });

};

MenuState::~MenuState() {

};

void MenuState::update(const float dt) {

};

void MenuState::draw(const float dt) {
	this->window->clear(sf::Color::Black);
	this->window->draw(sprite);
	sprite.setTexture(texture);
	//music.setLoop(true);
	//music.play();

	window->draw(playgame);
	window->draw(exitgame);
};

void MenuState::handleInput() {
	sf::Event event;

	while (this->window->pollEvent(event)) {
		switch (event.type) {
			case sf::Event::Closed:
				this->window->close();
			break;
			case sf::Event::KeyPressed:
				switch (event.key.code) {
					case sf::Keyboard::Escape:
						this->window->close();
					break;
					case sf::Keyboard::Up:
						playgame.setCharacterSize(100);
						playgame.setColor(sf::Color(0, 0, 0, 100));
						playgame.setPosition({ 275.f, 210.f });
						exitgame.setCharacterSize(70);
						exitgame.setColor(sf::Color(50, 50, 50, 100));
						exitgame.setPosition({ 315.f, 310.f });
					break;
					case sf::Keyboard::Down:
						playgame.setCharacterSize(70);
						playgame.setColor(sf::Color(50, 50, 50, 100));
						playgame.setPosition({ 315.f, 220.f });
						exitgame.setCharacterSize(100);
						exitgame.setColor(sf::Color(0, 0, 0, 100));
						exitgame.setPosition({ 275.f, 290.f });
					break;
					case sf::Keyboard::Space:
					case sf::Keyboard::Return:
						if (playgame.getCharacterSize() == 70)
							ended = 1;
						else
							ended = 2;
					break;
				}
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
