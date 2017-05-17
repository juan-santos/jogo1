#include "../include/StateManager.hpp"
#include <iostream>
StateManager::StateManager() {
    // nothing to see here
};

void StateManager::pushState(States *state) {
  this->states.push(state);
};

void StateManager::popState() {
  delete this->states.top();
  this->states.pop();
};

void StateManager::changeState(States *state) {
  if (!this->states.empty())
    popState();
  pushState(state);
};

States *StateManager::topState() {
  if(this->states.empty())
    return nullptr;
  return this->states.top();
};

void StateManager::clearStates() {
  while (!this->states.empty())
    this->states.pop();
};

bool StateManager::isEmpty() {
  return this->states.empty();
};
