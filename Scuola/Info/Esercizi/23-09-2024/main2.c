

/*
Marchesi Pietro 4BI
Realizzare la procedura che carica un array di record prelevando i dati da file csv (pseudocodice e linguaggio Cstd in cui >NON è possibile usare le []). voi caricaArray(TDati *v, int n);
Realizzare ambiente chiamante sia con array istanziato a run time che con array allocato a compile time.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Costanti
#define NMAX 100
#define LEN 100

//Struct
typedef struct{
  int n;
  float f;
  char c;
  char s[LEN];
}TDati;

//Prototipi
void caricaArray(TDati* v, int *n);
int leggiInt (int vmin, int vmax, char *msg);

int main(){
  TDati* dati = (TDati*) malloc(sizeof(TDati));
  int *n = (int*) malloc(sizeof(int));
  caricaArray(dati, n);
  return 0;
}
/*
apri file in input
se file e aperto
  mentre file non e finito
    leggi la pross stringa e mettila in str
    dividi str in elementi e metti gli elementi nei rispettivi campi della struct
  fciclo
  chiudi il file
altrimenti 
  scrivi errore
fse
*/
void caricaArray(TDati* v, int *n){
  char *str = (char*) malloc(LEN);
  FILE* f;
  f = fopen("a.csv","r");
  if(f != NULL){
    fgets(str,LEN,f);
    while(feof(f) == 0){
      ((v) -> n) = atoi(strtok(str,";"));
      ((v) -> f) = atof(strtok(NULL,";"));
      strcpy(&((v) -> c), strtok(NULL,";"));
      strcpy(((v) -> s),strtok(NULL,";"));
      fgets(str,LEN,f);
    }
  }else{
    printf("Non e stato trovato il file\n");
  }
  fclose(f);
}

int leggiInt (int vmin, int vmax, char *msg){
  int n;
  puts(msg);
  do{
    scanf("%i",&n);
    if(n<vmin || n>vmax)
      puts("errore \n");
  }while(n<vmin || n>vmax);
  return n;
}

