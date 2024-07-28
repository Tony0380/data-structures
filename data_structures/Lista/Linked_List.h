//
// Created by Colam on 28/07/2024.
//
#include "List.h"
#include <stdexcept>
#ifndef DATA_STRUCTURES_LINKED_LIST_H
#define DATA_STRUCTURES_LINKED_LIST_H

#endif //DATA_STRUCTURES_LINKED_LIST_H


template <class T>
class Nodo_Lista {
public:
    typedef T tipoelem;

    //costruttore
    Nodo_Lista(tipoelem);

    Nodo_Lista* getPred() const;
    Nodo_Lista* getNext() const;
    void setNext(Nodo_Lista*);
    void setPred(Nodo_Lista*);
    tipoelem getElem() const;
    void setElem(const tipoelem&);

private:
    Nodo_Lista* Pred;
    Nodo_Lista* Next;
    tipoelem Elem;
};

template <class T>
class Linked_List : public List<T, Nodo_Lista<T>*> {
public:
    typedef typename List<T, Nodo_Lista<T> *>::tipoelem tipoelem;
    typedef typename List<T, Nodo_Lista<T> *>::posizione posizione;

    //costruttore vuoto
    Linked_List();
    //costruttore di copia
    Linked_List(const Linked_List<T>&);
    //distruttore
    ~Linked_List();

    //ridefinizione dei metodi virtuali puri della classe List
    void crealista();
    bool listavuota() const;
    tipoelem leggilista(posizione) const;
    void scrivilista(const tipoelem&, posizione);
    posizione primolista() const;
    bool finelista(posizione) const;
    posizione succlista(posizione) const;
    posizione predlista(posizione) const;
    void inslista(const tipoelem&, posizione&);
    void canclista(posizione&);


    //operatori ausiliari
    void stampalista() const;

    // sovraccarico operatori
    Linked_List<T>& operator= (const Linked_List<T>&);
    bool operator == (const Linked_List<T>&);


private:
    Nodo_Lista<T>* testa;
    int lunghezza;

};

template <class T>
Nodo_Lista<T> *Nodo_Lista<T>::getPred() const {
    return Pred;
}

template <class T>
Nodo_Lista<T> *Nodo_Lista<T>::getNext() const {
    return Next;
}

template <class T>
T Nodo_Lista<T>::getElem() const {
    return Elem;
}

template <class T>
void Nodo_Lista<T>::setElem(const Nodo_Lista::tipoelem &newElem) {
    this->Elem = newElem;
}

template <class T>
void Nodo_Lista<T>::setNext(Nodo_Lista<T> *newNext) {
    this->Next = newNext;
}

template <class T>
void Nodo_Lista<T>::setPred(Nodo_Lista<T> *newPred) {
    this->Pred = newPred;
}

template <class T>
Nodo_Lista<T>::Nodo_Lista(Nodo_Lista::tipoelem newElem) {
    this->Elem = newElem;
    this->Next = NULL;
    this->Pred = NULL;
}
