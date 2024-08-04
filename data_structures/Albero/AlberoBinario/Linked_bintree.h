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

    bool sinistrovuoto ( nodo ) const;

    bool destrovuoto ( nodo ) const;

    void cancsottobinalbero (nodo);

    tipo_elem legginodo ( nodo ) const;

    void scrivinodo (const tipo_elem &, nodo);

    void insbinradice (const tipo_elem &);

    void insfigliosinistro (nodo, const tipo_elem &);

    void insfigliodestro (nodo, const tipo_elem &);

    void stampavistapreordine() const;

    void stampavistapostordine() const;

    void stampavistasimmetrica() const;
    //sovraccarico degli operatori

    Linked_bintree<T> &operator= (const Linked_bintree<T> &);

    bool operator== (const Linked_bintree<T> &);

private:

    void cancellanodo(nodo);

    nodo root;

    void stampavistapreordineRic(nodo n) const;

    void stampavistapostordineRic(nodo n) const;

    void stampavistasimmetricaRic(nodo n) const;
};

template<class T>
void Linked_bintree<T>::stampavistasimmetrica() const {
    if (binalberovuoto()) {
        cout << "Albero vuoto" << endl;
    } else {
        stampavistasimmetricaRic(root);
        cout << endl;
    }
}

template<class T>
void Linked_bintree<T>::stampavistasimmetricaRic(nodo n) const {
    if (n != nullptr) {
        stampavistasimmetricaRic(figliosinistro(n));  // Visita il sottoalbero sinistro
        cout << legginodo(n) << " ";  // Visita il nodo corrente
        stampavistasimmetricaRic(figliodestro(n));  // Visita il sottoalbero destro
    }
}

template<class T>
Linked_bintree<T>::Linked_bintree(const Linked_bintree &copia) {
    if(copia.binalberovuoto()) {
        creabinalbero();
    } else {
        root = new Nodo<T>();
        root->setElem(copia.legginodo(copia.binradice()));
        nodo n = copia.binradice();
        nodo n1 = root;
        while(!copia.destrovuoto(n)) {
            if(!copia.sinistrovuoto(n)) {
                insfigliosinistro(n1, copia.legginodo(copia.figliosinistro(n)));
                n1 = figliosinistro(n1);
                n = copia.figliosinistro(n);
            }
            if(!copia.destrovuoto(n)) {
                insfigliodestro(n1, copia.legginodo(copia.figliodestro(n)));
                n1 = figliodestro(n1);
                n = copia.figliodestro(n);
            }
        }
    }
}

template<class T>
void Linked_bintree<T>::stampavistapostordine() const {
    if (binalberovuoto()) {
        cout << "Albero vuoto" << endl;
    } else {
        stampavistapostordineRic(root);
        cout << endl;
    }
}

template<class T>
void Linked_bintree<T>::stampavistapostordineRic(nodo n) const {
    if (n != nullptr) {
        stampavistapostordineRic(figliosinistro(n));  // Visita il sottoalbero sinistro
        stampavistapostordineRic(figliodestro(n));  // Visita il sottoalbero destro
        cout << legginodo(n) << " ";  // Visita il nodo corrente
    }
}

template<class T>
void Linked_bintree<T>::stampavistapreordine() const {
    if (binalberovuoto()) {
        cout << "Albero vuoto" << endl;
    } else {
        stampavistapreordineRic(root);
        cout << endl;
    }
}

template<class T>
void Linked_bintree<T>::stampavistapreordineRic(nodo n) const {
    if (n != nullptr) {
        cout << legginodo(n) << " ";  // Visita il nodo corrente
        stampavistapreordineRic(figliosinistro(n));  // Visita il sottoalbero sinistro
        stampavistapreordineRic(figliodestro(n));  // Visita il sottoalbero destro
    }
}

template<class T>
void Linked_bintree<T>::cancellanodo(Linked_bintree::nodo n) {
    if(n != nullptr) {
        cancellanodo(n->getDestro());
        cancellanodo(n->getSinistro());
        n = nullptr;
        delete n;
    }
}

template<class T>
void Linked_bintree<T>::cancsottobinalbero(Linked_bintree::nodo n) {
    cancellanodo(n->getSinistro());
    cancellanodo(n->getDestro());
    n->setSinistro(nullptr);
    n->setDestro(nullptr);
}

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
typename Linked_bintree<T>::tipo_elem Linked_bintree<T>::legginodo(Linked_bintree::nodo n) const {
    return n->getElem();
}

template<class T>
bool Linked_bintree<T>::destrovuoto(Linked_bintree::nodo n) const {
    return (n->getDestro() == nullptr);
}

template<class T>
bool Linked_bintree<T>::sinistrovuoto(Linked_bintree::nodo n) const {
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
    if(root != nullptr) {
        cancsottobinalbero(root);
        delete root;
    }
}

template<class T>
Linked_bintree<T>::Linked_bintree() {
    creabinalbero();
}

#endif //DATA_STRUCTURES_LINKED_BINTREE_H
