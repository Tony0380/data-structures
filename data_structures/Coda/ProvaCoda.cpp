//
// Created by Colam on 31/07/2024.
//

#include <iostream>
#include <stdexcept>

#include "Queue_Vector.h"

int main() {
    Queue_Vector<int> Q1,Q2;
    Q1.incoda(1);
    Q2.incoda(2);
    Q2.incoda(3);
    Q2.incoda(4);
    Q2.stampacoda();
    Q2.fuoricoda();
    Q2.stampacoda();
    if(Q1 == Q2) {
        cout<<"si";
    }
    Q1 = Q2;
    Q1.stampacoda();
    Q1.fuoricoda();
    Q1.incoda(9);
    if(Q1 == Q2) {
        cout<<"si";
    }
}