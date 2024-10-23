#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

/*COSTANTI*/
#define TAR 10
#define LEN 100

typedef struct TAuto{
  char targa[TAR], modello[LEN], tipo[LEN];
  float prezzo, km;
}TAuto;

typedef struct TNodo {
  TAuto a;
  struct TNodo* next;
}TNodo;

//Prototipi
void menu();
TNodo* importazione(TNodo* first, char* nf);
bool controllo(TAuto a,TNodo* first);
TNodo* ricercaTarga(char* targa,TNodo* first);
void stampa(TNodo* first);
void visualizzaDati(TNodo* first);
void esportaTipo(TNodo* first);
void calcoloDaTarga(TNodo* first);
void calcoloStampa(TNodo* nodo);


//PROTOTIPI FUNZIONI INPUT
int leggiInt (int vmin, int vmax, char *msg);
float leggiFloat (float vmin, float vmax, char *msg);
char leggiChar(char *msg);
void leggiStr(char *s,char *msg);
