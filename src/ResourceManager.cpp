#include <iostream>
#include "../include/TextureManager.hpp"

void TextureManager::loadTextures(Textures id, const std::string &filename) {
  std::unique_ptr<st::Texture> texture(new sf::Texture());
  if(!texture->loadFromFile(filename))
    throw std::runtime_error( "Error loading filename PATH: " + filename);

  TextureMap.insert(std::make_pair(id, std::move(texture)));
};

sf::Texture &TextureManager::getTexture(Textures id) {
  auto found = TextureMap.find(id);
  //std::unique_ptr<sf::Texture> found = TextureMap.find(id);
  return *found->second;
};
