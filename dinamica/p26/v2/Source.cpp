// Grupo 21, CRISTHIAN RODRIGUEZ GOMEZ y JONATHAN CARRERO ARANDA

/*
PRACTICA 27: Insercion de parentesis
para resolver el porblema hemos rellenado la tabla por diagonales, empezando por la diagonal principal para el caso baasico.
como tenemos tres funciones mutuamente recursivas, necesitamos tres matrices booleanas A, B, C que se rellenan simultaneamente.
Vamos a completar el algoritmo de manera que tambien se devuelva una tabla de decisiones para cada predicado pa, pb, pc que nos permitiran
calcular la forma adecuada de insertar los parentesis.
Cada decision consistira en la posicion ken la que se divide, y los caracteres que hay que obtener en cada parte.

O(n^3) debido a los tres bucles anidados, donde n es el numero de caracteres
*/
#include <iomanip>
#include <iostream>
#include <limits>
#include <algorithm> // min
#include "Matriz.h"
#include <vector>
#include <string>

using namespace std;

typedef struct {

	int longitud;
	int coste;

}tDescripcion;


bool varilla(int &n_total, int &n_min, int &min_coste, vector<tDescripcion> const& varillas, int L) {

	bool posible = false;
	int n = varillas.size() - 1;

	Matriz<int> minCoste( n+1 , L+1, 0);
	Matriz<int> longitud ( n+1, L+1, 0);

	// rellenar la matriz
	for (int i = 1; i <= n; ++i) 
	{
		longitud[i][0] = 0;

		for (int j = 1; j <= L; ++j) 
		{
			if (varillas[i].longitud > j)				// no se puede considerar longitud[i] para pagar L
				
				longitud[i][j] += longitud[i - 1][j];

			else{
			
				longitud[i][j] += min(longitud[i - 1][j], longitud[i][j - varillas[i].longitud] + 1);
			}
		
		}
	}	cout << endl << longitud[1][L] << endl;

	return posible;
}


bool resuelveCaso() {

	int n;	// numero de varillas
	int l;	// Longitud varilla

	cin >> n >> l;

	if (!cin) {
		return false;
	}

	// leer varillas (longitud , coste)
	vector<tDescripcion> varillas(n + 1);
	
	for (int i = 1; i < n; i++)
	{
		cin >> varillas[i].longitud;
		cin >> varillas[i].coste;
	}

	int n_total;	 // numero total de maneras de obtener tal varilla
	int n_min;		 // numero minimo de varillas a utilizar
	int min_coste;	 // minimo coste necesario

	bool posible = varilla(n_total, n_min, min_coste, varillas, l);

	//// mostrar solucion
	//if (solucion) cout << "SI" << endl;
	//else cout << "NO" << endl;

	return true;
}

int main() {

	while (resuelveCaso());

	return 0;
}
