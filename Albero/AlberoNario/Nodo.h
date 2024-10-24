//
// Created by Colam on 03/08/2024.
//

#ifndef DATA_STRUCTURES_NODO_H
#define DATA_STRUCTURES_NODO_H

#include "../../Lista/Linked_List.h"

template<typename T>
class Nodo {
public:
    typedef T tipo_elem;
    typedef typename Linked_List<Nodo<T> *>::posizione posizione;

    //costruttore
    Nodo ();

    Nodo *getPadre () const;

    void setPadre (Nodo *);

    tipo_elem getElem () const;

    void setElem (const tipo_elem &);

    void aggiungiFiglio (Nodo *);

    void rimuoviFiglio (posizione);

    bool noFigli () const;

    posizione ultimoFiglio () const;

    posizione primoFiglio () const;

    posizione succFratello (posizione) const;

    bool ultimoFratello (posizione) const;

    void stampaFigli () const;

    void cancellaFigli ();

    //sovraccarico operatori

    Nodo &operator= (const Nodo &);

private:
    Nodo *padre;

    tipo_elem Elemento;

    Linked_List<Nodo<T> *> Figli;
};

template<typename T>
Nodo<T> &Nodo<T>::operator= (const Nodo &n) {
    padre = n.padre;
    Elemento = n.Elemento;
    Figli = n.Figli;
    return *this;
}

template<typename T>
typename Nodo<T>::posizione Nodo<T>::ultimoFiglio () const {
    return Figli.ultimolista ()->getPred ();
}

template<typename T>
Nodo<T>::Nodo () {
    padre = nullptr;
    Figli = Linked_List<Nodo<T> *> ();
}

template<typename T>
Nodo<T> *Nodo<T>::getPadre () const {
    return padre;
}

template<typename T>
void Nodo<T>::setPadre (Nodo *p) {
    padre = p;
}

template<typename T>
typename Nodo<T>::tipo_elem Nodo<T>::getElem () const {
    return Elemento;
}

template<typename T>
void Nodo<T>::setElem (const tipo_elem &e) {
    Elemento = e;
}

template<typename T>
void Nodo<T>::aggiungiFiglio (Nodo *figlio) {
    posizione p = Figli.ultimolista ();
    Figli.inslista (figlio, p);
    figlio->padre = this;
}

template<typename T>
void Nodo<T>::rimuoviFiglio (posizione p) {
    Figli.canclista (p);
    p->getElem ()->padre = nullptr;
}

template<typename T>
bool Nodo<T>::noFigli () const {
    return Figli.listavuota ();
}

template<typename T>
typename Nodo<T>::posizione Nodo<T>::primoFiglio () const {
    return Figli.primolista ();
}

template<typename T>
typename Nodo<T>::posizione Nodo<T>::succFratello (posizione p) const {
    return Figli.succlista (p);
}

template<typename T>
bool Nodo<T>::ultimoFratello (posizione p) const {
    return Figli.finelista (p);
}

template<typename T>
void Nodo<T>::stampaFigli () const {
    cout << "Figli di " << Elemento << ": ";
    for (posizione p = Figli.primolista (); !Figli.finelista (p); p = Figli.succlista (p)) {
        cout << p->getElem ()->getElem () << " ";
    }
}

template<typename T>
void Nodo<T>::cancellaFigli () {
    posizione p = Figli.primolista ();
    while (!Figli.finelista (p)) {
        posizione q = p;
        p = Figli.succlista (p);
        delete q->getElem ();
        delete q;
    }
}


#endif //DATA_STRUCTURES_NODO_H
