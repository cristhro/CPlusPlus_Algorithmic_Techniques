#include "Grafo.h"

class Arbol_Libre
{
public:
	/* Constructor */
	Arbol_Libre(Grafo const& G);

	bool es_Arbol_libre();

private:	

	bool libre; // Atributo para saber si es libre un grafo
	std::vector<size_t> recorrido;

	void dfs_Aristas(Grafo const& G, size_t v, size_t &k, size_t &a);
};

