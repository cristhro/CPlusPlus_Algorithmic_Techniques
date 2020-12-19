// Grupo 21, CRISTHIAN RODRIGUEZ GOMEZ y JONATHAN CARRERO ARANDA

/*
	PRACTICA 31: Mejor no llevar muchas monedas

*/
#include <iomanip>
#include <iostream>
#include <limits>
#include <algorithm> // min
#include "Matriz.h"
#include <vector>

using namespace std;

bool monedas(vector<int> V, vector<int> C, int precio, vector<int> numMonedas){
	
	bool esPosible = false;
	int n = V.size();

	Matriz<int> monedas(V.size(), precio, 0);

	for (int i = 1; i < n; i++){
		for (int j = 1; j < precio; j++){
			for (int k = 1; k * V[i] < precio; k++){	// Bucle que para cuando nos pasamos del precio o cuando las monedas de tipo i se han acabado
				if (V[i] > precio){	// No puede pagarse con la monedas de tipo i, pues supera el valor de precio
					monedas[i - 1][j];
				}
				else{
					monedas[i][j] = (monedas[i - 1][j - k*V[i]] + k);
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

	bool es_posible = monedas(V, C, precio + 1, tipo_Monedas);		// Indica si es posible pagar el precio del coche

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

