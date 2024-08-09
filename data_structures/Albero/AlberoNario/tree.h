//
// Created by Colam on 06/08/2024.
//

#ifndef DATA_STRUCTURES_TREE_H
#define DATA_STRUCTURES_TREE_H

#include <iostream>
#include "../AlberoNario/Nodo.h"

template<class T, class N>
class tree {
public:
    typedef T tipo_elem;
    typedef N nodo;
    typedef typename Linked_List<Nodo<T>*>::posizione posizione;

    virtual void creaalbero () = 0;

    virtual bool alberovuoto () const = 0;

    virtual void insradice (nodo) = 0;

    virtual nodo radice () const = 0;

    virtual nodo padre (nodo) const = 0;

    virtual bool foglia (nodo) const = 0;

    virtual nodo primofiglio (nodo) const = 0;

    virtual bool ultimofratello (nodo) const = 0;

    virtual nodo succfratello (nodo) const = 0;
};

#endif //DATA_STRUCTURES_TREE_H
