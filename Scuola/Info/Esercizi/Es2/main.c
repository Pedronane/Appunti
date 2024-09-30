#include "header.h"

/*
Un negozio di informatica commissiona un applicativo per la gestione del proprio catalogo di videogiochi.
Ogni videogioco ha le seguenti caratteristiche:
§ ID – Univoco
§ Nome
§ Costo
§ Classificazione (S, A, B)
§ Usato (0->usato, 1->nuovo)
Realizzare un menu che presenti le seguenti funzionalità:
1) Importa il catalogo dei videogiochi da file (controlla che i dati del videogioco siano corretti. In caso di errori la riga riferita al videogioco dovrà essere esportata in un file chiamato log.csv);
2) Stampa catalogo;
3) Stampa il valore economico totale del catalogo;
4) Dato l'ID, stampa i dati videogioco;
5) Dato l’ID, modifica il costo del videogioco;
6) Data la classificazione, esporta in un file i videogiochi aventi quella classificazione;

§ VINCOLI/OBBLIGHI
- Il progetto dovrà essere realizzato dividendo il codice in più file.
- Per gli input si dovranno utilizzare le apposite funzioni realizzate.
- L’array di record si deve istanziare a run time
- obbligo di uso dei puntatori all’interno delle procedure e delle funzioni.
- Non è possibile utilizzare parentesi quadre ([]).
- ogni singolo punto del menu deve essere preceduto dallo pseudocodice con descrizione dei parametri e delle var locali
*/
int main()
{
    int sc, n;
    n = contarighe();
    printf("%d", n);
    TGioco *giochi = (TGioco*) malloc(sizeof(TGioco)*n);
    do{
        printf("1)...");
        sc = leggiInt(1,7,"Quale opzione si vuole scegliere?");
        switch (sc){
            case 1:
                importa(giochi, n);
                break;
            case 2:
                break;
            case 3:
                break;
            case 4:
                break;
            case 5:
                break;
            case 6:
                break;
            case 7:
                printf("Grazie per aver usato il programma\n");
                break;
        }
    }while(sc != 0);
    return 0;
}
