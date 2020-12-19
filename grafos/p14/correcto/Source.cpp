// Grupo 21, CRISTHIAN RODRIGUEZ GOMEZ y JONATHAN CARRERO ARANDA

// El problema se ha resuelto usando  la clase Manchas,  
// con un nuevo método que devuelve el numero mayor de manchas  ( calculado despues de la lectura del bitmap).
// o(n^2) donde n es el numero de casillas del bitmap

#include <iostream>
#include <string>
#include "Manchas.h"
using namespace std;


// resuelve un caso de prueva
bool resuelveCaso(){

	int F,C;
	
	cin >> F;
	cin >> C;
	
	cin.ignore();
	if (!cin){
		return false;

	}
	

	
	Manchas<char> manchas(F, C);
	
	// leemos matriz
	manchas.read_by_user();

	//// mostrar solucion
	cout << manchas.mancha_mas_grande() << endl;

	return true;
}

int main(){

	// casos de prueba ilimitados
	while (resuelveCaso());

	return 0;
}