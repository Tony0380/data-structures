//
// Created by Colam on 29/07/2024.
//

#include <iostream>
#include "Stack_Vector.h"

using namespace std;

int main () {
    Stack_Vector<int> S;
    S.inpila(1);
    S.stampapila();
    S.inpila(2);
    S.inpila(3);
    S.stampapila();
    S.fuoripila();
    S.stampapila();
    cout<<S.leggipila()<<endl;
    Stack_Vector<int> S2 = Stack_Vector(S);
    S2.stampapila();
    return 0;
}