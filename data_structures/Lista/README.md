<h1> Liste </h1>

*  Una lista è una sequenza fnita, anche vuota, di elementi dello
   stesso tipo
* La diferenza col concetto di “insieme” è che mentre in un
  insieme un elemento non può comparire più di una volta, nella
  lista uno stesso elemento può comparire più volte, in posizioni
  diverse
* Gli elementi della lista, cui sono associate delle informazioni,
  sono defniti atomi o nodi
* Indichiamo la lista con la notazione
  * **_l = < a1, a2, … , an > ; n >= 0_**
* A ciascun elemento di una lista viene associata una posizione
    * **_pos( i )_**
* e un valore
    * **_a( i )_**

### Specifica Sintattica

* **Tipi: lista, posizione, boolean, tipoelem**

* **Operatori:**
    * crealista : ( ) → lista
    * listavuota : (lista) → boolean
    * leggilista : (posizione, lista) → tipoelem
    * scrivilista : (tipoelem, posizione, lista) → lista
    * primolista : (lista) → posizione
    * finelista : (posizione, lista) → boolean
    * succlista : (posizione, lista) → posizione
    * predlista : (posizione, lista) → posizione
    * inslista : (tipoelem,posizione,lista) → lista
    * canclista : (posizione, lista) → lista
### Specifica Semantica
* Tipi:
  * Lista: insieme delle sequenze l = < a1, a2, … , an >, n>=0, di elementi di
    tipo tipoelem dove l'elemento i-esimo ha valore a(i) e posizione pos(i)
  * boolean: insieme dei valori di verità
* Operatori:
  * **crealista = l'** 
    * POST: l' = < > (Sequenza vuota)
  * **listavuota(l) = b**
    * POST: b = true se l = < >, b = false altrimenti
  * **leggilista(p, l) = a**
    * PRE: p = pos(i) AND 1 <= i <= n
    * POST: a = a(i)
  * **scrivilista(a, p, l) = l'**
    * PRE: p = pos(i) AND 1 <= i <= n
    * POST: l' = < a1, a2, … , a(i-1), a, a(i+1), … , an >
  * **primolista(l) = p**
    * POST: p = pos(1)
  * **finelista(p, l) = b**
    * PRE: p = pos(i) AND 1 <= i <= n + 1
    * POST: b = true se p = pos(n + 1), b = false altrimenti
  * **succlista(p, l) = q**
    * PRE: p = pos(i) AND 1 <= i <= n
    * POST: q = pos(i + 1)
  * **predlista(p, l) = q**
    * PRE: p = pos(i) AND 2 <= i <= n + 1
    * POST: q = pos(i - 1)
  * **inslista(a, p, l) = l'**
    * PRE: p = pos(i) AND 1 <= i <= n + 1
    * POST: l' = < a1, a2, … , a(i-1), a, a(i), … , an > se 1 <= i <= n ; l' = < a, a1, a2, … , an > se i = n + 1
  * **canclista(p, l) = l'**
    * PRE: p = pos(i) AND 1 <= i <= n
    * POST: l' = < a1, a2, … , a(i-1), a(i+1), … , an >