#include "header.h"
/*
INIZIO
  apri file catalogo.csv in input 
  se il file e aperto
  allora 
    leggi la prima riga
    finche file non e finito
      spezza la riga e controlla che siano corretti gli item
      se gli item sono corretti
      allora
        inserisci gli item all'interno di first 
        crea un nuovo nodo in coda
      fse
    fciclo
  altrimenti 
    scrivi il file non esiste
  fse
FINE
*/
TNodo* importazione(TNodo* first, char* nf){
  TNodo* aus;
  TAuto* auto;
  FILE* f = fopen(nf,"r");
  char str[LEN];
  if(f != NULL) {
    fgets(str,LEN,f);
    while (!feof(f)) {
      strcpy(auto.targa,strtok(str,";"));
      strcpy(auto.modello,strtok(NULL,";"));
      strcpy(auto.tipo,strtok(NULL,";"));
      auto->prezzo = atof(strtok(NULL,";"));
      auto->km = atof(strtok(NULL,";"));
      int con = controllo(auto, first);
      if(con==-1){
        first->auto = auto;
        aus = first; 
        first = (TNodo*) malloc(sizeof(TNodo));
        first->next = aus;
      }
      fgets(str,LEN,f);
    }
  }
}

int controllo(TAuto* a,TNodo* first){
   for (int i=0;;while (true) {
   };) {
   } 
}

//FUNZIONI DI INPUT

int leggiInt (int vmin, int vmax, char *msg){
    int n;
    puts(msg);
    do{
        scanf("%d",&n);
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
