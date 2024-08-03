//
// Created by Colam on 23/07/2024.
//

#include <iostream>
#include <stdexcept>
#include "Linked_List.h"
#include "List_Vector.h"

using namespace std;

int main() {
    Linked_List<int> l,l2;
    l.crealista();
    Nodo_Lista<int>* p = l.primolista();
    l.inslista(1, p);
    l.inslista(2, p);
    l.inslista(3, p);
    l.inslista(4, p);
    cout <<l;
    p = l.predlista(p);
    l.canclista(p);
    cout <<l;
    l2 = l;
    if (l == l2) {
        cout <<"ciaooo;";
    }

    return 0;

}