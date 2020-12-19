// Grupo 21, CRISTHIAN RODRIGUEZ GOMEZ y JONATHAN CARRERO ARANDA

/*
	PRACTICA 31: Mejor no llevar muchas monedas

/*				PROBLEMA DEL CAMBIO: CALCULO DE LA SOLUCION OPTIMA

				intput: conjunto M de tipos de monedas (cantidad ilimitada), cantidad C a pagar
				output: numero minimo de monedas para pagar la cantidad C considerando los tipos de monedas del 1 al n.

				//	Coste: O(nC) tanto en tiempo como en espacio adicional.
				
				DEFINICION RECURSIVA:

				monedas(i,j) = { min (monedas(i-1, j), monedas(i,j-mi) + 1)	

				NOTA:
				Se cumple el principio de optimalidad de Bellman según el cual para conseguir
				una solución óptima basta considerar subsoluciones óptimas.


*/
#include <iomanip>
#include <iostream>
#include <limits>
#include <algorithm> // min
#include "Matriz.h"
#include <vector>
using namespace std;



double devolver_cambio2(vector<int> const& M, int C) {

	size_t n = M.size() - 1;
	//Matriz<double> monedas(n + 1, C + 1, numeric_limits< double> :: infinity());
	vector<double> monedas(C + 1, numeric_limits< double> ::infinity());
	monedas[0] = 0;

	//rellenar la matriz
	for (size_t i = 1; i <= n; ++i)
		for (size_t j = M[i]; j <= C; ++j)
			monedas[j] = min(monedas[j], monedas[j - M[i]] + 1);


	return monedas[C];

}
// monedas[n][C] != infinito
vector<int> calcular_monedas1(vector<int> const& M, int C,
	Matriz<double> const& monedas) {
	size_t n = M.size() - 1;
	vector<int> cuantas(n + 1, 0);
	int i = n; int j = C;
	while (j > 0) { // no se ha pagado todo
		if (M[i] <= j && monedas[i][j] != monedas[i--1][j]) {
			// tomamos una moneda de tipo i
			++cuantas[i];
			j = j - M[i];
		}
		else // no tomamos más monedas de tipo i
			--i;
	}
	return cuantas;
}
/*
¿Podemos optimizar en espacio y seguir calculando la solución óptima?
La última fila contiene la información sobre el número de monedas mínimo
para cada cantidad, con el sistema monetario completo.

Si monedas(n, j) = monedas(n, j ? mi ) + 1

para algún j y algún i, sabemos que podemos coger una moneda de tipo i para
conseguir una solución óptima para pagar j.
Además, como el número de monedas de cada tipo es ilimitado, el sistema
monetario no cambia y se puede iterar el proceso para j ? mi haciendo
comparaciones de nuevo en la última fila, es decir, el vector.
Para implementar este proceso, al principio j vale C e i vale n; la cantidad j
decrece tal y como se van cogiendo monedas y, cuando la ecuación anterior
no es cierta y por tanto no se puede coger ninguna moneda más de tipo i, se
decrementa i pasando a considerar el tipo de moneda anterior i ? 1.

*/
// monedas[C] != infinito
vector<int> calcular_monedas2(vector<int> const& M, int C,
	vector<double> const& monedas) {
	size_t n = M.size() - 1;
	vector<int> cuantas(n + 1, 0);
	int i = n; int j = C;
	while (j > 0) { // no se ha pagado todo
		if (M[i] <= j && monedas[j] == monedas[j -- M[i]] + 1) {
			// tomamos una moneda de tipo i
			++cuantas[i];
			j = j - M[i];
		}
		else // no tomamos más monedas de tipo i
			--i;
	}
	return cuantas;
}
bool resuelveCaso() {
	// -------------------------------------IntPut-------------------------------------
	int n;
	cin >> n;	// numero de tipos diferentes de monedas

	// lectura de n valores de las monedas
	vector<int> M(n + 1);
	for (int i = 1; i < n; i++)
		cin >> M[i];

	// lectura de las cantidades de cada tipo
	vector<int> C(n + 1);
	for (int i = 1; i < n; i++)
		cin >> M[i];

	//lectura del  precio del coche
	int precio;
	cin >> precio;
	
	// no hay mas casos de prueba
	if (!cin) {
		return false;
	}

	// -------------------------------------OutPut-------------------------------------
	bool es_posible = true;			// Indica si es posible pagar el precio del coche
	vector<int> tipo_Monedas(n + 1,0);	// numero de monedas de cada tipo a utilizar

	if (es_posible)
		cout << "SI";
	for (int tipo : tipo_Monedas)
		cout << tipo << "M";
	
		return true;
}

int main() {

	while (resuelveCaso());

	return 0;
}

