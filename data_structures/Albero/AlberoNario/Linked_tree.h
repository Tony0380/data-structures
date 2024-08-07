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

    posizione primofiglio(nodo) const;

    bool ultimofratello(posizione) const;

    posizione succfratello(posizione) const;

    //sovraccarico degli operatori

    Linked_bintree<T> &operator= (const Linked_tree<T> &);

    bool operator== (const Linked_tree<T> &);

private:

    void cancellanodo(nodo);

    nodo root;
};

template<class T>
Linked_tree<T>::Linked_tree(const Linked_tree &t) {
    if(t.root!=nullptr) {
        root = new Nodo<T>();
        root->setElem(t.root->getElem());
        if(!t.root->noFigli()) {
            posizione p = t.root->primoFiglio();
            while(!t.root->ultimoFiglio()) {
                root->aggiungiFiglio(p->getElem());
                p = p->succFratello();
            }
            root->aggiungiFiglio(p->getElem());
        }
    }
}

template<class T>
bool Linked_tree<T>::ultimofratello(Linked_List<Nodo<T>>::posizione p) const {
    return p->getElem().ultimoFiglio();
}

template<class T>
typename Linked_List<Nodo<T>>::posizione Linked_tree<T>::succfratello(Linked_List<Nodo<T>>::posizione p) const {
    return p->succFratello();
}

template<class T>
typename Linked_List<Nodo<T>>::posizione Linked_tree<T>::primofiglio(nodo n) const {
    return n->primoFiglio();
}

template<class T>
bool Linked_tree<T>::foglia(Linked_tree::nodo n) const {
    return n->noFigli();
}

template<class T>
typename Linked_tree<T>::nodo Linked_tree<T>::padre(Linked_tree::nodo n) const {
    return n->getPadre();
}

template<class T>
typename Linked_tree<T>::nodo Linked_tree<T>::radice() const {
    return root;
}

template<class T>
void Linked_tree<T>::insradice(Linked_tree::nodo n) {
    if(root == nullptr) {
        root = n;
    } else {
        throw std::out_of_range("l'albero ha gia una radice");
    }
}

template<class T>
bool Linked_tree<T>::alberovuoto() const {
    return (root==nullptr);
}

template<class T>
Linked_tree<T>::~Linked_tree() {
    if(root!=nullptr) {
        cancellanodo(root);
    }
}

template<class T>
Linked_tree<T>::Linked_tree() {
    creaalbero();
}

template<class T>
void Linked_tree<T>::creaalbero() {
    root = new Nodo<T>();
}

#endif //DATA_STRUCTURES_LINKED_TREE_H
