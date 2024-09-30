#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//COSTANTI
#define LEN 100

//Prototipi
void Richiesta(char *f);

int leggiInt (int vmin, int vmax, char *msg);
float leggiFloat (float vmin, float vmax, char *msg);
char leggiChar(char vmin, char vmax, char *msg);
void leggiStr(char *s,char *msg);

