//
// Created by Colam on 03/08/2024.
//

#ifndef DATA_STRUCTURES_LINKED_BINTREE_H
#define DATA_STRUCTURES_LINKED_BINTREE_H

#include "bintree.h"
using namespace std;

template<class T>
class Linked_bintree : public bintree<T, Nodo<T> *> {
public:
    typedef typename bintree<T, Nodo<T> *>::tipo_elem tipo_elem;
    typedef typename bintree<T, Nodo<T> *>::nodo nodo;

    //costruttore vuoto
    Linked_bintree();

    //costruttore di copia
    Linked_bintree(const Linked_bintree &);

    //distruttore
    ~Linked_bintree();

    //ridefinizione dei metodi virtuali puri della classe bintree
};

#endif //DATA_STRUCTURES_LINKED_BINTREE_H
