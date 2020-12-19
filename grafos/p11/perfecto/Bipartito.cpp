#include "Bipartito.h"

// O( e + v )donde v es el numero de vertices y e es el numero de aristas del grafo.

Bipartito::Bipartito(Grafo const& G) : edgeTo(G.V()), color(G.V()), marked(G.V(), false), esBi(true)
{

	for (size_t v = 0; v < G.V(); v++)
	{
		if (!marked[v])
		{
			color[v] = false;
			dfs_bipartito(G, v);
		}
	}
}


void Bipartito ::  dfs_bipartito(Grafo const& G, size_t v) {

	marked[v] = true;

	for (auto w : G.adj(v)) {

		// si vertice v no tiene color continua
		if (!marked[w])
		{
			edgeTo[w] = v;
			color[w] = !color[v];
			dfs_bipartito(G, w);
		}
		else if (color[w] == color[v])	// si el adj w al vertice v son del mismo color 
		{
			esBi = false;		// no es bipartito
			return;
	
		}
	}


}
bool Bipartito:: es_bipartito(){
	return esBi;
}