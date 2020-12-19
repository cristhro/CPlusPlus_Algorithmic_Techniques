// Grupo 21, CRISTHIAN RODRIGUEZ GOMEZ y JONATHAN CARRERO ARANDA
// Practica 36: Subsecuencia mas larga
/*
	C(i,j) = longitud de la subsecuencia mas larga de Xi y Yj

	Caso basico:
	C(i,j) = 0					 si i = 0 v j = 0

	Caso recursivo:
	C(i,j) = C(i-1,j-1)			 si i,j>0 y Xi == Yj
	= max( C(i-1,j)		 si i,j>0 y Xi != Yj
	C(i,j-1)
	)
	COSTE : (n*m)
*/
#include <iostream>
#include <vector>
#include <string>
#include "Matriz.h"

using namespace std;

void ObtenerSecuencia(Matriz<int> const&  B, vector<char>  const& X, int i, int j) {
	if (i == 0 || j == 0) {
		return;
	}
	if (B[i][j] == 1) {
		ObtenerSecuencia(B, X, i - 1, j - 1);
		cout << X[i];
	}
	else if (B[i][j] == 2) {
		ObtenerSecuencia(B, X, i - 1, j);
	}
	else {
		ObtenerSecuencia(B, X, i, j - 1);
	}
}

Matriz<int> subsecuencia(vector<char> const& X, vector<char> const& Y) {
	int m = X.size();
	int n = Y.size();

	Matriz<int> C(m, n);
	Matriz<int> B(m, n);

	//inicializacion
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

		for (size_t j = 1; j < n; j++)
		{
			//si los dos ultimos caracteres coinciden
			if (X[i] == Y[j]) {
				C[i][j] = C[i - 1][j - 1] + 1;
				B[i][j] = 1;
			}

			else if (C[i - 1][j] >= C[i][j - 1]){
				C[i][j] = C[i - 1][j];
				B[i][j] = 2;
			}
			else {
				C[i][j] = C[i][j - 1];
				B[i][j] = 3;
			}
		}
	}
	return B;
}
bool resuelveCaso() {

	string cad1;
	string cad2;

	cin >> cad1;
	if (!cin) return false;

	cin >> cad2;

	vector<char>X(cad1.size() + 1);
	vector<char>Y(cad2.size() + 1);

	// convertimos a vector de caracteres

	for (int i = 0; i < cad1.size(); i++){
		X[i + 1] = cad1.at(i);
	}
	for (int j = 0; j < cad2.size(); j++){
		Y[j + 1] = cad2.at(j);
	}

	Matriz<int> B = subsecuencia(X, Y);

	ObtenerSecuencia(B, X, X.size()-1, Y.size()-1);
	cout << endl;
	return true;
}
int main() {
	while (resuelveCaso());
	return 0;
}