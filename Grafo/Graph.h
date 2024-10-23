//
// Created by tony on 23/10/24.
//

#ifndef DATA_STRUCTURES_GRAPH_H
#define DATA_STRUCTURES_GRAPH_H

#include <iostream>
#include "Nodo.h"

template <typename T>
class Graph {
public:
    typedef T tipoelem;

    virtual void creagrafo();
    virtual bool vuoto();
    virtual void insnodo(nodo);

};

#endif //DATA_STRUCTURES_GRAPH_H
