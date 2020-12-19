#include "Pavimentar_City.h"
#include <stdio.h>      /* printf */
#include <stdlib.h>     /* abs */
#include <cfloat> 
#include <limits>
Pavimentar_City::Pavimentar_City(GrafoValorado<double> const& G) :coste_min (0), edgeTo(G.V()), weight(1), marked(G.V(), false), pq(G.V()), distTo(G.V(), std::numeric_limits<double>::infinity())
{
	
	distTo[0] = 0.0;
	pq.push(1, 0);

	while (!pq.empty()  ) {  
		int minpq; minpq = pq.top().elem; pq.pop();
		visit(G, minpq);
	}
}


// add all edges e incident to v onto pq if the other endpoint has not yet been scanned
void Pavimentar_City::visit(GrafoValorado<double> const& G, int v){
	marked[v] = true;
	for (Arista<double> e : G.adj(v)){

		int w = e.otro(v);
		if (marked[w]) continue; // v-w is ineligible.
		if (e.valor() < distTo[w])
		{ // Edge e is new best connection from tree to w.
			edgeTo[w] = e;
			distTo[w] = e.valor();
			if (pq.contains(w)) {
			
				pq.update(w, distTo[w]);
			}
			else pq.update(w, distTo[w]);
		}
	}
		
}

// devuelve el coste minimo 
int Pavimentar_City::coste_minimo(){
	for (size_t i = 0; i < distTo.size(); i++)
	{
		if (distTo[i] != std::numeric_limits<double>::infinity())
		coste_min += distTo[i];
	}
	return coste_min;
}

