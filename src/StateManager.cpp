#include "../include/StateManager.hpp"

StateManager::StateManager() {

};

void StateManager::pushState(States *state) {
  this->states.push(state);
};

void StateManager::popState() {
  this->states.pop();
};

void StateManager::clearStates() {
  while (!this->states.empty())
    this->states.pop();
};

bool StateManager::isEmpty() {
  return this->states.empty();
};
