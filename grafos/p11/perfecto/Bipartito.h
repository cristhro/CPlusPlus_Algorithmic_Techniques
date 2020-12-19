#include "Grafo.h"
#include <stack>
#include <list>
class Bipartito
{

public:
	/* Constructor */
	Bipartito(Grafo const& G);
	
	bool es_bipartito();

private:

	bool esBi; // Atributo para saber si es libre un grafo
	std::vector<bool> color;
	std::vector<bool> marked;
	std::vector<size_t> edgeTo;

	void dfs_bipartito(Grafo const& G, size_t v);
};

