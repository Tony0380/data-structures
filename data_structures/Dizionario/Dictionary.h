//
// Created by Colam on 02/08/2024.
//

#ifndef DATA_STRUCTURES_DICTIONARY_H
#define DATA_STRUCTURES_DICTIONARY_H

#include <iostream>

template<typename K, typename V>
class coppia {
public:
    typedef K chiave;
    typedef V valore;

    //costruttore
    coppia ();

    //costruttore completo
    coppia (const chiave &, const valore &);

    //costruttore di copia
    coppia (const coppia &);

    chiave getChiave () const;

    void setChiave (const chiave &);

    valore getValore () const;

    void setValore (const valore &);

private:
    chiave Key;
    valore Value;
};

template<typename K, typename V>
void coppia<K, V>::setValore (const valore &newValue) {
    Value = newValue;
}

template<typename K, typename V>
typename coppia<K, V>::valore coppia<K, V>::getValore () const {
    return Value;
}

template<typename K, typename V>
void coppia<K, V>::setChiave (const chiave &newKey) {
    Key = newKey;
}

template<typename K, typename V>
typename coppia<K, V>::chiave coppia<K, V>::getChiave () const {
    return Key;
}

template<typename K, typename V>
coppia<K, V>::coppia (const coppia &c2) {
    Key = c2.getChiave ();
    Value = c2.getValore ();
}

template<typename K, typename V>
coppia<K, V>::coppia (const chiave &k, const valore &v) {
    Key = k;
    Value = v;
}

template<typename K, typename V>
coppia<K, V>::coppia () = default;

template<typename K, typename V, typename C>
class Dictionary {
public:
    typedef K chiave;
    typedef V valore;
    typedef C coppia;

    virtual void creadizionario () = 0;

    virtual bool dizionariovuoto () const = 0;

    virtual bool appartiene (chiave) const = 0;

    virtual void inserisci (coppia) = 0;

    virtual void cancella (chiave) = 0;

    virtual valore recupera (chiave) const = 0;


};

#endif //DATA_STRUCTURES_DICTIONARY_H
