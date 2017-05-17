#include "../include/GameState.hpp"
#include "../include/Player.hpp"
#include "../include/Entities.hpp"
#include "../include/EntitieStack.hpp"
#include <iostream>
#include <string>
using namespace std;

GameState::GameState(sf::RenderWindow *window) {
	this->window = window;
	ended = 0;
	i = 0;
	player = new Player;
	entitie = new Entities;
	entitie->initEntitie();

	// stack.push(*entitie);
	//font.loadFromFile("bin/Release/files/fonts/crackman.ttf");
	//score.setFont(font);
	// score.setCharacterSize(100);
	// score.setColor(sf::Color(20, 20, 20, 100));
	// score.setPosition({ 275.f, 210.f });

	// texture.loadFromFile("bin/Release/files/images/game/background.png");
	// sprite.setTexture(texture);
	//
	// texture.loadFromFile("bin/Release/files/images/game/player01.png");
	// sprite.setTexture(texture);


};

GameState::~GameState() {
	delete player;
	delete entitie;
};

void GameState::update(const float dt) {
	//score.setString(std::to_string(player->getScore()));
	//this->entitie->setPosY(10);
	entitie->updateEntitie();
};

void GameState::draw(const float dt) {

	//this->window->draw(entitie->entitieData());

	texture.loadFromFile("bin/Release/files/images/game/background.png");
	sprite.setTexture(texture);
	sprite.setPosition(0, 0);
	this->window->draw(sprite);

	switch(i > 3 ? i = 0 : i++) {
		case 0:
			texture.loadFromFile("bin/Release/files/images/game/player01.png");
		break;
		case 1:
			texture.loadFromFile("bin/Release/files/images/game/player02.png");
		break;
		case 2:
			texture.loadFromFile("bin/Release/files/images/game/player03.png");
		break;
		case 3:
			texture.loadFromFile("bin/Release/files/images/game/player04.png");
		break;
		case 4:
			texture.loadFromFile("bin/Release/files/images/game/player05.png");
		break;
		default:
		texture.loadFromFile("bin/Release/files/images/game/player01.png");
		break;
	}

	sprite.setTexture(texture);
	sprite.setPosition(player->getPosX(), player->getPosY());
	this->window->draw(sprite);

	texture.loadFromFile(entitie->filename);
	sprite.setTexture(texture);
	sprite.setPosition(entitie->getPosX(), entitie->getPosY());
	this->window->draw(sprite);

	//drawStack();


};

void GameState::handleInput() {
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
					case sf::Keyboard::Left:
						player->stepLeft();
					break;
					case sf::Keyboard::Right:
						player->stepRight();
					break;
					case sf::Keyboard::Space:
					case sf::Keyboard::Return:
					break;
				}
			break;
			case sf::Event::MouseMoved:
				if ((event.mouseMove.x - 50) >= 0 && (event.mouseMove.x + 50) < 800)
					player->setPosX(event.mouseMove.x - 125);
			default:
			break;
		}
	}
};

int GameState::hasEnded() {
	return this->ended;
};

// void GameState::drawStack() {
// 	Entities ent;
// 	sf::Vector2f posi;
// 	while (!stack.empty())
// 		aux.push(stack.pop());
//
// 	posi.x = player->getPosX() + 125;
// 	posi.y = player->getPosY() + 108;
//
// 	while (!aux.empty()) {
// 		if (aux.pop(ent)) {
// 			stack.push(ent);
//
// 			entitie->entitieData().setPosition(posi.x, posi.y);
// 			this->window->draw(entitie->entitieData());
// 		}
// 	}
//
// };
