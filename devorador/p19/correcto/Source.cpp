// Grupo 21, CRISTHIAN RODRIGUEZ GOMEZ y JONATHAN CARRERO ARANDA
#include <iostream>
using namespace std;

bool resuelveCaso(){

	
	unsigned int N, L; // donde N = número de agujero y L = longitud del parche

	cin >> N;

	if (!cin)
		return false;

	cin >> L;

	int agujeroSiguiente, agujeroActual, distancia, longParche = L, numParches = 1;

	cin >> agujeroActual;

	for (int i = 1; i < N; i++){
		cin >> agujeroSiguiente;

		distancia = agujeroSiguiente - agujeroActual;

		if (distancia > longParche){
			numParches++;
			longParche = L;
		} else
			longParche = longParche - distancia;

		agujeroActual = agujeroSiguiente;
	}

	cout << numParches << endl;

	return true;
}

int main(){
	while (resuelveCaso());
	return 0;
}