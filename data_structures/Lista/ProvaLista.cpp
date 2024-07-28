//
// Created by Colam on 23/07/2024.
//

#include <iostream>
#include <stdexcept>
#include "List_Vector.h"

using namespace std;

int main() {
    List_Vector<int> l = List_Vector<int>();
    int i = l.primolista();
    cout << i << endl;
    l.scrivilista(5, i);
    cout << "prova" << endl;
    l.stampalista();
    i = l.succlista(i);
    l.inslista(6,i);
    l.stampalista();
}