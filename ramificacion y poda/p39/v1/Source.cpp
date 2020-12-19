
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

void canciones_rp()//vector<double> const& D, vector<double> const& P, double const& T, vector<double> &sol_mejor, double &beneficio_mejor)
{
	tNodo X, Y;
	PriorityQueue<tNodo> C;

}

bool resuelveCaso() {


	int N; // numero de cubos

	cin >> N;

	return true;
}

int main() {

	while (resuelveCaso());

	return 0;
}
int main(){

}