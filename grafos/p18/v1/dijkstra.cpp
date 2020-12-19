#include "dijkstra.h"
#include <limits>

dijkstra::dijkstra(const GrafoValorado<double>  &G, int s)
	:
	distTo(G.V(), std::numeric_limits<double>::infinity()),
	edgeTo(G.V(), Arista<double>(0, 0, 0)),
	pq(G.V()),
	camino_mejor(std::numeric_limits<double>::infinity()),
	rep(1)
{

	distTo[s] = 0.0;
	pq.push(1, 0);

	while (!pq.empty()  ) {  

		int v; 
		v = pq.top().elem; 
		pq.pop();

		for (Arista<double> e : G.adj(v))
		{
			relax(e,v);
		}
		
	}
}


bool dijkstra::imposible() {
	return false;

}

void dijkstra:: relax(const Arista<double> &e, int v)
{
	int  w = e.otro(v);

	if (distTo[w] >= distTo[v] + e.valor()) 
	{
	

		distTo[w] = distTo[v] + e.valor();
		edgeTo[w] = e;
		pq.update(w, distTo[w]);

		/*if (w == 7){
			if (camino_mejor > distTo[7]){
				camino_mejor = distTo[7];
				rep = 1;
			}
			else if (camino_mejor == distTo[7]){
				rep++;
			}
		}*/
		
	}
	if (w == 7){
		if (camino_mejor > distTo[7]){
			camino_mejor = distTo[7];
			rep = 1;
		}
		else if (camino_mejor == distTo[7]){
			rep++;
		}
	}
	
}

