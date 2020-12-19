// Grupo 21, CRISTHIAN RODRIGUEZ GOMEZ y JONATHAN CARRERO ARANDA

/*
	PRACTICA 29: de aventura por el Amazonas
	Para la resoluci�n del problema, hemos usado una matriz de coste rellenada por diagonales.
	En la recursi�n, para ir desde un punto i hasta un punto j (si no estamos en el caso b�sico), 
	elegiremos el m�nimo coste de alquiler, el cual es quedarnos con el menor entre lo que nos cuesta ir
	desde i hasta j o del coste que supone ir desde i hasta el punto intermedio m�s lo que supone ir desde el punto
	intermedio hasta j.

	O(n^3) en tiempo debido al recorrido de las diagonales, elementos de cada diagonal y su c�lculo m�nimo correspondiente (los tres bucles for).
	O(1) en espacio.
*/
#include <iomanip>
#include <iostream>
#include <limits>
#include <algorithm>
#include "Matriz.h"
#include <vector>
#include <string>

using namespace std;

int canoas(Matriz<int> &alquiler){

	// NOTA: Falta poner el caso b�sico

	// NOTA: Falta inicializar la matriz de coste a la matriz de alquiler

	for (int d = 2; d < n - 1; d++){	// Recorrer diagonales
		for (int i = 1; i < n - d; i++){	// Recorrer elementos de la diagonal
			
			int j = i + d;

			for (int k = i + 1; k < j - 1){	// C�lculo del m�nimo
				coste[i][j] = min(coste[i][j], coste[i][k] + coste[k][j]);
			}
		}
	}
}

bool resuelveCaso() {

	int n;
	cin >> n;

	if (!cin) {
		return false;
	}

	// Declaramos la matriz de alquiler (NOTA: falta rellenarla)
	Matriz<int> alquiler(n - 1);

	int coste =  canoas(alquiler);

	// Falta imprimir el resultado

	return true;
}

int main() {

	while (resuelveCaso());

	return 0;
}


/*

Esquema de programaci�n din�mica:

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