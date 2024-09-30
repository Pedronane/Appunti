#include "header.h"

int main()
{
  float *voti;
  int numVoti;

  numVoti = leggiInt("Inserire numero voti: ", 1, INT_MAX)

  voti = (float *) malloc(sizeof(float) *numVoti);

  caricaVoti(voti, numVoti);
  stampaVoti(voti, numVoti);
  printf("\n\nMedia: %.2f", mediaVoti(voti, numVoti));

  return 0;
}
