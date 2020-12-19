/*

				PROBLEMA DEL CAMBIO: 

				intput: conjunto M de tipos de monedas (cantidad ilimitada), cantidad C a pagar
				output: numero minimo de monedas para pagar la cantidad C considerando los tipos de monedas del 1 al n.

				//	Coste: O(nC) tanto en tiempo como en espacio adicional.
				
				DEFINICION RECURSIVA:

				monedas(i,j) = { monedas( i-1, j)								SI mi > j
							   { min (monedas(i-1, j), monedas(i,j-mi) + 1)		SI mi <= j
				CASOS BASICOS:
								monedas(i,0) = 0		0 <= i <= n
								monedas(0,j) = +inf		1 <= j <= C
				NOTA:
				Se cumple el principio de optimalidad de Bellman seg�n el cual para conseguir
				una soluci�n �ptima basta considerar subsoluciones �ptimas.


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
void mostrar_matriz(const Matriz<double> &M) {
	//cout << setw(5) << " ";
	for (int k = 0; k < M.numcols(); k++) cout << setw(5) << k  ;
	cout << endl;
	for (size_t i = 0; i < M.numfils(); i++)
	{
		cout << i << " ";
		for (size_t j = 0; j < M.numcols(); j++)
		{
			cout << setw(4) <<  M[i][j] << " ";
		}
		cout << endl;
	}
	for (int k = 0; k < M.numcols(); k++) cout << setw(5) << "--";
	cout << endl;
}

double devolver_cambio(vector<int> const& M, int C) {

	size_t n = M.size() - 1;
	Matriz<double> monedas(n + 1, C + 1, numeric_limits< double> :: infinity());
	monedas[0][0] = 0;

	//mostrar_matriz(monedas);
	//rellenar la matriz
	for (size_t i = 1; i <= n; ++i)
	{
		monedas[i][0] = 0;
		for (size_t j = 1; j <= C; ++j)
		{
			if (M[i] > j)	// no se puede considerar M[i] para pagar j
			{
				monedas[i][j] = monedas[i - 1][j];
			}
			else
			{
				monedas[i][j] = min (monedas[i - 1][j] , monedas[i][j - M[i]] + 1);
			}
			mostrar_matriz(monedas);
		}

	}
	//mostrar_matriz(monedas);

	return monedas[n][C];

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

	cout << devolver_cambio(M, C) << "\n";

	return true;
}

int main() {

	while (resuelveCaso());

	return 0;
}



/*

Esquema de programaci�n din�mica

Identificaci�n
--------------
� Especificaci�n de la funci�n que representa el problema a	resolver.
� Determinaci�n de las ecuaciones recurrentes para calcular dicha funci�n.
� Comprobaci�n del alto coste de c�lculo de dicha funci�n debidoa la repetici�n de subproblemas a resolver.

Construcci�n
-------------
� Sustituci�n de la funci�n por una tabla.
� Inicializaci�n de la tabla seg�n los casos base de la definici�nrecursiva de la funci�n.
� Sustituci�n, en las ecuaciones, de las llamadas recursivas porconsultas a la tabla.
� Planificaci�n del orden de llenado de la tabla, de forma que serespeten las necesidades de cada entrada de la tabla.
� Posible optimizaci�n en espacio.

*/