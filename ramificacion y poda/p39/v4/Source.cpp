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
#include "PriorityQueue.h"

using namespace std;

typedef struct {
	vector<double> sol;
	int k;
	double beneficio;
	double beneficio_opt;
	vector<double>ocupada;

}tNodo;

bool operator< (tNodo a, tNodo b){
	return a.beneficio_opt < b.beneficio_opt;
}
int calculo_pesimista(vector<double> D, vector<double> P, int T, int k, double B, vector<double> O){

	int n = D.size();
	vector<double> ocupada_aux(2);

	for (int i = 0; i < 2; i++){
		ocupada_aux[i] = O[i];
	}

	int pesimista = B;

	int j = k + 1;
	while (j < n && (ocupada_aux[1] <= T / 2 || ocupada_aux[1] <= T / 2)){
		if ((ocupada_aux[0] + D[j]) <= T / 2){
			ocupada_aux[0] = ocupada_aux[0] + D[j];
			pesimista = pesimista + P[j];
		}
		else {
			if ((ocupada_aux[1] + D[j]) <= T / 2){
				ocupada_aux[1] = ocupada_aux[1] + D[j];
				pesimista = pesimista + P[j];
			}
		}
		j = j + 1;
	}
	return pesimista;
}

int calculo_optimista(vector<double> D, vector<double> P, int T, int k,double B, vector<double> O){

	int hueco = T - (O[0] + O[1]);
	int optimista = B;
	int n = D.size();

	int j = k + 1;

	while (j < n && D[j] <= hueco){
		// Podemos grabar la canción entera
		hueco = hueco - D[j];
		optimista = optimista + P[j];
		j++;
	}

	if (j < n){	// Quedan canciones por probar
		// Cortamos canción 
		optimista = optimista + (hueco / D[j]) * P[j];
	}
	return optimista;
}

void canciones_rp(vector<double> const& D, vector<double> const& P, double const& T, vector<double> &sol_mejor, double &beneficio_mejor)
{
	int n = D.size();
	tNodo X, Y;
	PriorityQueue<tNodo> C;
	double pes;

	Y.k = 0;
	for (size_t i = 0; i < 2; i++){
		Y.ocupada.push_back(0);
		X.ocupada.push_back(0);
	}
	for (size_t i = 0; i < n; i++)
	{	
		X.sol.push_back(0);
		Y.sol.push_back(0);
	}
	Y.beneficio = 0;
	
	Y.beneficio_opt = calculo_optimista(D, P, T, Y.k, Y.beneficio, Y.ocupada);
	C.push(Y);
	beneficio_mejor = calculo_pesimista(D, P, T, Y.k, Y.beneficio, Y.ocupada);

	while (!C.empty() &&C.top().beneficio_opt >= beneficio_mejor)
	{
		Y = C.top();
		C.pop();

		X.k = Y.k + 1; X.sol = Y.sol;
		
		// grabar la cancion X.K en la cara 1
		if (Y.ocupada[0] + D[X.k] <= T/2)
		{	
			//beneficio-opoo(X) = beneficio-opt(Y)>= beneficio-mejor
			X.sol[X.k] = 0;
			X.ocupada[0] = Y.ocupada[0] + D[X.k];
			X.ocupada[1] = Y.ocupada[1];
			X.beneficio = Y.beneficio + P[X.k];
			X.beneficio_opt = Y.beneficio_opt;

			if (X.k == n-1)
			{
				sol_mejor = X.sol; beneficio_mejor = X.beneficio;
			}
			else{
				C.push(X);
			// la estimacion pesimista tambien coincide y no puede mejorar beneficio mejor	
			}
				
		}
		if (Y.ocupada[0] != Y.ocupada[1] ){
			// grabar la cancion X.k en la cara 2
			// la estimacion optimista coincide con la de Y, y no es menor que el beneficio-mejor
			if (Y.ocupada[1] + D[X.k] <= T / 2){
				

				X.sol[X.k] = 1;
				X.ocupada[0] = Y.ocupada[0] + D[X.k];
				X.ocupada[1] = Y.ocupada[1];
				X.beneficio = Y.beneficio + P[X.k];
				X.beneficio_opt = Y.beneficio_opt;

				if (X.k == n-1)
				{
					sol_mejor = X.sol; beneficio_mejor = X.beneficio;
				}
				else{
					C.push(X);
					// la estimacion pesimista no coincide con la de y	
					 pes = calculo_pesimista(D, P, T, X.k, X.beneficio, X.ocupada);
					 beneficio_mejor = max(beneficio_mejor, pes);
				}
			}
		}
		//no grabar la cancion k (simpre es factible)
		X.ocupada = Y.ocupada;
		X.beneficio = Y.beneficio;
		X.beneficio_opt = calculo_optimista(D, P, T, X.k, X.beneficio, X.ocupada);
		
		if (X.beneficio_opt >= beneficio_mejor)
		{
			X.sol[X.k] = 0;
			if (X.k == n-1)
			{
				sol_mejor = X.sol;
				beneficio_mejor = X.beneficio;
			}
			else
			{
				C.push(X);
				pes = calculo_pesimista(D, P, T, X.k, X.beneficio, X.ocupada);
				beneficio_mejor = max(beneficio_mejor, pes);
			}
		}
	}
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
