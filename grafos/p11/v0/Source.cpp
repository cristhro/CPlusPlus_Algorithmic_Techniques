// Grupo 21, CRISTHIAN RODRIGUEZ GOMEZ y JONATHAN CARRERO ARANDA

/*
				PRACTICA 11: es bipartito
				-------------------------
		
*/
#include <iostream>
#include <string>
#include "Grafo.h"
#include<fstream>
#include <cstdio>
#include <stack>
#include <list>

using namespace std;



void Grafo::ponArista(size_t v, size_t w) {
	if (v >= _V || w >= _V) throw std::invalid_argument("Vértice inexistente");
	++_E;
	_adj[v].push_back(w);
	_adj[w].push_back(v);
}

const Adys& Grafo::adj(size_t v) const {
	if (v >= _V) throw std::invalid_argument("Vértice inexistente");
	return _adj[v];
}
/*

*/
void dfs_bipartito(Grafo const& G,size_t v, bool &isBi, bool *&color, bool *&marked, size_t *&edgeTo, stack<size_t> &cycle) {
	
	marked[v] = true;

	for (auto w : G.adj(v)) {
		
				if (!cycle.empty())
					return;

				if (!marked[w])
				{
					edgeTo[w] = v;
					color[w] = !color[v];
					dfs_bipartito(G, w, isBi, color, marked, edgeTo, cycle);
				}
				else if (color[w] == color[v])
				{
					isBi = false;
					cycle.push(w);
					for (size_t x = v; x != w; x = edgeTo[x])
					{
						cycle.push(x);
					}
					cycle.push(w);
				}
	}
	
	
}


bool es_bipartito(Grafo const& G) {
	bool isBi= true;
	bool *color = new bool[G.V()];
	bool *marked = new bool[G.V()];
	size_t *edgeTo = new size_t[G.V()];
	stack<size_t> cycle;
	for (size_t i = 0; i < G.V(); i++)
	{
		marked[i] = false;
	}
	for (size_t v = 0; v < G.V(); v++)
	{
		if (!marked[v])
		{
			color[v] = false;
			dfs_bipartito(G, v, isBi, color, marked, edgeTo, cycle);
		}
	}
	return isBi;
}

/*
*	Funcion estandar que lee un grafo
*/
Grafo leer_Grafo(size_t V){

	size_t E;
	cin >> E;

	Grafo g(V);
	size_t v, w;

	for (size_t i = 0; i < E; i++)
	{
		cin >> v;
		cin >> w;
		g.ponArista(v, w);
	}
	
	return g;
}

bool resuelveCaso(){

	
	size_t V;
	cin >> V;

	if (!cin){
		return false;
	}
	// leer grafo
	Grafo G = leer_Grafo(V);

	bool ok = es_bipartito(G);

	 //Mostrar solucion
	if (ok) cout << "SI"<<  endl;
	else cout << "NO" << endl;

	return true;

}

int main(){

	while (resuelveCaso());

	return 0;
}