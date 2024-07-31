//
// Created by Colam on 31/07/2024.
//

#ifndef DATA_STRUCTURES_QUEUE_H
#define DATA_STRUCTURES_QUEUE_H

#include <iostream>

template <typename T>
class Queue {
public:
    typedef T tipo_elem;

    virtual void creacoda() = 0;
    virtual bool codavuota() const = 0;
    virtual tipo_elem leggicoda() const = 0;
    virtual void fuoricoda() = 0;
    virtual void incoda(const tipo_elem&) = 0;
};

#endif //DATA_STRUCTURES_QUEUE_H
