// Grupo 21, CRISTHIAN RODRIGUEZ GOMEZ y JONATHAN CARRERO ARANDA
#include <iostream>
#include <algorithm>
#include "PriorityQueue.h"
using namespace std;

bool resuelveCaso(){

	int N, numDefensores, numAtacantes, ciudadesDefendidas = 0;

	cin >> N;

	if (!cin)
		return false;

	vector<int> defensores(N);
	vector<int> atacantes(N);

	for (int i = 0; i < N; i++){	// Rellenamos el vector atacantes
		cin >> numAtacantes;
		atacantes[i] = numAtacantes;
	}

	for (int i = 0; i < N; i++){	// Rellenamos el vector defensores
		cin >> numDefensores;
		defensores[i] = numDefensores;
	}

	sort(atacantes.begin(), atacantes.end());	// Ordenamos el vector atacantes
	sort(defensores.begin(), defensores.end());	// Ordenamos el vector defensores

	int d = 0;	// Índice para el vector defensores
	int a = 0;	// Índice para el vector atacantes

	while (d < N){	// Se usa el índice de defensores (d) porque será el que primero llegue a N, pues no se pueden defender más ciudades de las que se estén atacando
		if (defensores[d] >= atacantes[a]){	// Si la ciudad se puede defender...
			ciudadesDefendidas++;
			d++;
			a++;
		}
		else if (defensores[d] < atacantes[a]){ // Si no se puede defender...
			d++;
		}
	}

	cout << ciudadesDefendidas << endl;

	return true;
}

int main(){
	while (resuelveCaso());
	return 0;
}