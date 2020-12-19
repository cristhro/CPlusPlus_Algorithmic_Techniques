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

bool varilla(vector<tDescripcion> const &V, int L) {

	bool posible = false;
	size_t n = V.size() - 1;
	vector<bool> varillas(n + 1, false);

	for (int i = 1; i <= n; i++){
		for (int j = V[i].longitud; j <= L; j++){
			if (varillas[j-1] == true)
				varillas[j] = true;
			else
				varillas[j] = false;
			
			if (varillas[j - V[i].longitud] == true)
				varillas[j] = true;
			else
				varillas[j] = false;
		}
	}


	
	return posible;
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
	for (int i = 1; i < N; i++)
	{
		cin >> varillas[i].longitud;
		cin >> varillas[i].coste; 
	}

	int n_total;	 // numero total de maneras de obtener tal varilla
	int n_min;		 // numero minimo de varillas a utilizar
	int min_coste;	 // minimo coste necesario

	bool posible = varilla(varillas, L);

	if (posible){

		cout << "SI" << " " << n_total << " " << n_min << " " << min_coste << endl;
	}

	cout << "NO" << endl;

	return true;
}

int main() {

	while (resuelveCaso());

	return 0;
}
