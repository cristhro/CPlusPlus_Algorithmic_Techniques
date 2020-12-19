// Grupo 21, CRISTHIAN RODRIGUEZ GOMEZ y JONATHAN CARRERO ARANDA

/*
				PRACTICA 9: Pajaros al vuelo
				---------------------------------------------------

*/
#include <iostream>
#include <string>
#include "PriorityQueue.h"
using namespace std;


/*
	Sobrecarga al operador para poder comparar la cola de prioridad 
	segun el orden de llegada y segun la prioridad del pasciente.
	*/
//bool operator <(tPareja a , tPareja b ) {
	//return (a.prioritario < b.prioritario);

//}

/*
	muestra la lista

	Complejidad O(n) segun el numero de elementos que tiene la lista.
*/
//void mostrar_lista(vector<string> lista){
//	for (size_t i = 0; i < lista.size(); i++)
//	{
//		cout << lista.at(i) << endl;
//	}
//}

void resuelveCaso(int edadLider, int parejas) {

	PriorityQueue<int,less_equal<int>> colaMinimo;
	PriorityQueue<int, greater_equal<int>> colaMaximo;

	int Lider = edadLider;
	int edad1, edad2;

	for (int i = 0; i < parejas; i++){
		
		cin >> edad1;
		cin >> edad2;

		
		if (edad1 != edad2){

			if (edad1 > Lider&& edad2 > Lider){

				// Insertamos las dos edades en colaMinimo
				colaMinimo.push(edad1);
				colaMinimo.push(edad2);

				// Insertamos el Lider en ColaMaximo
				colaMaximo.push(Lider);

				// Actualizamos el Lider, el cual, será el primer elemento de colaMinimo
				Lider = colaMinimo.top();
				colaMinimo.pop();
			}
			else if (edad1 < Lider && edad2 < Lider){

				// Insertamos las dos edades en colaMaximo
				colaMaximo.push(edad1);
				colaMaximo.push(edad2);

				// Insertamos el Lider en colaMinimo
				colaMinimo.push(Lider);

				// Actualizamos el Lider, el cual, será el primer elemento de colaMaximo
				Lider = colaMaximo.top();
				colaMaximo.pop();
			}
			else if (edad1 < Lider && edad2 > Lider){

				//  Insertamos la edad1 (que es menor que el Lider) en colaMaximo
				colaMaximo.push(edad1);

				// Insertamos la edad2 (que es mayor que el Lider) en colaMinimos
				colaMinimo.push(edad2);
			}
			else if (edad1 > Lider && edad2 < Lider){

				// Insertamos la edad1 (que es mayor que el Lider) en colaMinimos
				colaMinimo.push(edad1);

				//  Insertamos la edad2 (que es menor que el Lider) en colaMaximo
				colaMaximo.push(edad2);
			}

			// Imprimir el Lider
			cout << Lider << endl;
		}
	}
	
}

int main() {

	int edad_pajaro;
	int parejas;

	cin >> edad_pajaro;
	cin >> parejas;

	while (edad_pajaro != 0 && parejas!= 0)
	{
		resuelveCaso(edad_pajaro, parejas);
		cin >> edad_pajaro;
		cin >> parejas;
	}

	return 0;
}