// Grupo 21, CRISTHIAN RODRIGUEZ GOMEZ y JONATHAN CARRERO ARANDA
//
// El coste del programa viene dado por la función sort(), la cual tiene un coste de O(n*logn)
#include<iostream>
#include <stdio.h>
#include<algorithm>
#include<vector>
#include "PriorityQueue.h"
using namespace std;

typedef struct {
	int inicio;
	int fin;

} tHora;

bool operator < (tHora a, tHora b) {
	return a.inicio < b.inicio;
}

int solucion(vector<tHora> & horario_peliculas) {

	int j = 1;	// siguiente
	int num_peliculas_proyectadas = 1;
	int termina;

	sort(horario_peliculas.begin(), horario_peliculas.end(), less<tHora>());	// O(n*logn), donde n es el número de películas

	termina = horario_peliculas[0].fin;

	while (j < horario_peliculas.size()) {

		if (horario_peliculas[j].inicio >= termina) {	// si el inicio de la siguiente es mayor que el comienzo
			termina = horario_peliculas[j].fin;
			num_peliculas_proyectadas++;
		}
		else if (termina > horario_peliculas[j].fin) {
			termina = horario_peliculas[j].fin;
		}
		j++;
	}

	return num_peliculas_proyectadas;
}
bool resuelveCaso() {

	int  N;	// numero de conferencias
	cin >> N;

	if (N == 0) {
		return false;
	}
	vector<tHora> horario_peliculas(N);	// vector de fechas (inicio, fin)
	int hh, mm, duracion;
	char c;

	for (int i = 0; i < N; i++)
	{
		cin >> hh >> c >> mm >> duracion;
		horario_peliculas[i].inicio = hh * 60 + mm;
		horario_peliculas[i].fin = hh * 60 + mm + duracion + 10;	// 10 para comprar las palomitas
	}

	cout << solucion(horario_peliculas) << endl;

	return true;
}

int main() {

	while (resuelveCaso());

	return 0;
}