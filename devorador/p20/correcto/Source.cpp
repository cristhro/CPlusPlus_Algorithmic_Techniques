// Grupo 21, CRISTHIAN RODRIGUEZ GOMEZ y JONATHAN CARRERO ARANDA
#include <stdio.h>
#include <iostream>
#include <cmath>
#include "PriorityQueue.h"
using namespace std;


bool resuelveCaso(){

	int N, alturaEsquiador, longitudEsquis, diferencia = 0;

	cin >> N;

	if (N == 0)	// Si no hay esquiadores...
		return false;

	PriorityQueue<int> Esquiadores(N);
	PriorityQueue<int> Esquis(N);

	for (int i = N; i > 0; i--){	// Rellenamos la cola Esquiadores
		cin >> alturaEsquiador;
		Esquiadores.push(alturaEsquiador);
	}

	for (int i = N; i > 0; i--){	// Rellenamos la cola Esquis
		cin >> longitudEsquis;
		Esquis.push(longitudEsquis);
	}

	while (!Esquiadores.empty()){	// Mientras la cola de Esquiadores (por ejemplo) no esté vacía...
		diferencia = diferencia + abs(Esquiadores.top() - Esquis.top());	// Obtener la diferencia en valor absoluto de ambas cimase e id sumando

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