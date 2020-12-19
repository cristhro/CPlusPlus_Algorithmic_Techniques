/*
	
	DIAPOSITIVA: NUMERO COMBINATORIO
	
	* Añadir a la función un parámetro que es una tabla con los valores ya calculados.
	* La tabla está inicializada con valores diferentes, por ejemplo ?1.		Inicialización con tiempo en ?(1). ¿Es posible?
*/







#include <iostream>
#include "Matriz.h"

using namespace std;

int num_combi(int i, int j, Matriz<int> &C) {

	if (j == 0 || j == i)
		return 1;
	else if (C[i][j] != -1)
		return C[i][j];
	else {
		int nc = num_combi(i - 1, j - 1, C) + num_combi(i - 1 , j, C);
		
		return C[i][j] = nc;
	}
}


bool resuelveCaso() {

	int n , k ;

	cin >> n;
	cin >> k;

	if (!cin) {
		return false;
	}

	Matriz<int> C(n + 1, k + 1, -1);

	cout << num_combi(n, k, C) << "\n";

	return true;
}

int main() {

	while (resuelveCaso());

	return 0;
}