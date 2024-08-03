//
// Created by Colam on 02/08/2024.
//

#include "Open_HashTable.h"

using namespace std;

int main() {
    Open_HashTable<int, int> tabella,tabella2;
    coppia A(1,2);
    tabella.inserisci(1,2);
    tabella.inserisci(11,3);
    cout<<tabella;
    if(tabella == tabella2) {
        cout<<"si";
    }
    tabella2 = tabella;
    cout<<tabella2;
    if(tabella == tabella2) {
        cout<<"si";
    }

}