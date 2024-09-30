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
        while(!feof(f) && n < NMAX){
            fgets(str,LEN,f);
            n++;
        }
    }else{
        printf("Il file non esiste\n");
    }
    fclose(f);
    return n-1;
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
void importa(TGioco *g, int n){
    char str[LEN];
    int num;
    FILE *f = fopen("catalogo.csv", "r");
    if(f != NULL){
        while(!feof(f) && num < n){
            fgets(str,LEN,f);
            strcpy((g+n)->id,strtok(str,";"));
            strcpy((g+n)->nome,strtok(NULL,";"));
            (g+n)->costo = atof(strtok(NULL,";"));
            (g+n)->clas = strtok(NULL,";");
            num++;
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
