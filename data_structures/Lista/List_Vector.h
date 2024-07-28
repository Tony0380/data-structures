//
// Created by Colam on 23/07/2024.
//

#ifndef DATA_STRUCTURES_LIST_VECTOR_H
#define DATA_STRUCTURES_LIST_VECTOR_H

#include <iostream>
#include <stdexcept>
#include "List.h"

using namespace std;

template <class T>
class List_Vector : public List<T,int> {
public:
    typedef typename List<T,int>::tipo_elem tipo_elem;
    typedef typename List<T,int>::posizione posizione;

    //costruttore vuoto
    List_Vector();
    //costruttore con dimensione elementi
    List_Vector(int);
    //costruttore di copia
    List_Vector(const List_Vector<T>&);
    //distruttore
    ~List_Vector();

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

private:
    tipo_elem* elementi;
    int dimensione;
    int lunghezza;
    void cambiadimensione();
};

template<class T>
void List_Vector<T>::stampalista() const {
    cout << "< ";
    for(int i = primolista(); i <= lunghezza; i = this->succlista(i)) {
        cout << this->leggilista(i) << " ";
    }
    cout << ">" <<endl;
}


//costruttore vuoto
template <class T>
List_Vector<T>::List_Vector()
{
    this->lunghezza = 1;
    this->crealista();
}

//costruttore con dimensione elementi
template <class T>
List_Vector<T>::List_Vector(int dim) {
    this->lunghezza = dim;
    this->crealista();
}

//costruttore di copia
template <class T>
List_Vector<T>::List_Vector(const List_Vector<T>& l) {
    this->lunghezza = l.lunghezza;
    this->dimensione = l.dimensione;
    this->elementi = new tipo_elem[this->dimensione];
    for(int i = 0; i < this->lunghezza; i++)
        this->elementi[i] = l.elementi[i];
}

//distruttore
template <class T>
List_Vector<T>::~List_Vector() {
    delete[] this->elementi;
}

//Operatori
template <class T>
void List_Vector<T>::crealista() {
    this->dimensione = 1;                                //
    this->elementi = new tipo_elem[this->dimensione];      // postcondizione
    cout << "Lista creata" << endl;
}

template <class T>
bool List_Vector<T>::listavuota() const {
    return this->dimensione == 0; //postcondizione
}

template <class T>
typename List_Vector<T>::tipo_elem List_Vector<T>::leggilista(posizione p) const {
    if ( p >= 1 && p <= this->lunghezza) { //precondizione
        return this->elementi[p - 1]; //postcondizione
    } else {
        throw std::out_of_range("Posizione non valida");
    }
}

template <class T>
void List_Vector<T>::scrivilista(const tipo_elem& e, posizione p) {
    if ( p >= 1 && p <= this->lunghezza) { //precondizione
        this->elementi[p - 1] = e; //postcondizione
    } else {
        throw std::out_of_range("Posizione non valida");
    }
}

template <class T>
typename List_Vector<T>::posizione List_Vector<T>::primolista() const {
    return 1; //postcondizione
}

template <class T>
bool List_Vector<T>::finelista(posizione p) const {
    if ( p >= 1 && p <= this->lunghezza + 1) { //precondizione
        if (p == lunghezza + 1) {
            return true; //postcondizione
        } else {
            return false; //postcondizione
        }
    } else {
        throw std::out_of_range("Posizione non valida");
    }
}

template <class T>
typename List_Vector<T>::posizione List_Vector<T>::succlista(posizione p) const {
    if ( p >= 1 && p <= this->lunghezza) { //precondizione
        return p + 1; //postcondizione
    } else {
        throw std::out_of_range("Posizione non valida");
    }
}

template <class T>
typename List_Vector<T>::posizione List_Vector<T>::predlista(posizione p) const {
    if ( p >= 2 && p <= this->lunghezza + 1) { //precondizione
        return p - 1; //postcondizione
    } else {
        throw std::out_of_range("Posizione non valida");
    }
}

template <class T>
void List_Vector<T>::inslista(const tipo_elem& e, posizione& p) {
    if (this->lunghezza == this->dimensione) {
        cambiadimensione();
    }

    if ( p >= 2 && p <= this->lunghezza + 1) { //precondizione
        for (int i = lunghezza; i >= p; i--) {
            elementi[i-1] = elementi[i];
        }
        elementi[p-1] = e; //postcondizione
        lunghezza++;

    } else {
        throw std::out_of_range("Posizione non valida");
    }
}

template <class T>
void List_Vector<T>::canclista(posizione& p) {
    if ( p >= 2 && p <= this->lunghezza ) { //precondizione
        for (int i = p; i < lunghezza - 1; i++) {
            elementi[i] = elementi[i+1];
        }
        lunghezza--;
    } else {
        throw std::out_of_range("Posizione non valida");
    }
}

template <class T>
void List_Vector<T>::cambiadimensione() {
    tipo_elem* temp = new tipo_elem[this->dimensione * 2];
    for (int i = 0; i < this->lunghezza; i++) {
        temp[i] = this->elementi[i];
    }
    delete[] this->elementi;
    this->elementi = temp;
    this->dimensione *= 2;
}

#endif //DATA_STRUCTURES_LIST_VECTOR_H
