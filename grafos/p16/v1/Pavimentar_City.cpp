#include "Pavimentar_City.h"
#include <stdio.h>      /* printf */
#include <stdlib.h>     /* abs */
#include <cfloat> 
#include "Grafo.h"
Pavimentar_City::Pavimentar_City(GrafoValorado<int> const& G) : weight(0), pq(G.V()), marked(G.V(), false), mst(G.V())
{
	for (int v = 0; v < G.V(); v++)     // run Prim from all vertices to
		if (!marked[v]) prim(G, v);     // get a minimum spanning forest
	
	// check optimality conditions
	check(G);
}

// run Prim's algorithm
void Pavimentar_City::prim(GrafoValorado<int> const& G, int s){
	scan(G, s);
	while (!pq.empty()) {                        // better to stop when mst has V-1 edges
		Arista<int> e = pq.top();  pq.pop();                   // smallest edge on pq
		int v = e.uno(), w = e.otro(v);        // two endpoints
		//assert marked[v] || marked[w];
		if (marked[v] && marked[w]) continue;      // lazy, both v and w already scanned
		mst.push_back(e);                            // add e to MST
		weight += e.valor();
		if (!marked[v]) scan(G, v);               // v becomes part of tree
		if (!marked[w]) scan(G, w);               // w becomes part of tree
	}
}

// add all edges e incident to v onto pq if the other endpoint has not yet been scanned
void Pavimentar_City::scan(GrafoValorado<int> const& G, int v){
	marked[v] = true;
	for (Arista<int> e : G.adj(v))
		if (!marked[e.otro(v)]) pq.push(e);
}

// check optimality conditions (takes time proportional to E V lg* V)
bool Pavimentar_City::check(GrafoValorado<int> const& G){
	// check weight
        double totalWeight = 0.0;
        for (Arista<int> e : mst) {
            totalWeight += e.valor();
        }
		if (abs(totalWeight - weight) > FLT_EPSILON) {
			std:: cout << "Weight of edges does not equal weight(): %f vs. %f\n", totalWeight, weight ;
            return false;
        }

        // check that it is acyclic
		Grafo g(G.V());
		ComponentesConexas  uf(g);

		for (Arista<int> e : mst) {    
 
            int v = e.uno(), w = e.otro(v);
			

            if (uf.areConnected(v, w)) {
				std :: cout << "Not a forest" ;
                return false;
            }
            g.ponArista(v, w);
        }
		 // ###---------------------------------------------------- CONTINUAR POR AQUI-----------------------------------------------------------------------------------


        // check that it is a spanning forest
		for (Arista<int> e : mst) {

            int v = e.either(), w = e.other(v);
            if (!uf.connected(v, w)) {
                System.err.println("Not a spanning forest");
                return false;
            }
        }

        // check that it is a minimal spanning forest (cut optimality conditions)
		for (Arista<int> e : mst) {

            // all edges in MST except e
            uf = new UF(G.V());
			for (Arista<int> f : mst) {
                int x = f.either(), y = f.other(x);
                if (f != e) uf.union(x, y);
            }

            // check that e is min weight edge in crossing cut
			for (Arista<int> e : mst) {
                int x = f.either(), y = f.other(x);
                if (!uf.connected(x, y)) {
                    if (f.weight() < e.weight()) {
                        System.err.println("Edge " + f + " violates cut optimality conditions");
                        return false;
                    }
                }
            }

        }

        return true;
}
// devuelve el coste minimo 
int Pavimentar_City::coste_minimo(){
	return weight;
}

