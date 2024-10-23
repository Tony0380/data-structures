//
// Created by Colam on 23/07/2024.
//

#include <iostream>
#include <stdexcept>
#include "Linked_List.h"
#include "List_Vector.h"

using namespace std;

int main() {
<<<<<<< Updated upstream
    Linked_List<int> l,l2;
    l.crealista();
    Nodo_Lista<int>* p = l.ultimolista();
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

=======
    List_Vector<int> l = List_Vector<int>();
    int i = l.primolista();
    cout << i << endl;
    l.scrivilista(5, i);
    cout << "prova" << endl;
    l.stampalista();
    i = l.succlista(i);
    l.inslista(6,i);
    l.stampalista();
    return 0;
>>>>>>> Stashed changes
}