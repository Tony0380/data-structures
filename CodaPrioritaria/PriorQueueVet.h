//
// Created by tony on 25/10/24.
//

#ifndef DATA_STRUCTURES_PRIORQUEUEVET_H
#define DATA_STRUCTURES_PRIORQUEUEVET_H

#include "PriorQueue.h"


template <class T>
class PriorQueueVet : public PriorQueue<T> {
private:
    typedef T tipoelem;

    void creaprioricoda();

    void inserisci(tipoelem);

    tipoelem min();

    virtual void cancellamin();

private:

    tipoelem coda[];

};



#endif //DATA_STRUCTURES_PRIORQUEUEVET_H
