//Marchesi Pietro 4BI header.h
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <float.h>

//COSTANTI
#define ID 10
#define LEN 100
#define NMAX 1000

//STRUCT
typedef struct{
    char id[ID], nome[LEN], clas;
    float costo;
    int usato;
}TGioco;

//PROTOTIPI
int contarighe();
TGioco* importa(TGioco *g, int n, int *num);
void stampa(TGioco *g, int n);
int ricerca(TGioco *v, char *el, int n);
void valoreEconomico(TGioco *g, int n);
void stampaDaId(TGioco *g, int n);
void modificaDaId(TGioco *g, int n);
void espCat(TGioco *g, int n);



//PROTOTIPI FUNZIONI INPUT
int leggiInt (int vmin, int vmax, char *msg);
float leggiFloat (float vmin, float vmax, char *msg);
char leggiChar(char *msg);
void leggiStr(char *s,char *msg);
