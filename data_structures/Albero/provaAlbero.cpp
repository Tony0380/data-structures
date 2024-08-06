//
// Created by Colam on 03/08/2024.
//

#include "AlberoBinario/Linked_bintree.h"
#include "AlberoNario/Linked_tree.h"
int main () {
    Linked_bintree<int> T,T2;
    Nodo<int> *nodo;
    T.insbinradice(1);
    nodo = T.binradice();
    T.insfigliosinistro(nodo,3);
    T.insfigliodestro(nodo,2);
    nodo = nodo->getSinistro();
    T.insfigliosinistro(nodo,4);
    T.cancsottobinalbero(nodo);
    T.stampavistapreordine();
    T.stampavistapostordine();
    T.stampavistasimmetrica();
    T2 = T;
    T2.stampavistasimmetrica();
}