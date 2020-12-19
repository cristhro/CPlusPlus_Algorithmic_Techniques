// Grupo 21, CRISTHIAN RODRIGUEZ GOMEZ y JONATHAN CARRERO ARANDA
// Practica 36: Subsecuencia mas larga

#include <iostream>
#include <vector>
#include <string>
#include "Matriz.h"

using namespace std;

int subsecuencia(vector<char> X, vector<char> Y) {
	int m = X.size();
	int n = Y.size();

	Matriz<int> C(m,n);
	Matriz<int> B(m, n); // tabla que usamos para resolver el subproblema 

	for (size_t j = 1; j < n; j++)
	{
		C[0][j] = 0;
	}
	for (size_t i = 1; i < m; i++)
	{
		C[i][0] = 0;
	}


	for (size_t i = 1; i < m; i++)
	{
		
		for (size_t j = 1;j  < n; j++)
		{
			if (X[i] == Y[j]) {
				C[i][j] = C[i - 1][j - 1] + 1;
			}
			else if(C[i-1][j] >= C[i][j-1]){
				C[i][j] = C[i-1][j];
			}
			else {
				C[i][j] = C[i][j-1];
			}
		}
	}
	return C[m-1][n-1];
}
bool resuelveCaso() {

	string cad1;
	string cad2;

	cin >> cad1;
	if (!cin) return false;

	cin >> cad2;

	vector<char>X(cad1.size()+1);
	vector<char>Y(cad2.size()+1);

	// convertimos a vector de caracteres
	for (size_t i = 0; i < cad1.size(); i++)
	{
		X[i + 1] = cad1.at(i);
	}
	for (size_t i = 0; i < cad2.size(); i++)
	{
		Y[i + 1] = cad2.at(i);
	}
	int sol = subsecuencia(X, Y);
	cout << sol << endl;
	return true;
}
int main() {
	while (resuelveCaso());
	return 0;
}