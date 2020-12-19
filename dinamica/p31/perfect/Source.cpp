// Grupo 21, CRISTHIAN RODRIGUEZ GOMEZ y JONATHAN CARRERO ARANDA

/*
	PRACTICA 31 B: Mejor no llevar muchas monedas

	DEF:
		monedas(i,j) = numero minimo de monedas del tipo 1 al tipo i  para pagar la cantidad j
	RE:
		monedas(i,j) = ( monedas(i-1,j)								si V[i] > j  ,
							min	( monedas(i-1, j - k*V[i]) + k )	si V[i] <= j	
						 0<=K<=C[i]
						)
	R0:
		monedas(i,0) = 0;
		monedas(0,j) = INFINITO;
*/
#include <iomanip>
#include <iostream>
#include <climits>
#include <algorithm> // min
#include "Matriz.h"
#include <vector>

using namespace std;


int monedas(vector<int> const& V, vector<int> const& C, int precio, vector<int> &tipo_Monedas){
	int n = V.size()-1;
	
	Matriz<int> monedas(n + 1, precio + 1, INT_MAX);
	Matriz<int> tipo(n + 1, precio + 1, 0);
	

	monedas[0][0] = 0;
	for (int i = 1; i <= n; i++) {
		monedas[i][0] = 0;
		for (int j = 1; j <= precio; j++) {
			if (V[i] > j) {
				monedas[i][j] = monedas[i - 1][j];
			}
			else{
				for (int k = 0; k <= C[i] && k*V[i] <= j; k++) {
					size_t temp = monedas[i - 1][j- k*V[i]] + k;
					if (temp < monedas[i][j]) {
						monedas[i][j] = temp;
						tipo[i][j] = k;
					}
				}
			}
		}
	}

	

		int j = precio;
		for (size_t i = n; i >= 1; i--)
		{
			int k = tipo[i][j];
			tipo_Monedas[i] = k;
			j = j - k*V[i];

		}

		return monedas[n][precio];
}

bool resuelveCaso() {

	int n;
	cin >> n;	// numero de tipos diferentes de monedas

	// no hay mas casos de prueba
	if (!cin) {
		return false;
	}
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
	

	vector<int> tipo_Monedas(n + 1,0);								// numero de monedas de cada tipo a utilizar
	int sol = monedas(V, C, precio, tipo_Monedas);		// Indica si es posible pagar el precio del coche

	if (sol != INT_MAX){
		cout << "SI ";
		for (size_t i = 1; i < tipo_Monedas.size(); i++)
		{
			cout << tipo_Monedas[i] << " " ; 
			if (i == tipo_Monedas.size() - 1) cout << endl;
		}
	}
	else cout << "NO" << endl;
		return true;
}

int main() {

	while (resuelveCaso());

	return 0;
}

