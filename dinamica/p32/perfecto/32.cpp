// Grupo 21, CRISTHIAN RODRIGUEZ GOMEZ y JONATHAN CARRERO ARANDA

/*
PRACTICA 32: El carpintero  Ebanisto

DEF:
	corte(i,j) = minimo esfuerzo a realizar con los corte 1 a i  para cortar el tablon de longitud j
REC:
	corte(i,j) =	min(	2(V[j]-V[i]) + corte(i,k) + corte(k,j))
				i+1<=k<=j-1		i+1 <= k <= j-1
R0:
		corte(i,j+1) = 0

coste : O(n^2) donde n es el numero de cortes que se deben realizar
*/
#include <string>
#include <iostream>
#include <climits>
#include <algorithm> // min
#include "Matriz.h"
#include <vector>

using namespace std;


int carpintero(vector<int> P) {
	int n = P.size();
	Matriz<int> carpintero(n, n,0);

	// recorre diagonales
	for (size_t d = 2; d < n; d++)
	{
		for (size_t i = 0; i < n-d; i++)
		{
			int j = i + d;
			carpintero[i][j] = INT_MAX;
			for (size_t k = i+1; k <= j-1; k++)
			{
				int temp = 2 * (P[j] - P[i]) + carpintero[i][k] + carpintero[k][j];
				if (temp < carpintero[i][j]) {
					carpintero[i][j] = temp;
				}
			}
		}

	}

	return carpintero[0][n-1];
}

bool resuelveCaso() {

	int L;	int N;

	cin >> L;	// longitud del tablon que queremos cortar
	cin >> N;	// numero de cortes que se deben realizar

				// no hay mas casos de prueba
	if (L == 0 && N == 0) {
		return false;
	}

	vector<int> puntos(N + 2);
	for (size_t i = 1; i <=N; i++)
	{
		cin >> puntos[i];
	}

	puntos[N + 1] = L;
	int sol = carpintero(puntos);

	cout << sol << endl;
	return true;
}

int main() {

	while (resuelveCaso());

	return 0;
}

