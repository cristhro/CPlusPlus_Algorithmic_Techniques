#include "Pavimentar_City.h"
#include <limits>
Pavimentar_City::Pavimentar_City(const GrafoValorado<double>  G)
	: weight(1),
	marked(G.V(),false),
	distTo(G.V(),    std::numeric_limits<double>::infinity()),
	edgeTo(G.V()),
	pq(G.V()),
	cont1 (0), 
	cont2(0), 
	coste_min (0)
{
	
	distTo[0] = 0.0;
	pq.push(1, 0);

	while (!pq.empty()  ) {  
		int minpq; minpq = pq.top().elem; pq.pop();
		visit(G, minpq);
	}
}


// add all edges e incident to v onto pq if the other endpoint has not yet been scanned
void Pavimentar_City::visit(const GrafoValorado<double>  G, int v){
	marked[v] = true;
	cont2++;
	for (Arista<double> e : G.adj(v)){

		int w = e.otro(v);
		if (marked[w]) continue; // v-w is ineligible.
		if (e.valor() < distTo[w])
		{ // Edge e is new best connection from tree to w.
			cont1++;
			edgeTo[w] = e;
			distTo[w] = e.valor();
			
			pq.update(w, distTo[w]);
			
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

bool Pavimentar_City::imposible() {
	return (cont1 == cont2 - 1  ); // numero de vertices conectados

}