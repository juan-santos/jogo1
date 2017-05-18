#include "Pilha.h"

template <class T>
Pilha<T>::Pilha()
{
    PilhaPtr = NULL;
    Topo = -1;
}

template <class T>
Pilha<T>::~Pilha()
{
    if(PilhaPtr != NULL)
        delete [] PilhaPtr;
}

template <class T>
void Pilha<T>::Insere(const T &elemento)
{
    if(Topo != -1)
    {
        T *PtrAux;
        int i;
        PtrAux = new T[++Topo];
        for(i=0;i<Topo;i++)
            PtrAux[i] = PilhaPtr[i];
        delete [] PilhaPtr;
        PilhaPtr = new T[Topo+1];
        for(i=0;i<Topo;i++)
            PilhaPtr[i] = PtrAux[i];
        PilhaPtr[i] = elemento;
        delete [] PtrAux;
    }
    else
    {
        PilhaPtr = new T[1];
        Topo++;
        PilhaPtr[0] = elemento;
    }
}

template <class T>
bool Pilha<T>::Retira(T &elemento)
{
    if(Topo > 0)
    {
        T *PtrAux;
        int i;
        elemento = PilhaPtr[Topo];
        PtrAux = new T[Topo];
        for(i=0;i<Topo;i++)
            PtrAux[i] = PilhaPtr[i];
        delete [] PilhaPtr;
        PilhaPtr = new T[Topo];
        for(i=0;i<Topo;i++)
            PilhaPtr[i] = PtrAux[i];
        Topo--;
        delete [] PtrAux;
    }
    else
    {
        if(Topo == 0)
        {
            elemento = PilhaPtr[Topo];
            Topo--;
            delete [] PilhaPtr;
            PilhaPtr = NULL;
        }
        else
            return false;
    }
    return true;
}

template <class T>
bool Pilha<T>::EstaVazia() const
{
    return Topo == -1;
}
