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
  TAuto* a = NULL;
  FILE* f = fopen(nf,"r");
  char str[LEN];
  if(f != NULL) {
    fgets(str,LEN,f);
    while (!feof(f)) {
      strcpy(a->targa,strtok(str,";"));
      strcpy(a->modello,strtok(NULL,";"));
      strcpy(a->tipo,strtok(NULL,";"));
      a->prezzo = atof(strtok(NULL,";"));
      a->km = atof(strtok(NULL,";"));
      bool con = controllo(a, first);
      if(!con){
        first->a = *(a);
        aus = first;
        first = (TNodo*) malloc(sizeof(TNodo));
        first->next = aus;
      }
      fgets(str,LEN,f);
    }
    if(a==NULL)
      printf("I dati inseriti non sono corretti");
  }
  return first;
}

bool controllo(TAuto* a,TNodo* first){
  bool tro = false;
  while(first!=NULL){
    if((strcmp(a->targa,first->a.targa)==0) || (strcmp(a->tipo,"Utilitaria")!=0 && strcmp(a->tipo,"lusso")!=0 && strcmp(a->tipo,"confort")!=0) || (a->prezzo<0) || (a->km < 0)){
      tro = true;
    }
    first=first->next;
  }
  return tro;
}

void stampa(TNodo* first){
  while(first!=NULL){
    printf("Targa: %s | ", first->a.targa);
    printf("Modello: %s | ", first->a.modello);
    printf("Tipologia: %s | ", first->a.tipo);
    printf("Prezzo al giorno: %f | ", first->a.prezzo);
    printf("Kilometraggio: %f\n", first->a.km);
    first=first->next;
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
