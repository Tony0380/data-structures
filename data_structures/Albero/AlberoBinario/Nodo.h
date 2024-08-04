//
// Created by Colam on 03/08/2024.
//

#ifndef DATA_STRUCTURES_NODO_H
#define DATA_STRUCTURES_NODO_H


template<typename T>
class Nodo {
public:
    typedef T tipo_elem;

    Nodo ();

    Nodo *getPadre () const;

    void setPadre(Nodo *);

    Nodo *getSinistro () const;

    Nodo *getDestro () const;

    void setSinistro (Nodo *);

    void setDestro (Nodo *);

    tipo_elem getElem () const;

    void setElem (const tipo_elem &);

private:
    Nodo *padre;
    Nodo *figlioSinistro;
    Nodo *figlioDestro;
    tipo_elem Elemento;
};

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
void Nodo<T>::setDestro (Nodo *newDestro) {
    figlioDestro = newDestro;
}

template<typename T>
void Nodo<T>::setSinistro (Nodo *newSinistro) {
    figlioSinistro = newSinistro;
}

template<typename T>
typename Nodo<T>::tipo_elem Nodo<T>::getElem () const {
    return Elemento;
}

template<typename T>
Nodo<T> *Nodo<T>::getDestro () const {
    return figlioDestro;
}

template<typename T>
Nodo<T> *Nodo<T>::getSinistro () const {
    return figlioSinistro;
}

template<typename T>
Nodo<T>::Nodo () {
    figlioDestro = nullptr;
    figlioSinistro = nullptr;
    padre = nullptr;
}

#endif //DATA_STRUCTURES_NODO_H
