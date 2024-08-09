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
    typedef typename Linked_List<Nodo<T> *>::posizione posizione;

    //costruttore vuoto
    Linked_tree ();

    //costruttore di copia
    //Linked_tree(const Linked_tree &);

    //distruttore
    ~Linked_tree();

    //ridefinizione dei metodi virtuali puri della classe tree

    void creaalbero ();

    bool alberovuoto () const;

    void insradice (nodo);

    nodo radice () const;

    nodo padre (nodo) const;

    bool foglia (nodo) const;

    nodo primofiglio (nodo) const;

    bool ultimofratello (nodo) const;

    nodo succfratello (nodo) const;

    //sovraccarico degli operatori

    Linked_tree &operator= (const Linked_tree &);

    bool operator== (const Linked_tree &) const;

private:
    nodo Radice;
};

template<class T>
Linked_tree<T>::~Linked_tree() {
    if (!alberovuoto()) {
        delete Radice;
    }
}

template<class T>
typename Linked_tree<T>::nodo Linked_tree<T>::succfratello (Linked_tree::nodo p) const {
    if (!ultimofratello (p)) {
        posizione tmp = p->getPadre ()->primoFiglio ();
        while (tmp->getElem () != p) {
            tmp = tmp->getNext ();
        }
        return p->getPadre ()->succFratello (tmp)->getElem ();
    } else {
        throw std::runtime_error ("Il nodo è l'ultimo fratello");
    }
}

template<class T>
bool Linked_tree<T>::ultimofratello (Linked_tree::nodo p) const {
    return p->getPadre ()->ultimoFiglio ()->getElem () == p;
}

template<class T>
typename Linked_tree<T>::nodo Linked_tree<T>::primofiglio(Linked_tree::nodo n) const {
    if (foglia(n)) {
        throw std::runtime_error("Il nodo non ha figli");
    }
    return n->primoFiglio()->getElem();
}

template<class T>
bool Linked_tree<T>::foglia (Linked_tree::nodo n) const {
    return n->noFigli ();
}

template<class T>
typename Linked_tree<T>::nodo Linked_tree<T>::padre (Linked_tree::nodo n) const {
    if (n != radice ()) {
        return n->getPadre ();
    } else {
        throw std::runtime_error ("Il nodo è la radice");
    }
}

template<class T>
typename Linked_tree<T>::nodo Linked_tree<T>::radice () const {
    if (!alberovuoto ()) {
        return Radice;
    } else {
        throw std::runtime_error ("L'albero è vuoto");
    }
}

template<class T>
void Linked_tree<T>::insradice (Linked_tree::nodo n) {
    if (alberovuoto ()) {
        Radice = n;
        n->setPadre (nullptr);
    } else {
        throw std::runtime_error ("L'albero ha già una radice");
    }
}

template<class T>
bool Linked_tree<T>::alberovuoto () const {
    return Radice == nullptr;
}

template<class T>
Linked_tree<T>::Linked_tree () {
    creaalbero ();
}

template<class T>
void Linked_tree<T>::creaalbero () {
    Radice = nullptr;
}



#endif //DATA_STRUCTURES_LINKED_TREE_H
