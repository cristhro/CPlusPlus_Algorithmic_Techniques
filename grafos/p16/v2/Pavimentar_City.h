#include "GrafoValorado.h"
#include "IndexPQ.h"
#include <queue>
#include <vector>
class Pavimentar_City
{
public:
	/* Constructor */
	Pavimentar_City(GrafoValorado<double> const& G);

	int coste_minimo();
private:
	int weight;                    // coste minimo en pavimentar
	std :: vector<bool> marked;    // marked[v] = true if v on tree
	std::vector <double> distTo;	   // distTo[w] = edgeTo[w].weight()
	std::vector <Arista<double>> edgeTo;      // shortest edge from tree vertex
	IndexPQ<double> pq;               // edges with one endpoint in tree
	int coste_min;

	// add all edges e incident to v onto pq if the other endpoint has not yet been scanned
	void visit(GrafoValorado<double> const& G, int v);

	// check optimality conditions (takes time proportional to E V lg* V)
	//bool check(GrafoValorado<int> const& G);
};	

