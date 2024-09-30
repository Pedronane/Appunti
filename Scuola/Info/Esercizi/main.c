#include <stdio.h>
#include <stdlib.h>

/*
per una serie di persone di cui si conosce peso ed altezza, realizzare un programma che permetta di:
a) calcolare l'indice BMI (indice di massa corporea) indicando a quale classe appartiene l'utente
b) elencare i dati forniti per le persone considerate "sottopeso" e il loro numero totale.
I dati delle persone sono contenute in un file di testo avente per ogni riga peso e altezza di una singola persona separata da uno spazio.
Vincoli: i dati del file DEVONO essere caricati in un array di record istanziato a run time con un numero di elòementi pari a numero delle righe del file 
*/

//Costanti
#define LEN 100


typedef Struct{
  float peso;
  int altezza;
}TPersona;

int main()
{
  int n = contarighe();
  TPersona persona = (TPersona*) malloc(sizeof(TPersona)*n);
  importa(persona, n);
  do{
    int sc = leggiInt(1,3,"Quale scelta si vuole fare");
    switch (sc){
      case 1:
        //funzione1
        break;
      case 2:
        //funzione2
        break;
      case 3:
        printf("Grazie per aver usato il programma\n");
        break;
    }
  }while(sc != 3);
  return 0;
}

/*
INIZIO
apri il file a.csv in lettura
se file esiste
allora
  conta le righe del file
  ritorna come valore il numero di righe
altrimenti 
  scrivi il file non esiste
fse
FINE

*/
int contarighe(){
  FILE* f = fopen("a.csv","r");
  if (f != NULL) {
    while (!feof(f) && n<num){
      fgets(str,f,LEN);
      n++;
    }
    return n;
  }else {
    printf("Il file non esiste\n");
  }
}

/*
INIZIO
apri il file f in lettura
se il file esiste
allora 
  mentre il file non e finito e n<num
    leggi una riga del file e mettila in str
    divida la riga in item e metti gli item nei campi della struct
    incrementa n
  fciclo
altrimenti 
  scrivi il file non esiste
fse
FINE
*/
void importa(TPersona *p, int num){
  char str[LEN];
  int n = 0;
  FILE* f = fopen("a.csv","r");
  if (f != NULL) {
    while (!feof(f) && n<num){
      fgets(str,f,LEN);
      (p+n) -> peso = atof(strtok(str,";"));
      (p+n) -> altezza = ato(strtok(NULL,";"));
      n++;
    }
  } 
}
