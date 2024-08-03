<h1> Albero </h1>

* Un albero è un tipo particolare di grafo definito come una coppia
  * **T = (N, A)**
* Dove N è un insieme finito di nodi ed A è un insieme di coppie non ordinate tali che:
  * Il numero degli archi è uguale al numero di nodi meno uno |A| = |N| - 1
  * T è connesso, ovvero per ogni coppia di nodi u e v in N, esiste una sequenza di k nodi distinti tali che u = u0, v = uk e la coppia <ui, ui+1> è un arco di A, per i = 0, 1, ..., k-1

  
  * Se T è un albero ed n e m sono nodi di T si dice che:
    * m è **discendete** di n se n è antenato di m, cioè se n=m oppure n è genitore di un antenato di m
    * Un nodo è **nodo interno** se non è foglia
    * Una **linea** di T connette due nodi, uno dei quali è genitore dell'altro
    * Un **cammino** in T è la sequenza di linee che unisce due nodi, uno dei quali è antenato dell'altro: la lunghezza del cammino è costituita dal numero di linee che lo compongono
    * L'**altezza** di un nodo è la lunghezza del cammino più lungo da quel nodo ad una foglia
    * La **profondità** di un nodo è la lunghezza del cammino dalla radice a quel nodo
  

* Proprietà:
  * Un albero è un **grafo aciclico**, in cui per ogni nodo c'è un solo arco entrante (tranne per la radice che non ne ha nessuno)
  * Un albero è un grafo **debolmente connesso**
  * Se esiste un cammino che va da un nodo u ad un altro nodo v, tale cammino è unico
  * In un albero esiste un solo cammino che va dalla radice a qualunque altro nodo
  * Tutti i nodi di un albero T (tranne r) possono essere ripartiti in insiemi disgiunti ciascuno dei quali individua un albero (detto sottoalbero)

___
<h2> Albero binario </h2>

### Specifica Sintattica

* **Tipi: alberobin, boolean, nodo, tipoelem**

* **Operatori:**
    * creabinalbero : ( ) → alberobin
    * binalberovuoto : (alberobin) → boolean
    * binradice : (alberobin) → nodo
    * binpadre : (nodo, alberobin) → nodo
    * figliosinistro : (nodo, alberobin) → nodo
    * figliodestro : (nodo, alberobin) → nodo
    * sinistrovuoto : (nodo, alberobin) → boolean
    * destrovuoto : (nodo, alberobin) → boolean
    * costrbinalbero : (alberobin, alberobin) → alberobin
    * cancsottobinalbero : (nodo, alberobin) → alberobin
    * legginodo : (nodo, alberobin) → tipoelem
    * scrivinodo : (tipoelem, nodo, alberobin) → alberobin
    * insbinradice : (nodo, alberobin) → alberobin
    * insfigliosinistro : (nodo, alberobin) → alberobin
    * insfigliodestro : (nodo, alberobin) → alberobin

 
### Specifica Semantica
* Tipi:
  * alberobin: insieme degli alberi binari T = (N,A) nei quali ad ogni nodo è associato un livello
  * boolean: insieme dei valori di verità
  * nodo: insieme dei nodi con etichetta di tipo tipoelem
* Operatori:
  * **creabinalbero = T'** 
    * POST: T' = (Ø,Ø) = ∧
  * **binalberobuoto(T) = b**
    * POST: b = vero se T = ∧; b = falso altrimenti
  * **binradice(T) = u**
    * PRE: T ≠ ∧
    * POST: u → radice di T → Livello(u) = 0
  * **binpadre(u, T) = v**
    * PRE: T ≠ ∧, u ∈ N, Livello(u) > 0
    * POST: v è padre di u → (v,u) ∈ A → Livello(u) = Livello(v) + 1
  * **figliosinistro(u, T) = v**
    * PRE: T ≠ ∧, u ∈ N, u ha un figlio sinistro
    * POST: v è figlio sinistro di u in T
  * **figliodestro(u, T) = v**
    * PRE: T ≠ ∧, u ∈ N, u ha un figlio destro
    * POST: v è figlio destro di u in T
  * **sinistrovuoto(u, T) = b**
    * PRE: T ≠ ∧, u ∈ N
    * POST: b = vero se u ha un figlio sinistro, b = falso altrimenti
  * **destrovuoto(u, T) = b**
    * PRE: T ≠ ∧, u ∈ N
    * POST: b = vero se u ha un figlio destro, b = falso altrimenti
  * **costrbinalbero(T, T') = T''**
    * POST: T'' si ottiene da T e T' introducendo automaticamente un nuovo nodo r'' che avrà come sottoalbero sinistro T e come sottoalbero destro T'
  * **cancsottoalbero(u, T) = T'**
    * PRE: T ≠ ∧, u ∈ N
    * POST: T' è ottenuto da T eliminando il sottoalbero di radice u, con tutti i suoi discendenti
  * **legginodo(n, T) = a**
    * PRE: n è un nodo di T, n ∈ N
    * POST: a è il valore associato al nodo n in T
  * **scrivinodo(a, n, T) = T'**
    * PRE: n è un nodo di T, n ∈ N
    * POST: T' è il nuovo albero corrispondente al vecchio albero T con il valore associato a al none n
  * **insbinradice(u, T) = T'**
    * PRE: T = ∧
    * POST: T' =(N,A), N ={u}, Livello(u) = 0, A = Ø
  * **insfigliosinistro(u, T) = T'**
    * PRE: T ≠ ∧, u ∈ N, sinistrovuoto(u,T) = true
    * POST: N' = N ∪ {v}, T' è ottenuto da T aggiungendo v come figlio sinistro di u
  * **insfigliodestro(u, T) = T'**
    * PRE: T ≠ ∧, u ∈ N, destrovuoto(u,T) = true
    * POST: N' = N ∪ {v}, T' è ottenuto da T aggiungendo v come figlio destro di u
