// Grupo 21, CRISTHIAN RODRIGUEZ GOMEZ y JONATHAN CARRERO ARANDA

/*
				PRACTICA 7
	Primero leemos la cola de la entrada estandar, luego calculamos el coste mediante la funcion min_coste_suma(),
	despues mostramos por pantalla la solucion.
	
*/
#include <iostream>
#include "PriorityQueue.h"

using namespace std;


// Lectura estandar de una cola con prioridad de n elementos
PriorityQueue<long long > leer(int n){
	PriorityQueue<long long > cola;
	long long  elem;

	for (size_t i = 0; i < n; i++)
	{
		cin >> elem;
		cola.push(elem);
	}
	return cola;
}
/*
	Funcio que calcula el minimo esfuerzo de una suma de n elementos

	Para calcular el coste minimo esfuerzo de la suma, hemos sumado los dos elementos mas prioritarios,
	luego quitamos dichos elementos de la cola, esa suma lo metimos otra ves en la cola. 
	en cada suma incrementamos el coste con la nueva suma.

	Complejidad: O(n)
*/
long long min_coste_suma(PriorityQueue<long long > cola){

		
		long long primer ;
		long long  segundo;
		long long  suma = 0;
		long long  min_coste = 0;

	while (cola.size() >  1){

		primer = cola.top();
		cola.pop();
		segundo = cola.top();
		cola.pop();

        suma = primer + segundo;

		min_coste += suma;
		cola.push(suma);

		
	}
	return min_coste;
}
////Resuelve un cado de prueba, leyendo de la entrada la
////configuracion, y escribiendo la respuesta
void resuelveCaso(int num_Elem){
	
	PriorityQueue<long long> cola;
	long long coste_minimo;

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