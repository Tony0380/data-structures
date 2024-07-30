//
// Created by Colam on 30/07/2024.
//
#include "Stack.h"
#include <iostream>
#include <stdexcept>

#ifndef DATA_STRUCTURES_LINKED_STACK_H
#define DATA_STRUCTURES_LINKED_STACK_H

using namespace std;

template<class T>
class Nodo_Stack {
public:
    typedef T tipo_elem;

    //costruttori:
    Nodo_Stack ();

    Nodo_Stack (const tipo_elem &);

    //distruttore
    ~Nodo_Stack ();

    //operatori;
    Nodo_Stack *getPred () const;

    void setPred (Nodo_Stack *);

    tipo_elem getElem () const;

    void setElem (const tipo_elem &);

private:
    Nodo_Stack *Pred;
    tipo_elem Elem;
};

template<class T>
class Linked_Stack : public Stack<T, Nodo_Stack<T>*> {
public:
    typedef typename Stack<T, Nodo_Stack<T> *>::tipo_elem tipo_elem;
    typedef typename Stack<T, Nodo_Stack<T> *>::posizione posizione;

    //costruttore vuoto
    Linked_Stack();
    //costruttore di copia
};




template<class T>
void Nodo_Stack<T>::setElem (const tipo_elem &newElem) {
    this->Elem = newElem;
}

template<class T>
typename Nodo_Stack<T>::tipo_elem Nodo_Stack<T>::getElem () const {
    return this->Elem;
}

template<class T>
void Nodo_Stack<T>::setPred (Nodo_Stack *newPred) {
    this->Pred = newPred;
}

template<class T>
Nodo_Stack<T> *Nodo_Stack<T>::getPred () const {
    return this->Pred;
}

template<class T>
Nodo_Stack<T>::~Nodo_Stack () {
    delete Pred;
}

template<class T>
Nodo_Stack<T>::Nodo_Stack (const tipo_elem &e) {
    this->Pred = NULL;
    this->Elem = e;
}

template<class T>
Nodo_Stack<T>::Nodo_Stack () {
    this->Pred = NULL;
}

#endif //DATA_STRUCTURES_LINKED_STACK_H
