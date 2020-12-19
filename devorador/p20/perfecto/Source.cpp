// Grupo 21, CRISTHIAN RODRIGUEZ GOMEZ y JONATHAN CARRERO ARANDA
//
// El coste del programa viene dado por el bucle While. Luego el programa tiene una complejidad O(n*logn).
#include <stdio.h>
#include <iostream>
#include <cmath>
#include "PriorityQueue.h"
using namespace std;

bool resuelveCaso(){

	int N, alturaEsquiador, longitudEsquis, diferencia = 0;

	cin >> N;

	if (N == 0)
		return false;

	PriorityQueue<int> Esquiadores(N);
	PriorityQueue<int> Esquis(N);

	for (int i = N; i > 0; i--){	// O(n), lineal en el número de Esquiadores
		cin >> alturaEsquiador;
		Esquiadores.push(alturaEsquiador);
	}

	for (int i = N; i > 0; i--){	// O(n), lineal en el número de Esquis
		cin >> longitudEsquis;
		Esquis.push(longitudEsquis);
	}

	while (!Esquiadores.empty()){	// O(n*logn), pop tiene coste logn y se hace n veces, donde n es el número de Esquis y Esquiadores
		diferencia = diferencia + abs(Esquiadores.top() - Esquis.top());	

		// Quitar ambas cimas
		Esquiadores.pop();
		Esquis.pop();
	}

	cout << diferencia << endl;

	return true;
}

int main(){
	while (resuelveCaso());
	return 0;
}