/*

  StackIT: TextureManager.hpp
  UFSCAR@2017

  A classe TextureManager é responsável por gerenciar o uso de texturas.

*/
#ifndef RESOURCEMANAGER_HPP
#define RESOURCEMANAGER_HPP

/*
 *	Libraries
 ***********************************************************************/
#include <iostream>
#include "Screen.hpp"
#include "Button.hpp"
#include <string>

#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
using namespace std;

/*
 *	Classes
 ***********************************************************************/
template <typename Resource, typename Identifier>
class ResourceManager {
public:
  ResourceManager();
  void loadTexture(Identifier id, const std::string &filename);
  Resource &getTexture(Identifier id);
  const Resource &getTexture(Identifier id) const;
private:
  std::map<Identifier, std::unique_ptr<Resource>> TextureMap;
};

#endif // RESOURCEMANAGER_HPP
