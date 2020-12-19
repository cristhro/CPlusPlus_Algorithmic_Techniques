// Grupo 21, CRISTHIAN RODRIGUEZ GOMEZ y JONATHAN CARRERO ARANDA

/*
	PRACTICA 34: Las Vacas pensantes

	O(n^2)
*/
#include <iomanip>
#include <iostream>
#include <limits>
#include <algorithm> // min
#include "Matriz.h"
#include <vector>
#include <string>

using namespace std;



long long vacas(vector<int> const& C) {

	long long cantidad_maxima = 0;
	int n = C.size() -1;
	Matriz<long long > vacas(n+1, n+1 );

	//inicializacion
	for (int i =1; i <= n - 1; i++)
	{
		vacas[i][i + 1] = max(C[i], C[i + 1]);
	}
	//recorre diagonales
	for (int d = 2; d <= n - 1; d+=2)
	{
		//recorre elementos dentro de la diagonal
		for (int i = 1; i <= n - d; i++)
		{
			int j = i + d;
			long long como_i;
			long long como_j;

			if (C[j] > C[i + 1]) {
				como_i = vacas[i + 1][j - 1];
			}
			else {
				como_i = vacas[i + 2][j];
			}
			
			if (C[i] > C[j-1])
			{
				como_j = vacas[i + 1][j - 1];
			}
			else {
				como_j = vacas[i ][j- 2];
			}
			vacas[i][j] = max(C[i] + como_i, C[j] + como_j);
		}
	}
	// fin recorrido diagonales
	cantidad_maxima = vacas[1][n];
	return cantidad_maxima;
}
bool resuelveCaso() {


	int N ; // numero de cubos

	cin >> N;

	if (N == 0) {
		return false;
	}
	vector<int>cantidad_comida(N + 1);

	for (size_t i = 1; i <= N; i++)
	{
		cin >> cantidad_comida[i];
	}
	long long solucion = vacas(cantidad_comida);

	// mostrar solucion
	cout << solucion << endl;
	return true;
}

int main() {

	while (resuelveCaso());

	return 0;
}