//
// Created by Colam on 30/07/2024.
//
#include "Stack.h"
#include <iostream>
#include <stdexcept>

#ifndef DATA_STRUCTURES_LINKED_STACK_H
#define DATA_STRUCTURES_LINKED_STACK_H

using namespace std;

template <class T>
class Nodo_Stack {
public:
    typedef T tipo_elem;

    //costruttori:
    Nodo_Stack();

    Nodo_Stack(tipo_elem);

    //distruttore
    ~Nodo_Stack();

    //operatori;
    Nodo_Stack *getPred() const;

    void setPred(Nodo_Stack *);

    tipo_elem getElem() const;

    void setElem(const tipo_elem &);

private:
    Nodo_Stack *Pred;
    tipo_elem Elem;
}

#endif //DATA_STRUCTURES_LINKED_STACK_H
