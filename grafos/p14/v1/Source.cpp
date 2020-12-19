// Grupo 21, CRISTHIAN RODRIGUEZ GOMEZ y JONATHAN CARRERO ARANDA

// El problema se ha resuelto usando  la clase SerpientesEscaleras,  
// con un nuevo método que devuelve el numero minimo de tiradas  (previamente calculado en el constructor de la clase).


#include <iostream>
#include <string>
#include "TreeMap_RB.h"
#include "manchasNegras.h"
#include <vector>
using namespace std;


char ** leerMatriz(size_t F, size_t C){
	char **matriz;
	char e;
	
	// creamos matriz	
	matriz = new char*[F];
	for (size_t i = 0; i < F; i++)
		matriz[i] = new char[C];


	for (size_t i = 0; i < F; i++)
	{
		for (size_t j = 0; j < C; j++)
		{
			cin.get(e);
			matriz[i][j] = e;
		}
		
	}
	return matriz;
}

void mostrarMatriz(char **matriz, int F, int C){
	cout << endl;
	for (size_t i = 0; i < F; i++)
	{
		for (size_t j = 0; j < C; j++)
		{
			cout << matriz[i][j] << " ";
		}
		cout << endl;
	}
}

// resuelve un caso de prueva
bool resuelveCaso(){

	size_t F,C;
	char ** matriz;

	cin >> F;
	cin >> C;
	
	
	if (!cin){
		return false;

		//// Elimino cada vector de la matriz
		//for (int i = 0; i < F; i++) {
		//	delete[] matriz[i];
		//}
		//// Elimino el vector principal
		//delete[] matriz;

	}
	
	// leemos matriz
	matriz = leerMatriz(F,C);

	mostrarMatriz(matriz,F,C);
	

	//manchasNegras ManchasNegras(matriz, F, C);

	//
	//// mostrar solucion
	//cout << ManchasNegras.mancha_mas_grande() << endl;

	return true;
}

int main(){

	// casos de prueba ilimitados
	while (resuelveCaso());

	return 0;
}