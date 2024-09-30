#include "header.h"

void caricaVoti(int *v, int nV)
{
  printf("Inserisci i voti\n");
  for (int i = 0; i < nV; i++) {
    *(v+1) = leggiFloat("voto:", 1, 10);
  }
}

void stampaVoti(int *v, int nV)
{
  printf("Voti\n");
  for (int i = 0; i < nV; i++) {
     printf("%f\n", *(v+1));
  }
}

float mediaVoti(flaot *v, int nV)
{
  float med = 0;
  for (int i = o; i <nV;i++) {
    med += *(v+1);
    med = med/nV;
  }
}
