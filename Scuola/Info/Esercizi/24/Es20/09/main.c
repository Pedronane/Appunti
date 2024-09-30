#include <stdio.h>
#include <stdlib.h>

//Costanti
#define NMAX 100

//Prototipi
void inserimento(int *v,int *n);
void stampa(int *v,int n);
int leggiInt(int vmin,int vmax, char *msg);

int main()
{
  int v[NMAX], num;
  inserimento(v,&num);
  stampa(v,num);
  return 0;
}

void inserimento(int *v,int *n){
  (*n) = leggiInt(1,NMAX,"Inserire la quantita di numeri che si vogliono inserire");
  for(int i=0;i<(*n);i++){
   *(v+i) = leggiInt(1,INT_MAX,"Inserire il numero");
  }
}

void stampa(int *v,int n){
  for(int i=0;i<n;i++){
   printf("%d\n",*(v+i));
  }
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
