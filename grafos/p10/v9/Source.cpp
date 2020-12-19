// Grupo 21, CRISTHIAN RODRIGUEZ GOMEZ y JONATHAN CARRERO ARANDA

// El problema se ha resuelto usando  la clase Arbol_Libre,  
// un nuevo método que devuelve si un arbol es libre (previamente calculado en el constructor de la clase).
// claves dadas.

#include <iostream>
#include <string>
#include "Grafo.h"
#include "Arbol_Libre.h"

using namespace std;



// lectura estandar de un grafo por consola
Grafo leer_Grafo(size_t V){  //param e/s *-g()//dev bool

	size_t E;
	cin >> E;

	Grafo g(V);
	size_t v, w;
	
	for (size_t i = 0; i < E; i++)
	{
		cin	 >> v;
		cin  >> w;
		g.ponArista(v, w);
	}
	return g;
}

// resuelve un caso de prueva

bool resuelveCaso(){

	// leer grafo
	size_t V;
	cin >> V ;

	if (!cin){
		return false;
	}

	Grafo G = leer_Grafo(V);			// O( n ) donde n es el numero de vertices del grafo.
	Arbol_Libre G2(G);					// O(e + v) donde v es el numero de vertices y e es el numero de aristas del grafo.

	// Arbol Libre
	bool ok = G2.es_Arbol_libre();		// O(1)

	// Mostrar solucion
	if (ok) cout << "SI" << endl;
	else cout << "NO" << endl;
	
	return true;

}

int main(){
	
	// casos de prueba ilimitados
	while (resuelveCaso());
	system("PAUSE");
	return 0;
}