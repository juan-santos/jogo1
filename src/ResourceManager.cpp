#include <iostream>
#include "../include/ResourceManager.hpp"

template <typename Resource, typename Identifier>
void ResourceManager<Resource, Identifier>::loadTextures(Identifier id, const std::string &filename) {
  std::unique_ptr<Resource> resource(new sf::Texture());
  if(!resource->loadFromFile(filename))
    throw std::runtime_error( "Error loading filename PATH: " + filename);

  TextureMap.insert(std::make_pair(id, std::move(resource)));
};

template <typename Resource, typename Identifier>
Resource &ResourceManager<Resource, Identifier>::getTexture(Identifier id) {
  auto found = TextureMap.find(id);
  //std::unique_ptr<sf::Texture> found = TextureMap.find(id);
  return *found->second;
};
