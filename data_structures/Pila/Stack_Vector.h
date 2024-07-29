//
// Created by Colam on 29/07/2024.
//

#ifndef DATA_STRUCTURES_STACK_VECTOR_H
#define DATA_STRUCTURES_STACK_VECTOR_H

#include <iostream>
#include <stdexcept>
#include "Stack.h"

using namespace std;

template<class T>
class Stack_Vector : public Stack<T,int> {
public:
    typedef typename Stack<T, int>::tipo_elem tipo_elem;
    typedef typename Stack<T, int>::posizione posizione;

    //costruttore vuoto
    Stack_Vector();

    //costruttore di copia
    Stack_Vector(const Stack_Vector &);

    //distruttore
    ~Stack_Vector();

    //ridefinizione dei metodi virtuali puri della classe Stack
    void creapila();

    bool pilavuota() const;

    tipo_elem leggipila() const;

    void fuoripila();

    void inpila(const tipo_elem &);

    void stampapila();
private:
    void cambiadimensione();
    const int DIM_INIZIALE = 10;
    tipo_elem* elementi;
    int dimensione;
    int testa;
};

template<class T>
Stack_Vector<T>::Stack_Vector() {
    creapila();
}

template<class T>
Stack_Vector<T>::Stack_Vector(const Stack_Vector & S) {
    this->testa = S.testa;
    this->dimensione = S.dimensione;
    this->elementi = new tipo_elem[this->dimensione];
    for(int i = 0; i < this->dimensione; i++) {
        this->elementi[i] = S.elementi[i];
    }
}

template<class T>
Stack_Vector<T>::~Stack_Vector() {
    delete[] this->elementi;
}

template<class T>
void Stack_Vector<T>::cambiadimensione() {
    tipo_elem* tmp = new tipo_elem[dimensione];
    for(int i = 0; i < dimensione; i++) {
        tmp[i] = this->elementi[i];
    }
    delete[] this->elementi;
    this->elementi = tmp;
    this->dimensione *= 2;
}

template<class T>
void Stack_Vector<T>::creapila() {
    this->dimensione = DIM_INIZIALE;
    this->testa = 0;
    elementi = new tipo_elem[dimensione];
}

template<class T>
bool Stack_Vector<T>::pilavuota() const {
    return (testa == 0);
}

template<class T>
typename Stack_Vector<T>::tipo_elem Stack_Vector<T>::leggipila() const {
    if (this->testa >= 1) { //precondizione
        return this->elementi[testa - 1]; //postcondizione
    } else {
        throw std::out_of_range("Nulla da leggere");
    }
}

template<class T>
void Stack_Vector<T>::fuoripila() {
    this->testa -= 1;
}

template<class T>
void Stack_Vector<T>::Stack_Vector<T>::inpila(const tipo_elem & elem) {
    if( this->testa ==  this->dimensione) {
        this->cambiadimensione();
    }

    this->testa += 1;
    this->elementi[testa - 1] = elem;
}

template<class T>
void Stack_Vector<T>::stampapila() {
    cout<<"< ";
    for (int i = 0; i < this->testa; i++) {
        cout<<this->elementi[i]<<" ";
    }
    cout<<">"<<endl;
}
#endif //DATA_STRUCTURES_STACK_VECTOR_H
