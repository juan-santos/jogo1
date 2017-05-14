/*

  StackIT: SceneNode.hpp
  UFSCAR@2017

  Esta classe é responsável por compor os elementos da window.

*/

#ifndef SCENENODE_HPP
#define SCENENODE_HPP

/*
 *	Libraries
 ***********************************************************************/
 #include <iostream>
 #include "Button.hpp"
 #include "States.hpp"
 #include <string>
 #include <SFML/Graphics.hpp>

class SceneNode {
public:
  SceneNode();
  typedef std::unique_ptr<SceneNode> ptr;

  void attachChild(ptr child);
  ptr detachChild(const SceneNode &node);
  
private:
  std::vector<ptr> children;
  SceneNode *parent;

};
#endif
