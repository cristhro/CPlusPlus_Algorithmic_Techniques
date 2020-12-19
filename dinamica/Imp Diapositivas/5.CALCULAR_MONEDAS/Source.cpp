/*

				PROBLEMA DEL CAMBIO: CALCULO DE LA SOLUCION OPTIMA

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


/* 
	Funcion Auxiliar para imprimir la matriz M
*/
//void mostrar_matriz(const Matriz<double> &M) {
//	//cout << setw(5) << " ";
//	for (int k = 0; k < M.numcols(); k++) cout << setw(5) << k  ;
//	cout << endl;
//	for (size_t i = 0; i < M.numfils(); i++)
//	{
//		cout << i << " ";
//		for (size_t j = 0; j < M.numcols(); j++)
//		{
//			cout << setw(4) <<  M[i][j] << " ";
//		}
//		cout << endl;
//	}
//	for (int k = 0; k < M.numcols(); k++) cout << setw(5) << "--";
//	cout << endl;
//}

/*
	Coste: ?(nC) en tiempo y ?(C) en espacio adicional
*/

double devolver_cambio2(vector<int> const& M, int C) {

	size_t n = M.size() - 1;
	//Matriz<double> monedas(n + 1, C + 1, numeric_limits< double> :: infinity());
	vector<double> monedas( C + 1, numeric_limits< double> ::infinity());
	monedas[0] = 0;

	//rellenar la matriz
	for (size_t i = 1; i <= n; ++i)
	{
		for (size_t j = M[i]; j <= C; ++j)
		{
				monedas[j] = min (monedas[j] , monedas[j - M[i]] + 1);
		}

	}

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

	
	int C, n ;
	
	cin >> C;
	cin >> n;
	
	vector<int> M(n + 1);
	
	for (int i = 1; i < n; i++)
	{
		cin >> M[i];
	}

	if (!cin) {
		return false;
	}

	//Matriz<int> C(n + 1, k + 1, -1);

	cout << devolver_cambio2(M, C) << "\n";

	return true;
}

int main() {

	while (resuelveCaso());

	return 0;
}



/*

Esquema de programación dinámica

Identificación
--------------
• Especificación de la función que representa el problema a	resolver.
• Determinación de las ecuaciones recurrentes para calcular dicha función.
• Comprobación del alto coste de cálculo de dicha función debidoa la repetición de subproblemas a resolver.

Construcción
-------------
• Sustitución de la función por una tabla.
• Inicialización de la tabla según los casos base de la definiciónrecursiva de la función.
• Sustitución, en las ecuaciones, de las llamadas recursivas porconsultas a la tabla.
• Planificación del orden de llenado de la tabla, de forma que serespeten las necesidades de cada entrada de la tabla.
• Posible optimización en espacio.

*/