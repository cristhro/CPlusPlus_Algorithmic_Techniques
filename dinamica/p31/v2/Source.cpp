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


bool monedas(vector<int> V, vector<int> C, int precio, vector<int> numMonedas){
	int esPosible = false;

	Matriz<int> monedas(V.size(), precio, 0);
	
	int n = V.size();

	for (int i = 1; i < n; i++){
		for (int j = 1; j < precio; j++){
			if (V[i]  > j){
				monedas[i][j] = monedas[i - 1][j];
			
			}else{

				
				for (int k = 1; k < C[i]; k++){
				
					int min = monedas[i - 1][j];
					if (min > monedas[i][j])
						monedas[i][j] = min;
				}
			}
		}
	}

	return esPosible;
}

bool resuelveCaso() {
	// -------------------------------------IntPut-------------------------------------
	int n;
	cin >> n;	// numero de tipos diferentes de monedas

	// lectura de n valores de las monedas
	vector<int> V(n + 1);
	for (int i = 1; i <= n; i++)
		cin >> V[i];

	// lectura de las cantidades de cada tipo
	vector<int> C(n + 1);
	for (int i = 1; i <= n; i++)
		cin >> C[i];

	//lectura del  precio del coche
	int precio;
	cin >> precio;
	
	// no hay mas casos de prueba
	if (!cin) {
		return false;
	}

	// -------------------------------------OutPut-------------------------------------
	vector<int> tipo_Monedas(n + 1,0);	// numero de monedas de cada tipo a utilizar

	bool es_posible = monedas(V, C, precio, tipo_Monedas);		// Indica si es posible pagar el precio del coche

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

