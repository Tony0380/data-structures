<h1> Pile </h1>

*  Una pila è una sequenza di elementi di un certo tipo in cui è possibile aggiungere o togliere elementi solo da un estremo della sequenza detto "testa"
* Può essere vista come un caso speciale di lista in cui l'ultimo elemento inserito è il primo ad essere rimosso (lifo) e non è possibile accedere ad alcun elemento che non sia quello in testa

### Specifica Sintattica

* **Tipi: pila, boolean, tipoelem**

* **Operatori:**
    * creapila : ( ) → pila
    * pilavuota  : (pila) → boolean
    * leggipila  : (pila) → tipoelem
    * fuoripila  : (pila) → pila
    * inpila  : (tipoelem, pila) → pila
### Specifica Semantica
* Tipi:
  * Pila: insieme delle sequenze P = < a1, a2, … , an >, n>=0, di elementi di
    tipo tipoelem gestita con accesso LIFO
  * boolean: insieme dei valori di verità
* Operatori:
  * **creapila = p** 
    * POST: p = < > (Sequenza vuota)
  * **pilavuota(p) = b**
    * POST: b = vero se p = < >, falso altrimenti
  * **leggipila(p) = a**
    * PRE: p = < a, a1, … , an >, n>=1
    * POST: a = a1
  * **fuoripila(p) = p'**
    * PRE: p = < a1 , … , an >, n>=1
    * POST: p' = < a2, … , an > se n>1, p' = < > se n=1
  * **inpila(a, p) = p'**
    * PRE: p = < a1, … , an > n>=0
    * POST: p' = < a, a1, … , an >