//
// Created by Colam on 03/08/2024.
//

#include "AlberoNario/Linked_tree.h"
int main () {
    Linked_tree<int> T;
    Nodo<int>* n = new Nodo<int>();
    T.creaalbero();
    n->setElem(5);
    T.insradice(n);
    if(T.foglia(n)) {
        cout << "Il nodo è una foglia" << endl;
    }
    Nodo<int>* p = new Nodo<int>();
    Nodo<int>* s = new Nodo<int>();
    p->setElem(6);
    n->aggiungiFiglio(p);
    s->setElem(7);
    n->aggiungiFiglio(s);
    n->stampaFigli();
    cout << "Il padre del nodo è: " << T.padre(p)->getElem() << endl;
}