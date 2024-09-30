#include <iostream>
#include <string>
/*Deve permettere di gestire un elenco di stringhe (nomi). Fate in modo che consenta:
inserimento di un nuovo nome (se c'è ancora spazio nel vettore)
visualizzazione di tutti i nomi inseriti
ricerca di un nome (dire se è presente o no) e stampare la posizione
(più difficile) eliminare un nome (tutti i nomi successivi a quello eliminato devono essere traslati*/
using namespace std;
const int NMAX = 100;

//prototipi
int leggiInt(int n1, int n2, string msg);
string leggiString(string msg);
void Inserimento(string *nomi, int &n);
void Stampa(string *nomi, int &n);
void Elimina();


int main()
{
  string nomi[NMAX];
  int sc;
  int n = -1;
  do {
    cout << "le quattro scelte" << endl;
    sc = leggiInt(1,4,"Inserire la propria scelta");
    switch(sc){
      case 1:
        Inserimento(nomi, n);
        break;
      case 2:
        Stampa(nomi, n);
        break;
      case 3:
        Elimina();
        break;
      case 4:
        cout << "Grazie per aver usato il programma" << endl;
        break;
    }
  } while(sc != 4);
  return 0;
}

void Inserimento(string *nomi, int &n){
  if (n<NMAX) {
    nomi[n+1] = leggiString("Digitare il nome che si vuole inserire");
    n++;
  }else {
    cout << "Il numero massimo di nomi e' stato raggiunto" << endl;
  }
}

void Stampa(string *nomi, int &n){
  if (n>=0) {
    for (int i = 0; i <= n; i++) {
      cout << nomi[i] << endl;
    }
  }else {
    cout << "Non sono ancora stati inseriti nomi" << endl;
  }
}

void Elimina(){

}

int leggiInt(int n1, int n2, string msg){
  int n;
  do {
    cout << msg <<endl;
    cin >> n;
    if (n<n1 || n>n2) {
      cout << "il numero non e' corretto reinserire" << endl;
    }
  } while(n<n1 || n>n2);
  return n;
}

string leggiString(string msg){
  string s;
  do {
    cout << msg << endl;
    cin >> s;
    if (s == "") {
      cout << "la stringa non e' corretta reinserire" << endl;
    }
  } while(s == "");
  return s;
}
