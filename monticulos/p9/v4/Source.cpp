// Grupo 21, CRISTHIAN RODRIGUEZ GOMEZ y JONATHAN CARRERO ARANDA

/*
				PRACTICA 9: Pajaros al vuelo
				-----------------------------

*/
#include <iostream>
#include <string>
#include "PriorityQueue.h"
using namespace std;


void resuelveCaso( int Lider,int parejas ) {

	PriorityQueue<int,less_equal<int>> cola_Minimos;
	PriorityQueue<int, greater_equal<int>> cola_Maximos;
	int edad1, edad2;

	for (int i = 0; i < parejas; i++){
		
		cin >> edad1;
		cin >> edad2;

		if (edad1 != edad2){

			//SON  MAYORES QUE LIDER
			if (edad1 > Lider && edad2 > Lider){

				cola_Minimos.push(edad1);
				cola_Minimos.push(edad2);

			}// MENORES QUE LIDER
			else if (edad1 < Lider && edad2 < Lider){

				cola_Maximos.push(edad1);
				cola_Maximos.push(edad2);

			} // EDAD1 < LIDER  EDAD2 > LIDER
			else if (edad1 < Lider && edad2 > Lider){

				cola_Maximos.push(edad1);
				cola_Minimos.push(edad2);

			} // EDAD1 > LIDER  EDAD2 < LIDER
			else if (edad1 > Lider && edad2 < Lider){

				cola_Minimos.push(edad1);
				cola_Maximos.push(edad2);

			}
			if (cola_Minimos.size() < cola_Maximos.size()) {

				cola_Minimos.push(Lider);
				cola_Maximos.pop(Lider);
				
			}
			else {
				cola_Maximos.push(Lider);
				cola_Minimos.pop(Lider);
			}

			// Imprimir el Lider
			cout << Lider << endl;
		}
	}
	
}

int main() {

	int edad_Lider;
	int parejas;

	cin >> edad_Lider;
	cin >> parejas;

	while (edad_Lider != 0 && parejas!= 0)
	{
		resuelveCaso(edad_Lider, parejas);
		cin >> edad_Lider;
		cin >> parejas;
	}

	return 0;
}