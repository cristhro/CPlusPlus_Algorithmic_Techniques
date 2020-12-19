// Grupo 21, CRISTHIAN RODRIGUEZ GOMEZ y JONATHAN CARRERO ARANDA

/*
	PRACTICA 26: Varillas

	[CUESTIÓN 1]
	DEF:	posible(i,j) = booleano que indica si es posible alcanzar j eligiendo alguna de las i primeras varillas. 
	REC:	posible(i,j) = posible(i - 1,j)								si Li > j
						 = posible(i - 1,j)	v posible(i - 1,j - Li)		si Li <= j
	BASICO:	posible(0,j) = false
			posible(i,0) = true
	[CUESTIÓN 2]
	DEF:	maneras(i,j) = numero de maneras de alcanzar j con las i primeras varillas. 
	REC:	maneras(i,j) = maneras(i - 1,j)									si Li > j
						 = maneras(i - 1,j)	+ posible(i - 1,j - Li)			si Li <= j
	BASICO: maneras(0,j) = 0
			maneras(i,0) = 1
	[CUESTIÓN 3]
	DEF:    varillas(i,j) = numero minimo de varillas i-n que se necesitan para  alcanzar j . 
	REC:	varillas(i,j) = varillas(i - 1,j)										si Li > j
				          = min (varillas(i - 1,j), varillas(i - 1,j - Li) + 1)		si Li <= j
	BASICO: varillas(0,j) = 0
			varillas(i,0) = 0
	[CUESTIÓN 4]
	DEF:	coste(i,j) =  minimo coste que se necesita para  alcanzar j con las  varillas i primeras. 
	REC:	coste(i,j) = varillas(i - 1,j)									si Li > j
				       = min (varillas(i - 1,j), varillas(i - 1,j - Li) + 1)		si Li <= j
	BASICO: coste(0,j) = 0
			coste(i,0) = 0

	coste en tiempo: O(n*L) donde n es el numero de varillas y L la longitud de la varilla deseada
	coste en espacio: O(n*L) donde n es el numero de varillas y L la longitud de la varilla deseada

	coste en espacio: O(L) donde L es la longitud de la varilla deseada
*/
#include <iomanip>
#include <iostream>
#include <limits>
#include <algorithm>
#include "Matriz.h"
#include <vector>
#include <string>
#include <climits>
using namespace std;

typedef struct {

	int longitud;
	int coste;

}tDescripcion;

bool varilla(vector<tDescripcion> const &V, int L, int &num_maneras, int &min_varillas, int &min_coste) {

	int n = V.size() - 1;
	const int Max = 2000000000;
	vector<bool> posible(L + 1, false);
	vector<int>  maneras(L + 1, 0);
	vector<int>  varillas( L + 1, Max);
	vector<int>  coste(    L + 1, Max);

	coste[0] = 0;
	varillas[0] = 0;
	posible[0] = true;
	maneras[0] = 1;

	//Calculo si es posible formar la varilla deseada L
	for (int i = 1; i <= n; i++) {
		for (int j = V[i].longitud; j <= L; j++) {
				posible[j] = posible[j] || posible[j - V[i].longitud];
		}
	}
	
	bool es_posible = posible[L];

	if (es_posible)
	{
		// Calculo del numero total de maneras 
		for (int i = 1; i <= n; i++) {
			for (int j = V[i].longitud; j <= L; j++) {
			//	if (j ==  )
					maneras[j] = maneras[j] + maneras[j - V[i].longitud];
				

			}
		}
		num_maneras = maneras[L];

		// Calculo del numero minimo de varillas
		for (int i = 1; i <= n; i++) {
			for (int j = V[i].longitud; j <= L; j++) {
					varillas[j] = min(varillas[j], varillas[j - V[i].longitud] + 1);
			}
		}
		min_varillas = varillas[L];

		//Calculo del minimo coste
		for (int i = 1; i <= n; i++) {
			for (int j = V[i].longitud; j <= L; j++) {
					coste[j] = min(coste[j], coste[j - V[i].longitud] + V[i].coste);

			}
		}
		min_coste = coste[L];
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

	int num_maneras	= 0;	 // numero total de maneras de obtener tal varilla
	int min_varillas = 0;	 // numero minimo de varillas a utilizar
	int min_coste	= 0;	 // minimo coste necesario

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