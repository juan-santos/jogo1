/*
  StackIT: Entities.hpp
  UFSCAR@2017

  Esta classe é responsável por definir a stack de objetos.
*/

#ifndef ENTITIESTACK_HPP
#define ENTITIESTACK_HPP

/*
 *	Libraries
 ***********************************************************************/
#include <iostream>
#include "ResourceManager.hpp"
#include <string>
#include <SFML/Graphics.hpp>

/*
 *	Classes
 ***********************************************************************/
template <typename S>
class EntitieStack {
public:
  EntitieStack();
  ~EntitieStack();

  void push(const S &aux);
  bool pop(S &aux);
  S &pop();
  bool empty() const;
  int size() const;

private:

  typedef struct {
    S data;
    struct node *next;
    struct node *prev;
  } node;

  node *ptr;
  node *paux;

  int psize;

};

#endif // ENTITIESTACK_HPP
