//
// Created by Colam on 31/07/2024.
//

#include <iostream>
#include <stdexcept>

#include "Queue_Vector.h"
#include "Linked_Queue.h"

int main() {
    Linked_Queue<int> Q1,Q2;
    Q1.incoda(1);
    Q1.incoda(2);
    Q1.incoda(3);
    Q1.fuoricoda();
    Q2 = Q1;
    Q2.stampacoda();
    Q1.stampacoda();
    if(Q1 == Q2) cout<<123;
}