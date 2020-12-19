// Grupo 21, CRISTHIAN RODRIGUEZ GOMEZ y JONATHAN CARRERO ARANDA

/*
				PRACTICA 8: Ordenando a los pacientes en urgencias
		
*/
#include <iostream>
#include <string>
#include "IndexPQ.h"
#include "PriorityQueue.h"
#include "TreeMap_RB.h"
using namespace std;


// Lectura estandar de una cola con prioridad de n elementos
//PriorityQueue<int> leer(int n){
//	PriorityQueue<int> cola;
//	int elem;
//	for (size_t i = 0; i < n; i++)
//	{
//		cin >> elem;
//		cola.push(elem);
//	}
//	return cola;
//}
///*
//	Funcio que calcula el minimo esfuerzo de una suma de n elementos
//
//	Complejidad: O(n)
//*/
//int min_coste_suma(PriorityQueue<int> cola){
//
//		
//		int primer;
//		int segundo;
//		int suma = 0;
//		int min_coste = 0;
//
//	while (cola.size() >  1){
//
//		cola.pop(primer);
//		cola.pop(segundo);
//
//        suma = primer + segundo;
//		min_coste += suma;
//		cola.push(suma);
//
//		
//	}
//	return min_coste;
//}
//////Resuelve un cado de prueba, leyendo de la entrada la
//////configuracion, y escribiendo la respuesta
//void resuelveCaso(int num_Elem){
//	
//	PriorityQueue<int> cola;
//	int coste_minimo;
//
//	// LEER
//	cola = leer(num_Elem);
//
//	// CALCULAR COSTE MINIMO
//	coste_minimo = min_coste_suma(cola);
//
//	// MOSTRAR SOLUCION
//	cout << coste_minimo << endl;
//}
//

//TreeMap<int, string> leerTabla(){
//	TreeMap<int, string> tabla;
//	int gravedad;
//	string paciente;
//
//		cin >> paciente;
//		cin >> gravedad;
//
//		tabla.insert(gravedad, paciente);
//	
//}
void resuelveCaso(int num_Elems){
	string evento;
	TreeMap<int, string> tabla;
	PriorityQueue<int> Cola_gravedad;

	int gravedad;
	string paciente;
	
	for (size_t i = 0; i < num_Elems; i++)
	{

		//LEER EVENTO
		cin >> evento;


		if (evento == "I"){

			cin >> paciente;
			cin >> gravedad;

			tabla.insert(gravedad, paciente);
			Cola_gravedad.push(gravedad);

		}
		else if (evento == "A"){

			int mas_prioritario;
			string paciente_curado;

			Cola_gravedad.pop(mas_prioritario);

			paciente_curado = tabla.at(mas_prioritario);
			cout << paciente_curado << endl;
		}

	}
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