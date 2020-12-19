// Grupo 21, CRISTHIAN RODRIGUEZ GOMEZ y JONATHAN CARRERO ARANDA

/*
	PRACTICA 32: Los funcionarios del Ministerio
*/
#include <iomanip>
#include <iostream>
#include <limits>
#include <algorithm>
#include "Matriz.h"
#include "PriorityQueue.h"
#include <vector>
using namespace std;


typedef struct {
	vector<double> sol;
	double k;
	double tiempo;
	double tiempo_opt;
	vector<bool> asignado;
} tNodo;


void pre_calculo_estimaciones(Matriz<double> T, vector<double> opt, vector<double> pes){

	int n = T.numcols();
	vector<double> rapido(n);
	vector<double> lento(n);

	for (int i = 0; i < n; i++){
		rapido[i] = T[i][1];
		lento[i] = T[i][1];
		for (int j = 2; j < n; j++){
			rapido[i] = min(rapido[i], T[i][j]);
			lento[i] = max(rapido[i], T[i][j]);
		}
	}

	opt[n] = 0;
	pes[n] = 0;

	for (int i = n - 1; i < 0; i--){
		opt[i] = opt[i + 1] + rapido[i + 1];
		pes[i] = pes[i + 1] + lento[i + 1];
	}
}


void funcionarios_min_rp(Matriz<double> T, vector<double> opt, vector<double> pes, vector<double> sol_mejor, double &tiempo_mejor){

	int n = T.numcols;
	tNodo X, Y;
	PriorityQueue<tNodo> C;

	//opt = pre_calculo_estimaciones(T);
	//pes = pre_calculo_estimaciones(T);

	Y.k = 0;

	for (int i = 0; i < n; i++){
		Y.asignado[i] = false;
	}

	Y.tiempo = 0;
	Y.tiempo_opt = opt[0];
	C.push(X);
	tiempo_mejor = pes[0];

	while (!C.empty() && C.top().tiempo_opt <= tiempo_mejor){
		Y = C.top();
		C.pop();

		X.k = Y.k + 1;
		X.sol = Y.sol;
		X.asignado = Y.asignado;

		for (int t = 1; t < n; t++){
			if (!X.asignado[t]){
				X.sol[X.k] = t;
				X.asignado[t] = true;
				X.tiempo = Y.tiempo + T[X.k, t];
				X.tiempo_opt = X.tiempo + opt[X.k];

				if (X.tiempo_opt <= tiempo_mejor){
					if (X.k = n){
						sol_mejor = X.sol;
						tiempo_mejor = X.tiempo;
					}
					else {
						C.push(X);
						tiempo_mejor = min(tiempo_mejor, X.tiempo + pes[X.k]);
					}
				}
				X.asignado[t] = false;
			}
		}
	}
}


bool resuelveCaso() {

	int N;
	bool resuelve = true;
	cin >> N;

	if (N == 0){
		resuelve = false;
	}

	vector<double> opt(N);	// Vector optimista
	vector<double> pes(N);	// Vector pesimista
	Matriz<double> T(N, N, 0);	// Matriz T[1...n, 1...n]
	vector<double> sol_mejor(N);
	double tiempo_mejor;
	
	funcionarios_min_rp(T, opt, pes, sol_mejor, tiempo_mejor);

	return resuelve;
}


int main() {

	while (resuelveCaso());

	return 0;
}

