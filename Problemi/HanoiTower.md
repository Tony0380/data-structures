# La Torre di Hanoi

Componenti:

* n dischi
* n pioli

Regole:

* I dischi possono stare solo sopra a dischi più grandi
* si possono spostare n dischi alla volta

### Strategia

1. muovi gli n-1 dischi da *origine* a *intermedio* utilizzando *destinazione*
2. muovi il disco rimanente da *origine* a destinazione
3. muovi gli n dischi da *intermedio* a *destinazione* utilizzando *origine*
