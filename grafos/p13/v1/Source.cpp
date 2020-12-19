// Grupo 21, CRISTHIAN RODRIGUEZ GOMEZ y JONATHAN CARRERO ARANDA


#include <iostream>
#include <string>
#include "Grafo.h"
#include "TreeMap_RB.h"
using namespace std;


// lectura estandar de un grafo por consola
Grafo leer_Grafo(size_t &N, size_t &K, TreeMap<size_t, size_t> &map){


	Grafo g(N*N);

	for (size_t i = 1; i < N*N; i++)
	{

		for (size_t j = i+1; j < i + K  && j < N*N - K; j++)
		{
			if (map.contains(j)){
				g.ponArista(i, map.at(j));

			}
			else{
				g.ponArista(i, j);
			
			}
		}
		
	}
	return g;
}

// resuelve un caso de prueva

bool resuelveCaso(){

	 //leer grafo
	size_t N,K,S,E, origen, destino;
	TreeMap <size_t, size_t> map;

	cin >> N;		// dimension del tablero
	cin >> K;	    // numero de caras
	cin >> S;		// numero de serpientes
	cin >> E;		// numero de escaleras
	
	if (N== 0 && K == 0 && S == 0 && E == 0){
		return false;
	}

					// insertamos las serpientes y las escaleras
	for (size_t i = 0; i < S + E; i++)
	{
		cin >> origen;
		cin >> destino;
		map.insert(origen, destino);
	}

	//map.print();
	
	Grafo G = leer_Grafo(N,K,map);			// O( e + v ) donde n es el numero de vertices del grafo.

	BreadthFirstPaths caminoCorto(G, 1);
	std::deque<size_t> a; 

	a = caminoCorto.pathTo(N*N);

	cout <<a.size() << endl;
	// Mostrar solucion


	return true;
}

int main(){

	// casos de prueba ilimitados
	while (resuelveCaso());

	return 0;
}