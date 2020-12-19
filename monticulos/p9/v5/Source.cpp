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

			// EDAD1 > LIDER
			if (edad1 > Lider){

				cola_DR_Minimos.push(edad1);

			}// EDAD1 < LIDER
			else{

				cola_IZ_Maximos.push(edad1);
			}
			
			// EDAD2 > LIDER
			if (edad2 > Lider){

				cola_DR_Minimos.push(edad2);

			} // EDAD2 < LIDER  
			else {

				cola_IZ_Maximos.push(edad2);

			} 

			// COMPROBAMOS EL TAMAÑO DE LAS COLAS

			if (cola_IZ_Maximos.size() < cola_DR_Minimos.size()){
				Lider = cola_DR_Minimos.top();
				cola_IZ_Maximos.push(Lider);
				
				cola_DR_Minimos.pop();


			
			}
			else{
				Lider = cola_IZ_Maximos.top();
				cola_DR_Minimos.push(Lider);
				
				cola_IZ_Maximos.pop(Lider);
			
			}

			// Imprimir el Lider
			cout << Lider ;
			if (i < parejas -1 ){
				cout << " ";
			}
		
	}
	
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