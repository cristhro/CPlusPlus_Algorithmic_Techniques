#include "Grafo.h"

class Arbol_Libre
{
public:
	Arbol_Libre(Grafo const& G);
	bool es_Arbol_libre();

private:	
	// recorrido en profundidad desde v Contabilizando las aristas
		bool libre;
		std::vector<size_t> recorrido;
	void dfs_Aristas(Grafo const& G, size_t v, size_t &k, size_t &a);

};

