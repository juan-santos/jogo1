#include "../include/Player.hpp"

Player::Player() {
  this->dim.x = 250;
  this->dim.y = 233;
  this->pos.x = 275;
  this->pos.y = 360;
  this->alpha = 100;
  this->step = 15;
  this->score = 0;
  this->waist = 155;

  //playerTexture.loadFromFile("bin/Release/files/images/game/player01.png");
  //playerSprite.setTexture(playerTexture);
};

Player::~Player() {
};

void Player::setStep(float speed) {
  this->step = speed;
};

void Player::setPos(float x, float y) {
  this->pos.x = x;
  this->pos.y = y;
};

void Player::setPosX(float x) {
  this->pos.x = x;
};

void Player::setPosY(float y) {
  this->pos.y = y;
};

float Player::getStep() const {
  return this->score;
};

int Player::getScore() const {
  return this->step;
};

sf::Vector2f Player::getPos() const{
  return this->pos;
};

float Player::getPosX() const {
  return this->pos.x;
};

float Player::getPosY() const {
  return this->pos.y;
};

float Player::getWaist() const {
  return this->waist;
};

void Player::increaseSpeed(float inc) {
  this->step += inc;
};

void Player::stepRight() {
  if ((this->pos.x + this->dim.x) < 875)
    this->pos.x += step;
};

void Player::stepLeft() {
  if ((this->pos.x > -75))
    this->pos.x -= step;
};

void Player::increaseScore(int inc) {
  this->score += inc;
};
