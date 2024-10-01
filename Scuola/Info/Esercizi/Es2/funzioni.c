#include "header.h"

//FUNZIONI

/*
INIZIO
apri il file cataologo.csv in letture
se file esiste
allora
    conta tutte le rige in n
    ritorna n
altrimenti
    scrivi il file non esiste
    ritorna 0
fse
chiudi il file
*/
int contarighe(){
    int n = 0;
    char str[LEN];
    FILE *f = fopen("catalogo.csv", "r");
    if(f != NULL){
        fgets(str,LEN,f);
        while(!feof(f) && n < NMAX){
            n++;
            fgets(str,LEN,f);
        }
    }else{
        printf("Il file non esiste\n");
    }
    fclose(f);
    return n;
}

/*
INIZIO
apri file catalogo.csv in lettura
se file esiste
allora
    mentre file non e finito e n < num
        leggi la prima riga
        dividi la riga in item e mettili nei campi della struct controllando che ID sia univoco, costo > 0, clas == A o B o S, usato == 0 o 1
        se uno dei campi non e corretto non copiare all'interno dei campi ma copia in log.csv
        n++
    fciclo
altrimenti
    scrivi il file non esiste
fse
*/
TGioco* importa(TGioco *g, int n, int *num){
    char str[LEN],aus[LEN];
    int i;
    FILE *f = fopen("catalogo.csv", "r");
    FILE *l = fopen("log.csv","w");
    if(f != NULL){
        g = (TGioco*)malloc(sizeof(TGioco)*n);
        fgets(str,LEN,f);
        while(!feof(f) && *num < n){
            strcpy(aus,str);
            strcpy((g+*num)->id,strtok(str,";"));
            i =ricerca(g,(g+*num)->id,*num);
            if(i == -1){
                strcpy((g+*num)->nome,strtok(NULL,";"));
                (g+*num)->costo = atof(strtok(NULL,";"));
                if((g+*num)->costo > 0){
                    strcpy(&((g+*num)->clas),strtok(NULL,";"));
                    if((g+*num)->clas=='S' || (g+*num)->clas=='A' || (g+*num)->clas=='B'){
                        (g+*num)->usato = atoi(strtok(NULL,";"));
                        if((g+*num)->usato == 0 || (g+*num)->usato == 1)
                            (*num)++;
                        else
                            fprintf(l,"%s",aus);
                    }else
                        fprintf(l,"%s",aus);
                }else
                    fprintf(l,"%s",aus);
            }else
                fprintf(l,"%s",aus);
            fgets(str,LEN,f);
        }
        fclose(f);
        fclose(l);
    }else{
        printf("Non e stato trovato il file\n");
    }
    return g;
}

/*
INIZIO
se il record e stato allocato
allora
    mentre i < n
        stampa i campi del record i
        i++
    fciclo
altrimenti
    scrivi il file non e acora stato importato
fse
FINE
*/

void stampa(TGioco *g, int n){
    if(g!=NULL){
        for(int i=0;i<n;i++){
            printf("%s\n",(g+i)->id);
            printf("%s\n",(g+i)->nome);
            printf("%f\n",(g+i)->costo);
            printf("%c\n",(g+i)->clas);
            printf("%d\n",(g+i)->usato);
        }
    }else
        printf("Il file non e ancora stato importato\n");
}

/*
INIZIO
se il record e stato allocato
allora
    ve=0
    mentre i<n
        somma il campo costo a ve
        i++
    fciclo
    stampa ve
altrimenti
    scrivi il file non e acora stato importato
fse
FINE
*/

void valoreEconomico(TGioco *g, int n){
    if(g!=NULL){
        float ve=0;
        for(int i=0;i<n;i++){
            ve += (g+i)->costo;
        }
        printf("%f\n",ve);
    }else
        printf("Il file non e ancora stato importato\n");
}

/*
INIZIO
se il record e stato allocato
allora
    leggi l'id1
    ricerca l'id all'interno del record
    se id esiste allora
        stampa dati videogioco
    altrimenti
        scrivi l'id non e stato trovato
    fse
altrimenti
    scrivi il file non e acora stato importato
fse
FINE
*/

void stampaDaId(TGioco *g, int n){
    if(g!=NULL){
        char id1[LEN];
        leggiStr(id1,"Inserire l'ID che si desidera cercare");
        int pos = ricerca(g,id1,n);
        if(pos != -1){
            printf("%s\n",(g+pos)->id);
            printf("%s\n",(g+pos)->nome);
            printf("%f\n",(g+pos)->costo);
            printf("%c\n",(g+pos)->clas);
            printf("%d\n",(g+pos)->usato);
        }else{
            printf("Non e stato trovato l'id\n");
        }
    }else
        printf("Il file non e ancora stato importato\n");
}

/*
INIZIO
se il record e stato allocato
allora
    leggi l'id1
    ricerca l'id all'interno del record
    se id esiste allora
        leggi costo e modifica
    altrimenti
        scrivi l'id non e stato trovato
    fse
altrimenti
    scrivi il file non e acora stato importato
fse
FINE
*/

void modificaDaId(TGioco *g, int n){
    if(g!=NULL){
        char id1[LEN];
        leggiStr(id1,"Inserire l'ID che si desidera cercare");
        int pos = ricerca(g,id1,n);
        if(pos != -1){
            (g+pos)->costo = leggiFloat(1,FLT_MAX,"Inserire il nuovo costo");
        }else{
            printf("Non e stato trovato l'id\n");
        }
    }else
        printf("Il file non e ancora stato importato\n");
}

/*
INIZIO
se il record e stato allocato
allora
    apri file in scrittura
    leggi la clas1
        esporta nel file giochi.txt tutti i giochi con clas == clas1
    altrimenti
        scrivi la classificazione non e stata trovata
    fse
altrimenti
    scrivi il file non e acora stato importato
fse
FINE
*/

void espCat(TGioco *g, int n){
    if(g!=NULL){
        char clas1;
        int pos = -1;
        clas1 = leggiChar("Inserire la classe che si desidera cercare");
        FILE *f = fopen("giochi.txt","w");
        for(int i=0;i<n;i++){
            if((g+i)->clas == clas1){
                fprintf(f,"%s ",(g+i)->id);
                fprintf(f,"%s ",(g+i)->nome);
                fprintf(f,"%f ",(g+i)->costo);
                fprintf(f,"%c ",(g+i)->clas);
                fprintf(f,"%d\n",(g+i)->usato);
                pos = i;
            }
        }
        if(pos == -1)
            printf("Non e stato trovato alcun gioco con questa categoria\n");
        fclose(f);
    }else
        printf("Il file non e ancora stato importato\n");
}

int ricerca(TGioco *v, char *el, int n){
    int pos = -1;
    for(int i=0; i<n && pos==-1; i++){
        if(strcmp((v+i)->id,el) == 0)
            pos = i;
    }
    return pos;
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
