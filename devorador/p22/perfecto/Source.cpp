// Grupo 21, CRISTHIAN RODRIGUEZ GOMEZ y JONATHAN CARRERO ARANDA
//
// El coste del programa viene dado por la funci�n sort que tiene una complejidad de O(n*logn)
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int solucion(vector<int> &pilas, int &voltajeMinimo){
	int numCoches = 0;

	sort(pilas.begin(), pilas.end());	// O(n*logn), donde n es el n�mero de pilas

	int i = 0;					// �ndice para el principio del vector
	int j = pilas.size() - 1;	// �ndice para el final del vector

	while (i < j){
		if (pilas[j] + pilas[i] >= voltajeMinimo){	// Si el voltaje es suficiente...
			numCoches++;
			i++;
			j--;
		}
		else{	// Si no, debemos coger una pila de m�s voltaje que la anterior que ten�amos
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