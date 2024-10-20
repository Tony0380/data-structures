//
// Created by Colam on 30/07/2024.
//
#include "Stack.h"
#include <iostream>
#include <stdexcept>

#ifndef DATA_STRUCTURES_LINKED_STACK_H
#define DATA_STRUCTURES_LINKED_STACK_H

using namespace std;

template<class T>
class Nodo_Stack {
public:
    typedef T tipo_elem;

    //costruttori:
    Nodo_Stack ();

    Nodo_Stack (const tipo_elem &);

    //distruttore
    ~Nodo_Stack ();

    //operatori;
    Nodo_Stack *getPred () const;

    void setPred (Nodo_Stack *);

    tipo_elem getElem () const;

    void setElem (const tipo_elem &);

private:
    Nodo_Stack *Pred;
    tipo_elem Elem;
};

template<class T>
class Linked_Stack : public Stack<T> {
public:
    typedef typename Stack<T>::tipo_elem tipo_elem;

    //costruttore vuoto
    Linked_Stack ();

    //costruttore di copia
    Linked_Stack (const Linked_Stack<T> &);

    //costruttore con primo elemento;
    Linked_Stack (const tipo_elem &);

    //distruttore
    ~Linked_Stack ();

    //operatori
    void creapila ();

    bool pilavuota () const;

    tipo_elem leggipila () const;

    void fuoripila ();

    void inpila (const tipo_elem &);

    //operatori ausiliari

    void stampapila () const;

    //sovraccarico operatori

    Linked_Stack<T> &operator= (const Linked_Stack<T> &);

    bool operator== (const Linked_Stack<T> &);

private:
    Nodo_Stack<T> *testa;
};

template<class T>
Linked_Stack<T> &Linked_Stack<T>::operator= (const Linked_Stack<T> &s2) {
    if (this != &s2) {
        while (!pilavuota ()) {
            fuoripila ();
        }
        Linked_Stack<T> tmp;
        Nodo_Stack<T> *tmp1 = s2.testa;
        while (tmp1 != nullptr) {
            tmp.inpila (tmp1->getElem ());
            tmp1 = tmp1->getPred ();
        }
        while (!tmp.pilavuota ()) {
            inpila (tmp.leggipila ());
            tmp.fuoripila ();
        }
    }
    return *this;
}

template<class T>
bool Linked_Stack<T>::operator== (const Linked_Stack<T> &s2) {
    Nodo_Stack<T> *tmp1 = testa;
    Nodo_Stack<T> *tmp2 = s2.testa;
    while (tmp1 != nullptr) {
        if (tmp1->getElem () != tmp2->getElem ()) {
            return false;
        }
        tmp1 = tmp1->getPred ();
        tmp2 = tmp2->getPred ();
    }
    return true;
}

template<class T>
void Linked_Stack<T>::stampapila() const {
    cout << "< ";
    Nodo_Stack<T> *sentinella = testa;
    while (sentinella != nullptr) {
        cout << sentinella->getElem() << " ";
        sentinella = sentinella->getPred();
    }
    cout << ">" << endl;
}

template<class T>
void Linked_Stack<T>::inpila (const tipo_elem &e) {
    Nodo_Stack<T> *nuovaTesta = new Nodo_Stack<T>;
    nuovaTesta->setElem (e);
    nuovaTesta->setPred (testa);
    testa = nuovaTesta; //postcondizione
}

template<class T>
void Linked_Stack<T>::fuoripila() {
    if (!pilavuota()) { // Precondizione
        Nodo_Stack<T> *tmp = testa;
        testa = testa->getPred(); // Postcondizione
        delete tmp;
    } else {
        throw std::out_of_range("PILA VUOTA");
    }
}

template<class T>
typename Linked_Stack<T>::tipo_elem Linked_Stack<T>::leggipila () const {
    if (!pilavuota ()) { //precondizione
        return testa->getElem (); //postcondizione
    } else {
        throw std::out_of_range ("PILA VUOTA");
    }
}

template<class T>
bool Linked_Stack<T>::pilavuota () const {
    return (testa == nullptr); //postcondizione
}

template<class T>
void Linked_Stack<T>::creapila () {
    testa = nullptr;
}

template<class T>
Linked_Stack<T>::Linked_Stack (const tipo_elem &e) {
    creapila ();
    inpila (e);
}

template<class T>
Linked_Stack<T>::~Linked_Stack () {
    while (!pilavuota ()) {
        fuoripila ();
    }
}

template<class T>
Linked_Stack<T>::Linked_Stack(const Linked_Stack<T> &copia) {
    testa = nullptr;
    Nodo_Stack<T> *tmp1 = copia.testa;
    while (tmp1 != nullptr) {
        inpila(tmp1->getElem());
        tmp1 = tmp1->getPred();
    }
}

template<class T>
Linked_Stack<T>::Linked_Stack () {
    creapila ();
}


template<class T>
void Nodo_Stack<T>::setElem (const tipo_elem &newElem) {
    this->Elem = newElem;
}

template<class T>
typename Nodo_Stack<T>::tipo_elem Nodo_Stack<T>::getElem () const {
    return this->Elem;
}

template<class T>
void Nodo_Stack<T>::setPred (Nodo_Stack *newPred) {
    this->Pred = newPred;
}

template<class T>
Nodo_Stack<T> *Nodo_Stack<T>::getPred () const {
    return this->Pred;
}

template<class T>
Nodo_Stack<T>::~Nodo_Stack () {

}

template<class T>
Nodo_Stack<T>::Nodo_Stack (const tipo_elem &e) {
    this->Pred = nullptr;
    this->Elem = e;
}

template<class T>
Nodo_Stack<T>::Nodo_Stack () {
    this->Pred = nullptr;
}

#endif //DATA_STRUCTURES_LINKED_STACK_H
