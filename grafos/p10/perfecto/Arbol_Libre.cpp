#include "Arbol_Libre.h"

// Busqueda en profundidad que nos permite recorrer todo el grafo desde el vertice v.
// devuelve  el numero de aristas sin repetir ( a )  y los vertices recorridos ( k ).
// O(v + e) donde v es el numero de vertices y e es el numero de aristas.
void Arbol_Libre:: dfs_Aristas(Grafo const& G, size_t v, size_t &k, size_t &a) {

	size_t w;
	++k;
	recorrido[v] = k;

	for (auto w : G.adj(v)) {

		if (v <= w){ // origen <= destino 

			a = a + 1;
		}
		if (recorrido[w] == 0){

			dfs_Aristas(G, w, k, a);
		}
	
	}

		


}
/* Constructor */
// Calcula previamente el numero de aristas y los vertices recorridos con la funcion dfs_aristas();
// Luego calcula si es Libre. Es libre si es conexo y el numero de aristas = numero de vertices menos uno); 
// O(v + e) donde v es el numero de vertices del grafo y e el numero de aristas.
Arbol_Libre::Arbol_Libre(Grafo const& G) : recorrido(G.V(),0) {

	size_t k = 0; size_t a = 0;

	dfs_Aristas(G, 1, k, a);

	libre = ((k == G.V()) && a == G.V() - 1);

}
// devuelve si el grafo  es libre.
 bool Arbol_Libre::es_Arbol_libre(){
	 return libre;
 }