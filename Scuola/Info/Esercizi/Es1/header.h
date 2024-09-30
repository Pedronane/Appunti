//Marchesi Pietro 4BI
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define LEN 100

//PROTOTIPI

void inserimento(char*frase);
void invertiStampa(char*frase);
void conta(char*frase);
void sostituisci(char*frase);
void contaChar(char*frase);

//Prototipi funzioni di Input
int leggiInt (int vmin, int vmax, char *msg);
float leggiFloat (float vmin, float vmax, char *msg);
char leggiChar(char *msg);
void leggiStr(char *s,char *msg);
