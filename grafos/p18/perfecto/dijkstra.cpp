#include "dijkstra.h"
#include <limits>

dijkstra::dijkstra(const GrafoValorado<double>  &G, int s)
	:
	distTo(G.V(), std::numeric_limits<double>::infinity()),
	edgeTo(G.V(), Arista<double>(0, 0, 0)),
	pq(G.V()),
	camino_mejor(std::numeric_limits<double>::infinity()),
	numero(G.V(), 0),
	rep(0)
{

	distTo[s] = 0.0;
	pq.push(1, 0);
	numero[s] = 1;

	while (!pq.empty()  ) {  

		int v; 
		v = pq.top().elem; 
		pq.pop();

		for (Arista<double> e : G.adj(v))
		{
			relax(e,v);
		}
	}

	rep = numero[G.V()-1];
}


bool dijkstra::imposible() {
	return false;

}

void dijkstra::relax(const Arista<double> &e, int v){
	int  w = e.otro(v);

	if (distTo[w] >  distTo[v] + e.valor()) {

		numero[w] = numero[v];
		distTo[w] = distTo[v] + e.valor();
		edgeTo[w] = e;
		pq.update(w, distTo[w]);
	}
	else if (distTo[w] == distTo[v] + e.valor()){
		numero[w] += numero[v];

	}
}

