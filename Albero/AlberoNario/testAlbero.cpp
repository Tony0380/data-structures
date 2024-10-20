#include <iostream>
#include <sstream>
#include <cassert>
#include <functional>
#include "Linked_tree.h"  // Assumiamo che questo sia il nome del file che contiene la definizione di Linked_tree

// Funzione di utilità per catturare l'output di cout
std::string captureOutput(std::function<void()> func) {
    std::stringstream buffer;
    std::streambuf* prevcoutbuf = std::cout.rdbuf(buffer.rdbuf());
    func();
    std::cout.rdbuf(prevcoutbuf);
    return buffer.str();
}

// Funzione di test
void testStampainvista() {
    Linked_tree<int> tree;

    // Creiamo un albero di test
    //       1
    //    /  |  \
    //   2   3   4
    //  / \     / \
    // 5   6   7   8

    auto root = new Nodo<int>();
    root->setElem(1);

    auto node2 = new Nodo<int>();
    node2->setElem(2);
    auto node3 = new Nodo<int>();
    node3->setElem(3);
    auto node4 = new Nodo<int>();
    node4->setElem(4);

    auto node5 = new Nodo<int>();
    node5->setElem(5);
    auto node6 = new Nodo<int>();
    node6->setElem(6);
    auto node7 = new Nodo<int>();
    node7->setElem(7);
    auto node8 = new Nodo<int>();
    node8->setElem(8);

    tree.insradice(root);
    tree.insfiglio(root, node2);
    tree.insfiglio(root, node3);
    tree.insfiglio(root, node4);
    tree.insfiglio(node2, node5);
    tree.insfiglio(node2, node6);
    tree.insfiglio(node4, node7);
    tree.insfiglio(node4, node8);

    // Test con diversi valori di i
    std::string output;

    output = captureOutput([&]() { tree.stampainvista(0); });
    assert(output == "1 2 5 6 3 4 7 8 " && "Test fallito per i = 0");
    std::cout << "Test passato per i = 0\n";

    output = captureOutput([&]() { tree.stampainvista(1); });
    assert(output == "5 2 6 1 3 7 4 8 " && "Test fallito per i = 1");
    std::cout << "Test passato per i = 1\n";

    output = captureOutput([&]() { tree.stampainvista(2); });
    assert(output == "5 6 2 3 1 7 8 4 " && "Test fallito per i = 2");
    std::cout << "Test passato per i = 2\n";

    output = captureOutput([&]() { tree.stampainvista(3); });
    assert(output == "5 6 2 3 7 8 4 1 " && "Test fallito per i = 3");
    std::cout << "Test passato per i = 3\n";

    std::cout << "Tutti i test sono passati!\n";
}

int main() {
    testStampainvista();
    return 0;
}