//
// Created by Colam on 03/08/2024.
//

#ifndef DATA_STRUCTURES_BINTREE_H
#define DATA_STRUCTURES_BINTREE_H

#include <iostream>
#include "Nodo.h"


template <class T, class N>
class bintree {
public:
    typedef T tipo_elem;
    typedef N nodo;

    virtual void creabinalbero() = 0;
    virtual bool binalberovuoto() const = 0;
    virtual nodo binradice() const = 0;
    virtual nodo binpadre() const = 0;
    virtual nodo figliosinistro(nodo) const = 0;
    virtual nodo figliodestro(nodo) const = 0;
    virtual bool sinistrovuoto(nodo) const = 0;
    virtual bool destrovuoto(nodo) const = 0;
    virtual bintree costrbinalbero(bintree) const = 0;
    virtual void cancsottobinalbero(nodo) = 0;
    virtual tipo_elem legginodo(nodo) const = 0;
    virtual void scrivinodo(tipo_elem, nodo) = 0;
    virtual void insbinradice(nodo) = 0;
    virtual void insfigliosinistro(nodo) = 0;
    virtual void insfigliodestro(nodo) = 0;

};

#endif //DATA_STRUCTURES_BINTREE_H
