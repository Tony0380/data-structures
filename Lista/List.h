//
// Created by Colam on 23/07/2024.
//

#ifndef DATA_STRUCTURES_LIST_H
#define DATA_STRUCTURES_LIST_H

#include <iostream>

template <typename T,typename P>
class List {
public:
    typedef T tipo_elem;
    typedef P posizione;

    virtual void crealista() = 0;
    virtual bool listavuota() const = 0;
    virtual tipo_elem leggilista(posizione) const = 0;
    virtual void scrivilista(const tipo_elem&, posizione) = 0;
    virtual posizione primolista() const = 0;
    virtual bool finelista(posizione) const = 0;
    virtual posizione succlista(posizione) const = 0;
    virtual posizione predlista(posizione) const = 0;
    virtual void inslista(const tipo_elem&, posizione&) = 0;
    virtual void canclista(posizione&) = 0;
};

#endif //DATA_STRUCTURES_LIST_H