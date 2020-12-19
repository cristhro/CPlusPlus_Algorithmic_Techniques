// Grupo 21, CRISTHIAN RODRIGUEZ GOMEZ y JONATHAN CARRERO ARANDA

// El problema se ha resuelto mediante una  clase nueva llamada ColaUrgencia con
// metodos para poder insetar, ver si es vacia la cola, obtener el primer nombre, y quitar el primero.

#include <iostream>
#include <string>
#include "ColaUrgencias.h"

using namespace std;



/*
	Funcion que 
	si el evento es  "I",
		lee los pacientes de la entrada estandar y los inserta en la cola de prioridad
	si el evento es "A" 
		lo insera en una lista . 

	 O(n log n ) donde n es el numero de elementos
*/

vector<string> Pacientes_Curados(int num_Elems){
	
	ColaUrgencias cola(num_Elems);
	string evento;
	string nombre;
	int gravedad;	

	vector<string> lista;
	int i = 0;

	while( i < num_Elems)
	{
		
		cin >> evento; // lee un evento

		if (evento == "I"){
			

			cin >> nombre;
			cin >> gravedad;
			cola.insertar(nombre, gravedad);

		}
		else if (evento == "A" && !cola.esVacia()){
			string nombre;

			nombre = cola.nombrePrimero();
			cola.quitarPrimero();
			lista.push_back(nombre);
		
		}
		i++;
	}
	return lista;
}

	//Procedimeinto que muestra la solucion
	// O(n) segun el numero de elementos que tiene la lista.

void mostrar_lista(vector<string> lista){
	for (auto i = 0; i < lista.size(); ++i) {
		
		cout << lista[i] << endl;
	}
}
	// resuelve un caso de prueba
bool resuelveCaso(){

	int N;
	vector<string> lista;

	cin >> N;  // número de Eventos (tamaño del problema)

	if (N == 0) // fin de los casos
		return false;

	lista = Pacientes_Curados(N);

	// escribimos el resultado
	mostrar_lista(lista);

	cout << "----" << endl;
	return true;
}

int main() {
	while (resuelveCaso()); // mientras haya casos los procesamos
	return 0;
}