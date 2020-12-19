// Grupo 21, CRISTHIAN RODRIGUEZ GOMEZ y JONATHAN CARRERO ARANDA

/*
				PRACTICA 9: Pajaros al vuelo
				---------------------------------------------------

*/
#include <iostream>
#include <string>
#include "PriorityQueue.h"
using namespace std;

typedef struct {
	int edad; 
	int prioritario;
}tPareja;

/*
	Sobrecarga al operador para poder comparar la cola de prioridad 
	segun el orden de llegada y segun la prioridad del pasciente.
	*/
bool operator< (tPareja a , tPareja b ) {
	return (a.prioritario < b.prioritario);

}

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

void resuelveCaso(int edad, int parejas){
	PriorityQueue<tPareja, less<tPareja>> cola;
	tPareja a,b,c;
	vector<string> lista;
	c.edad = edad;
	c.prioritario = parejas;
	cola.push(c);
	

	for (int i = 0; i < parejas; i++)
	{
		
		cin >> a.edad;
		cin >> b.edad;

		tPareja p;
		p = cola.top();
		cola.pop();

		// si prioritario es menor que ambos
		if (p.edad < a.edad && p.edad < b.edad) {

			// prioritario es el menor(a,b)
			if (a.edad < b.edad) {
				a.prioritario = parejas - 2 * (1+i);
				b.prioritario = parejas - 1 * (1 + i);
				p.prioritario = parejas - 0;

			
				cola.push(c);
			}
			else {// prioritario es el menor(b,a)
				a.prioritario = parejas - 1 * (1 + i);
				b.prioritario = parejas - 2 * (1 + i);
				p.prioritario = parejas - 0;

				cola.push(a);
				cola.push(b);
				cola.push(c);
			}
		}
		// si prioritario es mayor que ambos
		else if (p.edad > a.edad && p.edad > b.edad) {

			// prioritario es el max(a,b)
			if (a.edad > b.edad) {
				a.prioritario = parejas - 2 * (1 + i);
				b.prioritario = parejas - 1 * (1 + i);
				p.prioritario = parejas - 0 * (1 + i);

				cola.push(a);
				cola.push(b);
				cola.push(c);
			}
			else {// prioritario es el max(b,a)
				a.prioritario = parejas - 1 * (1 + i);
				b.prioritario = parejas - 2 * (1 + i);
				p.prioritario = parejas - 0;

				cola.push(a);
				cola.push(b);
				cola.push(c);
			}
		
		
		}
		else {
			if (a.edad < b.edad) {
				a.prioritario = parejas - 1 * (1 + i);
				b.prioritario = parejas - 0 * (1 + i);
			}
			else {
				a.prioritario = parejas - 0 * (1 + i);
				b.prioritario = parejas - 1 * (1 + i);
			}
			cola.push(a);
			cola.push(b);
			cola.push(p);
		}
		cout << cola.top().edad<< endl;
	}

}

int main(){

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