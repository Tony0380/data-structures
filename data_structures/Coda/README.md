<h1> Code </h1>

*  Una coda è un tipo astratto che consente di rappresentare una sequenza di elementi in cui è possibile aggiungere elementi ad un estremo ("il fondo") e togliere elementi dall'altro estremo ("la testa")
* Tale disciplina di accesso è detta FIFO (First In First Out)
* È particolarmente adatta a rappresentare sequenze nelle quali l'elemento viene elaborato secondo l'ordine di arrivo
  * Esempi: liste d'attesa, dispositivi in attesa di risorse, etc.


### Specifica Sintattica

* **Tipi: coda, boolean, tipoelem**

* **Operatori:**
    * creacoda : ( ) → coda
    * codavuota : (coda) → boolean
    * leggicoda : (coda) → tipoelem
    * fuoricoda : (coda) → coda
    * incoda : (tipoelem, coda) → coda

### Specifica Semantica
* Tipi:
  * coda: insieme delle sequenze q = < a1, a2, … , an >, n>=0, di elementi di
    tipo tipoelem caratterizzata dall'accesso FIFO
  * boolean: insieme dei valori di verità
* Operatori:
  * **creacoda = q'** 
    * POST: q' = < > (Sequenza vuota)
  * **codavuota(q) = b**
    * POST: b = vero se q = < >, falso altrimenti
  * **leggicoda(q) = a**
    * PRE: q = < a, a1, … , an >, n>=1
    * POST: a = a1
  * **fuoricoda(q) = q'**
    * PRE: q = < a1 , … , an > e n>=1
    * POST: q' = < a2, … , an > se n>1, q' = < > se n=1
  * **incoda(a, q) = q'**
    * PRE: q = < a1, … , an > n>=0
    * POST: q' = < a1, … , an, a >