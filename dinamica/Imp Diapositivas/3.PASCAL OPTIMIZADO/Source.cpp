/*
	OPTIMIZACION EN ESPACIO 

	PROBLEMA : Numeros Combinatorios (resuelto mediante el TRIANGULO DE  PASCAL ) 

				intput: non negative integers n and r, where r ? n.
				output: the binomial coefficient (n , r)

				Coste: ?(nr) en tiempo y en espacio adicional

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





#include <iostream>
#include "Matriz.h"
#include <vector>
using namespace std;

/*
	Dejando aparte los casos b�sicos, para calcular cada entrada (i, j) en la tabla
	se necesitan las entradas (i ? 1, j ? 1) e (i ? 1, j) de la fila anterior, por lo que
	el espacio adicional se puede reducir a un vector que se rellena de derecha a izquierda.
*/


int pascal2 (int n, int r) {
	//Matriz<int> C(n + 1, r + 1, 0);
	vector<int> C(r + 1, 0);
	C[0] = 1;
	for (int i = 1; i <= n; i++) {
		for (int j = r; j >= 1; j--) {
			C[j] = C[j - 1] + C[j];
		}
	}

	return C[r];
}


bool resuelveCaso() {

	int n , r ;

	cin >> n;
	cin >> r;

	if (!cin) {
		return false;
	}

	//Matriz<int> C(n + 1, k + 1, -1);

	cout << pascal2(n, r) << "\n";

	return true;
}

int main() {

	while (resuelveCaso());

	return 0;
}