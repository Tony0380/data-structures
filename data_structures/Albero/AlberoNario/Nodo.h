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
    typedef typename Linked_List<Nodo<T>>::posizione posizione;

    Nodo ();

    Nodo *getPadre () const;

    void setPadre (Nodo *);

    tipo_elem getElem () const;

    void setElem (const tipo_elem &);

    void aggiungiFiglio (Nodo);

    void rimuoviFiglio (posizione);

    bool noFigli () const;

    posizione primoFiglio () const;

    Nodo *succFratello () const;

    bool ultimoFiglio () const;

private:
    Nodo *padre;

    tipo_elem Elemento;

    Linked_List<Nodo<T>*> Figli;
};

template<typename T>
Nodo<T> *Nodo<T>::succFratello () const {
    return Figli.succlista (this);
}

template<typename T>
bool Nodo<T>::ultimoFiglio () const {
    return Figli.finelista (this);
}

template<typename T>
typename Linked_List<Nodo<T>>::posizione Nodo<T>::primoFiglio () const {
    return Figli.primolista();
}

template<typename T>
bool Nodo<T>::noFigli () const {
    return Figli.listavuota ();
}

template<typename T>
void Nodo<T>::rimuoviFiglio (Nodo::posizione p) {
    Figli.canclista (p);
}

template<typename T>
void Nodo<T>::aggiungiFiglio (Nodo<T> n) {
    posizione p = Figli.primolista ();
    while(!Figli.finelista(p)) {
        p = Figli.succlista(p);
    }
    Figli.inslista (n, p);
}

template<typename T>
void Nodo<T>::setPadre (Nodo *newPadre) {
    padre = newPadre;
}

template<typename T>
Nodo<T> *Nodo<T>::getPadre () const {
    return padre;
}

template<typename T>
void Nodo<T>::setElem (const tipo_elem &newElem) {
    Elemento = newElem;
}

template<typename T>
typename Nodo<T>::tipo_elem Nodo<T>::getElem () const {
    return Elemento;
}

template<typename T>
Nodo<T>::Nodo () {
    Figli.crealista();
    padre = nullptr;
}

#endif //DATA_STRUCTURES_NODO_H
