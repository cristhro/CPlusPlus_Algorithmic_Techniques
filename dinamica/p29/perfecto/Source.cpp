// Grupo 21, CRISTHIAN RODRIGUEZ GOMEZ y JONATHAN CARRERO ARANDA

/*
	PRACTICA 29: de aventura por el Amazonas
	Para la resolución del problema, hemos usado una matriz de coste rellenada por diagonales.
	En la recursión, para ir desde un punto i hasta un punto j (si no estamos en el caso básico), 
	elegiremos el mínimo coste de alquiler, el cual es quedarnos con el menor entre lo que nos cuesta ir
	desde i hasta j o del coste que supone ir desde i hasta el punto intermedio más lo que supone ir desde el punto
	intermedio hasta j.

	O(n^3) en tiempo debido al recorrido de las diagonales, elementos de cada diagonal y su cálculo mínimo correspondiente (los tres bucles for).
	O(1) en espacio.
	
	
	Llamada recursiva:
	
	Tendremos que: coste(i , j) = coste mínimo para ir desde i hasta j, por lo tanto la recurrencia queda definida de la siguiente forma:
	coste(i, j) = min{alquiler[i, j], min{coste(i, k) + coste (k, j)}}  si i < j - 1
	
	Caso básico:
	
	coste(i, i + 1) = aquiler[i, i + 1]
*/
#include <iomanip>
#include <iostream>
#include <limits>
#include <algorithm>
#include "Matriz.h"
#include <vector>
#include <string>

using namespace std;

Matriz<int> canoas(Matriz<int> &alquiler){

	int n = alquiler.numcols();
	Matriz<int>coste(n, n);
	
	//inicializar la matriz de coste a la matriz de alquiler
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			coste[i][j] = alquiler[i][j];
		}
	}

	for (int d = 1; d < n - 1; d++){	// Recorrer diagonales
		for (int i = 1; i < n - d; i++){	// Recorrer elementos de la diagonal
			
			int j = i + d;

			for (int k = i ; k < j ; k++){	// Cálculo del mínimo
				coste[i][j] = min(coste[i][j], coste[i][k] + coste[k][j]);
			}
		}
	}
	return coste;
}

bool resuelveCaso() {

	int n;
	cin >> n;

	if (!cin) {
		return false;
	}
	Matriz<int> alquiler(n + 1, n + 1, 0);

	// Declaramos la matriz de alquiler (NOTA: falta rellenarla)
	for (size_t i = 1; i < n; i++)
	{
		for (size_t j = i + 1; j <= n; j++)
		{
			cin >> alquiler[i][j];
		}
	}
	

	Matriz<int> coste = canoas(alquiler);

	// imprimir el resultado
	for (size_t i = 1; i <= n; i++)
	{
		for (size_t j = i + 1; j <= n; j++)
		{
			cout <<  coste[i][j];
			if (j < n)
				cout << " ";
		}
		if (i < n)
		cout << endl;
	}

	return true;
}

int main() {

	while (resuelveCaso());

	return 0;
}


/*

Esquema de programación dinámica:

Identificación
--------------
• Especificación de la función que representa el problema a	resolver.
• Determinación de las ecuaciones recurrentes para calcular dicha función.
• Comprobación del alto coste de cálculo de dicha función debidoa la repetición de subproblemas a resolver.

Construcción
-------------
• Sustitución de la función por una tabla.
• Inicialización de la tabla según los casos base de la definiciónrecursiva de la función.
• Sustitución, en las ecuaciones, de las llamadas recursivas porconsultas a la tabla.
• Planificación del orden de llenado de la tabla, de forma que serespeten las necesidades de cada entrada de la tabla.
• Posible optimización en espacio.

*/