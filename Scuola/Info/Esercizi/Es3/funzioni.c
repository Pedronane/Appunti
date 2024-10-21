#include "header.h"

void menu(){
  printf("1)Importazione\n");
  printf("2)Stampa\n");
  printf("3)Visualizzare dati di un auto di cui si fornisce la targa\n");
  printf("4)Salvare su file le auto di un tipo scelto\n");
  printf("5)Calcola guadagno in base ai km effettuati data la targa\n");
  printf("0)Uscire dal programma\n");
}

/*
descr file
il file contiene i dati una singola auto su una riga separati da un ;
i dati sono: targa;modello;tipo;prezzo;km


descr var
aus,nodo ausiliario,TNodo*
a,nodo che contiene i dati prima di essere controllati,TNodo*
f,file csv aperto in lettura,FILE*
str, stringa contente una riga del file,char*
con,vera se il nodo a e sbagliato,ool
descr par
first,primo nodo della lista,TNodo*
nf, nome file, char*

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

/*
descr var
tro,se il nodo e corretto
descr par
a,nodo da controllare,TNodo*
first,primo nodo della lista,TNodo*

INIZIO
  controlla che il nodo a sia corretto
FINE
*/
bool controllo(TAuto* a,TNodo* first){
  bool tro = true;
    if(ricercaTarga(a->targa,first) == NULL){
      if(strcmp(a->tipo,"Utilitaria")==0 || strcmp(a->tipo,"Lusso")==0 || strcmp(a->tipo,"Confort")==0){
        if(a->prezzo>0){
          if(a->km > 0){
            tro = false;
          }
        }
      }
    }
  return tro;
}


/*
descr var
tro,se e stata trovata la targa,bool

descr par
targa,targa da cercare,char*
first,primo nodo della lista,TNodo*

INIZIO
  ricerca la targa passata come parametro nella lista
FINE
*/
TNodo* ricercaTarga(char* targa,TNodo* first){
  bool tro = false;
  while(first!=NULL && tro==false){
    if(strcmp(targa,first->a.targa))
      tro = true;
    first=first->next;
  }
  if(tro == false)
    first = NULL;
  return first;
}

/*
descr par
first,primo nodo della lista,TNodo*

INIZIO
  stampa i dati della lista se esiste
  altrimenti
    scrivi la lista non esiste
  fse
FINE
*/
void stampa(TNodo* first){
  if(first==NULL){
    printf("Non sono ancora stati importati i dati\n");
  }else{
    while(first!=NULL){
      printf("Targa: %s | ", first->a.targa);
      printf("Modello: %s | ", first->a.modello);
      printf("Tipologia: %s | ", first->a.tipo);
      printf("Prezzo al giorno: %f | ", first->a.prezzo);
      printf("Kilometraggio: %f\n", first->a.km);
      first=first->next;
    }
  }
}


/*
descr var
targa,targa che si vuole cercare,char*

descr par
first,primo nodo della lista,TNodo*

INIZIO
  se la lista esiste
  allora
    leggi targa
    ricerca targa all'interno della lista
    se targa e stata trovata
      stamapa i dati dell auto
    altrimenti
      scrivi non e stata trovata un auto con questa targa
    fse
  altrimenti
    scrivi la lista non e ancora stata creata
  fse
FINE
*/
void visualizzaDati(TNodo* first){
  if(first!=NULL){
    char targa[LEN];
    leggiStr(targa,"Inserire la targa da leggere\n");
    first = ricercaTarga(targa,first);
    if(first == NULL)
      printf("Non e stata trovata un auto con questa targa\n");
    else{
      first->next=NULL;
      stampa(first);
    }
  }else{
    printf("la lista non e ancora stata creata\n");
  }
}


/*
descr var
f,file aperto in scrittura,FILE*
tipo,tipo da cercare,char*
tro,se e stato trovato almeno unnodo con tipo,bool

descr par
first,primo nodo della lista,TNodo*

INIZIO
  se la lista esiste
  allora
    apri il file f in scrittura
    leggi tipo
    ricerca tipo all'interno della lista
    se viene trovato
    allora
      salva su file il record in cui e stato trovato
    se non e mai stato trovato
    allora
      scrivi il tipo non e stato trovato
    fse
    chiudi file
  altrimenti
    scrivi la lista non e ancora stata creata
FINE
*/
void esportaTipo(TNodo* first){
  if(first!=NULL){
    FILE* f = fopen("tipo.bin","w");
    char tipo[LEN];
    leggiStr(tipo,"Inserire il tipo da leggere\n");
    bool tro = false;
    while(first!=NULL && tro==false){
      if(strcmp(tipo,first->a.tipo)){
        fwrite(&(first->a),sizeof(TAuto),1,f);
        tro = true;
      }
      first=first->next;
    }
    if(!tro){
      printf("il tipo non e stato trovato\n");
    }
  }else{
    printf("La lista non e ancora stata creata\n");
  }
}


/*
descr var
targa, targa da ricercare,char*
descr par
first,primo nodo della lista,TNodo*

INIZIO
  se la lista esiste
  allora
    leggi targa
    ricerca targa all'interno della lista
    se targa esiste allora
      calcola il guadagno
      stampa il guadagno
    altrimenti
      scrivi la targa non e stata trovata
    fse
  altrimenti
    scrivi la lista non e ancora stata creata
FINE
*/
void calcoloDaTarga(TNodo* first){
  if(first!=NULL){
    char targa[LEN];
    leggiStr(targa,"Inserire la targa da leggere\n");
    first = ricercaTarga(targa,first);
    if(first==NULL)
      printf("Non e stata trovata un auto con questa taraga\n");
    else{
      calcoloStampa(first);
    }
  }else{
    printf("La lista non e ancora stat creata\n");
  }
}


/*
descr var
prz,prezzo calcolato,float
util,prezzo auto utilitaria,float
lusso,prezzo auto lusso,float
confort,prezzo auto confort,float

descr par
nodo,nodo dell'auto di cui si deve calcolare il prz,TNodo*

INIZIO
  calcola il guadagno dell'auto passata come parametro e stampa
FINE
*/
void calcoloStampa(TNodo* nodo){
  float prz;
  float util = 0.44;
  float lusso = 1.99;
  float confort = 0.99;
  if(strcmp(nodo->a.tipo,"Utilitaria")){
    prz = nodo->a.km*util;
  }else if(strcmp(nodo->a.tipo,"Lusso")){
    prz = nodo->a.km*lusso;
  }else{
    prz = nodo->a.km*confort;
  }
  printf("Il prezzo dell'auto e di %f",prz);
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
