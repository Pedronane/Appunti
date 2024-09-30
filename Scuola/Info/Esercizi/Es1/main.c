/*
Marchesi Pietro 4BI
Realizzare un programma contenente un menu in cui sono presenti I seguenti punti:
1. Chiedere in input una frase all’utente;
2. Contare il numero di vocali e consonanti di cui è composta quella frase;
3. Stampare la frase al contrario;
4. Sostituire le vocali con il simbolo “-” e stampare il risultato
5. Dato un carattere chiesto in input, contare quante volte è presente quel carattere nella frase
*/
#include "header.h"

int main()
{
    int sc;
    char frase[LEN];
    do{
        system("cls");
        sc=leggiInt(1,6,"Fare la propria scelta ");
        switch(sc){
            case 1:{
                inserimento(frase);
                break;
            }
            case 2:{
                conta(frase);
                break;
            }
            case 3:{
                invertiStampa(frase);
                break;
            }
            case 4:{
                sostituisci(frase);
                break;
            }
            case 5:{
                contaChar(frase);
                break;
            }
            case 6:{
                printf("Grazie per aver usato il programma");
                break;
            }
        }
        system("pause");
        system("cls");
    }while(sc!=6);
    return 0;
}
