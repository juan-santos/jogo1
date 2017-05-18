#include "../include/PilhaObjetos.hpp"

template <typename S>
PilhaObjetos<S>::PilhaObjetos() {
  ptr = new node;
  ptr->next = ptr;
  ptr->prev = ptr;

  int size = 0;
};

template <typename S>
PilhaObjetos<S>::~PilhaObjetos() {
  paux = ptr->next;
  while (paux != ptr)
    delete paux;
  delete ptr;
};

template <typename S>
void PilhaObjetos<S>::push(const S &aux) {
  paux = new node;
  paux->next = ptr->next;
  paux->prev = ptr;

  ptr->next->prev = paux;
  ptr->next = paux;

  paux->data = aux;
  size++;
};

template <typename S>
bool PilhaObjetos<S>::pop(S &aux) {
  if (this->empty()) {
    return false;
  } else {
    paux = ptr->next;
    aux = paux->data;

    ptr->next = paux->next;
    paux->next->prev = ptr;

    delete paux;
    size--;

    return true;
  }
};

template <typename S>
S &PilhaObjetos<S>::pop() {
  S pdata;
  if (!this->empty()) {
    paux = ptr->next;
    pdata = paux->data;

    ptr->next = paux->next;
    paux->next->prev = ptr;

    delete paux;
    size--;

    return pdata;
  }
};

template <typename S>
bool PilhaObjetos<S>::empty() const{
  return ptr == ptr->next;
};

template <typename S>
int PilhaObjetos<S>::size() const{
  return this->psize;
};
