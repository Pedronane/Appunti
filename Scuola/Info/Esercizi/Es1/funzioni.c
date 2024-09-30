//Marchesi Pietro 4BI
#include "header.h"

void inserimento(char*frase){
    leggiStr(frase,"Insere la frase");
}

void conta(char*frase){
    int voc=0,cons=0;
    for(int i=0;*(frase+i)!='\0';i++){
        if(*(frase+i)=='a'||*(frase+i)=='e'||*(frase+i)=='i'||*(frase+i)=='0'||*(frase+i)=='u')
            voc++;
        else if((*(frase+i)>=65&&*(frase+i)<=90)||(*(frase+i)>=97&&*(frase+i)<=123))
            cons++;
    }
    printf("Il numero di vocali e %i \n",voc);
    printf("Il numero di consonanti e %i \n",cons);
}

void invertiStampa(char*frase){
   int lun=strlen(frase);
   for(int i=lun-1;i>=0;i--){
        printf("%c",*(frase+i));
        printf("\n");
   }
}

void sostituisci(char*frase){
     char *frase1=(char*)malloc(sizeof(char)*strlen(frase));
     strcpy(frase1,frase);
     for(int i=0;*(frase1+i)!='\0';i++){
        if(*(frase+i)=='a'||*(frase+i)=='e'||*(frase+i)=='i'||*(frase+i)=='o'||*(frase+i)=='u')
            *(frase1+i)='-';
     }
     printf("%s",frase1);
     printf("\n");
}

void contaChar(char*frase){
    char c = leggiChar("Inserire il carattere da cercare\n");
    int n = 0,lun = strlen(frase);
    for(int i=0;i<lun-1;i++){
        if(c == *(frase+i))
            n++;
   }
   printf("Il carattere inserito appare %i volte\n",n);
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
