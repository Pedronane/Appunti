/*

Marchesi Pietro 4BI main.c

Creare un software per la gestione delle auto poste a noleggio di una azienda. Per ogni auto vengono memorizzate
le seguenti informazioni:
▪ Targa (Univoco)
▪ Modello
▪ tipo auto (utilitaria, lusso, confort)
▪ prezzo al giorno
▪ km fatti dall’acquisto.
Realizzare un programma che permetta di:
1. Caricare da file *.csv il parco macchine dall’azienda disponibili per il noleggio.
2. Stampa tutte le auto contenute nella lista.
3. Visualizzare i dati di un’auto di cui si fornisce la targa.
4. Salvare su file binario tutti le auto di un tipo scelto in input dall’utente.
5. Data in input una targa calcolare il guadagno in base ai km effettuati.
Per il calcolo del guadagno usare una funzione parametrizzata che segua le seguenti regole:
▪ per il livello “utilitaria” il guadagno al km è 0,44 euro;
▪ per il livello “lusso” il guadagno al km è 1,99 euro;
▪ per il livello “confort” il guadagno al km è 0,99 euro.
Obblighi/Limiti:
− Ogni singolo punto del menu deve essere preceduto dallo pseudocodice con descrizione dei parametri,
delle variabili locali e delle strutture dei file creati.
− Il progetto dovrà essere realizzato dividendo il codice in più file.
− Per gli input si dovranno utilizzare le apposite funzioni realizzate.
*/
#include "header.h"

int main()
{
    int sc;
    char nf[LEN];
    TNodo* first = NULL;
    do {
      sc = leggiInt(0, 5,"Fare la propria scelta");
      switch (sc) {
        case 1:
          first = importazione(first,nf);
          break;
        case 2:
          stampa(first);
          break;
        case 3:
          break;
        case 4:
          break;
        case 5:
          break;
        case 0:
          printf("Grazie per aver usato il programma\n");
          break;
      }
    } while (sc!=0);
    return 0;
}
