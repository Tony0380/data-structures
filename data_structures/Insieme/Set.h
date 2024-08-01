//
// Created by Colam on 01/08/2024.
//

#ifndef DATA_STRUCTURES_SET_H
#define DATA_STRUCTURES_SET_H
#include <iostream>

template <typename T>
class Set {
public:
    typedef T tipo_elem;

    virtual void creainsieme() = 0;
    virtual bool insiemevuoto() const = 0;
    virtual bool appartiene(const tipo_elem &) const = 0;
    virtual void inserisci(const tipo_elem &) = 0;
    virtual void cancella(const tipo_elem &) = 0;

};
#endif //DATA_STRUCTURES_SET_H
