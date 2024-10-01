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
    int sc, n = 0, nrighe;
    nrighe = contarighe();
    TGioco *giochi = NULL;
    do{
        printf("1) Importazione catalogo;\n");
        printf("2) Stampa catalogo;\n");
        printf("3) Valore economico totale;\n");
        printf("4) Dato ID, stampa dati;\n");
        printf("5) Dato ID, modifica costo;\n");
        printf("6) Esporta i videogiochi con una data la classificazione;\n");
        printf("0) Termina programma;\n");
        sc = leggiInt(0,6,"Quale opzione si vuole scegliere?");
        switch (sc){
            case 1:
                giochi = importa(giochi, nrighe, &n);
                break;
            case 2:
                stampa(giochi, n);
                break;
            case 3:
                valoreEconomico(giochi, n);
                break;
            case 4:
                stampaDaId(giochi, n);
                break;
            case 5:
                modificaDaId(giochi, n);
                break;
            case 6:
                espCat(giochi,n);
                break;
            case 0:
                printf("Grazie per aver usato il programma\n");
                break;
        }
    }while(sc != 0);
    free(giochi);
    return 0;
}
