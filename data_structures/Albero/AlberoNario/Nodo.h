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

    void setPadre(Nodo *);

    tipo_elem getElem () const;

    void setElem (const tipo_elem &);

    void aggiungiFiglio(Nodo<T>);

    void rimuoviFiglio(posizione);


private:
    Nodo *padre;

    tipo_elem Elemento;

    Linked_List<Nodo<T>> Figli;
};

template<typename T>
void Nodo<T>::rimuoviFiglio(Nodo::posizione p) {
    Figli.canclista(p);
}

template<typename T>
void Nodo<T>::aggiungiFiglio(Nodo<T> n) {
    posizione p = Figli.primolista();
    Figli.inslista(n, p);
}

template<typename T>
void Nodo<T>::setPadre(Nodo* newPadre) {
    padre = newPadre;
}

template<typename T>
Nodo<T> *Nodo<T>::getPadre() const {
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
    Figli = new Linked_List<Nodo<T>>;
    padre = nullptr;
}

#endif //DATA_STRUCTURES_NODO_H
