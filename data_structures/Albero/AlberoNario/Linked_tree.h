//
// Created by Colam on 06/08/2024.
//

#ifndef DATA_STRUCTURES_LINKED_TREE_H
#define DATA_STRUCTURES_LINKED_TREE_H

#include "tree.h"
#include <stdexcept>

template<class T>
class Linked_tree : public tree<T, Nodo<T> *> {
public:
    typedef typename tree<T, Nodo<T> *>::tipo_elem tipo_elem;
    typedef typename tree<T, Nodo<T> *>::nodo nodo;
    typedef typename Linked_List<Nodo<T> *>::posizione posizione;

    //costruttore vuoto
    Linked_tree ();

    //costruttore di copia
    //Linked_tree(const Linked_tree &);

    //distruttore
    ~Linked_tree ();

    //ridefinizione dei metodi virtuali puri della classe tree

    void creaalbero ();

    bool alberovuoto () const;

    void insradice (nodo);

    nodo radice () const;

    nodo padre (nodo) const;

    bool foglia (nodo) const;

    nodo primofiglio (nodo) const;

    bool ultimofratello (nodo) const;

    nodo succfratello (nodo) const;

    //metodi aggiuntivi

    void insfiglio (nodo, nodo);

    void cancfiglio (nodo, nodo);

    void stampapreordine () const;

    void stampapostordine () const;

    void stampainvista (const int &) const;

    //sovraccarico degli operatori

    //Linked_tree &operator= (const Linked_tree &);

    //bool operator== (const Linked_tree &) const;

private:
    void stampainvistaRic (nodo, const int &) const;

    void stampapostordineRic (nodo) const;

    void stampapreordineRic (nodo) const;

    nodo Radice;
};

template<class T>
void Linked_tree<T>::stampainvista (const int &i) const {
    if (!alberovuoto ()) {
        stampainvistaRic (radice (), i);
    }
}

template<class T>
void Linked_tree<T>::stampainvistaRic (nodo n, const int &i) const {
    if (i == 0) {
        stampapreordineRic (n);
    } else {
        if (!foglia (n)) {
            posizione p = n->primoFiglio ();
            int j = 0;
            while ((!n->ultimoFratello (p) || p == n->primoFiglio ()) && j < i) {
                stampainvistaRic (p->getElem (), i);
                p = p->getNext ();
                j++;
            }
            cout << n->getElem () << " ";
            while (!n->ultimoFratello (p) || p == n->primoFiglio ()) {
                stampainvistaRic (p->getElem (), i);
                p = p->getNext ();
            }
        } else {
            cout << n->getElem () << " ";
        }
    }
}

template<class T>
void Linked_tree<T>::stampapostordine () const {
    if (!alberovuoto ()) {
        stampapostordineRic (radice ());
    }
}

template<class T>
void Linked_tree<T>::stampapostordineRic (nodo n) const {
    if (!foglia (n)) {
        posizione p = n->primoFiglio ();
        while (!n->ultimoFratello (p) || p == n->primoFiglio ()) {
            stampapostordineRic (p->getElem ());
            p = p->getNext ();
        }
    }
    cout << n->getElem () << " ";
}

template<class T>
void Linked_tree<T>::stampapreordine () const {
    if (!alberovuoto ()) {
        stampapreordineRic (radice ());
    }
}

template<class T>
void Linked_tree<T>::stampapreordineRic (nodo n) const {
    cout << n->getElem () << " ";
    if (!foglia (n)) {
        posizione p = n->primoFiglio ();
        while (!n->ultimoFratello (p) || p == n->primoFiglio ()) {
            stampapreordineRic (p->getElem ());
            p = p->getNext ();
        }
    }
}

template<class T>
Linked_tree<T>::~Linked_tree () {
    if (!alberovuoto ()) {
        delete Radice;
        Radice = nullptr;
    }
}

template<class T>
typename Linked_tree<T>::nodo Linked_tree<T>::succfratello (Linked_tree::nodo p) const {
    if (!ultimofratello (p)) {
        posizione tmp = p->getPadre ()->primoFiglio ();
        while (tmp->getElem () != p) {
            tmp = tmp->getNext ();
        }
        return p->getPadre ()->succFratello (tmp)->getElem ();
    } else {
        throw std::runtime_error ("Il nodo è l'ultimo fratello");
    }
}

template<class T>
bool Linked_tree<T>::ultimofratello (Linked_tree::nodo p) const {
    return p->getPadre ()->ultimoFiglio ()->getElem () == p;
}

template<class T>
typename Linked_tree<T>::nodo Linked_tree<T>::primofiglio (Linked_tree::nodo n) const {
    if (foglia (n)) {
        throw std::runtime_error ("Il nodo non ha figli");
    }
    return n->primoFiglio ()->getElem ();
}

template<class T>
bool Linked_tree<T>::foglia (Linked_tree::nodo n) const {
    return n->noFigli ();
}

template<class T>
typename Linked_tree<T>::nodo Linked_tree<T>::padre (Linked_tree::nodo n) const {
    if (n != radice ()) {
        return n->getPadre ();
    } else {
        throw std::runtime_error ("Il nodo è la radice");
    }
}

template<class T>
typename Linked_tree<T>::nodo Linked_tree<T>::radice () const {
    if (!alberovuoto ()) {
        return Radice;
    } else {
        throw std::runtime_error ("L'albero è vuoto");
    }
}

template<class T>
void Linked_tree<T>::insradice (Linked_tree::nodo n) {
    if (alberovuoto ()) {
        Radice = n;
        n->setPadre (nullptr);
    } else {
        throw std::runtime_error ("L'albero ha già una radice");
    }
}

template<class T>
bool Linked_tree<T>::alberovuoto () const {
    return Radice == nullptr;
}

template<class T>
Linked_tree<T>::Linked_tree () {
    creaalbero ();
}

template<class T>
void Linked_tree<T>::creaalbero () {
    Radice = nullptr;
}

template<class T>
void Linked_tree<T>::insfiglio (Linked_tree::nodo n, Linked_tree::nodo f) {
    if (n != nullptr) {
        n->aggiungiFiglio (f);
    } else {
        throw std::runtime_error ("Il nodo padre non esiste");
    }
}

template<class T>
void Linked_tree<T>::cancfiglio (Linked_tree::nodo n, Linked_tree::nodo f) {
    if (n != nullptr && f != nullptr && !foglia (n)) {
        posizione p = n->primoFiglio ();
        while (p->getElem () != f) {
            p = p->getNext ();
        }
        n->rimuoviFiglio (p);
    } else {
        throw std::runtime_error ("Il nodo padre non esiste");
    }
}


#endif //DATA_STRUCTURES_LINKED_TREE_H
