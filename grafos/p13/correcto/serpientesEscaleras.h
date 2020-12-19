#include "TreeMap_RB.h"
#include "GrafoDirigido.h"
class serpientesEscaleras
{
public:

	serpientesEscaleras(const size_t &v,  TreeMap<size_t, size_t> &map, const size_t &k) : menor(0)
	{
		GrafoDirigido grafo = crear_Grafo(v,map,k);
		
		BreadthFirstDirectedPaths b(grafo,1);

		// Devuelve el número de aristas en el camino más corto a v
		menor = b.distance(v-1);
	}

	size_t obtener_menor_numero_movimientos(){
		return menor;
	}

private:
	size_t  menor;

	GrafoDirigido crear_Grafo(const size_t &V,  TreeMap<size_t, size_t> &map, const size_t &K){

		GrafoDirigido g(V);

		for (size_t i = 1; i < V; i++)
		{

			for (size_t j = i + 1; j <= i + K && j < V ; j++)
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
};

