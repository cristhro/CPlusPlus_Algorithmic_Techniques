// Grupo 21, CRISTHIAN RODRIGUEZ GOMEZ y JONATHAN CARRERO ARANDA

/*
	PRACTICA 31: Mejor no llevar muchas monedas
	
	DEF:
		corte(i,j) = minimo esfuerzo a realizar desde i+1 hasta j-1
	REC:
		corte(i,j) =	min			(	2(V[j]-V[i]) + corte(i,k) + corte(k,j))
		  i<j-1		i+1 <= k <= j-1			
	R0:
		corte(i,j+1) = 0
*/
#include <string>
#include <iostream>
#include <limits>
#include <algorithm> // min
#include "Matriz.h"
#include <vector>

using namespace std;


int carpintero(vector<int> P, int L){
	int n = P.size() -1;
	Matriz<int> carpintero(L,L);
	int minEsfuerzo;
	
	// inicializacion
	for (size_t i = 0; i <= n; i++)
	{
		for (size_t j = 1; j < L+1; j++)
		{
			carpintero[i][j] = 0;
		}

	}
	int min = INT_MAX;
	for (size_t i = 0; i <= n; i++)
	{
		for (size_t j = 1; j < L; j++)
		{
			
			int corte = 0;
			for (size_t  k = i+1; k < n - j; k++)
			{
				corte +=carpintero[k][j] + carpintero[i][k] + (2*(P[n-i]-P[n-j])) ;
				if (corte < min){
					carpintero[i][j] = corte;
				}
			}

		}

	}


	return 1;
}

bool resuelveCaso() {

	int L;	int N;

	cin >> L;	// longitud del tablon que queremos cortar
	cin >> N;	// numero de cortes que se deben realizar

	// no hay mas casos de prueba
	if (L == 0 && N == 0) {
		return false;
	}
	
	vector<int> puntos(N);
	for (size_t i = 0; i < N; i++)
	{
		cin >> puntos[i];
	}
		
	int sol = carpintero(puntos,L);
	
	cout << sol << endl;
	return true;
}

int main() {

	while (resuelveCaso());

	return 0;
}

