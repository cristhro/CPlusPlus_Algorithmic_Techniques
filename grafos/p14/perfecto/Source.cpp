// Grupo 21, CRISTHIAN RODRIGUEZ GOMEZ y JONATHAN CARRERO ARANDA

// El problema se ha resuelto usando  la clase Manchas,  
// con un nuevo método que devuelve el numero mayor de manchas  ( calculado despues de la lectura del bitmap).
// O (F*C + log *) donde f es numero de filas, c numero de columnas, log * coste de unir y buscar el cual tiende a constante

#include <iostream>
#include <string>
#include "Manchas.h"
#include <vector>
using namespace std;


// resuelve un caso de prueva
bool resuelveCaso(){						//O( F*C)

	int F, C;
	vector <int> sol;

	cin >> F;
	cin >> C;

	cin.ignore();
	if (!cin){
		return false;
	}

	Manchas<char> manchas(F, C);					// O ( F*C ), donde N es el numero de elementos que tiene la matriz

	// leemos matriz
	manchas.read_by_user();							// O (F*C + log *)


	
	// mostrar solucion
	cout << manchas.mancha_mas_grande() << endl;

	return true;
}

int main(){

	// casos de prueba ilimitados
	while (resuelveCaso());

	return 0;
}