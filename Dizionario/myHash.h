//
// Created by Colam on 02/08/2024.
//

#ifndef DATA_STRUCTURES_MYHASH_H
#define DATA_STRUCTURES_MYHASH_H

#include <string>
#include <stdexcept>
#include <ostream>
#include <string>

using std::string;

template<typename T>
class myHash {
public:
    size_t operator() (const T Key) const {
        return size_t (Key);
    }
};

//polimorfismo parametrico ad hoc per il tipo stringa
template<>
class myHash<string> {
    size_t operator() (const string &Key) const {
        unsigned long hash_value = 0;
        int length = (int) Key.length ();
        for (int i = 0; i < length; i++)
            hash_value = 5 * hash_value + Key.at (i);
        return size_t (hash_value);
    }
};

#endif //DATA_STRUCTURES_MYHASH_H
