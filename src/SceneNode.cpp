#include "../include/SceneNode.hpp"

SceneNode::SceneNode() {

};

void SceneNode::attachChild(ptr child) {
  child->parent = this;
  children.push_back(std::move(child));
};
