// Grupo 21, CRISTHIAN RODRIGUEZ GOMEZ y JONATHAN CARRERO ARANDA

/*
				PRACTICA 12: Arborecencia
				-------------------------
		
*/
#include <iostream>
#include <string>
#include "GrafoDirigido.h"
#include<fstream>

using namespace std;


/*
	Funcion ###

	Complejidad O(n + m);
*/
void dfs_arborecencia(GrafoDirigido const& G, size_t v, size_t &k, bool *visitado, bool &arb) {

	 vector<size_t> lista;
	 size_t w ;
	 ++k;

	visitado[v] = true;
	lista = G.adj(v);

	while (!lista.empty()){

		w = lista.back();
		lista.pop_back();

		if (visitado[w]){

			arb = false;
		}
		else {
			dfs_arborecencia(G, w, k, visitado, arb);
		}
	}
	
}
vector<size_t> obtener_grado_de_entrada(GrafoDirigido const& g) {

	vector<size_t> grado_de_entrada;
	vector<size_t> lista;
	size_t i, j;
	size_t grado = 0;
	
	for ( i = 0; i < g.V(); i++)
	{
		grado = 0;

		//OBTIENE LAS LISTAS DE CADA Nodo i
		for (size_t t = 0; t < g.V(); t++)
		{
				lista = g.adj(t);
				//RECORRE LAS LISTAS DE CADA NODO
				for (j = 0; j < lista.size(); j++)
				{
					//COMPARA SI EL NODO i TIENE ENTRADAS
					if (lista.at(j) == i) {
						grado += 1;
					}
				}

		}
				
			
		
		grado_de_entrada.push_back(grado);
	}
	return grado_de_entrada;
}
/*
	Funcion ###

	Complejidad O(n + m);
*/
bool es_Arborecencia(GrafoDirigido const& G, size_t &raiz){

	size_t r = 0; 
	size_t k = 0;
	vector<size_t> grado_de_entrada;
	
	bool *visitado = new bool[G.V()];
	bool b = false;
	grado_de_entrada = obtener_grado_de_entrada(G);
		
	
	for (size_t i = 0; i < G.V(); i++){

		if (grado_de_entrada.at(i)== 0){

			r++; raiz = i;
		} 
	}

	if (r == 1){
		k = 0;
		b = true;

		// INICIALIZAMO VISITADO A FALSE
		for (size_t i = 0; i < G.V(); i++) visitado[i] = false;
		
		dfs_arborecencia(G, raiz, k, visitado, b);

		b = (b && k == G.V());	
	}
	else {
		b = false;
	}
	return b;
}

void GrafoDirigido::ponArista(size_t v, size_t w) {
	if (v >= _V || w >= _V) throw std::invalid_argument("Vértice inexistente");
	++_E;
	_adj[v].push_back(w);
}

const Adys& GrafoDirigido::adj(size_t v) const {
	if (v >= _V) throw std::invalid_argument("Vértice inexistente");
	return _adj[v];
}




/*
*	Funcion estandar que lee un grafo
*/
GrafoDirigido leer_Grafo(size_t V){  

	size_t E;
	cin >> E;

	GrafoDirigido g(V);
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

	
	size_t V, raiz = 0;
	cin >> V;

	if (!cin){
		return false;
	}
	// leer grafo
	GrafoDirigido G = leer_Grafo(V);

	bool ok = es_Arborecencia(G, raiz);

	 //Mostrar solucion
	if (ok) cout << "SI " << raiz<<  endl;
	else cout << "NO" << endl;

	return true;

}

int main(){

	while (resuelveCaso());

	return 0;
}