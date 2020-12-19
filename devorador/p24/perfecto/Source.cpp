// Grupo 21, CRISTHIAN RODRIGUEZ GOMEZ y JONATHAN CARRERO ARANDA
//
// El coste del programa viene dado por la función sort(), la cual tiene una complejidad de O(n*logn).
#include<iostream>
#include <stdio.h>
#include<algorithm>
#include<vector>
#include "PriorityQueue.h"

using namespace std;

typedef struct {
	int inicio;
	int fin;

} tFecha;

bool operator < (tFecha a, tFecha b) {
	return a.inicio < b.inicio;
}

int solucion(vector<tFecha> & pareja_horas) {

	int j = 1;	// siguiente

	int min_num_salas_ocupadas = 1;
	PriorityQueue<int, less<int>> salas_ocupadas;

	// ordenamos fecha inicio mayor								
	sort(pareja_horas.begin(), pareja_horas.end(), less<tFecha>());	// O(n*logn), donde n es el número de conferencias

	salas_ocupadas.push(pareja_horas[0].fin);

	while (j < pareja_horas.size()) {

		if (pareja_horas[j].inicio >= salas_ocupadas.top()) {
			salas_ocupadas.pop();
			salas_ocupadas.push(pareja_horas[j].fin);

		}
		else {
			salas_ocupadas.push(pareja_horas[j].fin);
			min_num_salas_ocupadas++;
		}
		j++;
	}

	return min_num_salas_ocupadas;
}
bool resuelveCaso() {

	int  N;									   	 // numero de conferencias
	cin >> N;

	if (N == 0) {
		return false;
	}
	vector<tFecha> vectorFechas(N);				 // vector de fechas (inicio, fin)

	tFecha fecha;								 // leemos fechas

	for (int i = 0; i < N; i++)
	{
		cin >> fecha.inicio;
		cin >> fecha.fin;
		vectorFechas[i] = fecha;
	}

	cout << solucion(vectorFechas) << endl;

	return true;
}

int main() {
	while (resuelveCaso());
	return 0;
}