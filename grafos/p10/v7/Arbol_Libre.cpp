#include "Arbol_Libre.h"

void Arbol_Libre:: dfs_Aristas(Grafo const& G, size_t v, size_t &k, size_t &a, std::vector<size_t> recorrido) {

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

			dfs_Aristas(G, w, k, a, recorrido);
		}
	}

}
 Arbol_Libre::Arbol_Libre(Grafo const& G){

	size_t k = 0; size_t a = 0;
	std::vector<size_t> recorrido(G.V());


	// INICIALIZAMOS A  0 el vector
	for (size_t i = 0; i < G.V(); i++)
	{
		recorrido[i] = 0;
	}

	dfs_Aristas(G, 1, k, a, recorrido);

	es_Arbol_Libre = ((k == G.V()) && a == G.V() - 1);

}
 bool Arbol_Libre::es_Arbol_libre(){
	 return es_Arbol_Libre;
 }