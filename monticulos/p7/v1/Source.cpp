// Grupo 21, CRISTHIAN RODRIGUEZ GOMEZ y JONATHAN CARRERO ARANDA

/*
				PRACTICA 7
	
*/
#include <iostream>
#include "IndexPQ.h"
#include "PriorityQueue.h"

using namespace std;


// Lectura estandar de una cola con prioridad de n elementos
PriorityQueue<int> leer(int n){
	PriorityQueue<int> cola;
	int elem;
	for (size_t i = 0; i < n; i++)
	{
		cin >> elem;
		cola.push(elem);
	}
	return cola;
}
/*
	Funcio que calcula el minimo esfuerzo de una suma de n elementos

	Complejidad: O(n)
*/
int min_coste_suma(PriorityQueue<int> cola){

		
		int primer;
		int segundo;
		int suma = 0;
		int min_coste = 0;

	while (cola.size() >  1){

		cola.pop(primer);
		cola.pop(segundo);

        suma = primer + segundo;
		min_coste += suma;
		cola.push(suma);

		
	}
	return min_coste;
}
////Resuelve un cado de prueba, leyendo de la entrada la
////configuracion, y escribiendo la respuesta
void resuelveCaso(int num_Elem){
	
	PriorityQueue<int> cola;
	int coste_minimo;

	// LEER
	cola = leer(num_Elem);

	// CALCULAR COSTE MINIMO
	coste_minimo = min_coste_suma(cola);

	// MOSTRAR SOLUCION
	cout << coste_minimo << endl;
}



int main(){
	int numCasos;

	cin >> numCasos;

	while (numCasos != 0)
	{
		resuelveCaso(numCasos);
		cin >> numCasos;
	}

	return 0;
}