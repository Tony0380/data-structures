//
// Created by Colam on 29/07/2024.
//

#include <iostream>
#include "Stack_Vector.h"
#include "Linked_Stack.h"
using namespace std;

int main () {
    Linked_Stack<int> S;
    S.inpila(1);
    S.stampapila();
    S.inpila(2);
    S.inpila(3);
    S.stampapila();
    S.fuoripila();
    S.stampapila();
    cout<<S.leggipila()<<endl;
    return 0;
}