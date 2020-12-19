// Grupo 21, CRISTHIAN RODRIGUEZ GOMEZ y JONATHAN CARRERO ARANDA
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int solucion(vector<int> &pilas, int &voltajeMinimo){
	int numCoches = 0;

	sort(pilas.begin(), pilas.end());	// Ordenamos el vector atacantes	O(nlog n)

	int i = 0;					// Índice para el principio del vector
	int j = pilas.size() - 1;	// Índice para el final del vector

	while (i < j){
		if (pilas[j] + pilas[i] >= voltajeMinimo){	// Si el voltaje es suficiente...
			numCoches++;
			i++;
			j--;
		}
		else{				// Si no, debemos coger una pila de más voltaje que la anterior que teníamos
			i++;
		}
	}
	return numCoches;
}

void resuelveCaso(){

	int numPilas, i_esimaPila, voltajeMinimo, numCoches = 0;

	cin >> numPilas;
	cin >> voltajeMinimo;



	vector<int> pilas(numPilas);

	for (int i = 0; i < numPilas; i++){	// Rellenamos el vector pilas
		cin >> i_esimaPila;
		pilas[i] = i_esimaPila;
	}

	
	// mostramos la solucion
	cout << solucion(pilas, voltajeMinimo) << endl;

}

int main(){

	int numCasos;
	cin >> numCasos;

	for (int i = 0; i < numCasos; i++){
		resuelveCaso();
	}
	return 0;
}