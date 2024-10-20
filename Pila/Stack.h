//
// Created by Colam on 29/07/2024.
//

#ifndef DATA_STRUCTURES_STACK_H
#define DATA_STRUCTURES_STACK_H

#include <iostream>

template <typename T>
class Stack {
public:
    typedef T tipo_elem;

    virtual void creapila() = 0;
    virtual bool pilavuota() const = 0;
    virtual tipo_elem leggipila() const = 0;
    virtual void fuoripila() = 0;
    virtual void inpila(const tipo_elem&) = 0;
};
#endif //DATA_STRUCTURES_STACK_H
