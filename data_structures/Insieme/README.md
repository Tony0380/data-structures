<h1> Insiemi </h1>

* Un insieme è una collezione (o famiglia) di elementi (componenti o membri) di tipo omogeneo. A differenza delle liste, gli elementi non sono caratterizzati da una posizione né possono apparire più di una volta
* In matematica possono essere definiti _estensionalmente_
  * A = { giallo, rosso, blu }
* Oppure _intensionalmente_ attraverso la proprietà che devono avere i componenti
  * B = { elementi nel collegio ba19 nel 1994 }
  * C = { numeri reali compresi tra 0 e 1 }
* In informatica ci riferiamo al modo estensionale

<h3> Operazioni </h3>

* Il numero di elementi ( |A| detto cardinalità ) rapppresenta la dimensione dell'insieme
  * |A| = 3
  * |B| è finita
  * |C| è infinita
* La relazione fondamentale è quella di appartenenza: x ∈ A, da cui deriva l'inclusione B ⊆ A.
* Le operazioni principali sono:
  * Unione: A ∪ B
  * Intersezione: A ∩ B
  * Differenza: A \ B


### Specifica Sintattica

* **Tipi: insieme, boolean, tipoelem**

* **Operatori:**
    * creainsieme : ( ) → insieme
    * insiemevuoto : (insieme) → boolean
    * appartiene : (tipoelem, insieme) → boolean
    * inserisci : (tipoelem, insieme) → insieme
    * cancella: (tipoelem, insieme) → insieme
    * unione (insieme, insieme) → insieme
    * intersezione (insieme, insieme) → insieme
    * differenza (insieme, insieme) → insieme

### Specifica Semantica
* Tipi:
  * insieme: famiglia di insiemi costituita da elementi di tipo tipoelem
  * boolean: insieme dei valori di verità
* Operatori:
  * **creainsieme = A**
    * POST: A = {}
  * **insiemevuoto(A) = b**
    * POST: b = vero se a = {}, b = falso altrimenti
  * **appartiene(x, A) = b**
    * POST: b = vero se x ∈ A, b = falso altrimenti
  * **inserisci(x, A) = A'**
    * PRE: x &#8713; A (oppure senza precondizione)
    * POST: A' = A ∪ {x} (se x ∈ A: A' = A)
  * **cancella(x, A) = A'**
    * PRE: x ∈ A (oppure senza precondizione)
    * POST: A' = A \ {x} (se x &#8713; A: A' = A)
  * **unione(A, B) = C**
    * POST: C = A ∪ B
  * **intersezione(A, B) = C**
    * POST: C = A ∩ B
  * **differenza(A, B) = C**
    * POST: C = A \ B
  
