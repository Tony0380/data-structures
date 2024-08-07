//
// Created by Colam on 06/08/2024.
//

#ifndef DATA_STRUCTURES_LINKED_TREE_H
#define DATA_STRUCTURES_LINKED_TREE_H

#include "tree.h"

template<class T>
class Linked_tree : public tree<T, Nodo<T> *> {
public:
    typedef typename bintree<T, Nodo<T> *>::tipo_elem tipo_elem;
    typedef typename bintree<T, Nodo<T> *>::nodo nodo;

    //costruttore vuoto
    Linked_tree();

    //costruttore di copia
    Linked_tree(const Linked_tree &);

    //distruttore
    ~Linked_tree();

    //ridefinizione dei metodi virtuali puri della classe tree

    void creaalbero();

    bool alberovuoto() const;

    void insradice(nodo);

    nodo radice() const;

    nodo padre(nodo) const;

    bool foglia(nodo) const;

    nodo primofiglio(nodo) const;

    bool ultimofratello(nodo) const;

    nodo succfratello(nodo) const;
};

#endif //DATA_STRUCTURES_LINKED_TREE_H
