//
// Created by Colam on 03/08/2024.
//

#ifndef DATA_STRUCTURES_LINKED_BINTREE_H
#define DATA_STRUCTURES_LINKED_BINTREE_H

#include "bintree.h"
#include <stdexcept>

using namespace std;

template<class T>
class Linked_bintree : public bintree<T, Nodo<T> *> {
public:
    typedef typename bintree<T, Nodo<T> *>::tipo_elem tipo_elem;
    typedef typename bintree<T, Nodo<T> *>::nodo nodo;

    //costruttore vuoto
    Linked_bintree ();

    //costruttore di copia
    Linked_bintree (const Linked_bintree &);

    //distruttore
    ~Linked_bintree ();

    //ridefinizione dei metodi virtuali puri della classe bintree

    void creabinalbero ();

    bool binalberovuoto() const;

    nodo binradice () const;

    nodo binpadre ( nodo ) const;

    nodo figliosinistro ( nodo ) const;

    nodo figliodestro ( nodo ) const;

    bool sinistrovuoto (const nodo &) const;

    bool destrovuoto (const nodo &) const;

    bintree<T, Nodo<T> *> costrbinalbero (bintree<T, Nodo<T> *>) const;

    void cancsottobinalbero (nodo);

    tipo_elem legginodo (const nodo &) const;

    void scrivinodo (const tipo_elem &, nodo);

    void insbinradice (const tipo_elem &);

    void insfigliosinistro (nodo, const tipo_elem &);

    void insfigliodestro (nodo, const tipo_elem &);

    //sovraccarico degli operatori

    Linked_bintree<T> &operator= (const Linked_bintree<T> &);

    bool operator== (const Linked_bintree<T> &);

    template<class T1>
    friend ostream &operator<< (ostream &, Linked_bintree<T1> &);

private:
    nodo root;
};

template<class T>
bool Linked_bintree<T>::binalberovuoto() const {
    return (root==nullptr);
}

template<class T>
void Linked_bintree<T>::insfigliodestro(Linked_bintree::nodo n, const tipo_elem &e) {
    if(destrovuoto(n)) {
        nodo nuovonodo = new Nodo<T>();
        nuovonodo->setElem(e);
        nuovonodo->setPadre(n);
        n->setDestro(nuovonodo);
    } else {
        throw std::out_of_range("il nodo ha gia un figlio destro");
    }
}

template<class T>
void Linked_bintree<T>::insfigliosinistro(Linked_bintree::nodo n, const tipo_elem &e) {
    if(sinistrovuoto(n)) {
        nodo nuovonodo = new Nodo<T>();
        nuovonodo->setElem(e);
        nuovonodo->setPadre(n);
        n->setSinistro(nuovonodo);
    } else {
        throw std::out_of_range("il nodo ha gia un figlio sinistro");
    }
}

template<class T>
void Linked_bintree<T>::insbinradice(const tipo_elem &e) {
    if(root == nullptr) {
        root = new Nodo<T>();
        root->setElem(e);
    } else {
        throw std::out_of_range("l'albero ha gia una radice");
    }
}

template<class T>
void Linked_bintree<T>::scrivinodo(const tipo_elem &e, Linked_bintree::nodo n) {
    n->setElem(e);
}

template<class T>
typename Linked_bintree<T>::tipo_elem Linked_bintree<T>::legginodo(Linked_bintree::nodo const &n) const {
    return n->getElem();
}

template<class T>
bool Linked_bintree<T>::destrovuoto(Linked_bintree::nodo const &n) const {
    return (n->getDestro() == nullptr);
}

template<class T>
bool Linked_bintree<T>::sinistrovuoto(Linked_bintree::nodo const &n) const {
    return (n->getSinistro() == nullptr);
}

template<class T>
typename Linked_bintree<T>::nodo Linked_bintree<T>::figliodestro(Linked_bintree::nodo  n) const {
    return n->getDestro();
}

template<class T>
typename Linked_bintree<T>::nodo Linked_bintree<T>::figliosinistro(Linked_bintree::nodo  n) const {
    return n->getSinistro();
}

template<class T>
typename Linked_bintree<T>::nodo Linked_bintree<T>::binpadre(Linked_bintree::nodo n) const {
    return n->getPadre();
}

template<class T>
typename Linked_bintree<T>::nodo Linked_bintree<T>::binradice() const {
    if(!binalberovuoto()) {
        return root;
    } else {
        throw std::out_of_range("albero vuoto, radice non presente");
    }
}

template<class T>
void Linked_bintree<T>::creabinalbero() {
    root = nullptr;
}

template<class T>
Linked_bintree<T>::~Linked_bintree() {
    cancsottobinalbero(root);
}

template<class T>
Linked_bintree<T>::Linked_bintree() {
    creabinalbero();
}

#endif //DATA_STRUCTURES_LINKED_BINTREE_H
