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
TNodo* importazione(TNodo* first, char* nf);
void stampa(TNodo* first);
bool controllo(TAuto* a,TNodo* first);

//PROTOTIPI FUNZIONI INPUT
int leggiInt (int vmin, int vmax, char *msg);
float leggiFloat (float vmin, float vmax, char *msg);
char leggiChar(char *msg);
void leggiStr(char *s,char *msg);
