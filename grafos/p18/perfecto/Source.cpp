// Grupo 21, CRISTHIAN RODRIGUEZ GOMEZ y JONATHAN CARRERO ARANDA

// El problema se ha resuelto usando  la clase dijkstra,  
// con un nuevo método que devuelve el numero de caminosminimos al ultimo vertice.
// O ( e*log v)  e numero de calles, v numero de intersecciones .

#include <iostream>
#include <string>
#include "GrafoValorado.h"
#include "dijkstra.h"
#include <limits>
using namespace std;



// lectura estandar de un grafo por consola
GrafoValorado<double> leer_Grafo(size_t V)
{
	size_t e;
	cin >> e;
	 
	GrafoValorado<double> g(V);		        
	
	size_t v, w, valor;

	for (size_t i = 0; i < e; i++)
	{
	
		cin >> v;
		cin >> w;
		cin >> valor;

		g.ponArista(Arista<double>(v, w, valor));
	}
	return g;
}


// resuelve un caso de prueva
bool resuelveCaso(){

	// leer grafo
	size_t v;
	cin >> v;

	if (!cin){
		return false;
	}

	GrafoValorado<double> G = leer_Grafo(v+1);			

	dijkstra a(G,1);					//O(e*log v  ) v numero de intersecciones, e numero de calles

	cout << a.caminosCortos() << endl;	//O(1)

	return true;

}

int main(){

	// casos de prueba ilimitados
	while (resuelveCaso());

	return 0;
}