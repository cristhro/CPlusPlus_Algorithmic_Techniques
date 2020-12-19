#include "Arbol_Libre.h"

// Busqueda en profundidad que nos permite recorrer todo el grafo desde el vertice v.
// el algoritmo devuelve  el numero de aristas sin repetir.
// O(v + e) donde v es el numero de vertices y e es el numero de aristas.
void Arbol_Libre:: dfs_Aristas(Grafo const& G, size_t v, size_t &k, size_t &a) {

	std :: vector<size_t> lista;
	size_t w;
	++k;

	recorrido[v] = k;
	lista = G.adj(v);

	while (!lista.empty()){

		w = lista.back();
		lista.pop_back();

		if (v <= w){

			a = a + 1;
		}
		if (recorrido[w] == 0){

			dfs_Aristas(G, w, k, a);
		}
	}

}
Arbol_Libre::Arbol_Libre(Grafo const& G) : recorrido(G.V()) {

	size_t k = 0; size_t a = 0;
	
	// INICIALIZAMOS A  0 el vector
	for (size_t i = 0; i < G.V(); i++)
	{
		recorrido[i] = 0;
	}

	dfs_Aristas(G, 1, k, a);

	libre = ((k == G.V()) && a == G.V() - 1);

}
 bool Arbol_Libre::es_Arbol_libre(){
	 return libre;
 }