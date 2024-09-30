#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
per una serie di persone di cui si conosce peso ed altezza, realizzare un programma che permetta di:
a) calcolare l'indice BMI (indice di massa corporea) indicando a quale classe appartiene l'utente
b) elencare i dati forniti per le persone considerate "sottopeso" e il loro numero totale.
I dati delle persone sono contenute in un file di testo avente per ogni riga peso e altezza di una singola persona separata da uno spazio.
Vincoli: i dati del file DEVONO essere caricati in un array di record istanziato a run time con un numero di elòementi pari a numero delle righe del file
*/

//Costanti
#define LEN 100
#define NMAX 100
#define BMISOTTO 18.4
#define BMISOVRA 25

//Struct
typedef struct{
  float peso;
  int altezza;
  float bmi;
  char cat[];
}TPersona;

//Prototipi
int contarighe();
void importa(TPersona *p, int num);
void calcola(TPersona *p, int num);
void elencoSotto(TPersona *p, int num);

//PROTOTIPI FUNZIONI INPUT
int leggiInt (int vmin, int vmax, char *msg);
float leggiFloat (float vmin, float vmax, char *msg);
char leggiChar(char *msg);
void leggiStr(char *s,char *msg);

int main()
{
  int n = contarighe(), sc;
  if(n != 0){
    TPersona* persona = (TPersona*) malloc(sizeof(TPersona)*n);
    importa(persona, n);
    do{
      sc = leggiInt(1,3,"Quale scelta si vuole fare");
      switch (sc){
        case 1:
          calcola(persona, n);
          break;
        case 2:
          elencoSotto(persona, n);
          break;
        case 3:
          printf("Grazie per aver usato il programma\n");
          break;
      }
    }while(sc != 3);
  }else{
    printf("Non e stato trovato il file csv\n");
  }
  return 0;
}

/*
INIZIO
apri il file a.csv in lettura
se file esiste
allora
  conta le righe del file
  ritorna come valore il numero di righe
altrimenti
  scrivi il file non esiste
fse
FINE

*/
int contarighe(){
  int n=0;
  char str[LEN];
  FILE* f = fopen("a.csv","r");
  if (f != NULL) {
    while (!feof(f) && n<NMAX){
      fgets(str,LEN,f);
      n++;
    }
  }else {
    printf("Il file non esiste\n");
  }
  return n;
}

/*
INIZIO
apri il file f in lettura
se il file esiste
allora
  mentre il file non e finito e n<num
    leggi una riga del file e mettila in str
    divida la riga in item e metti gli item nei campi della struct
    incrementa n
  fciclo
altrimenti
  scrivi il file non esiste
fse
FINE
*/
void importa(TPersona *p, int num){
  char str[LEN];
  int n = 0;
  FILE* f = fopen("a.csv","r");
  if (f != NULL) {
    while (!feof(f) && n<num){
      fgets(str,LEN,f);
      (p+n) -> peso = atof(strtok(str," "));
      (p+n) -> altezza = atoi(strtok(NULL," "));
      n++;
    }
  }
}

/*
INIZIO
mentre i<n
  calcola il bmi della persona alla posizione i
  controlla in quale categoria ricade la persona
  stampa indice e categoria della persona
  i++
fciclo
FINE
*/
void calcola(TPersona *p, int num){
  int h;
  float peso;
  for(int i=0;i<num;i++){
    peso = (p+i)->peso;
    h = (p+i)->altezza;
    (p+i)->bmi = peso/(h*2);
    if((p+i)->bmi <= BMISOTTO){
      strcpy((p+i)->cat,"Sottopeso");
    }else if((p+i)->bmi >= BMISOVRA){
      strcpy((p+i)->cat,"Sovrappeso");
    }else{
      strcpy((p+i)->cat,"Normopeso");
    }
    printf("La %d persona ha un bmi di %f ed appartiene alla categoria %s\n",i+1,(p+i)->bmi,(p+i)->cat);
  }
}

/*
INIZIO
mentre i<n
  se cat == Sottopeso
  stampa ibm altezza e peso
  i++
fciclo
FINE
*/
void elencoSotto(TPersona *p, int num){
  for(int i=0;i<num;i++){
    if(strcmp((p+i)->cat, "Sottopeso")==0){
      printf("La %d persona ha un bmi di %f, un' altezza di %dcm ed ha un peso di %fKg\n",i+1,(p+i)->bmi,(p+i)->altezza,(p+i)->peso);
    }
  }
}


//FUNZIONI DI INPUT

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
