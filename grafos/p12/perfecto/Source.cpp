// Grupo 21, CRISTHIAN RODRIGUEZ GOMEZ y JONATHAN CARRERO ARANDA

// El problema se ha resuelto usando  la clase Arborecencia,  
// con  nuevo método que devuelve si un arbol es Arborecente 
//  (calculado previamente en el constructor de la clase).



#include <iostream>
#include <string>
#include "GrafoDirigido.h"
#include "Arborecencia.h"
#include<fstream>

using namespace std;

// lectura estandar de un grafo por consola
GrafoDirigido leer_Grafo(size_t V){

	size_t E;
	cin >> E;

	GrafoDirigido g(V);
	size_t v, w;
	
	for (size_t i = 0; i < E; i++)
	{
		cin >> v;
		cin >> w;
		g.ponArista(v, w);
	}

	return g;
}

// resuelve un caso de prueva
bool resuelveCaso(){


	size_t V, raiz = 0;
	cin >> V;

	if (!cin){
		return false;
	}
	// leer grafo
	GrafoDirigido G = leer_Grafo(V);	  // O(e + v)donde v es el numero de vertices y e es el numero de aristas del grafo.
	Arborecencia arb(G, raiz);			  // O(e + v) donde v es el numero de vertices y e es el numero de aristas del grafo.

	bool ok = arb.es_Arborecencia();	  // O(1) 

	//Mostrar solucion
	if (ok) cout << "SI " << raiz << endl;
	else cout << "NO" << endl;

	return true;

}

int main(){

	// casos de prueba ilimitados
	while (resuelveCaso());

	return 0;
}