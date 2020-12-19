// Grupo 21, CRISTHIAN RODRIGUEZ GOMEZ y JONATHAN CARRERO ARANDA

/*
	PRACTICA 34: Las Vacas pensantes
	
	DEF:
		vacas(i,j) = Cantidad maxima que come listilla con los cubos desde Pi hasta pj
					 cuando le toca empezar a comer
	
	CASO REC:
		vacas(i,j) = max( pi + (vacas(i+1,j-1)	si pj > pi+1)	
							 + (vacas(i+2,j)	si pi+1 > pj)
						  ,
						  pj + (vacas(i+1,j-1)	si pi > pj-1)
							 + (vacas(i,j-2)	si pi-1 > pi)
						)
	CASO BASICO:
		vacas(i,i+1) = max(pi,pi+1) 
	
	coste en tiempo: O(n^2)  
	coste en espacio: 0(n^2)
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
	for (int d = n - 1; d > 2; d-=2) // 7 3 -> 6
	{
		//recorre elementos dentro de la diagonal
		for (int i = 1; i <= n - d; i++)// 1 <- 4
		{
			int j = i + d;
			long long como_i;
			long long como_j;
			//listilla
			if (C[j] > C[i + 1]) {
				como_i = vacas[i + 1][j - 1];
			}
			else {
				como_i = vacas[i + 2][j];
			}
			// deboradora
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

bool impar(int i){
	return (i % 2 == 1);
}
int vacas_par_impar(vector<int> const& P){
	int n = P.size();
	
	// calcula las sumas de posiciones pares e impares
	int impares = 0;
	int pares = 0;
	
	for (size_t i = 0; i < n; i++)
	{
		if (impar(i)){
			impares += P[i];
		}
		else{
			pares += P[i];
		}
	}

	int izq = 0; int der = n-1; int cuanto = 0;
	while (izq < der)
	{
		//come listilla, hay un numero par de cubos 
		if (impares >= pares){ //come impar
			
			if (impar(izq)){
				cuanto += P[izq];
				impares -= P[izq];
				izq += 1;
			}
			else{
				cuanto += P[der];
				impares -= P[der];
				der -= 1;
			}
		}
		else{//come impar
			if (impar(izq)){
				cuanto += P[der];
				pares -= P[der];
				der -= 1;
			}
			else{
				cuanto += P[izq];
				pares -= P[izq];
				izq += 1;
			}
		}
	
	
	
		//come devoradora
		if (P[izq] >= P[der]){ // come por la izquierda
			if (impar(izq)){
				impares -= P[izq];
			}
			else
			{
				pares -= P[izq];
			}
			izq += 1;
		}
		else{// come por la derecha
			if (impar(der)){
			
				impares -= P[der];
			}
			else
			{
				pares -= P[der];
			}
			der -= 1;
		}
	}
	cout << cuanto << endl;
	return cuanto;
}
bool resuelveCaso() {


	int N ; // numero de cubos

	cin >> N;

	if (N == 0) {
		return false;
	}
	vector<int>cantidad_comida(N);

	for (size_t i = 0; i < N; i++)
	{
		cin >> cantidad_comida[i];
	}
	//long long solucion = vacas(cantidad_comida);
	int solucion = vacas_par_impar(cantidad_comida);
	// mostrar solucion
	cout << solucion << endl;
	return true;
}

int main() {

	while (resuelveCaso());

	return 0;
}