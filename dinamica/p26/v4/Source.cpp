// Grupo 21, CRISTHIAN RODRIGUEZ GOMEZ y JONATHAN CARRERO ARANDA

/*
PRACTICA 26: Varillas


*/
#include <iomanip>
#include <iostream>
#include <limits>
#include <algorithm>
#include "Matriz.h"
#include <vector>
#include <string>

using namespace std;

typedef struct {

	int longitud;
	int coste;

}tDescripcion;

bool varilla(vector<tDescripcion> const &V, int L, long long &num_maneras, long long &min_varillas, long long &min_coste) {

	int n = V.size() - 1;

	Matriz<long long> maneras(n + 1, L + 1, 0);
	Matriz<long long> varillas(n + 1, L + 1, INT_MAX);
	Matriz<long long> coste(n + 1, L + 1, INT_MAX);
	Matriz<bool> posible(n + 1, L + 1, false);

	coste[0][0] = 0;
	varillas[0][0] = 0;

	//Calculo si es posible formar la varilla deseada L
	for (int i = 1; i <= n; i++) {
		posible[i][0] = true;
		for (int j = V[i].longitud; j <= L; j++) {
			if (V[i].longitud > j) //no se puede considerar Li para 
				posible[i][j] = posible[i - 1][j];
			
			else
				posible[i][j] = posible[i - 1][j] || posible[i - 1][j - V[i].longitud];
		}
	}
	
	bool es_posible = posible[n][L];

	if (es_posible)
	{
		maneras[0][0] = 1;
		// Calculo del numero total de maneras 
		for (int i = 1; i <= n; i++) {
			maneras[i][0] = 1;
			for (int j = V[i].longitud; j <= L; j++) {
				if (V[i].longitud > j) {//no se puede considerar Li para 
					maneras[i][j] = maneras[i - 1][j];
				}
				else
					maneras[i][j] = maneras[i - 1][j] + maneras[i - 1][j - V[i].longitud];

			}
		}
		//num_maneras = maneras[n][L];

		// Calculo del numero minimo de varillas
		for (int i = 1; i <= n; i++) {
			varillas[i][0] = 0;
			for (int j = V[i].longitud; j <= L; j++) {
				if (V[i].longitud > j) {//no se puede considerar Li para 
					varillas[i][j] = varillas[i - 1][j];
				}
				else
					varillas[i][j] = min(varillas[i - 1][j], varillas[i - 1][j - V[i].longitud] + 1);

			}
		}
		min_varillas = varillas[n][L];

		//Calculo del minimo coste
		for (int i = 1; i <= n; i++) {
			coste[i][0] = 0;
			for (int j = V[i].longitud; j <= L; j++) {
				if (V[i].longitud > j) {//no se puede considerar Li para 
					coste[i][j] = coste[i - 1][j];
				}
				else
					coste[i][j] = min(coste[i - 1][j], coste[i - 1][j - V[i].longitud] + V[i].coste);

			}
		}
		min_coste = coste[n][L];
	}

	return es_posible;
}


bool resuelveCaso() {

	int N;	// Numero de varillas
	int L;	// Longitud varilla

	cin >> N >> L;

	if (!cin) {
		return false;
	}

	vector<tDescripcion> varillas(N + 1);

	// Rellenar el vector varillas
	for (int i = 1; i <= N; i++)
	{
		cin >> varillas[i].longitud;
		cin >> varillas[i].coste;
	}

	long long num_maneras	= 0;	 // numero total de maneras de obtener tal varilla
	long long min_varillas = 0;	 // numero minimo de varillas a utilizar
	long long min_coste	= 0;	 // minimo coste necesario

	bool posible = varilla(varillas, L, num_maneras, min_varillas, min_coste);

	if (posible) 
		cout << "SI" << " " << num_maneras << " " << min_varillas << " " << min_coste << endl;
	else
		cout << "NO" << endl;

	return true;
}

int main() {

	while (resuelveCaso());

	return 0;
}