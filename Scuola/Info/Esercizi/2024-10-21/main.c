/*
Marchesi Pietro 4BI
Realizzare il programma che prenda da un file binario prodotto.bin i dati dei prodotti di una certa categoria produca un file CSV con tali dati ordinati in senso crescente rispetto al codice
(usare un lista semplicemente concatenata come struttura intermedia in cui i prodotti sono inseriti in ordine crescente di codice)
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define LEN 100

typedef struct{
  char codice[LEN], nome[LEN];
  float prz;
}TProdotto;

typedef struct TNodo{
  TProdotto p;
  struct TNodo* next;
}TNodo;


TNodo* importa(TNodo* first);
TNodo* ricerca(TNodo* first,TNodo* nodo);

int main(){
  TNodo* first = NULL;
  first = importa(first);
  return 0;
}

/*
INIZIO
apri file f in lettura
apri file l in scrittura
se il file f e aperto
  leggi il primo record dal file f in nodo
  mentre il file non e finito
    se first != NULL
    allora
      ricerca la posizione in cui deve essere inserito il record
      istanzia il record aus alla posizione ricercata
      istanzia il record prec alla posizione precedente
      se prec == NULL
      allora
        istanzia first a un nuovo nodo e mettilo = a nodo
        fai puntare first->next a aus
      altrimenti
        crea un nodo tra aus e prec e mettilo = a nodo
    altrimenti
      istanzia first
      copia nodo in first
    fse
    leggi record successivo
  fciclo
altrimenti
  scrivi il file non esiste
fse
FINE
*/

TNodo* importa(TNodo* first){
  FILE* f = fopen("prodotto.bin", "r");
  FILE* l = fopen("prodotti.csv", "w");
  TNodo* nodo = (TNodo*) malloc(sizeof(TNodo*));
  if(f != NULL){
    fread(nodo,sizeof(TNodo),1,f);
    while(nodo!=NULL){
      if(first != NULL){
        TNodo* prec = ricerca(first,nodo);
        TNodo* aus = prec->next;
        if(prec == NULL){
          first = (TNodo*) malloc(sizeof(TNodo*));
          first = nodo;
          first->next = aus;
        }else{
          prec->next = (TNodo*) malloc(sizeof(TNodo*));
          TNodo* aus2 = prec->next;
          aus2 = nodo;
          aus2->next = aus;
        }
      }else{
        first = (TNodo*) malloc(sizeof(TNodo*));
        first = nodo;
      }
      fread(nodo,sizeof(TNodo),1,f);
    }
    nodo = first;
    while(nodo->next != NULL){
      fprintf(l,"%s;",nodo->p.codice);
      fprintf(l,"%s;",nodo->p.nome);
      fprintf(l,"%f\n",nodo->p.prz);
      nodo = nodo->next;
    }
  }else
    printf("Il file non esiste");
  return first;
}

TNodo* ricerca(TNodo* first,TNodo* nodo){
  TNodo* prec = NULL;
  TNodo* aus = first;
  bool tro = false;
  while(aus->next!=NULL && tro == false){
    if(strcmp(aus->p.codice,nodo->p.codice)==0){
      tro = true;
    }
    prec = aus;
    aus = aus->next;
  }
  return prec;
}
