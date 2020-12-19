// Grupo 21, CRISTHIAN RODRIGUEZ GOMEZ y JONATHAN CARRERO ARANDA

/*
	PRACTICA 10: Arboles libres
	

		
*/
#include <iostream>
#include <string>
#include "Grafo.h"
#include "Arbol_Libre.h"
using namespace std;



/*
	Funcion que recorre un grafo contabilizando las aristas ( a ),
	tendremos en  cuenta que no contaremos dos veces las aristas,
	es decir que el origen solo contaremos cuando el origen <= al destino.	

	Complejidad O(v + e)
*/



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



bool resuelveCaso(){

	// leer grafo
	size_t V;
	cin >> V ;

	if (!cin){
		return false;
	}

	Grafo G = leer_Grafo(V);
	Arbol_Libre G2(G);

	// Arbol Libre
	bool ok = G2.es_Arbol_libre();

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