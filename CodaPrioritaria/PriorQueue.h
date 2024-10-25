//
// Created by tony on 25/10/24.
//

#ifndef DATA_STRUCTURES_PRIORQUEUE_H
#define DATA_STRUCTURES_PRIORQUEUE_H

template <typename T>
class PriorQueue {
public:
    typedef T tipoelem;
    virtual void creaprioricoda();
    virtual void inserisci(tipoelem);
    virtual tipoelem min();
    virtual void cancellamin();
};

#endif //DATA_STRUCTURES_PRIORQUEUE_H
