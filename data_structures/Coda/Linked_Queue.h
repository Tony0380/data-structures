//
// Created by Colam on 31/07/2024.
//

#ifndef DATA_STRUCTURES_LINKED_QUEUE_H
#define DATA_STRUCTURES_LINKED_QUEUE_H

#include <iostream>
#include <stdexcept>
#include "Queue.h"

using namespace std;

template<class T>
class Nodo_Queue {
public:
    typedef T tipo_elem;

    //costruttori:

    Nodo_Queue();

    Nodo_Queue(const tipo_elem &);

    //operatori;

    Nodo_Queue* getPred() const;

    void setPred(Nodo_Queue*);

    Nodo_Queue* getNext() const;

    void setNext(Nodo_Queue*);

    tipo_elem getElem() const;

    void setElem(const tipo_elem &);

private:
    Nodo_Queue* Pred;
    Nodo_Queue* Next;
    tipo_elem Elem;
};

template<class T>
class Linked_Queue : public Queue<T> {
public:
    typedef typename Queue<T>::tipo_elem tipo_elem;

    //costruttore vuoto
    Linked_Queue();

    //costruttore di copia
    Linked_Queue(const Linked_Queue &);

    //distruttore
    ~Linked_Queue();

    //operatori

    void creacoda();

    bool codavuota() const;

    tipo_elem leggicoda() const;

    void fuoricoda();

    void incoda(const tipo_elem &);

    //operatori ausiliari

    void stampacoda();

    //sovraccarico operatori

    Linked_Queue<T> &operator= (const Linked_Queue<T> &);

    bool operator== (const Linked_Queue<T> &);

private:
    Nodo_Queue<T>* testa;
};

template<class T>
Linked_Queue<T>::~Linked_Queue() {
    delete testa;
}

template<class T>
void Linked_Queue<T>::stampacoda() {
    cout << "< ";
    Nodo_Queue<T>* sentinella = testa->getNext();
    while(sentinella != testa) {
        cout << sentinella->getElem()<<" ";
        sentinella = sentinella->getNext();
    }
    cout << ">" << endl;
}

template<class T>
void Linked_Queue<T>::incoda(const tipo_elem &e) {
    Nodo_Queue<T> *nuovoNodo = new Nodo_Queue<T>(e);
    nuovoNodo->setNext(testa->getNext());
    testa->getNext()->setPred(nuovoNodo);
    testa->setNext(nuovoNodo);
    nuovoNodo->setPred(testa);
}

template<class T>
void Linked_Queue<T>::fuoricoda() {
    if(!codavuota()) { //precondizione
        Nodo_Queue<T> *tmp = testa->getPred()->getPred();
        testa->setPred(tmp);
        Nodo_Queue<T> *tmp2 = tmp->getNext();
        tmp->setNext(testa);
        delete tmp2;
    } else {
        throw std::out_of_range ("CODA VUOTA");
    }
}

template<class T>
typename Linked_Queue<T>::tipo_elem Linked_Queue<T>::leggicoda() const {
    if(!codavuota()) { //precondizione
        return testa->getPred()->getElem(); //postcondizione
    } else {
        throw std::out_of_range ("CODA VUOTA");
    }
}

template<class T>
bool Linked_Queue<T>::codavuota() const {
    return testa->getNext() == testa;
}

template<class T>
void Linked_Queue<T>::creacoda() {
    testa = new Nodo_Queue<T>;
    testa->setNext(testa);
    testa->setPred(testa);
}

template<class T>
Linked_Queue<T>::Linked_Queue() {
    creacoda();
}


template<class T>
void Nodo_Queue<T>::setElem(const tipo_elem &e) {
    this->Elem = e;
}

template<class T>
typename Nodo_Queue<T>::tipo_elem Nodo_Queue<T>::getElem() const {
    return this->Elem;
}

template<class T>
void Nodo_Queue<T>::setNext(Nodo_Queue *newNext) {
    this->Next = newNext;
}

template<class T>
Nodo_Queue<T> *Nodo_Queue<T>::getNext() const {
    return this->Next;
}

template<class T>
void Nodo_Queue<T>::setPred(Nodo_Queue *newPred) {
    this->Pred = newPred;
}

template<class T>
Nodo_Queue<T> *Nodo_Queue<T>::getPred() const {
    return this->Pred;
}

template<class T>
Nodo_Queue<T>::Nodo_Queue(const tipo_elem &e) {
    Pred = nullptr;
    Next = nullptr;
    Elem = e;
}

template<class T>
Nodo_Queue<T>::Nodo_Queue() {
    Pred = nullptr;
    Next = nullptr;
}

#endif //DATA_STRUCTURES_LINKED_QUEUE_H
