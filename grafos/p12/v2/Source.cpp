// Grupo 21, CRISTHIAN RODRIGUEZ GOMEZ y JONATHAN CARRERO ARANDA

/*
				PRACTICA 10: Arboles libres
				-----------------------------
		
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
/*
	Funcion ###

	Complejidad O(n + m);
*/
bool es_Arborecencia(GrafoDirigido G, size_t &raiz){

	size_t r = 0; 
	size_t k = 0;
	size_t *grado_de_entrada = new size_t[G.V()];
	
	bool *visitado = new bool[G.V()];
	bool b = false;
	// ### FALTA CODIGO obtener_grado_de entrada
	for (size_t i = 0; i < G.V(); i++)
	{
		// Contar elementos de la lista de adyacentes
		//y meterlos en el grado de entrada.
	}
		
	
	for (size_t i = 0; i < G.V(); i++){

		if (grado_de_entrada[i] == 0){

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
}


void GrafoDirigido::ponArista(size_t v, size_t w) {
	if (v >= _V || w >= _V) throw std::invalid_argument("Vértice inexistente");
	++_E;
	_adj[v].push_back(w);
	_adj[w].push_back(v);
}

const Adys& GrafoDirigido::adj(size_t v) const {
	if (v >= _V) throw std::invalid_argument("Vértice inexistente");
	return _adj[v];
}



const Adys& GrafoDirigido::adj(size_t v) const {
	if (v >= _V) throw std::invalid_argument("Vértice inexistente");
	return _adj[v];
}

/*
*	Funcion estandar que lee un grafo
*/
GrafoDirigido leer_Grafo(size_t V){  //param e/s *-g()//dev bool

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


/*
*
*
*
*/
bool resuelveCaso(){

	// leer grafo
	size_t V;
	cin >> V;

	if (!cin){
		return false;
	}

	GrafoDirigido G = leer_Grafo(V);

	// Arbol Libre
	bool ok = es_Arborecencia(G);

	// Mostrar solucion
	if (ok) cout << "SI" << endl;
	else cout << "NO" << endl;

	return true;

}

int main(){

	// casos de prueba ilimitados

	while (resuelveCaso());
	//system("PAUSE");
	return 0;
}