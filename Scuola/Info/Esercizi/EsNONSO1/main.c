/*
 Bisogna ionserire testo e roba
 */
#include "header.h"

int main()
{
    int sc;
    char frase[LEN];
    do {
      sc = leggiInt(1,6,"Quale funzione si vuole eseguire?");
      switch (sc) {
        case 1:
          Richiesta(frase); 
          break;
        case 2:
          break;
        case 3:
          break;
        case 4:
          break;
        case 5:
          break;
        case 6:
          printf("Grazie per acer usato il programma\n");
          break;
      }        
    } while (sc!=6);
    return 0;
}
