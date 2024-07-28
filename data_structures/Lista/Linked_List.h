//
// Created by Colam on 28/07/2024.
//
#include "List.h"
#include <iostream>
#include <stdexcept>
#ifndef DATA_STRUCTURES_LINKED_LIST_H
#define DATA_STRUCTURES_LINKED_LIST_H

#endif //DATA_STRUCTURES_LINKED_LIST_H

using namespace std;

template <class T>
class Nodo_Lista {
public:
    typedef T tipo_elem;

    //costruttori
    Nodo_Lista();
    Nodo_Lista(tipo_elem);

    //distruttore
    ~Nodo_Lista();

    //operatori
    Nodo_Lista* getPred() const;
    Nodo_Lista* getNext() const;
    void setNext(Nodo_Lista*);
    void setPred(Nodo_Lista*);
    tipo_elem getElem() const;
    void setElem(const tipo_elem&);

private:
    Nodo_Lista* Pred;
    Nodo_Lista* Next;
    tipo_elem Elem;
};



template <class T>
class Linked_List : public List<T, Nodo_Lista<T>*> {
public:
    typedef typename List<T, Nodo_Lista<T> *>::tipo_elem tipo_elem;
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
    tipo_elem leggilista(posizione) const;
    void scrivilista(const tipo_elem&, posizione);
    posizione primolista() const;
    bool finelista(posizione) const;
    posizione succlista(posizione) const;
    posizione predlista(posizione) const;
    void inslista(const tipo_elem&, posizione&);
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

template<class T>
Linked_List<T>::~Linked_List() {
    posizione p = primolista();
    while(!finelista(p)) {
        posizione q = p;
        p = succlista(p);
        delete q;
    }
    delete testa;

}

template<class T>
void Linked_List<T>::stampalista() const {
    cout<<"< ";
    for(Nodo_Lista<T>* p = primolista(); p != testa; p = succlista(p)) {
        cout<<p->getElem()<<" ";
    }
    cout<<">"<<endl;
}

template<class T>
void Linked_List<T>::canclista(Linked_List::posizione & p) {
    if(!finelista(p)) {
        p->getPred()->setNext(p->getNext());
        p->getNext()->setPred(p->getPred());
        delete p;
        lunghezza--;
    }
}

template<class T>
void Linked_List<T>::inslista(const Linked_List::tipo_elem & e, Linked_List::posizione & p) {
    Nodo_Lista<T>* nuovoNodo = new Nodo_Lista<T>;
    nuovoNodo->setElem(e);
    nuovoNodo->setPred(p->getPred());
    nuovoNodo->setNext(p);
    p->getPred()->setNext(nuovoNodo);
    p->setPred(nuovoNodo);
    lunghezza++;
}

template<class T>
typename Linked_List<T>::posizione Linked_List<T>::predlista(Linked_List::posizione p) const {
    return p->getPred();
}

template<class T>
typename Linked_List<T>::posizione Linked_List<T>::succlista(Linked_List::posizione p) const {
    return p->getNext();
}

template<class T>
bool Linked_List<T>::finelista(Linked_List::posizione p) const {
    return p == testa;
}

template<class T>
typename Linked_List<T>::posizione Linked_List<T>::primolista() const {
    return testa->getNext();
}

template<class T>
void Linked_List<T>::scrivilista(const Linked_List::tipo_elem &e, Linked_List::posizione p) {
    if (!finelista(p)) { //precondizione
        p->setElem(e);
    } else {
        throw std::out_of_range("Posizione non valida");
    }
}

template<class T>
typename Linked_List<T>::tipo_elem Linked_List<T>::leggilista(Linked_List::posizione p) const {
    if (!finelista(p)) { //precondizione
        return p->getElem();
    } else {
        throw std::out_of_range("Posizione non valida");
    }
}

template<class T>
bool Linked_List<T>::listavuota() const {
    return (lunghezza == 0);
}

template<class T>
Linked_List<T>::Linked_List(const Linked_List<T> &Copia) {
    crealista();
    posizione p = Copia.primolista();
    posizione p1 = this->primolista();
    while(!Copia.finelista(p)) {
        this->inslista(Copia.leggilista(p),p1);
        p1 = this->succlista(p1);
        p = Copia.succlista(p);
    }
}

template<class T>
void Linked_List<T>::crealista() {
    testa = new Nodo_Lista<T>;
    testa->setNext(testa);
    testa->setPred(testa);
    lunghezza = 0;
}

template<class T>
Linked_List<T>::Linked_List() {
    crealista();
}

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
void Nodo_Lista<T>::setElem(const Nodo_Lista::tipo_elem &newElem) {
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
Nodo_Lista<T>::Nodo_Lista(Nodo_Lista::tipo_elem newElem) {
    this->Elem = newElem;
    this->Next = NULL;
    this->Pred = NULL;
}

template<class T>
Nodo_Lista<T>::Nodo_Lista() {
    this->Next = NULL;
    this->Pred = NULL;
}

template<class T>
Nodo_Lista<T>::~Nodo_Lista() {
    delete Next;
    delete Pred;
}
