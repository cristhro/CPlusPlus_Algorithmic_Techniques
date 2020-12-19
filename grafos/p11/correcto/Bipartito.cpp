#include "Bipartito.h"


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

		if (!cycle.empty())
			return;

		if (!marked[w])
		{
			edgeTo[w] = v;
			color[w] = !color[v];
			dfs_bipartito(G, w);
		}
		else if (color[w] == color[v])
		{
			esBi = false;
			cycle.push(w);
			for (size_t x = v; x != w; x = edgeTo[x])
			{
				cycle.push(x);
			}
			cycle.push(w);
		}
	}


}
bool Bipartito:: es_bipartito(){
	return esBi;
}