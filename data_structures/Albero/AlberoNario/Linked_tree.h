//
// Created by Colam on 06/08/2024.
//

#ifndef DATA_STRUCTURES_LINKED_TREE_H
#define DATA_STRUCTURES_LINKED_TREE_H

#include "tree.h"
#include <stdexcept>

template<class T>
class Linked_tree : public tree<T, Nodo<T> *> {
public:
    typedef typename tree<T, Nodo<T> *>::tipo_elem tipo_elem;
    typedef typename tree<T, Nodo<T> *>::nodo nodo;
    typedef typename Linked_List<Nodo<T>*>::posizione posizione;
    //costruttore vuoto
    Linked_tree();

    //costruttore di copia
    //Linked_tree(const Linked_tree &);

    //distruttore
    //~Linked_tree();

    //ridefinizione dei metodi virtuali puri della classe tree

    void creaalbero();

    bool alberovuoto() const;

    void insradice(nodo);

    nodo radice() const;

    nodo padre(nodo) const;

    bool foglia(nodo) const;

    posizione primofiglio(nodo) const;

    bool ultimofratello(posizione) const;

    posizione succfratello(posizione) const;

    //sovraccarico degli operatori
private:
    nodo Radice;
};

template<class T>
typename Linked_tree<T>::nodo Linked_tree<T>::radice() const {
    if(!alberovuoto()) {
        return Radice;
    } else {
        throw std::runtime_error("L'albero è vuoto");
    }
}

template<class T>
void Linked_tree<T>::insradice(Linked_tree::nodo n) {
    if(alberovuoto()) {
        Radice = n;
    } else {
        throw std::runtime_error("L'albero ha già una radice");
    }
}

template<class T>
bool Linked_tree<T>::alberovuoto() const {
    return Radice == nullptr;
}

template<class T>
Linked_tree<T>::Linked_tree() {
    Radice = nullptr;
}

template<class T>
void Linked_tree<T>::creaalbero() {
    Radice = nullptr;
}


#endif //DATA_STRUCTURES_LINKED_TREE_H
