<h1> Dizionario </h1>

* Un dizionario è un insieme i cui elementi sono generalmente tipo strutturati ai quali si accede per mezzo di un riferimento a un campo chiave. Gli elementi assumono la forma di una coppia costituita da (chiave, valore)
* La caratteristica della chiave è legata all'applicazione
  * nei dizionari degli elaboratori di testi la chiave individua una parola mentre in un dizionario di magazzino la chiave può essere un codice prezzo
* Il valore associato, invece, rappresenta l'informazione associata per scopi di gestione o manutenzione


### Specifica Sintattica

* **Tipi: dizionario, boolean, chiave, valore**

* **Operatori:**
    * creadizionario : ( ) → dizionario
    * dizionariovuoto : (dizionario) → boolean
    * appartiene : (chiave, dizionario) → boolean
    * inserisci : (<chiave, valore>, dizionario) → dizionario
    * cancella : (chiave, dizionario) → dizionario
    * recupera : (chiave, dizionario) → valore

### Specifica Semantica
* Tipi:
  * Dizionario: famiglia di dizionari costituita da coppie di tipo <chiave, valore>
  * boolean: insieme dei valori di verità
* Operatori:
  * **creadizionario = D** 
    * POST: D = {}
  * **dizionariovuoto(D) = b**
    * POST: b = vero se D = {}, b = falso altrimenti
  * **appartiene(k, D) = b**
    * POST: b = vero se esiste una coppia <k', v> ∈ D tale che k' = k, b = falso altrimenti
  * **inserisci(<k, v>, D) = D'**
    * POST: D' = D ∪ {<k, v>} se non esiste una coppia <k', v'> ∈ D tale che k' = k;
            
       D' = D \ {<k', v'>} ∪ { <k, v> } se esiste già una coppia <k', v'> ∈ D tale che k' = k;
  * **cancella(k, D) = D'**
    * PRE: esiste una coppia <k', v'> ∈ D tale che k' = k
    * POST: D' = D \ <k', v'>
  * **recupera(k ,D) = v**
    * PRE: esiste una coppia <k', v'> ∈ D tale che k' = k
    * POST: v = v'