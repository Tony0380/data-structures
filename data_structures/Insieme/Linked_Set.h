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

    Linked_Set<T> unione (const Linked_Set<T> &) const;

    Linked_Set<T> intersezione (const Linked_Set<T> &) const;

    Linked_Set<T> differenza (const Linked_Set<T> &) const;

private:
    Nodo_Insieme<T> *testa;
};

template<class T>
Linked_Set<T> Linked_Set<T>::differenza (const Linked_Set<T> &) const {
    return Linked_Set<T> ();
}

template<class T>
Linked_Set<T> Linked_Set<T>::intersezione (const Linked_Set<T> &I2) const {
    Linked_Set<T> I;
    Nodo_Insieme<T> *sentinella = testa->getNext ();
    while (sentinella != testa) {
        if (I2.appartiene (sentinella->getElem ())) {
            I.inserisci (sentinella->getElem ());
        }
        sentinella = sentinella->getNext ();
    }
    return I;
}

template<class T>
Linked_Set<T> Linked_Set<T>::unione (const Linked_Set<T> &I2) const {
    Linked_Set<T> U;
    Nodo_Insieme<T> *sentinella = testa->getNext ();
    while (sentinella != testa) {
        U.inserisci (sentinella->getElem ());
        sentinella = sentinella->getNext ();
    }
    sentinella = I2.testa->getNext ();
    while (sentinella != I2.testa) {
        U.inserisci (sentinella->getElem ());
        sentinella = sentinella->getNext ();
    }
    return U;
}

template<class T>
void Linked_Set<T>::cancella (const tipo_elem &e) {
    if (appartiene (e)) { //precondizione
        bool trovato = false;
        Nodo_Insieme<T> *sentinella = testa->getNext ();
        while (!trovato) {
            if (sentinella->getElem () == e) {
                trovato = true;
                sentinella->getNext ()->setPred (sentinella->getPred ());
                sentinella->getPred ()->setNext (sentinella->getNext ());
            } else {
                sentinella = sentinella->getNext ();
            }
        }
        delete sentinella;
    }
}

template<class T>
Linked_Set<T>::~Linked_Set () {
    delete testa;
}

template<class T>
void Linked_Set<T>::inserisci (const tipo_elem &e) {
    if (!appartiene (e)) { //precondizione
        Nodo_Insieme<T> *nuovoNodo = new Nodo_Insieme (e);
        nuovoNodo->setPred (testa);
        nuovoNodo->setNext (testa->getNext ());
        testa->getNext ()->setPred (nuovoNodo);
        testa->setNext (nuovoNodo);
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
