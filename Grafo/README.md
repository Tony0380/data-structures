<h1> Grafi </h1>

* Il grafo è una struttura composta da nodi e archi che
  rappresenta una relazione binaria sull'insieme costituito
  dai nodi

### Specifica Sintattica

* **Tipi: grafo, boolean, nodo, lista, tipoelem**

* **Operatori:**
    * creagrafo() → grafo
    * vuoto (grafo) → boolean
    * insnodo (nodo, grafo) → grafo
    * insarco  (nodo, nodo, grafo) → grafo
    * cancnodo (nodo, grafo) → grafo
    * cancarco (nodo, nodo, grafo) → grafo
    * adiacenti (nodo, grafo) → lista
    * esistenodo (nodo, grafo) → boolean
    * esistearco (nodo, nodo, grafo) → boolean
    * legginodo (nodo, grafo) → tipoelem
    * scrivinodo (tipoelem, nodo, grafo) → grafo

### Specifica Semantica
* Tipi:
    * Grafo: Insieme G = (N, A) con N sottoinsiemi finito di elementi di tipo _nodo_ e A ⊆ NxN
    * boolean: insieme dei valori di verità
    * nodo: insieme finito qualsiasi
    * lista: lista di elementi di tipo nodo
* Operatori:
    * **creagrafo = G**
        * POST: G = (N, A) con N = Ø e A = Ø