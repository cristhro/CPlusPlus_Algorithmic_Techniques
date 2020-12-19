// Grupo 21, CRISTHIAN RODRIGUEZ GOMEZ y JONATHAN CARRERO ARANDA

/*
	PRACTICA 38: Los funcionarios del Ministerio
	
	Coste en tiempo: 
	Coste en espacio: O(n^2) debido al uso de la matriz T[1...n, 1...n]
	
	
	NOTA: T(i,j) = representa el tiempo que el funcionario i tarda en realizar el
			 trabajo j.
*/

#include <iostream>
#include <climits>
#include <algorithm>
#include "Matriz.h"
#include "PriorityQueue.h"
#include <vector>
using namespace std;


typedef struct {
	vector<int> sol;
	int k;
	int tiempo;
	int tiempo_opt;
	vector<bool> asignado;
} tNodo;

bool operator<(tNodo a, tNodo b){
	return a.tiempo_opt < b.tiempo_opt;
}

void pre_calculo_estimaciones(Matriz<int> const& T, vector<int> &opt, vector<int> &pes){

	int n = T.numcols() - 1 ;
	vector<int> rapido(n+1);
	vector<int> lento(n+1);

	for (int i = 1; i <= n; i++){
		rapido[i] = T[i][1];
		lento[i]  = T[i][1];
		for (int j = 2; j <= n; j++){
			rapido[i] = min(rapido[i], T[i][j]);
			lento[i]  = max(lento[i], T[i][j]);
		}
	}

	opt[n] = 0;
	pes[n] = 0;
	for (int i = n-1 ; i >= 0; i--){
		opt[i] = opt[i + 1] + rapido[i + 1];
		pes[i] = pes[i + 1] + lento[i + 1];
	}
}


void funcionarios_min_rp(Matriz<int> const& T, vector<int> &sol_mejor, int &tiempo_mejor){

	int n = T.numcols()-1;
	tNodo X, Y;
	PriorityQueue<tNodo> C;
	vector<int> opt(n + 1);		// Vector optimista
	vector<int> pes(n + 1);		// Vector pesimista

	//calculo de las estimaciones
	pre_calculo_estimaciones(T, opt, pes);

	Y.k = 0;
	Y.asignado = vector<bool>(n + 1, false);
	Y.tiempo = 0;
	Y.tiempo_opt = opt[0];
	C.push(Y);
	tiempo_mejor = pes[0];

	while (!C.empty() && C.top().tiempo_opt <= tiempo_mejor){
		Y = C.top();
		C.pop();
		X.k = Y.k + 1;
		X.asignado = Y.asignado;
		for (int t = 1; t <= n; t++){
			if (!X.asignado[t]){
				X.asignado[t] = true;
				X.tiempo = Y.tiempo + T[X.k][t];
				X.tiempo_opt = X.tiempo + opt[X.k];
				if (X.tiempo_opt <= tiempo_mejor){
					if (X.k == n){
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
}


bool resuelveCaso() {

	int N;
	cin >> N;

	if (N == 0){
		return false;
	}
	
	Matriz<int> T(N+1, N+1, 0);	// Matriz T[1...n, 1...n]
	vector<int> sol_mejor(N+1);

	int tiempo_mejor = INT_MAX;
	
	for (int i = 1; i <= N; i++){
		for (int j = 1; j <= N; j++){
			cin >> T[i][j];
		}
	}

	
	funcionarios_min_rp(T,  sol_mejor, tiempo_mejor);

	cout << tiempo_mejor << endl;
	return true;
}


int main() {

	while (resuelveCaso());

	return 0;
}

