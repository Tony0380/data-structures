//
// Created by Colam on 02/08/2024.
//

#ifndef DATA_STRUCTURES_OPEN_HASHTABLE_H
#define DATA_STRUCTURES_OPEN_HASHTABLE_H

#define DIM 10

#include "../Lista/Linked_List.h"
#include "Dictionary.h"

template<typename K, typename V>
class Open_HashTable : public Dictionary<K, V, coppia<K, V>> {
public:
    typedef typename Dictionary<K, V, coppia<K, V>>::coppia coppia;
    typedef typename Dictionary<K, V, coppia>::valore valore;
    typedef typename Dictionary<K, V, coppia>::chiave chiave;
    typedef typename Linked_List<coppia>::posizione posizione;

    //costruttore vuoto
    Open_HashTable ();

    //costruttore di copia
    Open_HashTable (const Open_HashTable &);

    //distruttore
    ~Open_HashTable ();

    //ridefinizione dei metodi virtuali puri della classe Dictionary

    void creadizionario ();

    bool dizionariovuoto () const;

    bool appartiene (const chiave &) const;

    void inserisci (const coppia &);

    /*polimorfismo parametrico ad hoc di del metodo "inserisci" in caso venga inserita la coppia scissa in <K,V>
    piuttosto che in tipo coppia" */
    void inserisci (const chiave &, const valore &);

    void cancella (const chiave &);

    valore recupera (const chiave &) const;

    //sovraccarico operatori

    Open_HashTable<K, V> &operator= (const Open_HashTable<K, V> &);

    bool operator== (const Open_HashTable<K, V> &);

    template<class K1, class V1>
    friend ostream &operator<< (ostream &, Open_HashTable<K1, V1> &);

private:
    Linked_List<coppia> *tabella; //moltecipli liste per utilizzare le liste di trabocco
    myHash<K> hashFunction;
};

template<class K1, class V1>
ostream &operator<< (ostream &os, Open_HashTable<K1, V1> &ht2) {
    for (int i = 0; i < DIM; i++) {
        os << "[ " << i << " ] : " << ht2.tabella[i];
    }
    return os;
}

template<typename K, typename V>
bool Open_HashTable<K, V>::operator== (const Open_HashTable<K, V> &ht2) {
    for (int i = 0; i < DIM; i++) {
        if (!(tabella[i] == ht2.tabella[i])) {
            return false;
        }
    }
    return true;
}

template<typename K, typename V>
Open_HashTable<K, V> &Open_HashTable<K, V>::operator= (const Open_HashTable<K, V> &copia) {
    for (int i = 0; i < DIM; i++) {
        tabella[i] = copia.tabella[i];
    }
    return *this;
}

template<typename K, typename V>
void Open_HashTable<K, V>::inserisci (const Open_HashTable::chiave &k, const Open_HashTable::valore &v) {
    coppia newCoppia (k, v);
    if (!appartiene (newCoppia.getChiave ())) {
        int k2;
        chiave k1 = newCoppia.getChiave ();
        k2 = hashFunction (k1) % DIM;
        posizione sentinella = tabella[k2].primolista ();
        tabella[k2].inslista (newCoppia, sentinella);
    } else {
        cout << "Elemento già presente";
    }
}

template<typename K, typename V>
typename Open_HashTable<K, V>::valore Open_HashTable<K, V>::recupera (const Open_HashTable::chiave &k1) const {
    if (appartiene (k1)) {
        int k;
        k = hashFunction (k1) % DIM;
        posizione sentinella = tabella[k].primolista ();
        while (!tabella[k].finelista (sentinella)) {
            if (sentinella->getElem ().getChiave () == k1) {
                return sentinella->getElem ().getValore ();
            }
            sentinella = tabella[k].succlista (sentinella);
        }
    } else {
        cout << "Elemento non presente";
    }
}

template<typename K, typename V>
void Open_HashTable<K, V>::cancella (const Open_HashTable::chiave &k1) {
    if (appartiene (k1)) {
        int k;
        k = hashFunction (k1) % DIM;
        posizione sentinella = tabella[k].primolista ();
        while (!tabella[k].finelista (sentinella)) {
            if (tabella[k].leggilista (sentinella).getChiave () == k1) {
                cout << "trovato";
                tabella[k].canclista (sentinella);
            }
            sentinella = tabella[k].succlista (sentinella);
        }
    } else {
        cout << "Elemento non presente";
    }
}

template<typename K, typename V>
void Open_HashTable<K, V>::inserisci (const Open_HashTable::coppia &newCoppia) {
    if (!appartiene (newCoppia.getChiave ())) {
        int k;
        chiave k1 = newCoppia.getChiave ();
        k = hashFunction (k1) % DIM;
        posizione sentinella = tabella[k].primolista ();
        tabella[k].inslista (newCoppia, sentinella);
    } else {
        cout << "Elemento già presente";
    }

}

template<typename K, typename V>
bool Open_HashTable<K, V>::appartiene (const chiave &k1) const {
    int k;
    k = hashFunction (k1) % DIM;
    posizione sentinella = tabella[k].primolista ();
    while (!tabella[k].finelista (sentinella)) {
        if (tabella[k].leggilista (sentinella).getChiave () == k1) {
            return true; //postcondizione
        }
        sentinella = tabella[k].succlista (sentinella);
    }
    return false;
}

template<typename K, typename V>
bool Open_HashTable<K, V>::dizionariovuoto () const {
    for (int i = 0; i < DIM; i++) {
        if (!tabella[i].listavuota ()) {
            return false;
        }
    }
    return true;
}

template<typename K, typename V>
Open_HashTable<K, V>::Open_HashTable (const Open_HashTable &d2) {
    for (int i = 0; i < DIM; i++) {
        tabella[i] = d2.tabella[i];
    }
}

template<typename K, typename V>
Open_HashTable<K, V>::~Open_HashTable () {
    delete[] tabella;
}

template<typename K, typename V>
void Open_HashTable<K, V>::creadizionario () {
    tabella = new Linked_List<coppia>[DIM];
}

template<typename K, typename V>
Open_HashTable<K, V>::Open_HashTable () {
    creadizionario ();
}

#endif //DATA_STRUCTURES_OPEN_HASHTABLE_H
