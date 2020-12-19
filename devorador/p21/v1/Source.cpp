// Grupo 21, CRISTHIAN RODRIGUEZ GOMEZ y JONATHAN CARRERO ARANDA
#include <iostream>
#include "PriorityQueue.h"
using namespace std;

// NOTA: Se resuelve de forma parecida al anterior, es decir, se crean dos colas de prioridad y se empieza a ver si la ciudad puede defenderse
bool resuelveCaso(){

	int N, numDefensores, numAtacantes, ciudadesDefendidas = 0;
	
	cin >> N;

	if (!cin)
		return false;

	PriorityQueue<int, less<int>> Defensores(N);
	PriorityQueue<int, less<int>> Atacantes(N);

	for (int i = N; i > 0; i--){	// Rellenamos la cola Defensores
		cin >> numDefensores;
		Defensores.push(numDefensores);
	}

	for (int i = N; i > 0; i--){	// Rellenamos la cola Defensores
		cin >> numAtacantes;
		Atacantes.push(numAtacantes);
	}

	while (!Atacantes.empty()){	// Mientras la cola de Atacantes (por ejemplo) no sea vacía...
		numDefensores = Defensores.top();
		numAtacantes = Atacantes.top();

		if (numDefensores >= numAtacantes){	// Si hay al menos el mismo número de defensores, la ciudad queda defendida
			ciudadesDefendidas++;
		}
	}


	cout << ciudadesDefendidas << endl;

	return true;
}

int main(){
	while (resuelveCaso());
	return 0;
}