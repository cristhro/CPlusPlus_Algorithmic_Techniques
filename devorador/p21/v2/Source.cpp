// Grupo 21, CRISTHIAN RODRIGUEZ GOMEZ y JONATHAN CARRERO ARANDA
#include <iostream>
#include <algorithm>
#include "PriorityQueue.h"
using namespace std;

// NOTA: Se resuelve de forma parecida al anterior, es decir, se crean dos colas de prioridad y se empieza a ver si la ciudad puede defenderse
bool resuelveCaso(){

	int N, numDefensores, numAtacantes, ciudadesDefendidas = 0;
	
	cin >> N;

	if (!cin)
		return false;

	int *defensores, *atacantes;
	defensores = new int[N];
	atacantes = new int[N];

	//PriorityQueue<int, greater<int>> Defensores(N);
	//PriorityQueue<int, greater<int>> Atacantes(N);

	for (int i = 0; i < N; i++){	// Rellenamos la cola Defensores
		cin >> numDefensores;
		defensores[i] = numDefensores;
	}

	for (int i = 0; i < N; i++){	// Rellenamos la cola Defensores
		cin >> numAtacantes;
		atacantes[i] = numAtacantes;
	}

	sort(defensores, atacantes);

	/*while (!Atacantes.empty()){	// Mientras la cola de Atacantes (por ejemplo) no sea vacía...
		numDefensores = Defensores.top();
		numAtacantes = Atacantes.top();

		if (numDefensores >= numAtacantes){	// Si hay al menos el mismo número de defensores, la ciudad queda defendida
			ciudadesDefendidas++;
		}
	}
	*/

	cout << ciudadesDefendidas << endl;

	return true;
}

int main(){
	while (resuelveCaso());
	system("PAUSE");
	return 0;
}