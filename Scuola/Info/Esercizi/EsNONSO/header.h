input.c

#include "header.h"
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
char leggiChar(char vmin, char vmax, char *msg){
    char c;
    puts(msg);
    fflush(stdin);
    do{
        scanf("%c",&c);
        if(c<vmin || c>vmax)
            puts("errore \n");
    }while(c<vmin || c>vmax);
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
