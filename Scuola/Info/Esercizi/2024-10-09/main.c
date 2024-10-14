/*
  Marchesi Pietro 4BI
  Esercizio: realizzare procedura per importazione dati (nome, cognome, eta) da un file csv ad una lista semplicemente concatenata con inserimento in testa. (produrre pseudo, descriz, var e traduzione in c standard).
  Inserire il compito su One Note.
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

typedef struct TNodo {
  TPersona pers;
  TNodo* next;
}TNodo;

struct TNodo* importazione(TNodo* first);

int main()
{
  struct TNodo* first = NULL;
  first = importazione(first);
  first = elimina(first);
  return 0;
}

/*
Inizio
  apri file f.csv in input
  se file e aperto
    leggi la prima riga dal file
    mentre file non e finito
      spezza in item la riga e mettili nei campi della struct p
      se first == NULL
      allora
        istanzia first 
        firs->next = NULL
        first = p
      altrimenti
        p->next = first
        istanzia un nodo in first
        first = p
      fse
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
struct TNodo* importazione(TNodo* first){
  FILE* f = fopen("f.csv","r");
  TNodo* p = (TNodo*)malloc(sizeof(TNodo));
  char str[LEN];
  if(f!=NULL){
    fgets(str,LEN,f);
    while (!feof(f)) {
      strcpy(p->pers.nome, strtok(str,";"));
      strcpy(p->pers.cognome, strtok(NULL,";"));
      p->pers.eta = atoi(strtok(NULL,";"));
      if(first == NULL){
        first = (struct TNodo*) malloc(sizeof(struct TNodo));
        p->next = NULL;
        first = p;
      }else {
        p->next = first;
        first = (struct TNodo*) malloc(sizeof(struct TNodo));
        first = p;
      }
      fgets(str,LEN,f);
    }
  }else{
    printf("Il file non esiste\n");
  }
  return fist;
}

/*
Esercizio (continuazione): dalla lista di studenti caricati da file csv nello scorso esercizio (che quindi deve essere, se necessario, corretto), cercare e cancellare uno studente fornito nome e cognome.
Produrre pseudocodice, descriz var e traduzione in cstd della procedura con relativo ambiente chiamante. 

INIZIO
  se la lista e stata istanziata
  allora 
    leggi nome e cognome
    ricerca nome e cognome all'interno della lista
    se non vengono trovati 
    allora
      scrivi la persona non e stata trovata
    altrimenti
      se il nodo e il primo allora
        fai diventare il nodo successivo il primo
        elimina il nodo trovato
      altrimenti
        prec->next = aus->next
        elimina il nodo trovato
    fsr
  altrimeti
    scrivi la lista non e ancora stata istanziata 
  fse
FINE

descr var
tro,descrive se e stato trovato il nodo cercato,bool
nome, nome da cercare,array di char
cognome, cognome da cercare, array di char
prec, nodo precedente a quello trovato,TNodo
aus, nood trovato,TNodo

descr parametri
first, primo nodo della lista,TNodo
*/

struct TNodo* elimina(TNodo* first){
  if(first!=NULL){
    bool tro = false;
    char nome[LEN], cognome[LEN];
    leggiStr(nome,"Inserire il nome");
    leggiStr(cognome,"Inserire il cognome");
    TNodo* prec = NULL;
    TNodo* aus = first;
    while(aus!=NULL && !tro){
      if(strcmp(aus->pers.nome,nome)&&strcmp(aus->pers.cognome,cognome)){
        tro = true;
      }else{
        prec = aus;
        aus = aus->next;
      }
    }
    if(!tro)
      printf("Non e stato trovata la persona");
    else{
      if(prec==NULL){
        first = first->next;
        free(aus);
      }else{
        prec->next = aus->next;
        free(aus);
      }
    }
  }else{
    printf("L'inserimento non e neancora stato fatto");
  }
  return first;
}

/*
esercizio 1: cancellazione dalla lista degli studenti di tutti i minorenni
esercizio 2: salvataggio della lista in un file binario
Consegnare pseudo e traduzione i C std in One Note

INIZIO
  se lista esiste
  allora
    ricerca all'interno della lista tutti i minorenni
      se il nodo e il primo 
      allora
        fai diventare il nodo successivo il primo
        elimina il nodo trovato
      altrimenti
        prec->next = aus->next
        elimina il nodo trovato
      fse
      passa al nodo successivo
  altrimenti  
    scrivi la lista non esiste
  fse
FINE
*/

struct TNodo* eliminaMin(TNodo* first){
  if(first!=NULL){
    bool tro = false;
    TNodo* prec = NULL;
    TNodo* aus = first;
    while(aus!=NULL){
      if(aus->pers.eta<18){
        tro = true;
        if(prec==NULL){
          first = first->next;
          free(aus);
        }else{
          prec->next = aus->next;
          free(aus);
        }
      }
      prec = aus;
      aus = aus->next;
    }
    if(!tro)
      printf("Non e stato trovata la persona");
  }
  else{
    printf("L'inserimento non e neancora stato fatto");
  }
  return first;
}

//FUNZIONI DI INPUT

int leggiInt (int vmin, int vmax, char *msg){
    int n;
    puts(msg);
    do{
        scanf("%i",&n);
        if(n<vmin || n>vmax)
            puts("errore \n");
    }while(n<vmin || n>vmax);
    return n;
}
float leggiFloat (float vmin, float vmax, char *msg){
    float n;
    puts(msg);
    do{
        scanf("%f",&n);
        if(n<vmin || n>vmax)
            puts("errore \n");
    }while(n<vmin || n>vmax);
    return n;
}
char leggiChar(char *msg){
    char c;
    puts(msg);
    fflush(stdin);
    do{
        scanf("%c",&c);
        if(c == ' ')
            puts("errore \n");
    }while(c == ' ');
    return c;
}
void leggiStr(char *s,char *msg){
    puts(msg);
    fflush(stdin);
    do{
        gets(s);
        if(strcmp(s,"")==0)
            puts("errore \n");
    }while(strcmp(s,"")==0);
}
