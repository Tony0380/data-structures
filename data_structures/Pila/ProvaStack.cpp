//
// Created by Colam on 29/07/2024.
//

#include <iostream>
#include "Stack_Vector.h"
#include "Linked_Stack.h"
using namespace std;

int main () {
    Linked_Stack<int> S;
    Stack_Vector<int> S2,S3;

    S2.inpila(1);
    S2.inpila(1);
    S2.inpila(1);
    S2.inpila(1);
    S2.inpila(1);
    S2.inpila(1);
    S2.inpila(1);
    S3.inpila(1);
    S3 = S2;
    S3.stampapila();
    return 0;
}