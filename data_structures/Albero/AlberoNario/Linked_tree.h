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

    //sovraccarico degli operatori

    Linked_bintree<T> &operator= (const Linked_tree<T> &);

    bool operator== (const Linked_tree<T> &);

private:
    nodo root;
};

template<class T>
Linked_tree<T>::Linked_tree() {
    creaalbero();
}

template<class T>
void Linked_tree<T>::creaalbero() {
    root = new nodo();
}

#endif //DATA_STRUCTURES_LINKED_TREE_H
