#include "GrafoValorado.h"
#include "PriorityQueue.h"
#include <queue>
#include <vector>
class Pavimentar_City
{
public:
	/* Constructor */
	Pavimentar_City(GrafoValorado<int> const& G);

	int coste_minimo();
private:
	double weight;       // coste minimo en pavimentar
	std :: deque <Arista<int>> mst;     // edges in the MST
	std :: vector<bool> marked;    // marked[v] = true if v on tree
	PriorityQueue<Arista<int>> pq;      // edges with one endpoint in tree
	
	// run Prim's algorithm
	void prim(GrafoValorado<int> const& G, int s);

	// add all edges e incident to v onto pq if the other endpoint has not yet been scanned
	void scan(GrafoValorado<int> const& G, int v);

	// check optimality conditions (takes time proportional to E V lg* V)
	bool check(GrafoValorado<int> const& G);
};	

