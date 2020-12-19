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

//void ObtenerSecuencia(Matriz<int>  B,vector<char> X,  int i, int j) {
//	if (i == 0 || j == 0) {
//		return;
//	}
//	if (B[i][j] == 1) {
//		ObtenerSecuencia(B, X,  i - 1, j - 1);
//		cout << X[i];
//	}
//	else if (B[i][j] == 2) {
//		ObtenerSecuencia(B, X,  i - 1, j );
//	}
//	else {
//		ObtenerSecuencia(B, X,  i , j - 1);
//	}
//}

string subsecuencia(string const& X,string const& Y) {
	int m = X.size();
	int n = Y.size();

	Matriz<string> C(m,n);

	//inicializacion
	//for (size_t j = 1; j < n; j++)
	//{
	//	C[0][j] = "";
	//}
	//for (size_t i = 1; i < m; i++)
	//{
	//	C[i][0] = "";
	//}


	for (size_t i = 1; i < m; i++)
	{
		
		for (size_t j = 1;j  < n; j++)
		{
			//si los dos ultimos caracteres coinciden
			if (X[i] == Y[j]) {
				C[i][j] = C[i - 1][j - 1] + X[i];
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

	string X;
	string Y;

	cin >> X;
	if (!cin) return false;

	cin >> Y;

	//vector<char>X(cad1.size());
	//vector<char>Y(cad2.size());

	// convertimos a vector de caracteres
	//
	X = " " + X;
	Y = " " + Y;
	string B = subsecuencia(X, Y);

	cout << B << endl;
	return true;
}
int main() {
	while (resuelveCaso());
	return 0;
}