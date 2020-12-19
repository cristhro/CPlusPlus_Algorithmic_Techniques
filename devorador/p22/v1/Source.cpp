// Grupo 21, CRISTHIAN RODRIGUEZ GOMEZ y JONATHAN CARRERO ARANDA
#include <iostream>
#include "PriorityQueue.h"
using namespace std;


void resuelveCaso(){

	int numPilas, voltajeMinimo, i_esimaPila, numCoches = 0;
	int voltajeActual, acumuladorVoltajeMinimos = 0;

	cin >> numPilas;
	cin >> voltajeMinimo;

	PriorityQueue <int, greater<int>> ColaMaximo(numPilas);
	PriorityQueue <int, less<int>> ColaMinimo(numPilas);

	for (int i = 0; i < numPilas; i++){
		cin >> i_esimaPila;
		ColaMaximo.push(i_esimaPila);
		ColaMinimo.push(i_esimaPila);
	}

	while (ColaMaximo.top() > ColaMinimo.top()){

		acumuladorVoltajeMinimos = acumuladorVoltajeMinimos + ColaMinimo.top();

		if (ColaMaximo.top() >= voltajeMinimo){
			numCoches++;
			ColaMaximo.pop();
		}
		else{
			voltajeActual = ColaMaximo.top() + acumuladorVoltajeMinimos;
			if (voltajeActual >= voltajeMinimo){
				numCoches++;
				ColaMaximo.pop();
				ColaMinimo.pop();
				acumuladorVoltajeMinimos = 0;
			}
			else{
				ColaMinimo.pop();
			}
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