/*
Marchesi Pietro 4BI
Scrivere funzione che "mystrconcat" che concatena due stringhe e ritorna la stringa concatenata.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LEN 100

//Prototipi
void leggiStr(char *s,char *msg);
char* mystrconcat();

int main()
{
    printf("%s\n",mystrconcat());
    return 0;
}

char* mystrconcat(){
    char s1[LEN],s2[LEN];
    int n=0;
    leggiStr(s1,"Inserire la prima stringa");
    leggiStr(s2,"Inserire la secoda stringa");
    int len = (strlen(s1) + strlen(s2))+1;
    char* s = (char*) malloc(sizeof(char)*len);
    for(int i=0;i<strlen(s1);i++){
        *(s+i)=*(s1+i);
    }
    for(int i=strlen(s1);i<len;i++){
        *(s+i) = *(s2+n);
        n++;
    }
    *(s+len) = '\0';
    return s;
    free(s);
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
