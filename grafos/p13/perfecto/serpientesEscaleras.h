#include "TreeMap_RB.h"
#include "GrafoDirigido.h"
class serpientesEscaleras
{
public:

	/* 
		Constructor 
		O( e + v )  donde V es el numero de vertices y E numero de aristas.
	*/

	serpientesEscaleras(const size_t &v,  TreeMap<size_t, size_t> &map, const size_t &k) : menor(0)
	{
		GrafoDirigido grafo = crear_Grafo(v,map,k);		// O( e + v )
		
		BreadthFirstDirectedPaths b(grafo,1);   		// O( e + v )

		// Devuelve el número de aristas en el camino más corto a v
		menor = b.distance(v-1);
	}

	/* 
		funcion que devuelve el numero minimo de tiradas
		O(1)
	 */
	size_t obtener_menor_numero_movimientos(){
		return menor;
	}

private:
	size_t  menor;

	/*
		Funcion que crea un grafo dirigido, con numero de aristas del vertice i sea igual al numero de caras ( K ) que tenga el dado.
		Usa un mapa para sustitir los vertices originales por  las serpientes o escaleras.
		O (v + e ) donde v es el numero de vertices y e es el número de aristas, es decir, e = v * k (donde k son las caras del dado)
	*/

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

