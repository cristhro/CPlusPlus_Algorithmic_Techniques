/*
PRACTICA 39: Las Vacas pensantes

O(n^2)
*/
#include <iomanip>
#include <iostream>
#include <limits>
#include <algorithm> // min
#include <vector>
#include <string>

using namespace std;

typedef struct {
	vector<double> sol;
	int k;
	double beneficio;
	double beneficio_opt;
	vector<double> ocupada;

}tNodo;

bool operator< (tNodo a, tNodo b){
	return a.beneficio_opt < b.beneficio_opt;
}

void canciones_rp(vector<double> const& D, vector<double> const& P, double const& T, vector<double> &sol_mejor, double &beneficio_mejor)
{
	tNodo X, Y;
	//PriorityQueue<tNodo> C;

	Y.k = 0;
	for (size_t i = 0; i < D.size(); i++)
	Y.ocupada[i] = 0;
	Y.beneficio = 0;

	
}

bool resuelveCaso() {


	int N; // numero de canciones
	int D; // duracion de cada una da las caras
	
	cin >> N;
	
	if (N == 0)
		return false;
	
	cin >> D;
	
	//numero de cintas con su duracion y su puntuacion	
	vector<double> duracion(N);
	vector<double> puntuacion(N);
	vector<double> ocupada(N);

	for (size_t i = 0; i < N; i++)
	{
		cin >> duracion[i];
		cin >> puntuacion[i];

	}
	int T = 2 * D;
	vector<double> sol_mejor(N);
	double beneficio_mejor;
	canciones_rp(duracion, puntuacion, T, sol_mejor, beneficio_mejor);

	return true;
}

int main() {

	while (resuelveCaso());

	return 0;
}


int calculo_pesimista(vector<double> D, vector<double> P, int T, int k, tNodo nodo, vector<double> O){

	int n = D.size();
	vector<double> ocupada_aux(2);

	for (int i = 0; i < n; i++){
		ocupada_aux[i] = O[i];
	}

	int pesimista = nodo.beneficio;

	int j = k + 1;
	while (j <= n && (ocupada_aux[1] <= T / 2 || ocupada_aux[2] <= T / 2)){
		if ((ocupada_aux[1] + D[j]) <= T / 2){
			ocupada_aux[1] = ocupada_aux[1] + D[j];
			pesimista = pesimista + P[j];
		}
		else {
			if ((ocupada_aux[2] + D[j]) <= T / 2){
				ocupada_aux[1] = ocupada_aux[1] + D[j];
				pesimista = pesimista + P[j];
			}
		}
		j = j + 1;
	}
	return pesimista;
}

int calculo_optimista(vector<double> D, vector<double> P, int T, int k, tNodo nodo, vector<double> O){

	int hueco = T - (O[1] + O[2]);
	int optimista = nodo.beneficio;
	int n = D.size();

	int j = k + 1;

	while (j <= n && D[j] <= hueco){
		// Podemos grabar la canción entera
		hueco = hueco - D[j];
		optimista = optimista + P[j];
		j++;
	}

	if (j <= n){	// Quedan canciones por probar
		// Cortamos canción 
		optimista = optimista + (hueco / D[j]) * P[j];
	}
	return optimista;
}
	