// Grupo 21, CRISTHIAN RODRIGUEZ GOMEZ y JONATHAN CARRERO ARANDA
#include <iostream>
#include "PriorityQueue.h"
using namespace std;


void resuelveCaso(){

	int numPilas, voltajeMinimo, i_esimaPila, numCoches = 0;

	cin >> numPilas;
	cin >> voltajeMinimo;

	PriorityQueue <int, greater<int>> ColaMaximo(numPilas);
	PriorityQueue <int, less<int>> ColaMinimo(numPilas);

	// Rellenamos las dos colas, una de Maximos y otra de Minimos
	for (int i = 0; i < numPilas; i++){
		cin >> i_esimaPila;
		ColaMaximo.push(i_esimaPila);
		ColaMinimo.push(i_esimaPila);
	}

	// Mientras la cima de Maximos sea mayor que la cima de Minimos, no se estarán repitiendo elementos
	while (ColaMaximo.top() > ColaMinimo.top()){

		if (ColaMaximo.top() + ColaMinimo.top() >= voltajeMinimo){
			numCoches++;
			ColaMaximo.pop();
			ColaMinimo.pop();
		}
		else if (ColaMaximo.top() + ColaMinimo.top() < voltajeMinimo){
			ColaMinimo.pop();
		}
	}

	cout << numCoches << endl;
}

int main(){

	int numCasos;
	cin >> numCasos;

	for (int i = 0; i < numCasos; i++){
		resuelveCaso();
	}
	return 0;
}