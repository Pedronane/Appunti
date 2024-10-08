/*
  Marchesi Pietro 4BI
  Esercizio: realizzare procedura per importazione dati (nome, cognome, eta) da un file csv ad una lista semplicemente concatenata con inserimento in testa. (produrre pseudo, descriz, var e traduzione in c standard). Inserire il compito su One Note.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LEN 100

typedef struct{
  char nome[LEN];
  char cognome[LEN];
  int eta;
}TPersona;

struct TNodo {
  TPersona pers;
  struct TNodo* next;
};

struct TNodo* importazione();
void stampa(struct TNodo *f);
void stampaEl(struct TNodo *el);

int main()
{
  struct TNodo* p;
  p = importazione();
  return 0;
}

/*
Inizio
  apri file f.csv in input
  se file e aperto
    crea primo nodo
    leggi la prima riga dal file
    mentre file non e finito
      spezza in item la riga e mettili nei campi del primo nodo
      aus = p
      p = nuovo nodo
      p.next = aus
      leggi riga succesiva
    fciclo
  altrimenti
    scrivi non e stato trovato il file
  fse
Fine

Descr variabili
f,file aperto in input, FILE
p,puntatore al primo nodo,TNodo
aus,puntatore ausiliario,TNodo
str,stringa contenente la riga,char[]
*/
struct TNodo* importazione(){
  FILE* f = fopen("f.csv","r");
  char str[LEN];
  struct TNodo* p;
  p = (struct TNodo*) malloc(sizeof(struct TNodo));
  if(f!=NULL){
    struct TNodo* aus;
    p->next = NULL;
    fgets(str,LEN,f);
    while (!feof(f)) {
      strcpy(p->pers.nome, strtok(str,";"));
      strcpy(p->pers.cognome, strtok(NULL,";"));
      p->pers.eta = atoi(strtok(NULL,";"));
      stampaEl(p);
      aus = p;
      p = (struct TNodo*) malloc(sizeof(struct TNodo));
      p->next = aus;
      system("pause");
      fgets(str,LEN,f);
    }
  }else{
    printf("Il file non esiste\n");
  }
  return p;
}

/*
stampa tutti i nodi
*/
void stampa(struct TNodo *f){
  struct TNodo* p = f;
  while(p != NULL){
    stampaEl(p);
    p = p->next;
  }
}

void stampaEl(struct TNodo *el){
  printf("Nome: %s | ", el->pers.nome);
  printf("Cognome: %s | ", el->pers.cognome);
  printf("Eta': %.0d\n", el->pers.eta);
}

