//
// Created by Colam on 01/08/2024.
//

#ifndef DATA_STRUCTURES_LINKED_SET_H
#define DATA_STRUCTURES_LINKED_SET_H

#endif //DATA_STRUCTURES_LINKED_SET_H

#include "Set.h"
#include <iostream>
#include <stdexcept>

using namespace std;

template<class T>
class Nodo_Insieme {
public:
    typedef T tipo_elem;

    //costruttori
    Nodo_Insieme ();

    Nodo_Insieme (const tipo_elem &);

    //distruttore
    ~Nodo_Insieme ();

    //operatori
    Nodo_Insieme *getPred () const;

    Nodo_Insieme *getNext () const;

    void setNext (Nodo_Insieme *);

    void setPred (Nodo_Insieme *);

    tipo_elem getElem () const;

    void setElem (const tipo_elem &);

private:
    Nodo_Insieme *Pred;
    Nodo_Insieme *Next;
    tipo_elem Elem;
};

template<class T>
class Linked_Set : public Set<T> {
public:
    typedef typename Set<T>::tipo_elem tipo_elem;

    //costruttore vuoto
    Linked_Set ();

    //costruttore di copia
    Linked_Set (const Linked_Set &);

    //distruttore
    ~Linked_Set ();

    //ridefinizione dei metodi virtuali puri della classe Set
    void creainsieme ();

    bool insiemevuoto () const;

    bool appartiene (const tipo_elem &) const;

    void inserisci (const tipo_elem &);

    void cancella (const tipo_elem &);

    Set<T> unione (const Set<T> &) const;

    Set<T> intersezione (const Set<T> &) const;

    Set<T> differenza (const Set<T> &) const;

private:
    Nodo_Insieme<T> *testa;
};

template<class T>
void Linked_Set<T>::inserisci (const tipo_elem &e) {
    if (!appartiene (e)) { //precondizione
        Nodo_Insieme<T> *nuovoNodo = new Nodo_Insieme (e);
        nuovoNodo->setPred (testa);
        nuovoNodo->setNext (testa->getNext ());
        testa->getNext ()->setPred (nuovoNodo);
        testa->setNext (nuovoNodo);
    } else {
        throw ::out_of_range ("elemento doppio");
    }


}

template<class T>
bool Linked_Set<T>::appartiene (const tipo_elem &e) const {
    Nodo_Insieme<T> *sentinella = testa->getNext ();
    while (sentinella != testa) {
        if (sentinella->getElem () == e) {
            return true;
        }
        sentinella = sentinella->getNext ();
    }
    return false;
}

template<class T>
bool Linked_Set<T>::insiemevuoto () const {
    return (testa->getNext () == testa);
}

template<class T>
void Linked_Set<T>::creainsieme () {
    testa = new Nodo_Insieme<T>;
    testa->setNext (testa);
    testa->setPred (testa);
}

template<class T>
Linked_Set<T>::Linked_Set () {
    creainsieme ();
}


template<class T>
Nodo_Insieme<T> *Nodo_Insieme<T>::getPred () const {
    return Pred;
}

template<class T>
Nodo_Insieme<T> *Nodo_Insieme<T>::getNext () const {
    return Next;
}

template<class T>
T Nodo_Insieme<T>::getElem () const {
    return Elem;
}

template<class T>
void Nodo_Insieme<T>::setElem (const Nodo_Insieme::tipo_elem &newElem) {
    this->Elem = newElem;
}

template<class T>
void Nodo_Insieme<T>::setNext (Nodo_Insieme<T> *newNext) {
    this->Next = newNext;
}

template<class T>
void Nodo_Insieme<T>::setPred (Nodo_Insieme<T> *newPred) {
    this->Pred = newPred;
}

template<class T>
Nodo_Insieme<T>::Nodo_Insieme (const Nodo_Insieme::tipo_elem &newElem) {
    this->Elem = newElem;
    this->Next = nullptr;
    this->Pred = nullptr;
}

template<class T>
Nodo_Insieme<T>::Nodo_Insieme () {
    this->Next = nullptr;
    this->Pred = nullptr;
}

template<class T>
Nodo_Insieme<T>::~Nodo_Insieme () {

}
