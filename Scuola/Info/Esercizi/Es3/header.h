#include <stdio.h>
#include <stdlib.h>
#include <string.h> 

typedef TAuto {
  char targa[TAR], modello[LEN], tipo[LEN]; 
  float prezzo, km;
}TAuto;

typedef TNodo {
  TAuto auto;
  TNodo next;
}TNodo;

//PROTOTIPI FUNZIONI INPUT
int leggiInt (int vmin, int vmax, char *msg);
float leggiFloat (float vmin, float vmax, char *msg);
char leggiChar(char *msg);
void leggiStr(char *s,char *msg);
