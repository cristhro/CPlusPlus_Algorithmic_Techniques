// Grupo 21, CRISTHIAN RODRIGUEZ GOMEZ y JONATHAN CARRERO ARANDA
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool resuelveCaso(){

	int numPilas, i_esimaPila, voltajeMinimo, numCoches = 0;

	cin >> numPilas;
	cin >> voltajeMinimo;

	if (!cin)
		return false;

	vector<int> pilas(numPilas);

	for (int i = 0; i < numPilas; i++){	// Rellenamos el vector pilas
		cin >> i_esimaPila;
		pilas[i] = i_esimaPila;
	}

	sort(pilas.begin(), pilas.end());	// Ordenamos el vector atacantes

	int i = 0;	// Índice para el principio del vector
	int j = numPilas - 1;	// Índice para el final del vector

	while (i < j){
		if (pilas[j] + pilas[i] > voltajeMinimo){	// Si el voltaje es suficiente...
			numCoches++;
			i++;
			j--;
		}
		else{	// Si no, debemos coger una pila de más voltaje que la anterior que teníamos
			i++;
		}
	}
	
	cout << numCoches << endl;

	return true;
}

int main(){

	int numCasos;
	cin >> numCasos;

	for (int i = 0; i < numCasos; i++){
		resuelveCaso();
	}
	return 0;
}