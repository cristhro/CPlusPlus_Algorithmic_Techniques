// Grupo 21, CRISTHIAN RODRIGUEZ GOMEZ y JONATHAN CARRERO ARANDA

/*
	PRACTICA 28: Insercion de parentesis 2
	
	para resolver el porblema hemos rellenado la tabla por diagonales, empezando por la diagonal principal para el caso baasico.

	O(n^3) debido a los tres bucles anidados, donde n es el numero de caracteres
*/
#include <iomanip>
#include <iostream>
#include <limits>
#include <algorithm> // min
#include "Matriz.h"
#include <vector>
#include <string>

using namespace std;

typedef struct {
	int posicion;
	char resultado1, resultado2;

}tDecision;



void asignar(tDecision &d, int p, char r1, char r2) 
{
	d.posicion = p;
	d.resultado1 = r1; 
	d.resultado2 = r2;
}

int parentesis(vector<char> const& X) {

	int numero = 0;
	int n = X.size();
	
	Matriz<int>A(n , n);
	Matriz<int>B(n , n);
	Matriz<int>C(n , n);

	for (int i = 1; i < n; i++)
	{
		if (X[i] == 'a') A[i][i] = 1 ; else  A[i][i] = 0;
		if (X[i] == 'b') B[i][i] = 1 ; else  B[i][i] = 0;
		if (X[i] == 'c') C[i][i] = 1 ; else  C[i][i] = 0;
	}
	//recorre diagonales
	for (int d = 1; d < n ; d++)
	{
		//recorre elementos dentro de la diagonal
		for (int i = 1; i < n-d; i++)
		{
			int j = i + d;
			
			//calcula la disyuncion para A
			A[i][j] = 0; B[i][j] = 0; C[i][j] = 0;
			
			for (int k = i ; k < j ; k++)
			{
				A[i][j] += A[i][k] * C[k + 1][j] + B[i][k] * C[k + 1][j] + C[i][k] * A[k + 1][j];
				B[i][j] += A[i][k] * A[k + 1][j] + A[i][k] * B[k + 1][j] + B[i][k] * B[k + 1][j];
				C[i][j] += B[i][k] * A[k + 1][j] + C[i][k] * B[k + 1][j] + C[i][k] * C[k + 1][j];
			}
		}
	}
	// fin recorrido diagonales
	numero = A[1][n - 1];

	return numero;
}
bool resuelveCaso() {

	
	string caracteres;
	
	cin >> caracteres;

	if (!cin) {
		return false;
	}
	// convertimos Striing a Vector de Char
	vector<char> X(caracteres.size() +1);
	int i = 1;
	for (char k : caracteres) {
		X[i] = k;
		i++;
	}

	int solucion =  parentesis(X);

	// mostrar solucion
	cout << solucion  << endl;
	

	return true;
}

int main() {

	while (resuelveCaso());

	return 0;
}



/*

Esquema de programaci�n din�mica

Identificaci�n
--------------
� Especificaci�n de la funci�n que representa el problema a	resolver.
� Determinaci�n de las ecuaciones recurrentes para calcular dicha funci�n.
� Comprobaci�n del alto coste de c�lculo de dicha funci�n debidoa la repetici�n de subproblemas a resolver.

Construcci�n
-------------
� Sustituci�n de la funci�n por una tabla.
� Inicializaci�n de la tabla seg�n los casos base de la definici�nrecursiva de la funci�n.
� Sustituci�n, en las ecuaciones, de las llamadas recursivas porconsultas a la tabla.
� Planificaci�n del orden de llenado de la tabla, de forma que serespeten las necesidades de cada entrada de la tabla.
� Posible optimizaci�n en espacio.

*/