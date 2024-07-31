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
    cout << "Lista vuota: " << l.listavuota() << endl;
    Nodo_Lista<int>* p = l.primolista();
    l.inslista(1, p);
    l.inslista(2, p);
    l.inslista(3, p);
    l.inslista(4, p);
    l.stampalista();
    p = l.predlista(p);
    p = l.predlista(p);
    l.inslista(5, p);
    l.stampalista();
    l2 = l;
    if(l2 == l) {cout << "== funziona:"<<endl; }
    l2.stampalista();
    l.stampalista();
    return 0;

}