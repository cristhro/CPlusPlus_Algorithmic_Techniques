// Grupo 21, CRISTHIAN RODRIGUEZ GOMEZ y JONATHAN CARRERO ARANDA

/*
				PRACTICA 9: Pajaros al vuelo
				-----------------------------

*/
#include <iostream>
#include <string>
#include "PriorityQueue.h"
using namespace std;



void resuelveCaso(size_t Lider, size_t parejas) {

	PriorityQueue<size_t, less<size_t>> cola_DR_Minimos;
	PriorityQueue<size_t, greater<size_t>> cola_IZ_Maximos;

	size_t edad1, edad2;

	for (size_t i = 0; i < parejas; i++){
		
		cin >> edad1;
		cin >> edad2;

			if (edad1 > Lider&& edad2 > Lider){

				// Insertamos las dos edades en cola_DR_Minimos
				cola_DR_Minimos.push(edad1);
				cola_DR_Minimos.push(edad2);

				// Insertamos el Lider en cola_IZ_Maximos
				cola_IZ_Maximos.push(Lider);

				// Actualizamos el Lider, el cual, será el primer elemento de cola_DR_Minimos
				Lider = cola_DR_Minimos.top();
				cola_DR_Minimos.pop();
			}
			else if (edad1 < Lider && edad2 < Lider){

				// Insertamos las dos edades en cola_IZ_Maximos
				cola_IZ_Maximos.push(edad1);
				cola_IZ_Maximos.push(edad2);

				// Insertamos el Lider en cola_DR_Minimos
				cola_DR_Minimos.push(Lider);

				// Actualizamos el Lider, el cual, será el primer elemento de cola_IZ_Maximos
				Lider = cola_IZ_Maximos.top();
				cola_IZ_Maximos.pop();
			}
			else if (edad1 < Lider && edad2 > Lider){

				//  Insertamos la edad1 (que es menor que el Lider) en cola_IZ_Maximos
				cola_IZ_Maximos.push(edad1);

				// Insertamos la edad2 (que es mayor que el Lider) en cola_DR_Minimoss
				cola_DR_Minimos.push(edad2);
			}
			else if (edad1 > Lider && edad2 < Lider){

				// Insertamos la edad1 (que es mayor que el Lider) en cola_DR_Minimoss
				cola_DR_Minimos.push(edad1);

				//  Insertamos la edad2 (que es menor que el Lider) en cola_IZ_Maximos
				cola_IZ_Maximos.push(edad2);
			}



			// Imprimir el Lider
			cout << Lider ;
			if (i < parejas -1 ){
				cout << " ";
			}
		
	}
	cout << endl;
	
}

int main() {

	size_t edad_Lider;
	size_t parejas;

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