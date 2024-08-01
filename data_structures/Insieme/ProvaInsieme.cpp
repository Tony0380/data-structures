//
// Created by Colam on 01/08/2024.
//

#include "Linked_Set.h"

int main() {
    Linked_Set<int> A,B,C,D,E;
    A.inserisci(1);
    A.inserisci(2);
    A.inserisci(3);
    B.inserisci(4);
    B.inserisci(3);
    cout<<A;
    cout<<B;
    C = A.unione(B);
    D = A.intersezione(B);
    E = A.differenza(B);

    cout<<C;
    cout<<D;
    cout<<E;
    A=B;
    cout<<A;
    cout<<B;
    if(A==B) cout<<"ciao";
    return 0;
}