#include <iostream>
#include <conio.h>
#include <string.h>
using namespace std;
struct Nodo{
  int valor;
  string nombre;
  Nodo *siguiente;
};
void insertarLista(int, string);
void mostrarlista();
Nodo *inicio = NULL;
int main(int argc, char const *argv[]) {
 Nodo *lista = NULL;
	int dato;
	char opcion;
	string dato2;

	do{
        cout << "Nombre del corredor: " ;
        cin.ignore();
        getline(cin, dato2);
		cout << "Tiempo en minutos: ";
		cin>>dato;
        insertarLista(dato, dato2);

		cout<<"\nDesea agregar un nuevo corredor(s=si/n=no): ";
		cin>>opcion;
	}while(opcion == 's' || opcion == 'S');
  cout << endl;
  mostrarlista();
  getch();
  return 0;
}//fin de main

void insertarLista(int n, string n2){
  Nodo *actual = new Nodo();
  actual->valor = n;
  actual->nombre = n2;
  Nodo *aux1 = inicio;
  Nodo *aux2;
  while((aux1 != NULL) && (aux1 -> valor < n)){
    aux2 = aux1;
    aux1 = aux1 -> siguiente;
  }

  if(inicio == aux1){
    inicio = actual;
  }else{
    aux2 -> siguiente = actual;
  }
  actual -> siguiente = aux1;
}

void mostrarlista(){
  Nodo *actual = new Nodo ();
  actual = inicio;
  int i=0;
  while (actual != NULL) {
    if(i==0){
        cout << "primer lugar: ";
    }if(i==1){
        cout << "segundo lugar: ";
    }if(i==2){
        cout << "tercer lugar: ";
    }
    if(i>2){
        cout << "sin lugar ... :(";
    }
    cout<< "\t" << actual->valor << "\t   " << actual->nombre << "\n"; //mostramos el dato
    actual = actual -> siguiente;
    i++;
  }
}


