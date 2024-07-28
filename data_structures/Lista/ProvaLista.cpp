//
// Created by Colam on 23/07/2024.
//

#include <iostream>
#include <stdexcept>
#include "Linked_List.h"
#include "List_Vector.h"

using namespace std;

int main() {
    Nodo_Lista<int> nodo1(1);
    Nodo_Lista<int> nodo2(2);
    nodo1.setNext(&nodo2);

    cout<<nodo1.getElem()<<nodo1.getNext()->getElem();
    nodo1.setElem(3);
    cout<<nodo1.getElem()<<nodo1.getNext()->getElem();
}