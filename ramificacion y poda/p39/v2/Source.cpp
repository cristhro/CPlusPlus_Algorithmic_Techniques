/*
PRACTICA 39: Las Vacas pensantes

O(n^2)
*/
#include <iomanip>
#include <iostream>
#include <limits>
#include <algorithm> // min
#include <vector>
#include <string>
#include "PriorityQueue.h"

using namespace std;

typedef struct {
	vector<double> sol;
	int k;
	double beneficio;
	double beneficio_opt;
	vector<double>ocupada;

}tNodo;

bool operator< (tNodo a, tNodo b){
	return a.beneficio_opt < b.beneficio_opt;
}

void canciones_rp(vector<double> const& D, vector<double> const& P, double const& T, vector<double> &sol_mejor, double &beneficio_mejor)
{
	tNodo X, Y;
	PriorityQueue<tNodo> C;

	Y.k = 0;
	for (size_t i = 0; i < D.size(); i++)
	Y.ocupada[i] = 0;
	Y.beneficio = 0;

	
}

bool resuelveCaso() {


	int N; // numero de canciones
	int D; // duracion de cada una da las caras
	
	cin >> N;
	
	if (N == 0)
		return false;
	
	cin >> D;
	
	//numero de cintas con su duracion y su puntuacion	
	vector<double> duracion(N);
	vector<double> puntuacion(N);

	for (size_t i = 0; i < N; i++)
	{
		cin >> duracion[i];
		cin >> puntuacion[i];

	}
	int T = 2 * D;
	vector<double> sol_mejor(N);
	double beneficio_mejor;
	canciones_rp(duracion, puntuacion, T, sol_mejor, beneficio_mejor);

	return true;
}

int main() {

	while (resuelveCaso());

	return 0;
}
int main(){

}