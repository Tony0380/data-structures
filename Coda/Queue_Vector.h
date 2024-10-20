//
// Created by Colam on 31/07/2024.
//

#ifndef DATA_STRUCTURES_QUEUE_VECTOR_H
#define DATA_STRUCTURES_QUEUE_VECTOR_H

#include <iostream>
#include <stdexcept>
#include "Queue.h"

using namespace std;

template<class T>
class Queue_Vector : public Queue<T> {
public:
    typedef typename Queue<T>::tipo_elem tipo_elem;

    //costruttore vuoto
    Queue_Vector ();

    //costruttore di copia
    Queue_Vector (const Queue_Vector &);

    //distruttore
    ~Queue_Vector ();

    //ridefinizione degli operatori virtuali puri della classe Queue

    void creacoda ();

    bool codavuota () const;

    tipo_elem leggicoda () const;

    void fuoricoda ();

    void incoda (const tipo_elem &);

    //operatori ausiliari

    void stampacoda () const;

    //sovraccarico operatori

    Queue_Vector<T> &operator= (const Queue_Vector<T> &);

    bool operator== (const Queue_Vector<T> &);

private:
    void cambiadimensione ();

    const int DIM_INIZIALE = 1;
    tipo_elem *elementi;
    int lunghezza;
    int dimensione;
};

template<class T>
bool Queue_Vector<T>::operator== (const Queue_Vector<T> &q2) {
    if (lunghezza != q2.lunghezza) {
        return false;
    }
    for (int i = 0; i < lunghezza; i++) {
        if (elementi[i] != q2.elementi[i]) {
            return false;
        }
    }
    return true;
}

template<class T>
Queue_Vector<T> &Queue_Vector<T>::operator= (const Queue_Vector<T> &copia) {
    if (this != &copia) {
        delete[] elementi;
        lunghezza = 0;
        elementi = new tipo_elem[DIM_INIZIALE];
        for (int i = copia.lunghezza - 1; i >= 0; i--) {
            incoda (copia.elementi[i]);
        }
    }
    return *this;
}

template<class T>
void Queue_Vector<T>::cambiadimensione () {
    tipo_elem *tmp = new tipo_elem[dimensione * 2];
    for (int i = 0; i < lunghezza; i++) {
        tmp[i] = this->elementi[i];
    }
    delete[] this->elementi;
    this->elementi = tmp;
    this->dimensione *= 2;
}

template<class T>
void Queue_Vector<T>::stampacoda () const {
    cout << "< ";
    for (int i = 0; i < this->lunghezza; i++) {
        cout << this->elementi[i] << " ";
    }
    cout << ">" << endl;
}

template<class T>
void Queue_Vector<T>::incoda (const tipo_elem &e) {
    if (lunghezza == dimensione) {
        cambiadimensione ();
    }
    for (int i = lunghezza; i > 0; i--) {
        elementi[i] = elementi[i - 1];
    }
    elementi[0] = e;
    lunghezza++;
}

template<class T>
void Queue_Vector<T>::fuoricoda () {
    if (lunghezza >= 1) { //precondizione
        lunghezza--; //postcondizione
    } else {
        throw std::out_of_range ("Coda vuota");
    }
}

template<class T>
typename Queue_Vector<T>::tipo_elem Queue_Vector<T>::leggicoda () const {
    if (lunghezza >= 1) { //precondizione
        return elementi[lunghezza - 1]; //postcondizione
    } else {
        throw std::out_of_range ("Coda vuota");
    }
}

template<class T>
bool Queue_Vector<T>::codavuota () const {
    return lunghezza == 0; //postcondizione
}

template<class T>
Queue_Vector<T>::~Queue_Vector () {
    delete[] elementi;
}

template<class T>
Queue_Vector<T>::Queue_Vector (const Queue_Vector &copia) {
    creacoda ();
    for (int i = 0; i < copia.lunghezza; i++) {
        incoda (copia.elementi[i]);
    }

}

template<class T>
void Queue_Vector<T>::creacoda () {
    elementi = new tipo_elem[DIM_INIZIALE];
    lunghezza = 0;
    dimensione = DIM_INIZIALE;
}

template<class T>
Queue_Vector<T>::Queue_Vector () {
    creacoda ();
}

#endif //DATA_STRUCTURES_QUEUE_VECTOR_H
