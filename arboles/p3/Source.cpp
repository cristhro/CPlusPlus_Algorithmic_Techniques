/*  
*	------------------------------------------------------------
*	TAIS21 - CRISTHIAN RODRIGUEZ G�MEZ y JONATHAN CARRERO ARANDA
*	------------------------------------------------------------
*	PR�CTICA 3: RANGO DE CLAVES EN UN �RBOL BINARIO DE B�SQUEDA
*	------------------------------------------------------------
*
*	Dado un �rbol dinario de b�squeda y dos claves k1 y k2, el problema consiste en producir una lista
*	ordenada con las claves comprendidas en el intervalo [k1, k2].
*/

#include <math.h>
#include <algorithm>
#include "TreeMapRango.h"
#include "BinTree.h"
#include "TreeMap_AVL.h"

using namespace std;

TreeMapRango<int, int> leeArbol(int n);
void resuelveCaso(int);
void muestra_Lista(vector<int> lista);

/*
*	Funci�n que va construyendo, a trav�s de insert, el ABB seg�n los valores que hayamos 
*	introducido por pantalla. Tambi�n, internamente, ejecuta el m�todo de reequilibrar si fuera necesario. 
*	Su complejidad depende del par�metro (n) el cual nos dice cu�ntos elementos tendr� nuestro �rbol.
*
*	Complejidad: O(log n)
*/
TreeMapRango<int, int> leeArbol(int n){

	TreeMapRango<int, int> a;
	int clave;
	int i = 1;

	 cin >> clave;
	 a.insert(clave, 0);

	 while (i < n){
		 cin >> clave;
		 a.insert(clave, 0);
		 i++;
	 }
	return a;
}

/*
*	Funci�n que recibe el tama�o (n) que tendr� el vector (lista). Lo que hace es leer (n)
*	elementos del ABB (arbol), leer el rango (k1, k2) de los valores buscados y buscar los elementos
*	comprendidos en el intervalo [k1, k2]. Su complejidad depende del tama�o de entrada (n).
*
*	Complejidad: O(n)
*/
void resuelveCaso(int n ){	

	TreeMapRango<int, int> arbol;
	vector<int> lista;

	// Leer (arbol).
	arbol = leeArbol(n);

	// Leer k1, k2.
	int k1, k2;
	cin >> k1 >> k2;

	// Calcular rango.
	lista = arbol.rango(k1, k2);
	
	// Mostrar resultado.
	muestra_Lista(lista);
}

int main(){
	
	int n;
	cin >> n;

	while (n != 0){
		resuelveCaso(n);
		cin >> n;
	}
	return 0;
}

/*
*	Funci�n que recibe como par�metro un vector (lista) y muestra por pantalla
*	todos los elementos contenidos en �l. Su complejidad depende del tama�o
*	que tenga el vector (lista).
*
*	Complejidad: O(n)
*/
void  muestra_Lista(vector<int> lista){

	int N = lista.size();

	for (int i = 0; i < N; i++){	
		cout << lista.at(i); 
		if(i < N-1)cout << " ";
	}
	cout << endl;
}
