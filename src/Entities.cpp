#include "../include/Entities.hpp"

Entities::Entities() {
  this->dim.x = 135;
  this->dim.y = 94;
  this->alpha = 100;
  this->speed = 15.0;
  initEntitie();
};

Entities::~Entities() {

};

void Entities::setScore(int score) {
  this->score = score;
};

void Entities::setSpeed(float speed) {
  this->speed = speed;
};

void Entities::setPos(float x, float y) {
  this->pos.x = x;
  this->pos.y = y;
};

void Entities::setPosX(float x) {
  this->pos.x = x;
};

void Entities::setPosY(float y) {
  this->pos.y = y;
};


int Entities::getScore() const {
  return this->score;
};

int Entities::getAlpha() const {
  return this->alpha;
};

float Entities::getSpeed() const {
  return this->speed;
};

sf::Vector2f Entities::getPos() const{
  return this->pos;
};

float Entities::getPosX() const {
  return this->pos.x;
};

float Entities::getPosY() const {
  return this->pos.y;
};

void Entities::initPos() {
  pos.y = 0 - dim.y;
  pos.x = (rand() % (600 - (int)dim.x));
};

void Entities::initType() {
  this->type = rand() % 5;
  switch (this->type) {
    case 0:
      filename = "bin/Release/files/images/game/skull.png";
      objTexture.loadFromFile("bin/Release/files/images/game/skull.png");
      score = 10;
    break;
    case 1:
      filename = "bin/Release/files/images/game/ball.png";
      objTexture.loadFromFile("bin/Release/files/images/game/ball.png");
      score = 15;
    case 2:
      filename = "bin/Release/files/images/game/cauldron.png";
      objTexture.loadFromFile("bin/Release/files/images/game/cauldron.png");
      score = 20;
    break;
    case 3:
      filename = "bin/Release/files/images/game/poison.png";
      objTexture.loadFromFile("bin/Release/files/images/game/poison.png");
      score = 25;
    break;
    default:
      filename = "bin/Release/files/images/game/ball.png";
      objTexture.loadFromFile("bin/Release/files/images/game/ball.png");
      score = 15;
    break;
  }
};

void Entities::initEntitie() {
  this->alpha = 100;
  initPos();
  initType();
};

void Entities::increaseSpeed(float inc) {
  this->speed += inc;
};

void Entities::increaseScore(int inc) {
  this->score += inc;
};

sf::Sprite *Entities::entitieData() {
  return &this->objSprite;
};

void Entities::updateEntitie() {
  if (pos.y + dim.y < 600)
    pos.y += speed;
  else
    destroy();
};

void Entities::destroy() {
  if (alpha != 0)
      alpha--;
  else
      initEntitie();
};
