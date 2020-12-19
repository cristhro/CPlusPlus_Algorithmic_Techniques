#include "Grafo.h"

class Arbol_Libre
{
public:
	Arbol_Libre(Grafo const& G);
	bool es_Arbol_libre();

private:	
	// recorrido en profundidad desde v Contabilizando las aristas
	void dfs_Aristas(Grafo const& G, size_t v, size_t &k, size_t &a, std::vector<size_t> recorrido);
	bool es_Arbol_Libre;
};

