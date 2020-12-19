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
	vector<float> sol;
	float k;
	float tiempo;
	float tiempo_opt;
	vector<bool> asignado;
} tNodo;

bool operator<(tNodo a, tNodo b){
	return a.tiempo_opt < b.tiempo_opt;
}
void pre_calculo_estimaciones(Matriz<float> T, vector<float> &opt, vector<float> &pes){

	int n = T.numcols();
	vector<float> rapido(n);
	vector<float> lento(n);

	for (int i = 1; i < n; i++){
		rapido[i] = T[i][1];
		lento[i] = T[i][1];
		for (int j = 2; j < n; j++){
			rapido[i] = min(rapido[i], T[i][j]);
			lento[i] = max(rapido[i], T[i][j]);
		}
	}

	opt[n-1] = 0;
	pes[n-1] = 0;

	for (int i = n - 2; i > 0; i--){
		opt[i] = opt[i + 1] + rapido[i + 1];
		pes[i] = pes[i + 1] + lento[i + 1];
	}
}


void funcionarios_min_rp(Matriz<float> T, vector<float> sol_mejor, float &tiempo_mejor){

	int n = T.numcols();
	tNodo X, Y;
	PriorityQueue<tNodo> C;
	vector<float> opt(n);	// Vector optimista
	vector<float> pes(n);	// Vector pesimista
	pre_calculo_estimaciones(T,opt,pes);

	Y.k = 0;
	
	for (int i = 1; i <= n; i++){
		Y.asignado.push_back(false);
		Y.sol.push_back(0);
	}

	Y.tiempo = 0;
	Y.tiempo_opt = opt[0];
	C.push(Y);
	tiempo_mejor = pes[0];
/**/
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
				X.tiempo = Y.tiempo + T[X.k][t];
				X.tiempo_opt = X.tiempo + opt[X.k];

				if (X.tiempo_opt <= tiempo_mejor){
					if (X.k = n){
						sol_mejor = X.sol;
						tiempo_mejor = X.tiempo;
					}else {
						C.push(X);
						tiempo_mejor = min(tiempo_mejor, X.tiempo + pes[X.k]);
					}
				}
				X.asignado[t] = false;
			}
		}
	}
	cout << tiempo_mejor;
}


bool resuelveCaso() {

	int N;
	bool resuelve = true;
	cin >> N;

	if (N == 0){
		resuelve = false;
	}
	N += 1;
	Matriz<float> T(N, N, 0);	// Matriz T[1...n, 1...n]
	vector<float> sol_mejor(N);
	float tiempo_mejor;
	
	for (int i = 1; i < N; i++){
		for (int j = 1; j < N; j++){
			cin >> T[i][j];
		}
	}

	funcionarios_min_rp(T,  sol_mejor, tiempo_mejor);

	return resuelve;
}


int main() {

	while (resuelveCaso());

	return 0;
}

