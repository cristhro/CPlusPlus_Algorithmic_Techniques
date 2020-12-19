// Grupo 21, CRISTHIAN RODRIGUEZ GOMEZ y JONATHAN CARRERO ARANDA
//
// problema 35: maraton de cine
//
// pelis(i) = maximo tiempo que puede ver las peliculas disponibles son del 1 al i
//
// pelis(i) = max(pelis(i), pelis(i-1)) 
//
//
#include<iostream>
#include <stdio.h>
#include<algorithm>
#include<vector>
#include "Matriz.h"
using namespace std;

typedef struct {
	int inicio;
	int fin;
	int duracion;
} tHora;

bool operator < (tHora a, tHora b) {
	return a.inicio < b.inicio;
}

int solucion(vector<tHora> & Horas, int N) {

	int num_peliculas_proyectadas = 1;
	Matriz<int> pelis(N+1, N+1, 0);

	//inicializacion
	for (size_t i = 1; i <= N; i++)
	{
		pelis[i][i] = Horas[i].duracion;

	}
	for (size_t i = 1; i <= N; i++)
	{
		for (size_t j = 1 ; j <= N -(N-i); j++)
		{
			if (Horas[i].inicio >= Horas[j].fin) 
			{
				pelis[i][j] =  max(Horas[j].duracion, pelis[i][j-1]);
			}
			else 
			{
				pelis[i][j] += pelis[i][j - 1];
				if (i == j) 
				{
					pelis[i][j] = max(pelis[i][j] , pelis[i - 1][j - 1]);
			    }
			}
		}

	}

	 
		return	pelis[N][N];
}
bool resuelveCaso() {

	int  N;	// numero de conferencias
	cin >> N;

	if (N == 0) {
		return false;
	}
	vector<tHora> horario_peliculas(N + 1);	// vector de fechas (inicio, fin)
	int hh, mm, duracion;
	char c;

	for (int i = 1; i <= N; i++)
	{
		cin >> hh >> c >> mm >> duracion;
		horario_peliculas[i].inicio = hh * 60 + mm;
		horario_peliculas[i].fin = hh * 60 + mm + duracion + 10;	// 10 para comprar las palomitas
		horario_peliculas[i].duracion = duracion;
	}

	cout << solucion(horario_peliculas, N) << endl;

	return true;
}

int main() {

	while (resuelveCaso());

	return 0;
}
