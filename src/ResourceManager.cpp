#include <iostream>
#include <map>
#include "../include/ResourceManager.hpp"

template <typename Resource>
void ResourceManager<Resource>::loadResources(const int id, const std::string &filename) {
  Resource resource;
  if(!resource.loadFromFile(filename))
    throw std::runtime_error( "Error loading filename PATH: " + filename);

  this->TextureMap[id] = resource;
};

template <typename Resource>
Resource &ResourceManager<Resource>::getReference(const int id) {
  //auto found = TextureMap.find(id);
  //std::unique_ptr<sf::Texture> found = TextureMap.find(id);
  return this->TextureMap.at(id);
};
