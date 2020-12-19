// Grupo 21, CRISTHIAN RODRIGUEZ GOMEZ y JONATHAN CARRERO ARANDA

// El problema se ha resuelto mediante una  clase nueva llamada PajarosEnVuelo con
// metodos publicos para poder insetar una pareja de pajaros, y otro para obtener el valor del lider.

#include <iostream>
#include <string>
#include "PajarosEnVuelos.h"
using namespace std;

//
bool resuelveCaso() {

	int edad_Lider;
	int numero_parejas;

	cin >> edad_Lider;
	cin >> numero_parejas; // número de Parejas (tamaño del problema)

	if (edad_Lider == 0 && numero_parejas == 0) // fin de los casos
		return false;

		// se construye una clase PajarosEnVuelo a partir de las edades leídas de la entrada
		// O(N log N), siendo N el número de parejas insertadas

	PajarosEnVuelos pajaros(edad_Lider);
	int edad1, edad2;

	for (int i = 0; i < numero_parejas; i++) {
		// leemos las edades de la pareja que entra al grupo
		cin >> edad1;
		cin >> edad2;

		pajaros.insertarPareja(edad1, edad2);	
		
		// y se busca el lider con el metodo de la clase PajarosEnVuelo O(1)
		cout << pajaros.edadLider();			//muestra solucion

		if (i<numero_parejas - 1) cout << " ";
	}

	cout << endl;
	return true;
}

int main() {
	while (resuelveCaso()); // mientras haya casos los procesamos
	return 0;
}